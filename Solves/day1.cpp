#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <vector>
using namespace std;

int main() {

  // Creates map for numbers and characters
  map<int, vector<char>> calibration;

  // Fetchest the file including the Data
  ifstream inputFile("../Inputs/day1.txt");
  if (!inputFile) {
    cerr << "Error opening file.." << endl;
  } else {
    cout << "this is working" << endl;
  }

  // Iterates throug the Data file by each Character
  for (char ch; inputFile.get(ch);) {
    cout << ch;
  }

  return 1;
}
