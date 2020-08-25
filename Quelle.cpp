#include <iostream>
#include <fstream>
#include <vector>


bool Quersumme(int _i);
void DEBUG_PRINT(std::ofstream*);
void DEBUG_PRINT(std::ofstream*, int*);


int main() {
	std::ofstream myFile;
	std::vector<int> AnnoTitelEins;
	std::vector<int> AnnoTitelZwei;

	bool isQuersum = false;
	int iCounter = 0;

	myFile.open("Anno_Titel.txt");

	for (int i = 0; i < 5000; i++) {
		if (Quersumme(i) == true) {																		//	Hier werden die _RICHTIGEN_ Titel erzeugt!
			std::cout << i << "\n";
			myFile << iCounter << "] " << i << "\n";
			iCounter += 1;

			AnnoTitelEins.push_back(i);
		}
	}

	DEBUG_PRINT(&myFile, &iCounter);

	for (int i = 0; i < 5000; i++) {												
		if (i % 9 == 0) {																				//	Hier werden die _FALSCHEN_ Titel erzeugt!
			std::cout << i << "\n";
			myFile << iCounter << "] " << i << "\n";
			iCounter += 1;

			AnnoTitelZwei.push_back(i);				
		}
	}

	DEBUG_PRINT(&myFile);

	for (int i = 0; i < AnnoTitelEins.size(); i++) {													//	Das sind die _RICHTIGEN_ Anno Titel (AnnoTitelEins)
		for (int j = 0; j < AnnoTitelZwei.size(); j++) {												//	Das sind die _FALSCHEN_ Anno Titel (AnnoTitelZwei)
			if (AnnoTitelEins[i] == AnnoTitelZwei[j]) {													//	_VERGLEICH_ der Zahlen ob der TItel übereinstimmt
				myFile << "Index: " << i << " equals index: " << j << "\n";								//	_WENN_ vergleich erfolgreich, printe in .txt format
			}
		}
	}

	myFile.close();

	return 0;
}


bool Quersumme(int _i) {
	int sum = 0;

	while (_i > 0) {
		sum += _i % 10;
		_i /= 10;
	}

	//std::cout << sum;

	if (sum == 9) {
		return true;
	}
	else {
		return false;
	}

}


void DEBUG_PRINT(std::ofstream* _myFile) {
	*_myFile << "===================================================\n";
}

void DEBUG_PRINT(std::ofstream* _myFile, int* _iCounter) {
	*_myFile << "===================================================\n";
	*_iCounter = 0;
}