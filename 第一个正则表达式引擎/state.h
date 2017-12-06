#ifndef __STATE__
#define __STATE__
#include"nstate.h"
#include<set>
#include<unordered_set>
class state {
	friend bool operator==(std::shared_ptr<state> lhs, std::shared_ptr<state> rhs);
	friend std::hash <std::shared_ptr<state>>;
	std::set<std::shared_ptr<nstate>> State;
	std::vector<std::shared_ptr<state>> next;
	bool mark = 0;
public:
	state():next(94,nullptr){}
	bool marked() { return mark; }
	bool exsist(std::shared_ptr<nstate> s) {
		if (State.find(s) != State.end())
			return true;
		else
			return false;
	}
	int get_nstate_size() { return State.size(); }
	std::shared_ptr<state> get_next(int i) { return next[i - '!']; }
	void add_next(int c, std::shared_ptr<state> next_state)
	{
		next[c - '!']=next_state;
	}
	void Union(std::shared_ptr<state> s) {
		for (auto it = s->State.begin(); it != s->State.end(); it++)
		{
			State.insert(*it);
	}
	}
	void add(std::shared_ptr<nstate> s) {
		State.insert(s);
	}
	void mark_it() { mark = true; }
	static std::shared_ptr<state> closure(std::shared_ptr<nstate> s);
	static std::shared_ptr<state> closure(std::shared_ptr<state> s);
	static std::shared_ptr<state> MOVE(char a,std::shared_ptr<state> s);
};
namespace std {
	template <> struct hash<std::shared_ptr<state>> {
		typedef size_t result_type;
		typedef std::shared_ptr<state> argument_type;
		size_t operator()(const std::shared_ptr<state>&) const;
	};
}
bool operator==(std::shared_ptr<state> lhs, std::shared_ptr<state> rhs);
#endif // !__STATE__
