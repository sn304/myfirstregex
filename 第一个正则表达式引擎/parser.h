#ifndef __PARSER__
#define __PARSER__
#include"LEX.h"
#include<iostream>
#include"nstate.h"
struct node
{
public:
	node(int type, std::shared_ptr<node> l, std::shared_ptr<node> r):type(type),left(l),right(r){}
	node(int type, std::shared_ptr<node> l):type(type), left(l){}
	node(int type, std::shared_ptr<content> Content) :type(type),Content(Content) {}
	int type;
	std::shared_ptr<node> left;
	std::shared_ptr<node> right;
	std::shared_ptr<content> Content;
	std::pair<std::shared_ptr<nstate>, std::shared_ptr<nstate>> nfa_s;

};
class parser {
	std::vector<std::shared_ptr<token>> token_squ;
	int current = 0;
	std::shared_ptr<node> E();
	std::shared_ptr<node> T();
	std::shared_ptr<node> E1(std::shared_ptr<node> tree);
	std::shared_ptr<node> T1(std::shared_ptr<node> tree);
	std::shared_ptr<node> F();
	std::shared_ptr<node> F1(std::shared_ptr<node> tree);
	std::shared_ptr<node> H();
	
public:
	parser(std::vector<std::shared_ptr<token>> &s):token_squ(s){}
	std::shared_ptr<node> analyse()
	{
		return E();
	}
};



#endif // !__PARSER__
