#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std; // minchia, mi ero dimenticato tutte ste cazzatine

void mergesort(vector<int> &v){
	if(v.size() > 0) ms(v, 0, v.size()-1);
}

void ms(vector<int> &v, int inizio, int fine){
	

}


int main(){
	
	std::vector<int> v = { 22, 536, 75 ,1 ,95, 83, 99, 20, 17, 53 };

	cout << "Vector disordinato: ";
	for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl;

	
	mergesort(v);

	
	cout << "Vector ordinato: ";
	for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl;

}
