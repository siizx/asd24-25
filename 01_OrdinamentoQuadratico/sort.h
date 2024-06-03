#include <vector> 
#include <stdlib.h>    
#include <iostream>
#include <fstream> 
#include <stdexcept>

using namespace std;

void selectionSort(vector<int>&);
void insertionSort(vector<int>&);
void bubbleSort(vector<int>&);


vector<int> leggiVettoreDaFile(string);
void stampaVettoreEDurataSuStream(const vector<int>&, string, double, ofstream&);
