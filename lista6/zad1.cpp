#include <iostream>
#include <string>


int hash(std::string text)
{
	int hashSize = 101;
	unsigned int hash = 0;
	
	for(char c : text)
	{
		hash = 31 * hash + c;
	}
	return hash % hashSize;
}

int main()
{
	std::string s1 = "test";
	std::string s2 = "test2";
	std::string s3 = "asd";
	std::string s4 = "test";
	
	std::cout << "String: " << s1 << std::endl;
	std::cout << "Hash: " << hash(s1) << std::endl; //86
	std::cout << "String: " << s2 << std::endl;
	std::cout << "Hash: " << hash(s2) << std::endl; //90
	std::cout << "String: " << s3 << std::endl;
	std::cout << "Hash: " << hash(s3) << std::endl; //23
	std::cout << "String: " << s4 << std::endl;
	std::cout << "Hash: " << hash(s4) << std::endl; //86
}
