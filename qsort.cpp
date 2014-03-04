// qsort sorts a table or array. It takes 4 params.
// 1: pointer to start of table to be sorted
// 2: number of elements in the table
// 3: size of each element
// 4: pointer to a comparison function

#include <iostream>

// form of sort_function required by qsort
int sortFunction( const void *intOne, const void *intTwo);
const int TableSize = 10;  // array size
int main(void)
{
  int i,table[TableSize];
  // fill the table with values
  for (i = 0; i<TableSize; i++)
	{
		std::cout << "Enter a number: ";
		std::cin >> table[i];
	}
  std::cout << "\n";
  // sort the values
  qsort((void *)table, TableSize, sizeof(table[0]), sortFunction);
  // print the results
  for (i = 0; i < TableSize; i++)
     std::cout << "Table [" << i << "]: " << table[i] << std::endl;
  std::cout << "Done." << std::endl;
	return 0;
}

int sortFunction( const void *a, const void *b)
{
  int intOne = *((int*)a);
  int intTwo = *((int*)b);
  if (intOne < intTwo)
  	return -1;
  if (intOne == intTwo)
		return 0;
	return 1;
}