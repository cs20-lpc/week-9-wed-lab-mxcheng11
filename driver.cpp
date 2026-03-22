#include "ArrayQueue.hpp"
#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Testing ArrayQueue w/ integers\n" << endl;
    
    // Test 1: constructor and basic operations
    cout << "Test 1: Creating queue with max size 5" << endl;
    ArrayQueue<int> q1(5);
    cout << "isEmpty: " << (q1.isEmpty() ? "true" : "false") << endl;
    cout << "getLength: " << q1.getLength() << endl;
    cout << "getMaxSize: " << q1.getMaxSize() << endl;
    
    // Test 2: enqueue and front/back
    cout << "\nTest 2: Enqueue elements 10, 20, 30" << endl;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    cout << "Length: " << q1.getLength() << endl;
    cout << "Front: " << q1.front() << endl;
    cout << "Back: " << q1.back() << endl;
    
    // Test 3: dequeue
    cout << "\nTest 3: Dequeue front element" << endl;
    q1.dequeue();
    cout << "Length after dequeue: " << q1.getLength() << endl;
    cout << "New front: " << q1.front() << endl;
    
    // Test 4: fill queue to capacity
    cout << "\nTest 4: Fill queue to capacity" << endl;
    q1.enqueue(40);
    q1.enqueue(50);
    q1.enqueue(60);
    cout << "Length: " << q1.getLength() << endl;
    cout << "isFull: " << (q1.isFull() ? "true" : "false") << endl;
    
    // Test 5: exception when enqueuing to full queue
    cout << "\nTest 5: Try to enqueue to full queue" << endl;
    try {
        q1.enqueue(70);
    } catch (string& e) {
        cout << "Exception caught: " << e << endl;
    }
    
    // Test 6: exception when dequeuing from empty queue
    cout << "\nTest 6: Clear queue then try to dequeue" << endl;
    ArrayQueue<int> q2(3);
    try {
        q2.dequeue();
    } catch (string& e) {
        cout << "Exception caught: " << e << endl;
    }
    
    // Test 7: exception when accessing front/back of empty queue
    cout << "\nTest 7: Try to access front/back of empty queue" << endl;
    try {
        q2.front();
    } catch (string& e) {
        cout << "Exception caught: " << e << endl;
    }
    try {
        q2.back();
    } catch (string& e) {
        cout << "Exception caught: " << e << endl;
    }
    
    // Test 8: clear function
    cout << "\nTest 8: Clear a non-empty queue" << endl;
    ArrayQueue<int> q3(5);
    q3.enqueue(100);
    q3.enqueue(200);
    q3.enqueue(300);
    cout << "Before clear  Length: " << q3.getLength() << endl;
    q3.clear();
    cout << "After clear  Length: " << q3.getLength() << endl;
    cout << "isEmpty: " << (q3.isEmpty() ? "true" : "false") << endl;
    
    // Test 9: clear empty queue 
    cout << "\nTest 9: Clear an already empty queue" << endl;
    q3.clear(); 
    cout << "Cleared successfully (no exception)" << endl;
    
    // Test 10: copy constructor
    cout << "\nTest 10: Copy constructor" << endl;
    ArrayQueue<int> q4(4);
    q4.enqueue(1);
    q4.enqueue(2);
    q4.enqueue(3);
    
    ArrayQueue<int> q5(q4);
    cout << "Original queue  Front: " << q4.front() << ", Back: " << q4.back() << ", Length: " << q4.getLength() << endl;
    cout << "Copied queue  Front: " << q5.front() << ", Back: " << q5.back() << ", Length: " << q5.getLength() << endl;
    
    // Test 11: Assignment operator
    cout << "\nTest 11: Assignment operator" << endl;
    ArrayQueue<int> q6(2);
    q6 = q4;
    cout << "Assigned queue Front: " << q6.front() << ", Back: " << q6.back() << ", Length: " << q6.getLength() << endl;
    
    // Test 12: Self-assignment
    cout << "\nTest 12: self-assignment" << endl;
    q6 = q6;
    cout << "self-assignment successful (no crash)" << endl;
    
    // Test 13: Circular behavior
    cout << "\nTest 13: Testing circular buffer behavior" << endl;
    ArrayQueue<int> q7(3);
    q7.enqueue(1);
    q7.enqueue(2);
    q7.enqueue(3);
    cout << "Queue full: " << (q7.isFull() ? "true" : "false") << endl;
    
    q7.dequeue();
    cout << "After dequeue, enqueue 4" << endl;
    q7.enqueue(4);
    cout << "Front: " << q7.front() << ", Back: " << q7.back() << ", Length: " << q7.getLength() << endl;
    
    q7.dequeue();
    q7.enqueue(5);
    cout << "After another dequeue and enqueue 5" << endl;
    cout << "Front: " << q7.front() << ", Back: " << q7.back() << ", Length: " << q7.getLength() << endl;
    
    // Test 14: Different data type (strings)
    cout << "\nTest 14: Testing with string data type" << endl;
    ArrayQueue<string> q8(3);
    q8.enqueue("testing");
    q8.enqueue("week 9");
    q8.enqueue("lab");
    cout << "Front: " << q8.front() << endl;
    cout << "Back: " << q8.back() << endl;
    cout << "Length: " << q8.getLength() << endl;
    
    q8.dequeue();
    cout << "After dequeue  new front: " << q8.front() << endl;
    
    
    
    cout << "\nAll tests completed" << endl;
    
    return 0;
}