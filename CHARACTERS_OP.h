//
// Created by calli on 8/28/2024.
//

#ifndef CHARACTERS_OP
#define CHARACTERS_OP

#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;
using std::string;
using std::ifstream;
using std::vector;
using std::right;
using std::left;
using std::setw;
using std::ostream;

class Character
{
private:
    //fields
    string name;
    int number, chapter, episode, year;

public:
    //constructors, getters, setters
    Character()
    {
        name = "John Doe";
        number = chapter = episode = 0;
        year = 0000;
    }

    Character(int number, string name, int chapter, int episode, int year)
    {
        this->number = number;
        this->name = name;
        this->chapter = chapter;
        this->episode = episode;
        this->year = year;
    }

    int getNumber() const{
        return number;
    }

    void setNumber(int number){
        this->number = number;
        this->number = number;
    }

    string getName() const{
        return name;
    };
    void setName(string name){
        this->name = name;
    }

    int getChapter() const{
        return chapter;
    }

    void setChapter(int chapter){
        this->chapter = chapter;
    }

    int getEpisode() const{
        return episode;
    }

    void setEpisode(int episode){
        this->episode = episode;
    }

    int getYear() const{
        return year;
    }

    void setYear(int year){
        this->year = year;
    }

    bool operator<(const Character &other) const{
        return this->chapter < other.chapter;
    }

    bool operator>(const Character &other) const{
        return this->chapter > other.chapter;
    }

    bool operator<=(const Character &other) const{
        return this->chapter <= other.chapter;
    }

    bool operator>=(const Character &other) const{
        return this->chapter >= other.chapter;
    }

    bool operator==(const Character &other) const{
        return this->chapter == other.chapter;
    }


    //overloaded operators
    friend ostream& operator << (ostream& outs, const Character& opchar)
    {
        outs << left << setw(6) <<opchar.getNumber();
        outs << left << setw(25) << opchar.getName();
        outs << setw(6) << opchar.getChapter();
        outs << setw(6) << opchar.getEpisode();
        outs << setw(6) << opchar.getYear();
        return outs;
    }

    void getA_Z(string firstName, string lastName)
    {
        cout << "The first character alphabetically is " << firstName << endl;
        cout << "The last character alphabetically is " << lastName << "\n" << endl;
    }


    //use & to pass vector by reference
    void getDataFromFile(string filename, vector<Character>& characters)
    {
        ifstream fileIn;
        fileIn.open(filename);
        if(fileIn)
        {
            string header;
            getline(fileIn, header);

            //declare variables
            string name = "", newline = "";
            int number = 0, chapter = 0, episode = 0, year = 0000;
            char comma = ',';

            while (fileIn)
            {
                //number
                fileIn >> number;
                fileIn >> comma;

                getline(fileIn, name, ',');

                //chapter
                fileIn >> chapter;
                if (!fileIn) //
                {
                    chapter = 0;
                    fileIn.clear();
                }
                fileIn >> comma;

                //episode
                fileIn >> episode;
                if (!fileIn)
                {
                    episode = 0;
                    fileIn.clear();
                }
                fileIn >> comma;

                fileIn >> year;
                if (!fileIn) //there was no class 2
                {
                    year = 0000;
                    fileIn.clear();
                }


                //read through newline at end of line to go to next line
                getline(fileIn, newline);

                //create a character object to store data from the line
                //and add it to the characters vector
                characters.push_back(Character(number, name, chapter, episode, year));
            }
        }
        else{
            cout << "Error opening file" << endl;}
        fileIn.close();

    };
};

#endif //CHARACTERS_OP
