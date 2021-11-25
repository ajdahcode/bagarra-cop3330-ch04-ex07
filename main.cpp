/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 alden bagarra
 */

#include <iostream>
#include <vector>
using namespace std;

// Make a vector of integer strings
void numberAsString(vector<string>& numbers){
	numbers.push_back("zero");
	numbers.push_back("one");
	numbers.push_back("two");
	numbers.push_back("three");
	numbers.push_back("four");
	numbers.push_back("five");
	numbers.push_back("six");
	numbers.push_back("seven");
	numbers.push_back("eight");
	numbers.push_back("nine");
}

// Function to convert the string into a number
int stringToNumber(vector<string> vctrOfIntStr, string str){
  int i = 0;
  // Increment if the string at i is less then vector 
  // size and vector at i is not an empty string
  while(i < vctrOfIntStr.size() && vctrOfIntStr[i] != str) {
   ++i;
  }

  // If the string is less than 10 then return the i at that string
  if(i < 10){
    return i;
  } 
  // If the string is not less than 10 the string will return 0
  else {
    cout << "Invalid Number: will turn into 0\n";
    return 0;
  }
}

int main(){
  vector<string> numbers;
  numberAsString(numbers);
  char opr;
  int val1, val2, result;
  string strVal1, strVal2;

  // Prompt the user for the single digit number and operator
  cout << "Enter two single digit numbers as integers or spelled out and an operator (all spaced out): ";

  // If the inputs are digits
  while(cin >> val1 >> val2 >> opr ){
    string operation;
    if(val1 < 10 && val2 < 10){
      switch(opr){
        case '+':
          operation = "The sum of ";
          result = val1+val2; 
          break;
        case '-':
          operation = "The difference between ";
          result = val1-val2; 
          break;
        case '*':
          operation = "The product of ";
          result = val1*val2; 
          break;
        case '/':
          operation = "The ratio of ";
          if (val2 == 0){
            cout << "Undefined";
            break;
          } 
          result = val1/val2; 
          break;
        default:
          cout << opr << "Invalid Operator";
          break;
      }
      cout << operation << val1 << " and " << val2 << " is " << result << '\n';
    }
    else{
      cout << "Only single digit numbers.\n";
    }
    
  }
  // Must clear if there is an invalid number
  cin.clear();

  // If the input is spelled out numbers
  while(cin >> strVal1 >> strVal2 >> opr) {
    string operation;
    switch(opr) {
      case '+':
        operation = "The sum of ";
        result = (stringToNumber(numbers, strVal1))+(stringToNumber(numbers, strVal2)); 
        break;
      case '-':
        operation = "The difference between ";
        result = (stringToNumber(numbers, strVal1))-(stringToNumber(numbers, strVal2));  
        break;
      case '*':
        operation = "The product of ";
        result = (stringToNumber(numbers, strVal1))*(stringToNumber(numbers, strVal2)); 
        break;
      case '/':
        operation = "The ratio of ";
        if (stringToNumber(numbers, strVal2) == 0){
          cout << "Undefined";
          break;
        } 
        result = (stringToNumber(numbers, strVal1))/(stringToNumber(numbers, strVal2));  
        break;
      default:
        cout << opr << "Invalid Operator";
        break;
    }
    cout << operation << strVal1 << " and " << strVal2 << " is " << result << '\n';
  }
}