#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Question
{
    string Questiontext;
    int answer[3];
    int RightAnswer;
};

void printQuestions(const Question& question)
{
    cout << question.Questiontext << endl;
    for(int i = 0; i <= 2; i++)
         cout << "\t" << i+1 << ". " << question.answer[i] << endl;

    cout << "Choose 1-3: ";
}

int main()
{
    int userInput;
    int score = 0;

    Question questions[3];

    questions[0] = {"1. What is 2+2?" , {5,4,8}, 2};
    questions[1] = {"2. What is 3+2?" , {5,4,8}, 1};
    questions[2] = {"3. What is 4+2" , {5,4,6}, 3};

    for(int i = 0; i <=2 ; i++)
    {
        printQuestions(questions[i]);
        cin >> userInput;
    if(userInput == questions[i].RightAnswer)
        {
            cout << "Correct!" << endl;
            score++;
        }
    else
        cout << "Nope!" << endl;
    }

    fstream myFile; // variable
    myFile.open("Quiz_questions.txt", ios::out); // write to file
    if(myFile.is_open())
    {
        myFile << "4. Which BTS member is the oldest?\n";
        myFile << "\t 1. Jungkook\n";
        myFile << "\t 2. Seokjin\n";
        myFile << "\t 3. Yoongi\n";
        myFile << "5. Which BTS member is the youngest?\n";
        myFile << "\t 1. Jimin\n";
        myFile << "\t 2. Namjoon\n";
        myFile << "\t 3. Jungkook\n";
        myFile.close();
    }

    myFile.open("Quiz_questions.txt", ios::in); // read from file
    if(myFile.is_open())
    {
        string line;
        int linesToRead = 4;
        int lineCount = 0;

        while(lineCount < linesToRead && getline(myFile, line))
            {
                cout << line << endl;
                lineCount ++;
            }
        cout << "Choose 1-3: ";
        cin >> userInput;
        if(userInput == 2)
            {
                cout << "Correct!" << endl;
                score++;
            }
        else
            cout << "Nope!" << endl;

        while(getline(myFile, line))
            cout << line << endl;
        cout << "Choose 1-3: ";
        cin >> userInput;
        if(userInput == 3)
            {
                cout << "Correct!" << endl;
                score++;
            }
        else
            cout << "Nope!" << endl;

        myFile.close();
    }

    cout << "Your score is: " << score << endl;

    return 0;
}