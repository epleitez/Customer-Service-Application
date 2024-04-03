//
// Created by Emely Pleitez on 2/20/24.
//

#include "fastq.h"
#include <stdexcept>
#include <iostream>

using namespace std;

ArrayBuffer::ArrayBuffer(int capacity){
    //If the specified capacity is less than 1
    //the constructor sets the capacity to 0
    if(capacity < 1){
        capacity = 0;
        m_buffer = nullptr;
    }//end if
    //allocate memory and initialize all member variables
    else if(capacity > 1){
        m_capacity = capacity;
        m_buffer = new int[capacity];
    }//end else if

    //initialize all member variables
    m_next = nullptr;
    m_count = 0;
    m_start = 0;
    m_end = 0;


}//end constructor, ArrayBuffer(int capacity)

void ArrayBuffer::clear(){
    //deallocate memory and re-initialize all member variables to default values
    delete[] m_buffer;

    m_buffer = nullptr;
    m_capacity = 0;
    m_count = 0;
    m_start = 0;
    m_end = 0;

}//end ArrayBuffer::clear()

ArrayBuffer::~ArrayBuffer(){
    clear();
}//end destructor, ArrayBuffer::~ArrayBuffer()

bool ArrayBuffer::empty() const {
    //returns true if buffer holds no items
    return m_count == 0;
}//end ArrayBuffer::empty() const


//function inserts the data into the array buffer at the proper index. (m_end)
void ArrayBuffer::enqueue(int data){

    if(m_count == m_capacity){
        //if buffer is full, throw exception overflow_error
        throw overflow_error("Buffer Overflow: cannot enqueue...");
    }//end if

    //updates the appropriate member variables in the object: m_end and m_count
    m_buffer[m_end] = data;
    m_end = (m_end + 1) % m_capacity;
    m_count++;

}//end ArrayBuffer::enqueue(int data)

//function removes a piece of data from the start of the list in the array.
int ArrayBuffer::dequeue(){
    if(empty()){
        //if buffer is empty, throw exception underflow_error
        throw underflow_error("Buffer Underflow: cannot dequeue...");
    }//end if

    //updates the appropriate member variables in the object: m_start and m_count
    int data = m_buffer[m_start];
    m_start = (m_start + 1) % m_capacity;
    m_count--;
    //returns the data value

    return data;

}//end ArrayBuffer::dequeue()

ArrayBuffer::ArrayBuffer(const ArrayBuffer & rhs){

    //copy all member variables from rhs
    m_buffer = nullptr;
    m_capacity = rhs.m_capacity;
    m_count = rhs.m_count;
    m_start = rhs.m_start;
    m_end = rhs.m_end;

    //deallocate the current memory if any,
    //and reallocate new memory to create a deep copy
    if(m_capacity > 0){
        m_buffer = new int[m_capacity];
        for(int i = m_start; i < m_start + m_count; i++){
            m_buffer[i % m_capacity] = rhs.m_buffer[i % m_capacity];
        }//end for
    }//end if
    else{
        m_buffer = nullptr;
    }//end else

}//end copy constructor

const ArrayBuffer & ArrayBuffer::operator=(const ArrayBuffer & rhs){
    //check for self-assignment
    if(this != &rhs){
        clear();
        m_capacity = rhs.m_capacity;
        m_count = rhs.m_count;
        m_start = rhs.m_start;
        m_end = rhs.m_end;

        //deallocate the current memory if any,
        //and reallocate new memory to create a deep copy
        if(m_capacity > 0){
            m_buffer = new int[m_capacity];
            for(int i = 0; i < m_capacity; i++){
                m_buffer[i] = rhs.m_buffer[i];
            }//end for
        }//end if
        else{
            m_buffer = nullptr;
        }//end else
    }//end if
    return *this;

}//end ArrayBuffer::operator=(const ArrayBuffer & rhs)

void ArrayBuffer::dump(){
    int start = m_start;
    //int end = m_end;
    int counter = 0;
    cout << "ArrayBuffer size: " << m_capacity << " : ";
    if (!empty()){
        while(counter < m_count){
            cout << m_buffer[start] << "[" << start << "]" << " ";
            start = (start + 1) % m_capacity;
            counter++;
        }
        cout << endl;
    }
    else cout << "ArrayBuffer is empty!" << endl;
}

ListBuffer::ListBuffer(int minBufCapacity){

    //If minBufCapacity is less than 1,
    // the constructor creates a buffer with default size

    if(minBufCapacity < 1){
        m_minBufCapacity = DEFAULT_MIN_CAPACITY;
    }//end if
    else{
        m_minBufCapacity = minBufCapacity;
    }//end else

    //create a new buffer with the specified capacity
    m_cursor = new ArrayBuffer(m_minBufCapacity);
    m_cursor->m_next = m_cursor;
    m_listSize = 1;


}//end constructor

ListBuffer::~ListBuffer(){
    clear();
    //delete the rest of the linked node
    ArrayBuffer *current = m_cursor->m_next;
    while(current != m_cursor){
        ArrayBuffer *temp = current;
        current = current->m_next;
        delete temp;
    }//end while
    delete m_cursor;
}//end destructor

//function deallocates all memory in the object
void ListBuffer::clear(){
    while(m_listSize > 0){
        ArrayBuffer *temp = m_cursor->m_next;
        delete m_cursor; //clear the current cursor
        m_cursor = temp;
        m_listSize--;
    }//end while
    m_cursor = new ArrayBuffer(m_minBufCapacity);
    m_cursor->m_next = m_cursor;
    m_listSize = 1;

}//end ListBuffer::clear()

//function inserts data into the queue.
// It adds the data item at the end index of the newest buffer in the linked list
void ListBuffer::enqueue(const int& data) {

    try {
        //if the buffer has space, the insertion is preformed correctly
        m_cursor->enqueue(data);

    } catch (overflow_error& e) {
        // If ArrayBuffer::enqueue throws overflow_error, insert a new buffer
        int newCapacity = max(m_minBufCapacity, m_cursor->m_capacity * INCREASE_FACTOR);
        ArrayBuffer* newBuffer = new ArrayBuffer(newCapacity);
        newBuffer->enqueue(data); // Insert data into the new buffer

        if (m_cursor == nullptr) {
            // If the list is empty, make the new buffer the only buffer
            m_cursor = newBuffer;
            m_cursor->m_next = m_cursor; // Point to itself since it's the only node
        } else {
            // Insert the new buffer into the list
            newBuffer->m_next = m_cursor->m_next;
            m_cursor->m_next = newBuffer;
        }
        m_cursor = newBuffer; // Advance the cursor to the new buffer
        m_listSize++; // Increment the list size
    }//end catch

}//end enqueue(const int& data)


//Function removes data from the queue.
// It removes the data item from the start index of the oldest buffer in the linked list
int ListBuffer::dequeue() {

    int data = 0;
    // If the oldest buffer is empty, remove the node containing the empty buffer
    if (m_listSize == 0) {
        throw underflow_error("Underflow Error: The queue is empty...");
    }//end if
    else{
        data = m_cursor->m_next->dequeue(); //try to dequeue from the oldest buffer
        if (m_cursor->m_next->empty()) {
            // If the oldest buffer is empty, remove the node containing the empty buffer
            ArrayBuffer* temp = m_cursor->m_next;
            m_cursor->m_next = temp->m_next;
            delete temp;
            m_listSize--;
        }//end if
    }//end else

    return data;

}//end dequeue()


//Copy constructor, creates a deep copy of rhs
//use the copy constructor from ArrayBuffer class here to create deep copies of ArrayBuffer objects.
ListBuffer::ListBuffer(const ListBuffer & rhs){
    // Copy the circular linked list
    m_cursor = new ArrayBuffer(*rhs.m_cursor);
    ArrayBuffer* rhsCursor = rhs.m_cursor->m_next;
    ArrayBuffer* prev = m_cursor;
    // Copy the rest of the linked list
    while(rhsCursor != rhs.m_cursor){
        prev->m_next = new ArrayBuffer(*rhsCursor);
        prev = prev->m_next;
        rhsCursor = rhsCursor->m_next;
    }
    prev->m_next = m_cursor; // Close the circular linked list

    // Copy other member variables
    m_listSize = rhs.m_listSize;
    m_minBufCapacity = rhs.m_minBufCapacity;

}//end ListBuffer(const ListBuffer & rhs)

const ListBuffer & ListBuffer::operator=(const ListBuffer & rhs){
    //check for self-assignment
    if(this != &rhs){
        clear();

        m_cursor = new ArrayBuffer(*rhs.m_cursor);
        ArrayBuffer* rhsCursor = rhs.m_cursor->m_next;
        ArrayBuffer* prev = m_cursor;
        while(rhsCursor != rhs.m_cursor){
            prev->m_next = new ArrayBuffer(*rhsCursor);
            prev = prev->m_next;
            rhsCursor = rhsCursor->m_next;
        }
        prev->m_next = m_cursor; // Close the circular linked list

        // Copy other member variables
        m_listSize = rhs.m_listSize;
        m_minBufCapacity = rhs.m_minBufCapacity;
    }//end if
    return *this;
}//end operator=(const ListBuffer & rhs)

void ListBuffer::dump(){
    ArrayBuffer* temp = m_cursor->m_next;
    //cout << "hello" << endl;
    for(int i=0;i<m_listSize;i++){
        temp->dump();

        temp = temp->m_next;

        cout << endl;
    }
    //cout << endl;
}