#include <cstdlib>
#include <ctime>
#include "ParsingIncludes/parsing.hpp"
#include "muparser-2.2.5/include/muParser.h"

#define LINESNUMBER 4

using std::ifstream;
using std::string;
using std::getline;
using std::stringstream;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;
using std::strtol;


TaskData::TaskData()
{
    taskString = answerString = "";
    answerValue = variablesNumber = 0;
    variablesRange = NULL;
}

TaskData::TaskData(const char* path)
{
  std::srand(std::time(NULL));//start random numbers machine
  string line;
  ifstream file(path);

  for(int i=0; i<LINESNUMBER; i++)
  {
      getline(file, line);
      cout<<"Line: "<<line<<endl;
      switch (i)
      {
      case 0:
          getVariablesNumberAndRange(line); break;
      case 1:
          equationString = line; break;
      case 2:
          taskString = generateTaskStringAndVariables(line); break;
      case 3:
          answerString = line; break;
      }
  }
  answerValue = solveEquation(equationString);
}

void TaskData::getVariablesNumberAndRange(string& line)
{
    char* charPointer;
    variablesNumber = strtol(line.c_str(), &charPointer, 10);
    variablesRange = new int *[variablesNumber];
    for(int j=0; j<variablesNumber; j++)
    {
      variablesRange[j] = new int[2];
      variablesRange[j][0] = strtol(&charPointer[2], &charPointer, 10);
      variablesRange[j][1] = strtol(&charPointer[1], &charPointer, 10);
    }
}

string& TaskData::generateTaskStringAndVariables(string& line)
{
   for(int i=0; i<variablesNumber; i++)
   {
       int randomVal = variablesRange[i][0] + (variablesRange[i][1]-variablesRange[i][0]) * std::rand()/RAND_MAX;
       variablesVector.push_back(randomVal);
       char temp[3];
       string s = "var";
       replaceAllStringOccurence(line, s + itoa(i, temp, 10), itoa(variablesVector[i], temp, 10));
   }
    return line;
}

void TaskData::replaceAllStringOccurence(std::string& str, const std::string& from, const std::string& to)
{
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}

ostream& operator<<(ostream& out, TaskData& p_TaskData)
{
    out<<endl<<"taskString: "    <<p_TaskData.taskString<<endl
             <<"answerString: "  <<p_TaskData.answerString<<endl
             <<"equationString: "<<p_TaskData.equationString<<endl
             <<"answerValue: "   <<p_TaskData.answerValue<<endl
             <<"variablesRange: "<<p_TaskData.variablesNumber<<endl;
    for(int i=0; i < p_TaskData.variablesNumber; i++)
    {
        out<<"\tvariable["<<i<<"]: <"<<p_TaskData.variablesRange[i][0]<<';'
                               <<p_TaskData.variablesRange[i][1]<<'>'<<endl;
    }
    return out;
}

double TaskData::solveEquation(string& expression_string)
{
    using namespace mu;
    Parser p;
    double result;
    double* varTable = new double[variablesNumber];
    try
    {
    Parser p;
    for(int i=0; i<variablesNumber; i++)
    {
        varTable[i] = variablesVector.at(i);
        p.DefineVar("var" + std::to_string(i), &(varTable[i]));
    }

    p.SetExpr(expression_string);
    result = double((int)(100*(p.Eval()+0.005)))/100;
    cout<<"result"<<result<<endl;
    }
    catch (Parser::exception_type &e)
    {
    std::cout << e.GetMsg() << std::endl;
    }

    return result;
}
