#include <algorithm>
#include "AVLTree.h"
#include "BinarySearchTree.h"
#include "SplayTree.h"
#include "CHARACTERS_OP.h"
#include <fstream>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

int main() {

    //integer trees
    BinarySearchTree<int> bst1;
    AVLTree<int> avl1;
    SplayTree<int> splay1;

    for (int i = 0; i < 100; i++)
    {
        bst1.add(i);
        avl1.add(i);
        splay1.add(i);
    }

    int bst1_depth = 0;
    int avl1_depth = 0;
    int splay1_depth = 0;

    ofstream outFile;
    outFile.open("../data/integerTrees.csv");
    bst1.find(0, bst1_depth);
    bst1_depth = 0;
    cout << "depth at 0: " << bst1_depth <<endl;
    bst1_depth = 0;
    bst1.find(101, bst1_depth);
    cout << "depth at 101: " << bst1_depth<<endl;
    bst1_depth = 0;
    bst1.find(102, bst1_depth);
    cout <<"depth at 102: " << bst1_depth<<endl;

    for (int i = 1; i <= 100; i++)
    {

        bst1.find(i, bst1_depth);
        avl1.find(i, avl1_depth);
        splay1.find(i, splay1_depth);

        outFile << "Depth of: " << i << ", BST depth: " << bst1_depth << ", AVL depth: " << avl1_depth << ", SPLAY depth: " << splay1_depth << "\n";
    }
    outFile.close();

    //random shuffle int trees
    BinarySearchTree<int> bst2;
    AVLTree<int> avl2;
    SplayTree<int> splay2;

    vector<int> randomNums;
    for (int i = 1; i <= 100; i++)
    {
        randomNums.push_back(i); //not sure if we covered this in class...looked it up on stack overflow (see report)

    }
    std::random_shuffle(randomNums.begin(),randomNums.end());

    for (int num : randomNums)
    {
        bst2.add(num);
        avl2.add(num);
        splay2.add(num);
    }
    int bst2_depth = 0;
    int avl2_depth = 0;
    int splay2_depth = 0;

    outFile.open("../data/integerShuffle.csv");
    for (int i = 1; i <= 100; i++)
    {

        bst2.find(i, bst2_depth);
        avl2.find(i, avl2_depth);
        splay2.find(i, splay2_depth);

        outFile << "Depth of: " << randomNums[i] << ", BST depth: " << bst2_depth << ", AVL depth: " << avl2_depth << ", SPLAY depth: " << splay2_depth << "\n";
    }
    outFile.close();


    //trees of custom data type
    vector<Character> characters;
    Character character;
    character.getDataFromFile("../OPCHAR_SORTED.csv", characters);
    BinarySearchTree<Character> bst3;
    AVLTree<Character> avl3;
    SplayTree<Character> splay3;
    for (const Character &character : characters) {
        bst3.add(character);
        avl3.add(character);
        splay3.add(character);
    }


    outFile.open("../data/customDataType.csv");
    for (const Character &character : characters) {
        int bst3_depth = 0, avl3_depth = 0, splay3_depth = 0;

        bst3.find(character, bst3_depth);
        avl3.find(character, avl3_depth);
        splay3.find(character, splay3_depth);

        outFile << "Character Name: " << character.getName() <<", BST depth: " << bst3_depth << ", AVL depth: " << avl3_depth << ", SPLAY depth: " << splay3_depth << "\n";

    }
    outFile.close();

    //todo last element written to csv twice
    //todo check in about graphs
    //todo REPORT


    //splay tree 5x
    vector<Character> characters2;
    Character character2;
    character2.getDataFromFile("../OPCHAR_SORTED.csv", characters2);
    SplayTree<Character> splay4;
    for (const Character &character2 : characters2) {
        splay4.add(character2);
    }


    outFile.open("../data/customSplay5x.csv");
    for (const Character &character2 : characters2)
    {
        int splay4_depth = 0;
        int repeats = 1;
        while (repeats <= 5)
        {
            splay4.find(character2, splay4_depth);
            outFile << "Character Name: " << character2.getName() << ", search number: " << repeats << ", SPLAY depth: " << splay4_depth << "\n";
            repeats++;
        }



    }
    outFile.close();

};
