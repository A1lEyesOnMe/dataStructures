#include<iostream>
#include <cstdlib>
int main()
{
	int a {200};

	char b = static_cast<char>(a);

	std::cout << b <<'\n';

	std::cout << static_cast<int>(b) << '\n';
	
}
