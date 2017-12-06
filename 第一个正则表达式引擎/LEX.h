#ifndef __LEX__
#define __LEX__
#include<string>
#include"token.h"
class lex {
	std::string pattern;
public :
	lex(const std::string& p) :pattern(p) {}
	std::vector<std::shared_ptr<token>> analyse();
};
#endif // !__LEX__
