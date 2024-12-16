#include <iostream>
#include <fstream>
#include <vector>
#include "CHARACTERS_OP"
#include <iomanip>
#include <ostream>

using namespace std;

int main() {
    vector<Character> characters;
    getDataFromFile("../OPCHAR.csv", characters);
    cout << "Reading from a list of all characters in One Piece" << endl;
    cout << "Number of One Piece Characters read from file: " << characters.size() << "\n" << endl;
    string firstName = characters.front().getName();
    string lastName = characters.back().getName();
    getA_Z(firstName, lastName);
    cout << "#     Character Name           ch#   ep#   year" << endl;

    for (const Character& opchar : characters)
    {
        cout << opchar << endl;

   }
    return 0;
}