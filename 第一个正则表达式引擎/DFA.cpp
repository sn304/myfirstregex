#include"DFA.h"
void DFA::make_DFA() {
	std::unordered_set<std::shared_ptr<state>> Dstate;
	auto x = nfa.get_start();
	auto y = state::closure(x);
	start = y;
	Dstate.insert(y);
	auto T = y;
	while (T) {
		T->mark_it();
		for (int i = '!'; i != '~' + 1; i++)
		{
			auto U = state::closure(state::MOVE(i, T));
			if (U->get_nstate_size() > 0) {
				auto k = Dstate.find(U);
				if (k == Dstate.end())
				{
					Dstate.insert(U);
					T->add_next(i, U);
				}
				else if (k != Dstate.end())
					T->add_next(i, *k);
			}
		}
		T = exsist_unmarked(Dstate);
	}
	for (auto &h : Dstate)
		if (h->exsist(nfa.get_finish()))
		{
			finish.insert(h);
		}
}
