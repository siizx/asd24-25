#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <chrono>

using namespace std;

int main(){

	int seed = time(NULL);
	int seed2 = static_cast<int>(chrono::system_clock::now().time_since_epoch().count());
	unsigned seed3 = chrono::system_clock::now().time_since_epoch().count();
	srand(seed3);

	int r = rand()%11; // modulo di numero desiderato+1

	// Generate a random number between 5 and 10 (inclusive) - range 7-40 inclusi:
	int t = rand() % 34 + 7;  // rand() % (max - min + 1) + min

	cout << "Il numero casuale generato e': " << t << endl;;




	return 0;
}
