#include <iostream>
#include <fstream>
#include <cstring>
#include "types/BinarySearchTree.h"


// Initialize a binary search tree from an input stream, used for string and file
int initializeFromStream(BinarySearchTree*& bst, std::istream& is);

// Initialize a binary search tree from a file, handles reading from file
int initializeFromFile(BinarySearchTree*& bst, char*& inputPtr);

// Initialize a binary search tree as a list of random numbers
int initializeRandom(BinarySearchTree*& bst, char*& inputPtr);

// Set setInt from char*, checks if input is valid
int intFromCstring(int& setInt, char*& cstring);

int main() {

  char* in = new char[64];

  int errorCode = 0;

  std::cout << "How would you like to initialize the search tree?" << std::endl;
  std::cout << "[f] From file" << std::endl;
  std::cout << "[s] From string" << std::endl;
  std::cout << "[r] Randomly"<< std::endl;
  std::cout << "[e] Empty" << std::endl;

  std::cout << " > ";
  std::cin.getline(in, 64);

  BinarySearchTree* bst;

  if (strcmp(in, "f") == 0) {
    // initialize from file
  } else if (strcmp(in, "s") == 0) {

    std::cout << " > ";

    errorCode = initializeFromStream(bst, std::cin);
    
    if (errorCode == 1) {
      std::cout << "ERROR: Empty input." << std::endl;
      delete[] in;
      return 1;
    }

    if (errorCode == 2) {
      std::cout << "ERROR: Failed parsing token." << std::endl;
      delete[] in;
      return 1;
    }

  } else if (strcmp(in, "r") == 0) {
    // initialize from random list
  } else if (strcmp(in, "e") == 0) {
    bst = new BinarySearchTree(nullptr, 0);
  } else {
    std::cout << "ERROR: Unrecognized initializer." << std::endl;
    delete[] in;
    return 1;
  }


  std::cout << *bst << std::endl;

  delete[] in;
  delete bst;
}

// Error code 1: error converting to int
int intFromCstring(int& setInt, char*& cstring) {

  char* end;
  int temp;

  temp = strtod(cstring, &end);

  if (*end != '\0') {
    return 1;
  }

  setInt = temp;

  return 0;

}

// Error code 1: input was empty
// Error code 2: error converting input to int 
int initializeFromStream(BinarySearchTree*& bst, std::istream& is) {

  int* dataArray = new int[256]{};
  int arrayIndex = 0;
  int dataTemp;
  char* in = new char[1024];
  int i = 1;

  is.getline(in, 1024);

  char* ptr = &in[0];

  // in case input was empty
  if (*ptr == '\0') { return 1; }

  while (in[i] != '\0') {

    if (in[i -1] == '\0') {
      ptr = &in[i];
    }

    if (in[i] == ' ') {
      in[i] = '\0';
      if (intFromCstring(dataTemp, ptr)) { return 2; }
      dataArray[arrayIndex++] = dataTemp;
    }

    i++;

  }

  if (intFromCstring(dataTemp, ptr)) { return 2; }
  dataArray[arrayIndex++] = dataTemp;

  bst = new BinarySearchTree(dataArray, arrayIndex);

  delete[] in;

  return 0;

}
