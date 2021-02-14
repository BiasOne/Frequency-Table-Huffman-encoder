#pragma once

#include "frequency_table.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <fstream>


using namespace std;

struct huffmanNode
{
	char data;
	int frequency;
	huffmanNode* left;
	huffmanNode* right;
	huffmanNode* parent;
	bool leftChild;	
	

	huffmanNode(char data, int frequency, bool leftChild)
	{
		left = nullptr;
		right = nullptr;
		parent = nullptr;
		this->data = data;
		this->frequency = frequency;	
		this->leftChild = leftChild;
		
	}

};

struct node_cmp
{
	bool operator()(const huffmanNode* a, const huffmanNode* b) const
	{
		return (a->frequency > b->frequency);
	}
};

class huffman_encoder {
    public:		
		priority_queue <huffmanNode*, vector<huffmanNode*>,node_cmp > priorityQ;
		unordered_map<char, int> characterMap;			
		unordered_map<char, string> encodedMap;

		huffmanNode* root = nullptr;
	
        huffman_encoder(const frequency_table &table);			
        ~huffman_encoder();

        string get_character_code(char c) const;
		string encode(const string &file_name) const;
		void encodeHelper(huffmanNode* root, string str,unordered_map<char, string> &encodedMap) const;
		string decode(const string &string_to_decode) const;
		string decodeHelper(huffmanNode* root, string encodedString) const;
		
};
