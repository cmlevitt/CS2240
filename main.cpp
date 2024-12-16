#include "OpenAddressing.h"
#include "SeparateChaining.h"
using namespace std;
#include "CHARACTERS_OP.h"


string getCharacterName(Character opchar)
{
    return opchar.getName();
}

string getKey1(const Character& character)
{
    return character.getName();
}

string getKey2(const Character& character)
{
    return character.getName() + to_string(character.getChapter());
}
int main()
{
    //plz
    Character character;
    vector<Character> characters;
    character.getDataFromFile("C:/Users/calli/Project5-cmlevitt/OPCHAR_SORTED.csv", characters);
    cout << "Number of Characters in Vector: " << characters.size() << endl;

    //open addressing
    QuadraticProbing<Character> openAddressing1(1317);
    QuadraticProbing<Character> openAddressing2(1500);
    QuadraticProbing<Character> openAddressing3(2000);
    QuadraticProbing<Character> openAddressing4(2500);
    QuadraticProbing<Character> openAddressing5(3000);


    QuadraticProbing<Character> openAddressing6(1317);
    QuadraticProbing<Character> openAddressing7(1500);
    QuadraticProbing<Character> openAddressing8(2000);
    QuadraticProbing<Character> openAddressing9(2500);
    QuadraticProbing<Character> openAddressing10(3000);


    //separate chaining
    SeparateChaining<Character> separateChaining1(1317);
    SeparateChaining<Character> separateChaining2(1500);
    SeparateChaining<Character> separateChaining3(2000);
    SeparateChaining<Character> separateChaining4(2500);
    SeparateChaining<Character> separateChaining5(3000);


    SeparateChaining<Character> separateChaining6(1317);
    SeparateChaining<Character> separateChaining7(1500);
    SeparateChaining<Character> separateChaining8(2000);
    SeparateChaining<Character> separateChaining9(2500);
    SeparateChaining<Character> separateChaining10(3000);


    ofstream CollisionsOpenAddressing;
    CollisionsOpenAddressing.open("C:/Users/calli/Project5-cmlevitt/OpenAddressing1-5.txt");

    ofstream CollisionsOpenAddressing2;
    CollisionsOpenAddressing2.open("C:/Users/calli/Project5-cmlevitt/OpenAddressing6-10.txt");

    ofstream CollisionsSeparateChaining;
    CollisionsSeparateChaining.open("C:/Users/calli/Project5-cmlevitt/SeparateChaining1-5.txt");

    ofstream CollisionsSeparateChaining2;
    CollisionsSeparateChaining2.open("C:/Users/calli/Project5-cmlevitt/SeparateChaining6-10.txt");

    for (unsigned long i = 0; i < characters.size(); i++)
    {
        Character character = characters[i];
        string key1 = getKey1(character);
        string key2 = getKey2(character);

        openAddressing1.insert(key1, character);
        openAddressing2.insert(key1, character);
        openAddressing3.insert(key1, character);
        openAddressing4.insert(key1, character);
        openAddressing5.insert(key1, character);

        openAddressing6.insert(key2, character);
        openAddressing7.insert(key2, character);
        openAddressing8.insert(key2, character);
        openAddressing9.insert(key2, character);
        openAddressing10.insert(key2, character);


        separateChaining1.insert(key1, character);
        separateChaining2.insert(key1, character);
        separateChaining3.insert(key1, character);
        separateChaining4.insert(key1, character);
        separateChaining5.insert(key1, character);

        separateChaining6.insert(key2, character);
        separateChaining7.insert(key2, character);
        separateChaining8.insert(key2, character);
        separateChaining9.insert(key2, character);
        separateChaining10.insert(key2, character);


    CollisionsOpenAddressing << "Key1: " << key1 << endl;
    CollisionsOpenAddressing << "Collisions- Open Addressing Table 1: " << openAddressing1.getCollisions() << endl;
    CollisionsOpenAddressing << "Collisions- Open Addressing Table 2: " << openAddressing2.getCollisions() << endl;
    CollisionsOpenAddressing << "Collisions- Open Addressing Table 3: " << openAddressing3.getCollisions() << endl;
    CollisionsOpenAddressing << "Collisions- Open Addressing Table 4: " << openAddressing4.getCollisions() << endl;
    CollisionsOpenAddressing << "Collisions- Open Addressing Table 5: " << openAddressing5.getCollisions() << endl;
    CollisionsOpenAddressing << "\n" << endl;

    CollisionsOpenAddressing2 << "Key2: " << key2 << endl;
    CollisionsOpenAddressing2 << "Collisions- Open Addressing Table 6: " << openAddressing6.getCollisions() << endl;
    CollisionsOpenAddressing2 << "Collisions- Open Addressing Table 7: " << openAddressing7.getCollisions() << endl;
    CollisionsOpenAddressing2 << "Collisions- Open Addressing Table 8: " << openAddressing8.getCollisions() << endl;
    CollisionsOpenAddressing2 << "Collisions- Open Addressing Table 9: " << openAddressing9.getCollisions() << endl;
    CollisionsOpenAddressing2 << "Collisions- Open Addressing Table 10: " << openAddressing10.getCollisions() << endl;
    CollisionsOpenAddressing2 << "\n" << endl;

    CollisionsSeparateChaining << "Key1: " << key1 << endl;
    CollisionsSeparateChaining << "Collisions- Separate Chaining Table 1: " << separateChaining1.getCollisions() << endl;
    CollisionsSeparateChaining << "Collisions- Separate Chaining Table 2: " << separateChaining2.getCollisions() << endl;
    CollisionsSeparateChaining << "Collisions- Separate Chaining Table 3: " << separateChaining3.getCollisions() << endl;
    CollisionsSeparateChaining << "Collisions- Separate Chaining Table 4: " << separateChaining4.getCollisions() << endl;
    CollisionsSeparateChaining << "Collisions- Separate Chaining Table 5: " << separateChaining5.getCollisions() << endl;
    CollisionsSeparateChaining << "\n" << endl;

    CollisionsSeparateChaining2 << "Key2: " << key2 << endl;
    CollisionsSeparateChaining2 << "Collisions- Separate Chaining Table 6: " << separateChaining6.getCollisions() << endl;
    CollisionsSeparateChaining2 << "Collisions- Separate Chaining Table 7: " << separateChaining7.getCollisions() << endl;
    CollisionsSeparateChaining2 << "Collisions- Separate Chaining Table 8: " << separateChaining8.getCollisions() << endl;
    CollisionsSeparateChaining2 << "Collisions- Separate Chaining Table 9: " << separateChaining9.getCollisions() << endl;
    CollisionsSeparateChaining2 << "Collisions- Separate Chaining Table 10: " << separateChaining10.getCollisions() << endl;
    CollisionsSeparateChaining2 << "\n" << endl;
}
    CollisionsOpenAddressing.close();
    CollisionsOpenAddressing2.close();
    CollisionsSeparateChaining.close();
    CollisionsSeparateChaining2.close();


    //table sizes open addressing
    //key1
    cout << "Open Addressing Table Sizes: " << endl;
    cout << openAddressing1.getTableSize() << endl;
    cout << openAddressing2.getTableSize() << endl;
    cout << openAddressing3.getTableSize() << endl;
    cout << openAddressing4.getTableSize() << endl;
    cout << openAddressing5.getTableSize() << endl;
    //key2
    cout << openAddressing6.getTableSize() << endl;
    cout << openAddressing7.getTableSize() << endl;
    cout << openAddressing8.getTableSize() << endl;
    cout << openAddressing9.getTableSize() << endl;
    cout << openAddressing10.getTableSize() << endl;


}


