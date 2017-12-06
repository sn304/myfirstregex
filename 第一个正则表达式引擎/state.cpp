#include"state.h"
#include<iostream>
std::shared_ptr<state> state::closure(std::shared_ptr<nstate> s) {
	auto x = std::make_shared<state>();
	auto li = s->operator[](empty-'!');
	for (auto &y : li)
		x->add(y);
	auto y = closure(x);
	y->add(s);
	return y;
}
std::shared_ptr<state> state::closure(std::shared_ptr<state> s) {
	for (auto it = s->State.begin(); it != s->State.end(); it++)
	{
		auto x= closure(*it);
		s->Union(x);
	}
	return s;
}
std::shared_ptr<state> state::MOVE(char a, std::shared_ptr<state> s) {
	auto x = std::make_shared<state>();
	for (auto it = s->State.begin(); it != s->State.end(); it++)
	{
		auto li = (*it)->operator[](a-'!');
		for (auto &y : li)
			x->add(y);
	}
	return x;
}
bool operator==(std::shared_ptr<state> lhs, std::shared_ptr<state> rhs) {

	return lhs->State == rhs->State;
}

size_t std::hash <std::shared_ptr<state>>:: operator()(const std::shared_ptr<state>& s) const {
	size_t m = hash<int>()(-1);
	for (auto x = s->State.begin(); x != s->State.end(); x++)
	{
		m=m^(std::hash<int>()((*(s->State.begin()))->ID));
	}
	return m;
}