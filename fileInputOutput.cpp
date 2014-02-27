#include <fstream>
#include <iostream>

int main()
{
	char fileName[80];
	char buffer[255]; // for user input
	std::cout << "File Name: ";
	std::cin >> fileName;

	std::ofstream fout(fileName); //open for writing
	fout << "This line written directly to the file...\n";
	std::cout << "Enter text for the file: ";
	std::cin.ignore(1,'\n'); // ignore the newline after the filename
	std::cin.getline(buffer, 255); //get user's input
	fout << buffer << "\n"; //write to the file
	fout.close(); //close the file

	std::ifstream fin(fileName); //reopen to read
	std::cout << "Here are the contents of the file: \n";
	char ch;
	while (fin.get(ch))
		std::cout << ch;
	std::cout << "\n***End of file contents.***\n";
	fin.close();

	return 0;
}