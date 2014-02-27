/*
Default behavior of ofstream can be modified.
Default: create file on opening if it doesn't already exist
	and delete all its contents if it does.
Modify behavior by adding second arg after filename:
ios::app – append to end of existing file
ios::ate – place at end of file, but you could write to anywhere in the file
ios:trun (default) – truncate file
ios::nocreat – if file does not exist, open fails
ios::noreplac – if file does exist, open fails
*/

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