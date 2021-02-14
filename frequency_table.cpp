#include "frequency_table.h"

using namespace std;

frequency_table::frequency_table(const string &file_name) 
{
	fstream txtFile(file_name);
	char fileCharacters;

	//checks whether the state of the stream is good otherwise throws an error
	if (txtFile.good())
	{
		//if character stream is good it reads in all of the characters without skipping white spaces
		while (txtFile >> noskipws >> fileCharacters)
		{
			//increment every characters frequency on the map
			characterMap[fileCharacters]++;
		}
	}
	else
	{
		//throws runtime if the state of stream is bad
		throw runtime_error("Runtime error has occurred!");
	}


}

frequency_table::~frequency_table() 
{
	//clears the character map
	characterMap.clear();
}

int frequency_table::get_frequency(char c) const 
{
	//trys to return the character at c
	try {

		return characterMap.at(c);
	}
	//if the try statement fails it will catch it and return 0
	catch (...)
	{
		return 0;
	}	
	
}


unordered_map<char, int> frequency_table::get_map() const
{
	return characterMap;
}


	
	
