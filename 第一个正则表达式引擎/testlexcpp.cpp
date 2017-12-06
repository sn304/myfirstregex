#include"regex.h"
#include<iostream>
int main() {
	regex r("[a-z]|[A-Z]");
	std::string s = "dadasfAS";
	auto x= r.match(s);
	for (auto &y : x)
		std::cout << y.first << " " << y.second << std::endl;
}  