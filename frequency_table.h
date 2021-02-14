#pragma once
#include <iostream>
#include <unordered_map>
#include <fstream>

using namespace std;

class frequency_table {
    // Something to store the frequency of each character
	unordered_map <char, int> characterMap;


    public:
		frequency_table(const std::string& file_name);
        ~frequency_table();
        
        int get_frequency(char c) const;		
		unordered_map<char, int> get_map() const;

};