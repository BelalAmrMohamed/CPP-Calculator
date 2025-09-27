#include<iostream>
#include <cmath> // Ensure this is included for pow()
#include<string>
#include<numbers>
#include<cstdlib>
#include<regex>
using namespace std;
void DisplayHelp();
void DisplayCalculate();
string DisplayExamples();
string CalculateIrrationalSympols(string question);
string CalculateFactorials(string question);
double Factorial(double num);
string CalculatePowers(string question);
string CalculateParentheses(string question);
double Calculate(string question);
double PrintDivisionErrorAndReturnZero();
double Parse(const string& num);
bool IsOperation(char letter);
void DivisionError();

int main() {
    while (true)
{
    system("CLS");
        cout << " _____                                                 _____ \n" ;
        cout << "( ___ )-----------------------------------------------( ___ )\n" ;
        cout << " |   |                                                 |   | \n" ;
        cout << " |   |     _       _                               _   |   | \n" ;
        cout << " |   |    / \\   __| |_   ____ _ _ __   ___ ___  __| |  |   | \n" ;
        cout << " |   |   / _ \\ / _` \\ \\ / / _` | '_ \\ / __/ _ \\/ _` |  |   | \n" ;
        cout << " |   |  / ___ \\ (_| |\\ V / (_| | | | | (_|  __/ (_| |  |   | \n" ;
        cout << " |   | /_/   \\_\\__,_| \\_/ \\__,_|_| |_|\\___\\___|\\__,_|  |   | \n" ;
        cout << " |   |   ____      _            _       _              |   | \n" ;
        cout << " |   |  / ___|__ _| | ___ _   _| | __ _| |_ ___  _ __  |   | \n" ;
        cout << " |   | | |   / _` | |/ __| | | | |/ _` | __/ _ \\| '__| |   | \n" ;
        cout << " |   | | |__| (_| | | (__| |_| | | (_| | || (_) | |    |   | \n" ;
        cout << " |   |  \\____\\__,_|_|\\___|\\__,_|_|\\__,_|\\__\\___/|_|    |   | \n" ;
        cout << " |___|                                                 |___| \n" ;
        cout << "(_____)-----------------------------------------------(_____)\n\n";

        cout << "[1] Calculate\n" ;
        cout << "[2] Examples\n" ;
        cout << "[3] Help Menu\n" ;
        cout << "Choose from above: ";
        
    // Remove all whitespaces and letters except 'e'
    string question = "";
    cin >> question;    
    system("CLS");
    if (question == "1") 
    {
        DisplayCalculate();
        cout << "Input a question: " << endl;
        question = "";
        cin >> question;
        cin.get();
    }
    else if (question == "2")
    {
        question = DisplayExamples();
        if (question.empty()) { continue; }      
        system("CLS");
        DisplayCalculate();
        cout << question << endl;   
        cin.get();          
    }
    else if (question == "3") 
    {
        DisplayHelp();
        continue;
    }
    else
    {
        DisplayCalculate();
        cout << question << endl;
        cin.get();        
    }

    //question = std::regex_replace(question, std::regex("[\\sA-DF-Za-df-z]"), "");
    question = std::regex_replace(question, std::regex("\\s"), "");
    if (question.empty())
    {
        cout << "No input detected! Try again." << endl;
        cin.get();
        continue;
    }

    question = CalculateIrrationalSympols(question);
    double answer = Calculate(question);
    cout << "The result is: " << answer << endl;
    cin.get();    
}
}

void DisplayHelp(){
cout << " _____                                                _____ \r\n";
cout <<"( ___ )----------------------------------------------( ___ )\r\n";
cout <<" |   |                                                |   | \r\n";
cout <<" |   |  _   _      _         __  __                   |   | \r\n";
cout <<" |   | | | | | ___| |_ __   |  \\/  | ___ _ __  _   _  |   | \r\n" ;
cout <<" |   | | |_| |/ _ \\ | '_ \\  | |\\/| |/ _ \\ '_ \\| | | | |   | \r\n" ;
cout <<" |   | |  _  |  __/ | |_) | | |  | |  __/ | | | |_| | |   | \r\n" ;
cout <<" |   | |_| |_|\\___|_| .__/  |_|  |_|\\___|_| |_|\\__,_| |   | \r\n" ;
cout <<" |   |              |_|                               |   | \r\n";
cout <<" |___|                                                |___| \r\n";
cout <<"(_____)----------------------------------------------(_____)\n\n";

cout << "Available operations:" << endl;
cout << "  Basic arithmetic: +, -, *, /, ^" << endl;
cout << "  Factorial: !" << endl;
cout << "  Constants: π, e, Φ, φ" << endl;
cout << "  Parentheses for grouping: ()" << endl;
cout << "Press any key to exit the help menu... " << endl;
cin.get();
cin.get();
}



string DisplayExamples(){
cout <<" _____                                               _____ \r\n";
cout <<"( ___ )---------------------------------------------( ___ )\r\n" ;
cout <<" |   |                                               |   | \r\n" ;
cout <<" |   |  _____                           _            |   | \r\n";
cout <<" |   | | ____|_  ____ _ _ __ ___  _ __ | | ___  ___  |   | \r\n" ;
cout <<" |   | |  _| \\ \\/ / _` | '_ ` _ \\| '_ \\| |/ _ \\/ __| |   | \r\n" ;
cout <<" |   | | |___ >  < (_| | | | | | | |_) | |  __/\\__ \\ |   | \r\n" ;
cout <<" |   | |_____/_/\\_\\__,_|_| |_| |_| .__/|_|\\___||___/ |   | \r\n" ;
cout <<" |   |                           |_|                 |   | \r\n" ;
cout <<" |___|                                               |___| \r\n" ;
cout <<"(_____)---------------------------------------------(_____)\n\n";

int const length = 10;
string list[length];
list[0] = "2 + 3 * 4 ^ 2";
list[1] = "(2 + 3) * (4 - 1) ^ 2";    
list[2] = "3! * 4! + 5!";
list[3] = "(3 + 2)! / 4!";    
list[4] = "π^2 + e^2"; 
list[5] = "Φ * φ - π";     
list[6] = "((2^3)! / (4! * 2)) + 1"; 
list[7] = "((5 - 3)^(2 + 1))! * 2";        
list[8] = "2^(3!) + 4 * 3!";
list[9] = "π * (e - Φ) / φ";

for (int i = 0; i < length; i++)
{
    cout << "[" << i + 1 << "] " << list[i] << endl;
}    
cout << "\nWhich one do you want to test? [1 - "<< length <<"] : ";

int ex;
cin >> ex;

if (ex >= 1 && ex <= 10){
return list[ex - 1];
}
else return "";
}

void DisplayCalculate(){
cout << " _____                                           _____ \r\n" ;
cout << "( ___ )-----------------------------------------( ___ )\r\n" ;
cout << " |   |                                           |   | \r\n" ;
cout << " |   |   ____      _            _       _        |   | \r\n" ;
cout << " |   |  / ___|__ _| | ___ _   _| | __ _| |_ ___  |   | \r\n" ;
cout << " |   | | |   / _` | |/ __| | | | |/ _` | __/ _ \\ |   | \r\n" ;
cout << " |   | | |__| (_| | | (__| |_| | | (_| | ||  __/ |   | \r\n" ;
cout << " |   |  \\____\\__,_|_|\\___|\\__,_|_|\\__,_|\\__\\___| |   | \r\n" ;
cout << " |___|                                           |___| \r\n" ;
cout << "(_____)-----------------------------------------(_____)\n\n";
}

string CalculateIrrationalSympols(string question){
//Replace any 'π' or 'e' or 'Φ, φ' (Golden ratio) in the "question" with their float value
for (int i = 0; i < question.length(); i++)
{
    if (i > 0 && (question[i] == 'e' || question[i] == L'\x3c0' || question[i] == L'\x3a6' || question[i] == L'\x3c6') &&
       (isdigit(question[i - 1]) || question[i - 1] == L'\x3c0' || question[i - 1] == 'e'))
    {
        question.insert(i, "*");
        i++;
    }

    if (question[i] == L'\x3c0') // π
    {
        question.erase(i, 1);        
        string pi = "3.141592653589793";
        question.insert(i, pi);
        i += pi.length() - 1;
    }
    else if (question[i] == 'e')
    {
        question.erase(i, 1);        
        string e = "2.718281828459045";
        question.insert(i, e);
        i += e.length() - 1;
    }
    else if (question[i] == L'\x3a6' || question[i] == L'\x3c6')  // Φ or φ
    {
        question.erase(i, 1);        
        string phi = "1.618033988749895";
        question.insert(i, phi);
        i += phi.length() - 1;        
    }
}
return question;
}

string CalculateFactorials(string question){
for (int i = 0; i < question.length(); i++)
{
    if (question[i] == '!')
    {
        int startIndex = i - 1;
        while (startIndex >= 0 && (isdigit(question[startIndex]) || question[startIndex] == '.'))
            startIndex--;
        startIndex++;

        string FactorialNum = question.substr(startIndex, i - startIndex);            
        string Factorialresult = std::to_string(Factorial(std::stod(FactorialNum)));
        question = question.substr(0, startIndex) + Factorialresult + question.substr(i + 1);
        i = startIndex + Factorialresult.length() - 1;
    }
}
return question;
}


double Factorial(double num)
{    
    if (num == 0 || num == 1) return 1;
    return num * Factorial(num - 1);
}


string CalculatePowers(string question){
for (int i = 0; i < question.length(); i++)
{
    if (question[i] == '^')
    {
        string a = "";
        string reverse = "";
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (isdigit(question[j]) || question[j] == '.' ||
               (question[j] == '-' && (j == 0 || IsOperation(question[j - 1])))) reverse += question[j];
            else break;
        }
        for (int z = reverse.length() - 1; z >= 0; z--) a += reverse[z];
        string b = "";
        int k;
        for (k = i + 1; k < question.length(); k++)
        {
            if (isdigit(question[k]) || question[k] == '.' || 
               (question[k] == '-' && (k == 0 || IsOperation(question[k - 1])))) b += question[k];
            else break;
        }
        string result = std::to_string(pow(std::stod(a), std::stod(b)));
        string before = question.substr(0, j + 1);
        string after = question.substr(k);
        question = before + result + after;
        i = j + result.length();
    }
    }
return question;
}


string CalculateParentheses(string question){
//Calculate the numbers between the Parentheses
for (int i = 0; i < question.length(); i++)
{

    if (question[i] == '(')
    {
        int parenCount = 1;
        string numberBetweenParentheses = "";
        int j;
        for (j = i + 1; j < question.length() && parenCount > 0; j++)
        {
            if (question[j] == '(') parenCount++;
            else if (question[j] == ')')
            {
                parenCount--;
                if (parenCount == 0) break;
            }

            if (parenCount > 0)
                numberBetweenParentheses += question[j];
        }
        numberBetweenParentheses = std::to_string(Calculate(numberBetweenParentheses));
        string before = i > 0 ? question.substr(0, i) : "";
        string after = j < question.length() ? question.substr(j + 1) : "";
        question = before + numberBetweenParentheses + after;
        i = before.length() + numberBetweenParentheses.length() - 1;
        cout << "The question after calculating the number Between Parentheses is: "<< question << endl;
    }
}
return question;
}


double Calculate(string question){
question = CalculateParentheses(question);
question = CalculateFactorials(question);
question = CalculatePowers(question);

char operation_1 = '\0';
bool operation_1_exists = false;

char operation_2 = '\0';
bool operation_2_exists = false;

string num1 = "";

string num2 = "";
bool num2_exists = false;

string num3 = "";
bool num3_exists = false;

for (int i = 0; i < question.length(); i++)
{
    //Storing operation 1
    if (IsOperation(question[i]) && (i > 0 ? !IsOperation(question[i - 1]) : true) && !operation_1_exists)
    {
        operation_1 = question[i];
        operation_1_exists = true;
    }
    //Storing operation 2
    else if (IsOperation(question[i]) && (i > 0 ? !IsOperation(question[i - 1]) : true) &&
            operation_1_exists && !operation_2_exists)
    {
        operation_2 = question[i];
        operation_2_exists = true;
        num2_exists = true;
    }
    else if (isdigit(question[i]) || question[i] == '.' || question[i] == '-')
    {
        if (!operation_1_exists)
        {
            num1 += question[i];
        }
        else if (operation_1_exists && !num2_exists)
        {
            num2 += question[i];
        }
        else if (operation_1_exists && operation_2_exists && !num3_exists)
        {
            num3 += question[i];
        }
    }
    //calculating if to empty a place for the 3rd operation 
    else if (IsOperation(question[i]) && operation_2_exists)
    {
        num3_exists = true;
        double int_num1 = Parse(num1);
        double int_num2 = Parse(num2);
        double int_num3 = Parse(num3);
        if ((operation_1 == '+' || operation_1 == '-') &&
            (operation_2 == '*' || operation_2 == '/'))
        {
            switch (operation_2)
            {
                case '*':
                    int_num2 *= int_num3;
                    operation_2 = question[i];
                    num2 = std::to_string(int_num2);
                    num3 = "";
                    num3_exists = false;
                    break;

                case '/':
                    // Check for division by zero
                    if (int_num3 != 0)
                    {
                        int_num2 /= int_num3;
                        operation_2 = question[i];
                        num2 = std::to_string(int_num2);
                        num3 = "";
                        num3_exists = false;
                    }
                    else
                    {
                        DivisionError();
                    }
                    break;
            }
        }
        else
        {
            switch (operation_1)
            {
                case '+':
                    int_num1 += int_num2;
                    int_num2 = int_num3;
                    num1 = std::to_string(int_num1);
                    num2 = std::to_string(int_num2);
                    operation_1 = operation_2;
                    operation_2 = question[i];
                    num3 = "";
                    num3_exists = false;
                    break;

                case '-':
                    int_num1 -= int_num2;
                    int_num2 = int_num3;
                    num1 = std::to_string(int_num1);
                    num2 = std::to_string(int_num2);
                    operation_1 = operation_2;
                    operation_2 = question[i];
                    num3 = "";
                    num3_exists = false;
                    break;

                case '*':
                    int_num1 *= int_num2;
                    int_num2 = int_num3;
                    num1 = std::to_string(int_num1);
                    num2 = std::to_string(int_num2);
                    operation_1 = operation_2;
                    operation_2 = question[i];
                    num3 = "";
                    num3_exists = false;
                    break;

                case '/':
                    // Check for division by zero
                    if (int_num2 != 0)
                    {
                        int_num1 /= int_num2;
                        int_num2 = int_num3;
                        num1 = std::to_string(int_num1);
                        num2 = std::to_string(int_num2);
                        operation_1 = operation_2;
                        operation_2 = question[i];
                        num3 = "";
                        num3_exists = false;
                    }
                    else
                    {
                        DivisionError();
                    }
                    break;
            }
        }
    }
}
//Parsing the values after checking if they aren't (double)s
double result;
double n1 = Parse(num1);
double n2 = Parse(num2);
double n3 = Parse(num3);
//If the user entered one number EX: (15)
if (!operation_1_exists && !question.empty())
{
    result = std::stod(question);
}

//If the user entered a one-operation question EX: (11*2)
else if (!operation_2_exists)
{
switch (operation_1){
    case '+':
        result = n1 + n2;
        break;
    case '-':
        result = n1 - n2;
        break;
    case '*':
        result = n1 * n2;
        break;
    case '/':
        if (n2 != 0)
            result = n1 / n2;
        else
            PrintDivisionErrorAndReturnZero();
        break;    
        default: PrintDivisionErrorAndReturnZero();
}
}
//If the remaining 2 operations have the first one
//Addition : (+ , -) and the second one Multiplication : (+ , -)
else if ((operation_1 == '+' || operation_1 == '-') &&
    (operation_2 == '*' || operation_2 == '/'))
{
    switch (operation_2)
    {
        case '*':
        n2 = n2 * n3;
        break;
        case '/':
        if(n3 != 0)
        {
            n2 = n2 / n3;
        }
        else PrintDivisionErrorAndReturnZero();
        default: PrintDivisionErrorAndReturnZero();
    }
switch(operation_1){
    case '+':
        result = n1 + n2;
        break;
    case '-':
        result = n1 - n2;
        break;
    default: PrintDivisionErrorAndReturnZero();
}
}
//If the operation are structered normally to be excuted secwentially
else
{
    switch (operation_1)
    {
        case '+':
            n1 += n2;
            break;
        case '-':
            n1 -= n2;
            break;
        case '*':
            n1 *= n2;
            break;
        case '/':
            if (n2 != 0)
                n1 /= n2;
            else
                PrintDivisionErrorAndReturnZero();
            break;
            default:
            PrintDivisionErrorAndReturnZero();
    }
    switch (operation_2)
    {
        case '+':
            result = n1 + n3;
            break;
        case '-':
            result = n1 - n3;
            break;
        case '*':
            result = n1 * n3;
            break;
        case '/':
            if (n3 != 0)
                result = n1 / n3;
            else
                PrintDivisionErrorAndReturnZero();
            break;
        default:
            PrintDivisionErrorAndReturnZero();
    }
}
return result;
}


double PrintDivisionErrorAndReturnZero(){
cout << "Error: Division by zero" << endl;
cin.get();
exit(0);
return 0;
}



double Parse(const string& num)
{
    try
    {
        return stod(num); // try to convert string to double
    }
    catch (const invalid_argument&) // if string is not a number
    {
        return 0;
    }
    catch (const out_of_range&) // if number is too big/small
    {
        return 0;
    }
}



bool IsOperation(char letter)
{
switch(letter)
{

    case '+':
    case '-':
    case '*':
    case '/':
        return true;
        default:
        return false;
}
}


void DivisionError()
{
    cout << "Error! Can't divide by zero." << endl;
    cin.get();
    return;
}