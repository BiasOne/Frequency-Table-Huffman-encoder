#include "huffman_encoder.h"

using namespace std;

huffman_encoder::huffman_encoder(const frequency_table& table) {
	characterMap = table.get_map();	

	auto it = characterMap.begin();
	while (it != characterMap.end())
	{
		huffmanNode* node = new huffmanNode(it->first, it->second, false);
		priorityQ.push(node);
		it++;
	}

	huffmanNode* left;
	huffmanNode* right;

	while (priorityQ.size() != 1)
	{
		left = priorityQ.top();
		priorityQ.pop();
		right = priorityQ.top();
		priorityQ.pop();
		huffmanNode* node = new huffmanNode('$', left->frequency + right->frequency, false);
		node->left = left;
		node->right = right;
		priorityQ.push(node);

	}


	root = priorityQ.top();
	encodeHelper(root, "", encodedMap);
}

huffman_encoder::~huffman_encoder() {
	characterMap.clear();
	encodedMap.clear();
	root = nullptr;
	root->left == nullptr;
	root->right == nullptr;
	root->parent == nullptr;

}


std::string huffman_encoder::get_character_code(char character) const {
	string charCode;	
	try 
	{		
		 return encodedMap.at(character);
			
	}
	catch (...)
	{
		return "";
	}		
}

std::string huffman_encoder::encode(const std::string& file_name) const {
	string encodedString = "";
	fstream txtFile(file_name);
	string content((istreambuf_iterator<char>(txtFile)), (istreambuf_iterator<char>()));	

	if (characterMap.size() == 1)
	{
		return "0";
	}
	else
	{
		for (int i = 0; i < content.length(); i++)
		{
			encodedString += get_character_code(content[i]);
		}
	}	
	return encodedString;
}



void huffman_encoder::encodeHelper(huffmanNode* root, string str, unordered_map<char, string>& characterMap) const
{
	if (!root)
	{
		return;
	}
	if (root->data != '$')
	{
		characterMap[root->data] = str;
	}
	else if (!root->left && !root->right)
	{
		characterMap[root->data] = str;
	}
	encodeHelper(root->left, str + "0", characterMap);
	encodeHelper(root->right, str + "1", characterMap);
}


std::string huffman_encoder::decode(const std::string& string_to_decode) const {
	string decodedString;
	decodedString=decodeHelper(root, string_to_decode);
	return decodedString;
}

string huffman_encoder::decodeHelper(huffmanNode* root, string encodedString) const
{	
	string decodedString = "";
	huffmanNode* curr = root;
	for (int i = 0; i < encodedString.size(); i++)
	{
		if (characterMap.size() == 1)
		{
			decodedString = curr->data;
			return decodedString;
		}
		else if (encodedString[i] == '0')
		{
			curr = curr->left;
		}
		else if (encodedString[i] == '1')
		{
			curr = curr->right;
		}
		
		if (!curr->left && !curr->right)
		{
			decodedString += curr->data;
			curr = root;
		}
	}
	return decodedString;
}
