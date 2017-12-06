#ifndef __DFA__
#define __DFA__
#include"state.h"
#include"NFA.h"
#include<queue>
class DFA {
	NFA nfa;
	std::shared_ptr<state> start;
	std::unordered_set<std::shared_ptr<state>> finish;
	std::shared_ptr<state> exsist_unmarked(std::unordered_set<std::shared_ptr<state>> Dstate) {
		for (auto it = Dstate.begin(); it != Dstate.end(); it++)
			if (!(*it)->marked())
				return (*it);
		return nullptr;
	}
public:
	bool find_finish(std::shared_ptr<state> s) {
		if (finish.find(s) != finish.end())
			return true;
		else
			return false;
	}
	std::shared_ptr<state> get_start() { return start; }
	std::unordered_set<std::shared_ptr<state>> get_finish() { return finish; }
	DFA(std::shared_ptr<node> tree) :nfa(tree) { make_DFA(); };
	void make_DFA();
};


#endif // !__DFA__
