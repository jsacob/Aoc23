#include <algorithm>
#include <cctype>
#include <cwchar>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string WordToNumber(const string &word) {
  if (word == "one")
    return "1";
  else if (word == "two")
    return "2";
  else if (word == "three")
    return "3";
  else if (word == "four")
    return "4";
  else if (word == "five")
    return "5";
  else if (word == "six")
    return "6";
  else if (word == "seven")
    return "7";
  else if (word == "eight")
    return "8";
  else if (word == "nine")
    return "9";
  return "";
}

int main() {
  int sum = 0;
  vector<string> calibration;
  vector<string> wordCalibration;
  vector<string> numberCalibration;

  // Imports the file
  ifstream inputFile("../Inputs/day1.txt");
  if (!inputFile) {
    cerr << "Error opening file" << endl;
    return 1;
  } else {
    cout << "File opened successfully" << endl;
  }

  string line;

  // Iterates through each line inside the file
  while (getline(inputFile, line)) {
    cout << "Line -> " << line << endl;

    vector<char> numbers;
    vector<char> letters;
    string currentWord = "";

    for (char c : line) {
      if (isalpha(c)) {
        letters.push_back(c); // Collect letters
      }
      if (isdigit(c)) {
        numbers.push_back(c); // Collect numbers
      }
    }

    // Process letters to form words
    for (char letter : letters) {
      currentWord += letter;
      string numEquivalent = WordToNumber(currentWord);
      if (!numEquivalent.empty()) {
        wordCalibration.push_back(currentWord);
        currentWord = "";
      }
    }

    // Process numbers for calibration vector
    if (numbers.size() == 1 && numbers[0] == '2') {
      calibration.push_back("22");
    } else if (numbers.size() >= 1) {
      calibration.push_back(string(1, numbers.front()) +
                            string(1, numbers.back()));
    }
  }

  vector<string> words = {"one", "two",   "three", "four", "five",
                          "six", "seven", "eight", "nine"};

  // Prints out Calibration values as strings and sums them up
  cout << "Calibration values:" << endl;
  for (const string &value : calibration) {
    cout << value << endl;
    sum += stoi(value);
  }

  cout << "Sum of calibration values: " << sum << endl;

  // Output words found
  cout << "Words found in letter calibration:" << endl;
  for (const string &letvalue : wordCalibration) {
    cout << letvalue << endl;
  }

  return 0;
}

class Solution {
private:
  void Function(std::string &word) {
    // function implementation here
  }
};
