/*
    Program File Name: Chapter5Ex11.cpp
    Programmer: Gabriel Inocentes
    Date: April 14, 2025
    Requirements:
    Create a program that generates 2 random numbers to be added, allowing the user to work the problem out and press a key to reveal the answer. On the branch, the program should recieve an answer and determine if it is incorrect or correct.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <limits>
using namespace std;

void generator(int& numb1, int& numb2);
void generateSeed(double &baseSeed);

int main()
{
    double baseSeed;
    generateSeed(baseSeed);
    
    int numb1, numb2;
    generator(numb1, numb2);

    cout << "Add the following 2 numbers together, and press the enter key to reveal the answer once you have solved the problem;" << endl;
    cout << right << setw(3) << numb1 << endl;
    cout << right << setw(3) << numb2 << endl;
    system("pause");
    cout << "The answer is " << numb1 + numb2;
}

void generateSeed(double &baseSeed) {
    //Generates a value based on the current time
    baseSeed = time(0);
    
    //Takes that value and increases it by the power of 2
    double seed = pow(baseSeed, 2);

    //Declares that value as the seed for the randomly generated number, so the numbers vary further from one another
    srand(seed);
}

void generator(int &numb1,int &numb2) {
    numb1 = rand() % 999;
    numb2 = rand() % 999;
}