#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using std::ifstream;
using std::string;
using std::ostream;
using std::vector;

class TaskData
{
    string taskString;
    string answerString;
    string equationString;
    double answerValue;
    int variablesNumber;
    std::vector<int> variablesVector;
    int** variablesRange;

    string& generateTaskStringAndVariables(string &);
    void getVariablesNumberAndRange(string &);
    double solveEquation(string &);
    void replaceAllStringOccurence(std::string& str, const std::string& from, const std::string& to);
public:
    TaskData();
    TaskData(const char* path);
    string getTaskField(){return taskString;}
    string getAnswerString(){return answerString;}
    double getAnswer(){return answerValue;}
    friend ostream& operator<<(ostream&, TaskData&);
};

