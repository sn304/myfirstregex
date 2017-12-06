#ifndef __REGEX__
#define __REGEX__
#include"DFA.h"
class regex{
	lex L;
	parser P;
	DFA D;
	std::shared_ptr<state> current_state;
public:
	regex(const std::string& patter):L(patter),P(L.analyse()),D(P.analyse()), current_state(D.get_start()){}
	std::vector<std::pair<int, int>> match(const std::string & text);
};

#endif // !__REGEX__
