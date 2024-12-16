//
// Created by calli on 9/24/2024.
//

#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"
#include <iostream>
using std::cout, std::endl;

template<typename Object>
class Queue
{
private:
    Node<Object>* front;
    Node<Object>* back;
public:
    Queue() //constructor, empty queue
    {
        front = back = nullptr;
    }

    // De-constructor aka destructor
    // This method will automatically be called
    // at the end of the lifetime of the object
    ~Queue() {
        // Make sure no heap allocation
        while (front != nullptr) {
            dequeue();
        }
        cout << "No memory leaks!" << endl;
    }

    // enqueue (add a value to the Queue)
    void enqueue(Object item) {
        // Store the item in a Node in heap memory
        Node<Object>* newNodePtr = new Node<Object>(item);
        newNodePtr->setNext(nullptr);


        if (back == nullptr)
        {
            front = back = newNodePtr;
        }
        else
        {
            back ->setNext(newNodePtr); //new node to the back
            back = newNodePtr;
        }

    }

    // dequeue(remove a value from the Queue)
    // Returns the value being dequeued
    Object dequeue() {
        // Check that there is a Node to dequeue
        if (front == nullptr) {
            // The Queue is empty
            return Object();
        }
        // Create a copy of the value to be returned
        Object item = front->getItem();
        // Store a copy of front
        const Node<Object>* frontCopy = front;
        // Update front
        front = front->getNext();

        if (front == nullptr)
        {
            front = back = nullptr;
        }

        // Delete the Node from heap memory
        delete frontCopy;
        // Return the value being popped
        return item;
    }

    // Search for an item in the Queue
    // Return true if the item is in the Queue
    // Return false otherwise
    bool search(Object item) const {
        Node<Object>* currentNode = front;
        while (currentNode != nullptr) {
            if (currentNode->getItem() == item) {
                return true;//found the node
            }
            currentNode = currentNode->getNext(); //move to next node in the queue
        }
        return false;
    }

    // Print (list all the values in the Queue)
    void print() const {
        cout << "Front of Queue" << endl;
        Node<Object>* curr = front;
        while (curr != nullptr) {
            cout << curr->getItem() << endl;
            curr = curr->getNext();
        }
        cout << "Back of Queue \n" << endl;
    }
};

#endif //QUEUE_H
