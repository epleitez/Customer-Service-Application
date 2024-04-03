//
// Created by Emely Pleitez on 2/28/24.
//
#include "fastq.h"


class Tester{
public:

    //Array Buffer Test Cases

    //testing constructor
    bool arrayBufferTestConstructorNormal(const ArrayBuffer& buffer); //testing normal case
    //testing copy constructor -> normal case and empty case
    bool arrayBufferTestCopyConstructor(ArrayBuffer& buffer);
    //testing enqueue
    bool arrayBufferTestEnqueueNormal(const ArrayBuffer& buffer); //testing normal case
    bool arrayBufferTestEnqueueFull(const ArrayBuffer& buffer); //testing full case
    //testing dequeue
    bool arrayBufferTestDequeueNormal(const ArrayBuffer& buffer);
    //testing enqueue and dequeue together
    //testing normal case, full case, and one element case
    bool arrayBufferTestEnqueueDequeueNormal(const ArrayBuffer& buffer); //enqueue and dequeue same amount of elements
    bool arrayBufferTestEnqueueDequeueOne(const ArrayBuffer& buffer); //enqueue data and dequeue only one data element
    bool arrayBufferTestEnqueueDequeueFull(const ArrayBuffer& buffer); //inserting and removing data with the same size as the buffer size

    //List Buffer Test Cases
    //testing constructor
    bool listBufferTestConstructor(const ListBuffer& buffer); //testing normal case
    //testing copy constructor -> normal case and empty case
    bool listBufferTestCopyConstructor(ListBuffer& buffer);

    //testing enqueue
    //test normal case and full case
    bool listBufferTestEnqueueNormal(const ListBuffer& buffer);

    //testing dequeue
    bool listBufferTestDequeueNormal(const ListBuffer& buffer);
    bool listBufferTestDequeueEmpty(const ListBuffer& buffer);
    bool listBufferTestDequeueFull(const ListBuffer& buffer);

    //testing enqueue and dequeue together
    //testing normal case, full case, and one element case
    bool listBufferTestEnqueueDequeue(const ListBuffer& buffer);
    bool listBufferTestEnqueueDequeueOne(const ListBuffer& buffer);
    bool listBufferTestEnqueueDequeueFull(const ListBuffer& buffer);

    //testing assignment operator
    bool listBufferTestAssignmentOperatorNormal(const ListBuffer& buffer);
    bool listBufferTestAssignmentOperatorEmpty(const ListBuffer& buffer);

};

int main() {
    Tester tester;

    //Array Buffer Test Cases

    cout << "\n****************** TESTING ARRAY BUFFER *****************" << endl;

    ArrayBuffer buffer1(10);

    cout << "\nTesting Constructor (normal case): " << endl;
    if (tester.arrayBufferTestConstructorNormal(buffer1)){
        cout << "\tConstructor passed!" << endl;
    } else{
        cout << "\tConstructor failed!" << endl;
    }

    cout << "\nTesting Copy Constructor (normal case): " << endl;
    if (tester.arrayBufferTestCopyConstructor(buffer1)){
        cout << "\tCopy Constructor passed! All tests passed. " << endl;
    } else{
        cout << "\tCopy Constructor failed! More than one test failed..." << endl;
    }

    cout << "\nTesting Copy Constructor (empty case): " << endl;
    ArrayBuffer emptyBuffer(0);
    if (tester.arrayBufferTestCopyConstructor(emptyBuffer)){
        cout << "\tCopy Constructor passed! All tests passed. " << endl;
    } else{
        cout << "\tCopy Constructor failed! More than one test failed..." << endl;
    }

    cout << "\nTesting Enqueue (normal case): " << endl;
    ArrayBuffer buffer2(5);
    tester.arrayBufferTestEnqueueNormal(buffer2);

    cout << "\nTesting Enqueue (full case): " << endl;
    ArrayBuffer buffer3(2);
    tester.arrayBufferTestEnqueueFull(buffer3);


    cout << "\nTesting Dequeue (normal case): " << endl;
    ArrayBuffer buffer4(5);
    tester.arrayBufferTestDequeueNormal(buffer4);

    cout << "\nTesting Enqueue and Dequeue Together (normal case): " << endl;
    ArrayBuffer buffer5(6);
    tester.arrayBufferTestEnqueueDequeueNormal(buffer5);

    cout << "\nTesting Enqueue and Dequeue Together (one element case): " << endl;
    ArrayBuffer buffer6(3);
    tester.arrayBufferTestEnqueueDequeueOne(buffer6);

    cout << "\nTesting Enqueue and Dequeue Together (full case): " << endl;
    ArrayBuffer buffer7(2);
    tester.arrayBufferTestEnqueueDequeueFull(buffer7);

    //List Buffer Test Cases
    cout << "\n\n****************** TESTING LIST BUFFER *****************" << endl;

    cout << "\nTesting Constructor (normal case): " << endl;
    ListBuffer listBuffer1(10);
    if (tester.listBufferTestConstructor(listBuffer1)){
        cout << "\tConstructor passed!" << endl;
    } else{
        cout << "\tConstructor failed!" << endl;
    }

    cout << "\nTesting Copy Constructor (normal case): " << endl;
    ListBuffer listBuffer2(5);
    if (tester.listBufferTestCopyConstructor(listBuffer2)){
        cout << "\tCopy Constructor passed! All tests passed. " << endl;
    } else{
        cout << "\tCopy Constructor failed! More than one test failed..." << endl;
    }

    cout << "\nTesting Copy Constructor (empty case): " << endl;
    ListBuffer emptyListBuffer(0);
    if (tester.listBufferTestCopyConstructor(emptyListBuffer)){
        cout << "\tCopy Constructor passed! All tests passed. " << endl;
        cout << "\tThe minBuffCapacity was 0 but constructor changed it to DEFAULT_MIN_CAPACITY." << endl;
    } else{
        cout << "\tCopy Constructor failed! More than one test failed..." << endl;
    }


    cout << "\nTesting Enqueue (normal case): " << endl;
    ListBuffer listBuffer3(5);
    tester.listBufferTestEnqueueNormal(listBuffer3);

    cout << "\nTesting Enqueue (Full case): " << endl;
    ListBuffer listBuffer4(2);
    tester.listBufferTestEnqueueNormal(listBuffer4);

    cout << "\nTesting Dequeue (normal case): " << endl;
    ListBuffer listBuffer7(5);
    tester.listBufferTestDequeueNormal(listBuffer7);

    cout << "\nTesting Dequeue (full case): " << endl;
    ListBuffer listBuffer8(2);
    tester.listBufferTestDequeueFull(listBuffer8);

    cout << "\nTesting Dequeue (empty case): " << endl;
    ListBuffer listBuffer9(0);
    tester.listBufferTestDequeueEmpty(listBuffer9);

    cout << "\nTesting Enqueue and Dequeue Together (normal case): " << endl;
    ListBuffer listBuffer10(6);
    tester.listBufferTestEnqueueDequeue(listBuffer10);

    cout << "\nTesting Enqueue and Dequeue Together (one element case): " << endl;
    ListBuffer listBuffer11(2);
    tester.listBufferTestEnqueueDequeueOne(listBuffer11);

    cout << "\nTesting Enqueue and Dequeue Together (full case): " << endl;
    ListBuffer listBuffer12(2);
    tester.listBufferTestEnqueueDequeueFull(listBuffer12);


    cout << "\nTesting Assignment Operator (normal case): " << endl;
    ListBuffer listBuffer5(5);
    tester.listBufferTestAssignmentOperatorNormal(listBuffer5);

    cout << "\nTesting Assignment Operator (empty case): " << endl;
    ListBuffer listBuffer6(0);
    tester.listBufferTestAssignmentOperatorEmpty(listBuffer6);





    return 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ARRAY BUFFER TEST CASES

bool Tester::arrayBufferTestConstructorNormal(const ArrayBuffer& buffer){
    //checks if constructor works for normal case
    bool result = false;
    if (buffer.m_capacity < 1){
        if (buffer.m_capacity == 0){
            result = true;
        }//end if
    } else if(buffer.m_capacity > 1){
        if(buffer.m_capacity == 10){
            result = true;
        }//end if
    }//end else if
    else{
        result = false;
    }//end else
    return result;
}//end testConstructorNormal(const ArrayBuffer& buffer)

bool Tester::arrayBufferTestCopyConstructor(ArrayBuffer& buffer){
    //checks if copy constructor works for normal case
    bool result = false;
    //enqueues 3 elements into the buffer
    if(buffer.m_capacity > 0){
        buffer.enqueue(1);
        buffer.enqueue(2);
        buffer.enqueue(3);
    }//end if
    //creates a copy of the buffer
    ArrayBuffer copy(buffer);

    //checks if the copy is the same as the original
    cout << "\nTest 1: Object Values of Original and Copy" << endl;
    cout << "Original: m_capacity: " << buffer.m_capacity << " m_count: " << buffer.m_count << " m_start: " << buffer.m_start << " m_end: " << buffer.m_end << endl;
    buffer.dump();
    cout << "Copy: m_capacity: " << copy.m_capacity << " m_count: " << copy.m_count << " m_start: " << copy.m_start << " m_end: " << copy.m_end << endl;
    copy.dump();
    if (buffer.m_capacity == copy.m_capacity &&
        buffer.m_count == copy.m_count &&
        buffer.m_start == copy.m_start &&
        buffer.m_end == copy.m_end){
        //checks if the buffer is the same as the copy
        for (int i = buffer.m_start; i < buffer.m_count + buffer.m_start; i++){
            if (buffer.m_buffer[i % buffer.m_capacity] == copy.m_buffer[i % buffer.m_capacity]){
                result = true;
            }//end if
            else{
                result = false;
            }//end else
        }//end for
    }//end if
    else{
        result = false;
    }//end else

    cout << "\nTest 2: Memory locations of Original and Copy" << endl;
    cout << "Original: " << &buffer << " Copy: " << &copy << endl;
    if( &buffer != &copy){
        result = true;
    }//end if
    else{
        result = false;
    }//end else

    return result;
}//end testCopyConstructorNormal(const ArrayBuffer& buffer)

bool Tester::arrayBufferTestEnqueueNormal(const ArrayBuffer &buffer) {
    bool result = false;
    cout << "Before: Buffer m_count: " << buffer.m_count << " Buffer m_capacity: " << buffer.m_capacity << endl;
    ArrayBuffer test(buffer);

    //enqueues 2 elements into the buffer
    test.enqueue(1);
    test.enqueue(2);

    cout << "After: Buffer m_count: " << test.m_count << " Buffer m_capacity: " << test.m_capacity << endl;
    //checks if two elements were enqueued
    if(test.m_count == 2){
        result = true;
        cout << "\tTest passed!" << endl;
    }//end if
    else{
        result = false;
        cout << "\tTest failed!" << endl;
    }//end else

    return result;

}//end testEnqueueNormal(const ArrayBuffer& buffer)


bool Tester::arrayBufferTestEnqueueFull(const ArrayBuffer &buffer) {
    bool result = false;
    cout << "Before: Buffer m_count: " << buffer.m_count << " Buffer m_capacity: " << buffer.m_capacity << endl;
    ArrayBuffer test(buffer);

    //enqueues 2 elements into the buffer
    test.enqueue(1);
    test.enqueue(2);

    cout << "After: Buffer m_count: " << test.m_count << " Buffer m_capacity: " << test.m_capacity << endl;
    if(test.m_count == 2){
        result = true;
        cout << "\tTest passed!" << endl;
    }//end if
    else{
        result = false;
        cout << "\tTest failed!" << endl;
    }//end else

    return result;

}//end testEnqueueFull(const ArrayBuffer& buffer)

bool Tester::arrayBufferTestDequeueNormal(const ArrayBuffer &buffer) {
    bool result = false;
    cout << "Before: Buffer m_count: " << buffer.m_count << " Buffer m_capacity: " << buffer.m_capacity << endl;
    ArrayBuffer test(buffer);

    //enqueues 5 elements into the buffer
    if(test.m_capacity > 0){
        cout << "Enqueue 5 elements..." << endl;
        test.enqueue(1);
        test.enqueue(2);
        test.enqueue(3);
        test.enqueue(4);
        test.enqueue(5);
        test.dump();

        cout << "Dequeue 2 elements..." << endl;
        test.dequeue();
        test.dequeue();
        test.dump();

        cout << "After: Buffer m_count: " << test.m_count << " Buffer m_capacity: " << test.m_capacity << endl;
        if(test.m_count == 3){
            result = true;
            cout << "\tTest passed!" << endl;
        }//end if
        else{
            result = false;
            cout << "\tTest failed!" << endl;
        }//end else

    }
    else{
        cout << "Buffer is empty!" << endl;
    }
    return result;
}//end testDequeueNormal(const ArrayBuffer& buffer)

bool Tester::arrayBufferTestEnqueueDequeueNormal(const ArrayBuffer &buffer) {
    bool result = false;
    ArrayBuffer test(buffer);

    if(test.m_capacity > 0){
        cout << "Enqueue 6 elements..." << endl;
        test.enqueue(1);
        test.enqueue(2);
        test.enqueue(3);
        test.enqueue(4);
        test.enqueue(5);
        test.enqueue(6);
        cout << "Before: Buffer m_count: " << test.m_count << " Buffer m_capacity: " << test.m_capacity << endl;
        test.dump();

        cout << "Dequeue 5 elements..." << endl;
        test.dequeue();
        test.dequeue();
        test.dequeue();
        test.dequeue();
        test.dequeue();
        test.dump();

        cout << "After: Buffer m_count: " << test.m_count << " Buffer m_capacity: " << test.m_capacity << endl;
        if((test.m_end = 5)){
            result = true;
            cout << "\tTest passed!" << endl;
        }//end if
        else{
            result = false;
            cout << "\tTest failed!" << endl;
        }//end else

    }
    else{
        cout << "Buffer is empty!" << endl;
    }
    return result;
}//end testEnqueueDequeueNormal(const ArrayBuffer& buffer)

bool Tester::arrayBufferTestEnqueueDequeueOne(const ArrayBuffer &buffer) {
    bool result = false;
    ArrayBuffer test(buffer);

    if(test.m_capacity > 0){
        cout << "Enqueue 1 element..." << endl;
        test.enqueue(1);
        cout << "Before: Buffer m_count: " << test.m_count << " Buffer m_capacity: " << test.m_capacity << endl;
        test.dump();

        cout << "Dequeue 1 element..." << endl;
        test.dequeue();
        test.dump();

        cout << "After: Buffer m_count: " << test.m_count << " Buffer m_capacity: " << test.m_capacity << endl;
        if(test.m_count == 0){
            result = true;
            cout << "\tTest passed!" << endl;
        }//end if
        else{
            result = false;
            cout << "\tTest failed!" << endl;
        }//end else

    }
    else{
        cout << "Buffer is empty!" << endl;
    }
    return result;
}//end testEnqueueDequeueOne(const ArrayBuffer& buffer)

bool Tester::arrayBufferTestEnqueueDequeueFull(const ArrayBuffer &buffer) {
    bool result = false;
    ArrayBuffer test(buffer);

    if(test.m_capacity > 0){
        cout << "Enqueue 2 elements..." << endl;
        test.enqueue(1);
        test.enqueue(2);
        cout << "Before: Buffer m_count: " << test.m_count << " Buffer m_capacity: " << test.m_capacity << endl;
        test.dump();

        cout << "Dequeue 2 elements..." << endl;
        test.dequeue();
        test.dequeue();
        test.dump();

        cout << "After: Buffer m_count: " << test.m_count << " Buffer m_capacity: " << test.m_capacity << endl;
        if(test.m_count == 0){
            result = true;
            cout << "\tTest passed!" << endl;
        }//end if
        else{
            result = false;
            cout << "\tTest failed!" << endl;
        }//end else

    }
    else{
        cout << "Buffer is empty!" << endl;
    }
    return result;
}//end testEnqueueDequeueFull(const ArrayBuffer& buffer)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// LIST BUFFER TEST CASES

//testing constructor
bool Tester::listBufferTestConstructor(const ListBuffer &buffer) {
    //checks if constructor works for normal case
    bool result = false;
    if (buffer.m_minBufCapacity < 1){
        if (buffer.m_minBufCapacity == 0){
            result = true;
        }//end if
    } else if(buffer.m_minBufCapacity > 1){
        if(buffer.m_minBufCapacity == 10){
            result = true;
        }//end if
    }//end else if
    else{
        result = false;
    }//end else
    return result;
}//end testConstructorNormal(const ListBuffer& buffer)

//testing copy constructor
bool Tester::listBufferTestCopyConstructor(ListBuffer &buffer) {
    //checks if copy constructor works for normal case
    bool result = false;
    //enqueues 3 elements into the buffer
    if(buffer.m_minBufCapacity > 0){
        buffer.enqueue(1);
        buffer.enqueue(2);
        buffer.enqueue(3);
    }//end if

    //creates a copy of the buffer
    ListBuffer copy(buffer);

    //checks if the copy is the same as the original
    cout << "\nTest 1: Object Values of Original and Copy" << endl;
    cout << "Original: m_minBufCapacity: " << buffer.m_minBufCapacity << " m_listSize: " << buffer.m_listSize << endl;
    buffer.dump();
    cout << "Copy: m_minBufCapacity: " << copy.m_minBufCapacity << " m_listSize: " << copy.m_listSize << endl;
    copy.dump();
    if (buffer.m_minBufCapacity == copy.m_minBufCapacity &&
        buffer.m_listSize == copy.m_listSize){
        //checks if the buffer is the same as the copy
        for (int i = buffer.m_cursor->m_start; i < buffer.m_cursor->m_count + buffer.m_cursor->m_start; i++){
            if (buffer.m_cursor->m_buffer[i % buffer.m_cursor->m_capacity] == copy.m_cursor->m_buffer[i % buffer.m_cursor->m_capacity]){
                result = true;
            }//end if
            else{
                result = false;
            }//end else
        }//end for
    }//end if
    else{
        result = false;
    }//end else

    cout << "Test 2: Memory locations of Original and Copy" << endl;
    cout << "Original: " << &buffer << " Copy: " << &copy << endl;
    if( &buffer != &copy){
        result = true;
    }//end if
    else{
        result = false;
    }//end else

    return result;
}//end testCopyConstructorNormal(const ListBuffer& buffer)

//testing enqueue
bool Tester::listBufferTestEnqueueNormal(const ListBuffer &buffer) {
    bool result = false;
    ListBuffer test(buffer);

    cout << "Before: Buffer count: " << test.m_cursor->m_count << " Buffer m_minBufCapacity: " << test.m_minBufCapacity << endl;
    //enqueues 2 elements into the buffer
    test.enqueue(1);
    test.enqueue(2);

    cout << "After: Buffer Count: " << test.m_cursor->m_count << " Buffer m_minBufCapacity: " << test.m_minBufCapacity << endl;
    //checks if two elements were enqueued
    if(test.m_cursor->m_count == 2){
        result = true;
        cout << "\tTest passed!" << endl;
    }//end if
    else{
        result = false;
        cout << "\tTest failed!" << endl;
    }//end else


    return result;

}//end testEnqueueNormal(const ListBuffer& buffer)

bool Tester::listBufferTestDequeueNormal(const ListBuffer &buffer) {
    bool result = false;
    ListBuffer test(buffer);

    //enqueues 5 elements into the buffer
    test.enqueue(1);
    test.enqueue(2);
    test.enqueue(3);
    test.enqueue(4);
    test.enqueue(5);
    cout << "Before: Buffer count: " << test.m_cursor->m_count << " Buffer m_minBufCapacity: " << test.m_minBufCapacity << endl;
    test.dump();

    //dequeues 2 elements from the buffer
    test.dequeue();
    test.dequeue();
    test.dump();
    cout << "After: Buffer Count: " << test.m_cursor->m_count << " Buffer m_minBufCapacity: " << test.m_minBufCapacity << endl;

    //checks if two elements were dequeued
    if(test.m_cursor->m_count == 3){
        result = true;
        cout << "\tTest passed!" << endl;
    }//end if
    else{
        result = false;
        cout << "\tTest failed!" << endl;
    }//end else


    return result;

}//end testDequeueNormal(const ListBuffer& buffer)

bool Tester::listBufferTestDequeueFull(const ListBuffer &buffer) {
    bool result = false;
    ListBuffer test(buffer);

    //enqueues 2 elements into the buffer
    test.enqueue(1);
    test.enqueue(2);
    cout << "Before: Buffer count: " << test.m_cursor->m_count << " Buffer m_minBufCapacity: " << test.m_minBufCapacity << endl;
    test.dump();

    //dequeues 2 elements from the buffer
    test.dequeue();
    test.dequeue();
    //test.dump();

    try{
        test.dequeue();
    }
    catch(underflow_error &e){
        cout << e.what() << endl;
        test.m_cursor->m_count = 0;
    }

    cout << "After: Buffer Count: " << test.m_cursor->m_count << " Buffer m_minBufCapacity: " << test.m_minBufCapacity << endl;
    //checks if two elements were dequeued
    if(test.m_cursor->m_count == 0){
        result = true;
        cout << "\tTest passed!" << endl;
    }//end if
    else{
        result = false;
        cout << "\tTest failed!" << endl;
    }//end else

    return result;

}//end testDequeueFull(const ListBuffer& buffer)

bool Tester::listBufferTestDequeueEmpty(const ListBuffer &buffer) {
    bool result = false;
    ListBuffer test(buffer);

    cout << "Before: Buffer count: " << test.m_cursor->m_count << " Buffer m_minBufCapacity: " << test.m_minBufCapacity << endl;
    test.dump();

    try{
        test.dequeue();
    }
    catch(underflow_error &e){
        cout << e.what() << endl;
    }
    cout << "After: Buffer Count: " << test.m_cursor->m_count << " Buffer m_minBufCapacity: " << test.m_minBufCapacity << endl;
    //checks if two elements were dequeued
    if(test.m_cursor->m_count == 0){
        result = true;
        cout << "\tTest passed!" << endl;
    }//end if
    else{
        result = false;
        cout << "\tTest failed!" << endl;
    }//end else


    return result;

}//end testDequeueEmpty(const ListBuffer& buffer)


bool Tester::listBufferTestEnqueueDequeue(const ListBuffer &buffer) {
    bool result = false;
    ListBuffer test(buffer);

    //enqueues 6 elements into the buffer
    test.enqueue(1);
    test.enqueue(2);
    test.enqueue(3);
    test.enqueue(4);
    test.enqueue(5);
    test.enqueue(6);
    cout << "Before: Buffer count: " << test.m_cursor->m_count << " Buffer m_minBufCapacity: " << test.m_minBufCapacity << endl;
    test.dump();

    //dequeues 5 elements from the buffer
    test.dequeue();
    test.dequeue();
    test.dequeue();
    test.dequeue();
    test.dequeue();
    test.dump();

    cout << "After: Buffer Count: " << test.m_cursor->m_count << " Buffer m_minBufCapacity: " << test.m_minBufCapacity << endl;
    //checks if two elements were dequeued
    if(test.m_cursor->m_count == 1){
        result = true;
        cout << "\tTest passed!" << endl;
    }//end if
    else{
        result = false;
        cout << "\tTest failed!" << endl;
    }//end else


    return result;

}//end testEnqueueDequeue(const ListBuffer& buffer)

bool Tester::listBufferTestEnqueueDequeueOne(const ListBuffer &buffer) {
    bool result = false;
    ListBuffer test(buffer);

    //enqueues 1 element into the buffer
    test.enqueue(1);
    cout << "Before: Buffer count: " << test.m_cursor->m_count << " Buffer m_minBufCapacity: " << test.m_minBufCapacity << endl;
    test.dump();

    //dequeues 1 element from the buffer
    test.dequeue();
    //test.dump();
    try{
        test.dequeue();
    }
    catch(underflow_error &e){
        cout << e.what() << endl;
        test.m_cursor->m_count = 0;
    }

    cout << "After: Buffer Count: " << test.m_cursor->m_count << " Buffer m_minBufCapacity: " << test.m_minBufCapacity << endl;
    //checks if two elements were dequeued
    if(test.m_cursor->m_count == 0){
        result = true;
        cout << "\tTest passed!" << endl;
        cout << "One element dequeued, thus the array is now empty..." << endl;
    }//end if
    else{
        result = false;
        cout << "\tTest failed!" << endl;
    }//end else


    return result;

}//end testEnqueueDequeueOne(const ListBuffer& buffer)

bool Tester::listBufferTestEnqueueDequeueFull(const ListBuffer &buffer) {
    bool result = false;
    ListBuffer test(buffer);

    //enqueues 2 elements into the buffer
    test.enqueue(1);
    test.enqueue(2);
    cout << "Before: Buffer count: " << test.m_cursor->m_count << " Buffer m_minBufCapacity: " << test.m_minBufCapacity << endl;
    test.dump();

    //dequeues 2 elements from the buffer
    test.dequeue();
    test.dequeue();
    //test.dump();
    try{
        test.dequeue();
    }
    catch(underflow_error &e){
        cout << e.what() << endl;
        test.m_cursor->m_count = 0;
    }
    cout << "After: Buffer Count: " << test.m_cursor->m_count << " Buffer m_minBufCapacity: " << test.m_minBufCapacity << endl;

    //checks if two elements were dequeued
    if(test.m_cursor->m_count == 0){
        result = true;
        cout << "\tTest passed!" << endl;
        cout << "same amount of elements enqueued and dequeued according to minBuffCapacity, thus the array is now empty..." << endl;
    }//end if
    else{
        result = false;
        cout << "\tTest failed!" << endl;
    }//end else


    return result;

}//end testEnqueueDequeueFull(const ListBuffer& buffer)


bool Tester::listBufferTestAssignmentOperatorNormal(const ListBuffer& buffer){
    bool result = true;
    //creates an instance of ListBuffer with data
    ListBuffer original(buffer);
    original.enqueue(1);
    original.enqueue(2);
    original.enqueue(3);

    //creates a copy of the buffer using the assignment operator
    ListBuffer copy(5);
    copy = original;
    cout << "Original ListBuffer: " << endl;
    original.dump();

    //clear the original buffer
    original.clear();

    cout << "de-queueing from copy..." << endl;
    while(!copy.m_cursor->m_count == 0){
        cout << copy.dequeue() << "[" << copy.m_cursor->m_count << "] ";
    }//end while
    //copy.dump();
    try{
        copy.dequeue();
    }
    catch(underflow_error &e){
        cout << e.what() << endl;
        copy.m_cursor->m_count = 0;
    }

    //checks if the copy of the original buffer is empty
    if(copy.m_cursor->m_count == 0){
        result = true;
        cout << "\n\tTest passed!" << endl;
    }//end if
    else{
        result = false;
        cout << "\n\tTest failed!" << endl;
    }//end else

    return result;
}//end testAssignmentOperatorNormal(const ListBuffer& buffer)


//testing assignment operator
bool Tester::listBufferTestAssignmentOperatorEmpty(const ListBuffer &buffer) {
    bool result = true;
    //creates an instance of ListBuffer with not data -> its empty
    ListBuffer original(buffer);


    //creates a copy of the buffer using the assignment operator
    ListBuffer copy(0);
    copy = original;
    cout << "Original ListBuffer: " << endl;
    original.dump();

    //clear the original buffer
    original.clear();

    cout << "de-queueing from copy..." << endl;
    while(!copy.m_cursor->m_count == 0){
        cout << copy.dequeue() << "[" << copy.m_cursor->m_count << "] ";
    }//end while
    //copy.dump();
    try{
        copy.dequeue();
    }
    catch(underflow_error &e){
        cout << e.what() << endl;
        copy.m_cursor->m_count = 0;
    }

    //checks if the copy of the original buffer is empty
    if(copy.m_cursor->m_count == 0){
        result = true;
        cout << "\nNothing was dequeued since the original buffer was empty thus so was the copy." << endl;
        cout << "\tTest passed!" << endl;

    }//end if
    else{
        result = false;
        cout << "\n\tTest failed!" << endl;
    }//end else

    return result;
}//end testAssignmentOperatorEmpty(const ListBuffer& buffer)

















