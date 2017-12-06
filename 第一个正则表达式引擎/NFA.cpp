#include"NFA.h"
void NFA::tree_walk(std::shared_ptr<node> tree) {
	if (!tree)
		return;
	if (tree->type == leaf)
	{
		auto s = std::make_shared<nstate>();
		auto f = std::make_shared<nstate>();
		for (auto it = tree->Content->s_begin(); it != tree->Content->s_end(); it++)
		{
			s->add_next(*it, f);
		}
		for (auto it = tree->Content->m_begin(); it != tree->Content->m_end(); it++)
		{
			for (int i = it->start; i != it->end + 1; i++)
			{
				s->add_next(i, f);
			}
		}
		tree->nfa_s.first = s;
		tree->nfa_s.second = f;
		return;
	}
	else {
		tree_walk(tree->left);
		tree_walk(tree->right);
		if (tree->type==or) {
			auto s = std::make_shared<nstate>();
			auto f = std::make_shared <nstate>();
			s->add_next(empty, tree->left->nfa_s.first);
			s->add_next(empty, tree->right->nfa_s.first);
			tree->left->nfa_s.second->add_next(empty, f);
			tree->right->nfa_s.second->add_next(empty, f);
			tree->nfa_s.first = s;
			tree->nfa_s.second = f;
			return;
		}
		else if (tree->type == star) {
			auto s = std::make_shared<nstate>();
			auto f = std::make_shared <nstate>();
			s->add_next(empty, tree->left->nfa_s.first);
			tree->left->nfa_s.second->add_next(empty, tree->left->nfa_s.first);
			tree->left->nfa_s.second->add_next(empty, f);
			s->add_next(empty, f);
			tree->nfa_s.first = s;
			tree->nfa_s.second = f;
			return;
		}
		else if (tree->type == connect) {

			tree->left->nfa_s.second->copy(tree->right->nfa_s.first);
			tree->nfa_s.first = tree->left->nfa_s.first;
			tree->nfa_s.second = tree->right->nfa_s.second;
			tree->right->nfa_s.first.reset();//去掉右边节点的开始状态，因为它已经被左节点的结束状态代替了
			return;
		}
	}

}
