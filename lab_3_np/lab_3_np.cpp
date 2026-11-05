#include <iostream>
#include <cstdio>
#include <string>

extern "C" void SUBSTR(const char* SOURCE, int POS, int LEN, char* DEST); // объявление внешнего идентификатора

int main() {
	std::string SOURCE;
	int POS;
	int LEN;
	char DEST[200] = {0};

	std::cout << "Enter string" << std::endl;
	std::getline(std::cin, SOURCE);

	std::cout << "Enter position in string (starting from 0)" << std::endl;
	std::cin >> POS;

	std::cout << "Enter length of substring" << std::endl;
	std::cin >> LEN;

	if (POS < 0 || LEN < 0 || POS + LEN > static_cast<int>(SOURCE.length())) {
		std::cout << "Incorrect data" << std::endl;
		return 1;
	}

	SUBSTR(SOURCE.c_str(), POS, LEN, DEST);

	std::cout << "Result:" << std::endl;
	std::cout << DEST << std::endl;

	return 0;
}