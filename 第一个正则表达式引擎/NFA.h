#ifndef __NFA__
#define __NFA__
#include"parser.h"
#include"nstate.h"
class NFA {
	std::shared_ptr<node> tree;
	std::shared_ptr<nstate> start;
	std::shared_ptr<nstate> finish;//一直只存在一个接受状态
	void make_NFA() {
		tree_walk(tree);
		start = tree->nfa_s.first;
		finish = tree->nfa_s.second;
	}
	void tree_walk(std::shared_ptr<node> tree);
public:
	NFA(std::shared_ptr<node> tree) :tree(tree) { make_NFA(); }
	std::shared_ptr<nstate> get_start() { return start; }
	std::shared_ptr<nstate> get_finish() { return finish; }
};

#endif // !__NFA__
