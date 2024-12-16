#include <iostream>
#include <fstream>
#include <vector>
#include "CHARACTERS_OP.h"
#include <iomanip>
#include <ostream>
#include "Queue.h"
#include "Stack.h"

using namespace std;

int main() {
    vector<Character> characters;
    getDataFromFile("../OP_Characters.csv", characters);
    //cout << "Reading from a list of all characters in One Piece" << endl;
    //cout << "Number of One Piece Characters read from file: " << characters.size() << endl;
    //for (int i = 99; i < characters.size() && i < 110; i++)
    // {
    //     cout << characters[i] << endl;
    // }

    cout << "Testing String and Integer Queue functions!" << endl;
    // create queue of strings, enqueue 5 items
    Queue<string> characterQueue;
    characterQueue.enqueue("Monkey D Luffy");
    characterQueue.enqueue("Roronoa Zoro");
    characterQueue.enqueue("Vinsmoke Sanji");
    characterQueue.enqueue("Nami");
    characterQueue.enqueue("Usopp");

    //demo that enqueueing works
    cout << "\n" << "String enqueue demo" << "\n" << endl;
    characterQueue.print();

    //demo that dequeueing works
    cout << "\n" << "String Dequeue demo" << "\n" << endl;
    cout << "Item dequeued: " << characterQueue.dequeue() << endl;
    characterQueue.print();

    //demo the queue search function
    cout << "\n" << "Character Search demo: Searching for 'Nami' in the queue" << endl;
    bool inQueue = characterQueue.search("Nami");
    if (inQueue)
    {
        cout << "Character 'Nami' found in queue" << endl;
    }
    else
    {
        cout << "Character 'Nami' not found in queue" << endl;
    }

    //create queue of integers, enqueue 5 items
    Queue<int> chapterQueue;
    chapterQueue.enqueue(1);
    chapterQueue.enqueue(2);
    chapterQueue.enqueue(3);
    chapterQueue.enqueue(4);
    chapterQueue.enqueue(5);

    //demo enqueueing works
    cout << "\n" << "Integer Enqueue demo" << "\n" << endl;
    chapterQueue.print();

    //demo dequeueing works
    cout << "\n" << "Integer Dequeue demo" << endl;
    cout << "Item dequeued:" << chapterQueue.dequeue() << "\n" << endl;
    chapterQueue.print();

    cout << "_______________________________________" << endl;
    cout << "Testing Third Queue and Stack \n" << endl;

    // Create a third Queue object and a Stack object, both of the type you created in Project 1.
    //Use a loop to print and enqueue the first 10 objects from your vector (from Project 1) onto the Queue.
    //Use a second loop to dequeue the 10 objects off the Queue and push them onto the Stack.
    //Use a third loop to pop the 10 objects off the Stack and print them.

    Queue<Character> OnePieceQueue;
    Stack<Character> OnePieceStack;
    //enqueue the first 10 items from the CSV
    for (int i = 0; i < characters.size() && i < 10; i++)
        {
            OnePieceQueue.enqueue(characters[i]);
        }
     OnePieceQueue.print();

    //dequeue items from queue and push onto stack
    for (int i = 0; i < 10; i++)
    {
        Character dequeuedChar = OnePieceQueue.dequeue();
        OnePieceStack.push(dequeuedChar);
    }

    //pop and print items from stack
    cout << "Items popped off Stack: " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << OnePieceStack.pop() << endl;
    }
    cout << "\n" << endl;

    return 0;
}