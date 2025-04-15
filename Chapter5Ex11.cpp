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
void answerCheck(int sum, int userSum);

int main()
{
    //Generates a value based on the current time
    double baseSeed = time(0);

    //Takes that value and increases it by the power of 2
    double seed = pow(baseSeed, 2);

    //Declares that value as the seed for the randomly generated number, so the numbers vary further from one another
    srand(seed);

    int numb1, numb2;
    generator(numb1, numb2);

    cout << right << setw(3) << numb1 << endl;
    cout << right << setw(3) << numb2 << endl;

    int sum = numb1 + numb2;
    int userSum;

    cout << "Enter the sum of the 2 numbers above;" << endl;
  
    //Begins a loop that will continue forever until reaching a break
    while (true) {
        cin >> userSum;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            //This outputs several messages for every non-interger character inputted, which is not intentional, however the fix for it is beyond my scope of understanding, so this will just be how it is.
            cout << "Invalid Input. Please enter a valid numbr." << endl;
        }
        else {
            break;
        }
    }

    answerCheck(sum, userSum);
}

//Generates and provides the number variables a value
void generator(int &numb1,int &numb2) {
    numb1 = rand() % 999;
    numb2 = rand() % 999;
}

//Checks to see if the answer is correct
void answerCheck(int sum, int userSum) {
    if (sum == userSum)
        cout << "Correct, you win nothing!";
    else
        cout << endl << "The answer provided is incorrect, the sum of the numbers above was " << sum << endl;
}