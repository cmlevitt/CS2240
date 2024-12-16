#include "sorting-algorithms/bubbleSort.h"
#include "sorting-algorithms/heapSort.h"
#include "sorting-algorithms/insertionSort.h"
#include "sorting-algorithms/mergeSort.h"
#include "sorting-algorithms/quickSort.h"
#include "sorting-algorithms/radixSort.h"
#include "sorting-algorithms/selectionSort.h"
#include "stability-test/contactsList.h"
#include <iomanip>
#include "CHARACTERS_OP.h"
using namespace std;

void stabilityTest();

int main() {
    Character opchar;
    vector<Character> characters;
    opchar.getDataFromFile("C:/Users/calli/cmlevitt-Project4/OPCHAR_SORTED.csv", characters);

    //characters.resize(1000);
    unsigned long allocations;
    unsigned long reads;
    for(int i = 1000; i >= 100; i -= 100)
    {
        characters.resize(i);
        reads = 0;
        allocations = 0;

        cout << "*************************************************" << endl;
        cout << "Sorting Vector of " << characters.size() << " items\n" << endl;

        cout << "Stable Algorithms: " << endl;

        bubbleSort(characters, reads, allocations);
        cout << "Bubble Sort: Reads: " << reads << ", Allocations: " << allocations << endl;

        mergeSort(characters, reads, allocations);
        cout << "Merge Sort: Reads: " << reads << ", Allocations: " << allocations << endl;

        cout << "\nUnstable Algorithms:" << endl;


        heapSort(characters, reads, allocations);
        cout << "Heap Sort: Reads: " << reads << ", Allocations: " << allocations << endl;


        selectionSort(characters, reads, allocations);
        cout << "Selection Sort: Reads: " << reads << ", Allocations: " << allocations << endl;

        characters.resize(characters.size() - 100);
    }
    stabilityTest();
    return 0;
}

void stabilityTest() {
    ContactsList people;
    people.readContactsFromFile("../stability-test/names.csv");
    cout << "*************************************************" << endl;
    cout << "\nPeople (Default ordering)" << endl;
    people.printList();

    cout << endl << "Bubble Sort" << endl;
    people.sortAndPrint(bubbleSort<contact>);

    cout << endl << "Merge Sort" << endl;
    people.sortAndPrint(mergeSort<contact>);

    cout << endl << "Heap Sort" << endl;
    people.sortAndPrint(heapSort<contact>);

    cout << endl << "Selection Sort" << endl;
    people.sortAndPrint(selectionSort<contact>);

}