#ifndef __NSTATE__
#define __NSTATE__
#include<vector>
#include<memory>
#include<list>
enum 
{
	empty = 126
};
struct nstate//nfa��һ��״̬
{
	static int id;
	int ID;
	nstate() :next(94) { ID = id;id++;}//! ��~֮����135���ַ� ���ϣ�-
	//bool f=0;
	std::vector<std::list<std::shared_ptr<nstate>>> next;
	std::list<std::shared_ptr<nstate>> operator[](int i) { return next[i]; }
	auto begin()->std::vector<std::list<std::shared_ptr<nstate>>>::iterator {
		return next.begin();
	}
	auto end()->std::vector<std::list<std::shared_ptr<nstate>>>::iterator {
		return next.end();
	}
	void copy(std::shared_ptr<nstate> s) {
		next = s->next;
	}
	void add_next(int c, std::shared_ptr<nstate> next_state)
	{
		next[c - '!'].push_back(next_state);
}
};
bool operator <(std::shared_ptr<nstate> lhs, std::shared_ptr<nstate> rhs);
bool operator ==(std::shared_ptr<nstate> lhs, std::shared_ptr<nstate> rhs);



#endif // !__STATE__
