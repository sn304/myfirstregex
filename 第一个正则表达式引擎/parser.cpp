#include"parser.h"
std::shared_ptr<node> parser::E() {
	if (token_squ[current]->get_type() == muitiple || token_squ[current]->get_type() == single || token_squ[current]->get_type() == left_embrace)
	{
		return E1(T());
	}
	else {
		std::cout << "w E";
		exit(0);
		//error
	}
}
std::shared_ptr<node> parser::T() {
	if (token_squ[current]->get_type() == muitiple || token_squ[current]->get_type() == single || token_squ[current]->get_type() == left_embrace)
	{
		return T1(F());
	}
	else
	{
		std::cout << "w T";
		exit(0);
		//error
	}
}
std::shared_ptr<node> parser::E1(std::shared_ptr<node> tree) {

	if (token_squ[current]->get_type() == or) {
		current++;
		return E1(std::make_shared<node>(or , tree, T()));

	}
	else if (token_squ[current]->get_type() == right_embrace || token_squ[current]->get_type() == end) {
		return tree;
	}
	else {
		std::cout << "w E1";
		exit(0);
		//error
	}
}
std::shared_ptr<node> parser::T1(std::shared_ptr<node> tree) {
	if (token_squ[current]->get_type() == connect) {
		current++;
		return T1(std::make_shared<node>(connect, tree, F()));
	}
	else if (token_squ[current]->get_type() == or||token_squ[current]->get_type() == right_embrace || token_squ[current]->get_type() == end)
	{
		return tree;
	}
	else
	{
		std::cout << "w T1";
		exit(0);
		//error
	}
}
std::shared_ptr<node> parser::F() {

	if (token_squ[current]->get_type() == muitiple || token_squ[current]->get_type() == single || token_squ[current]->get_type() == left_embrace)
	{
		return F1(H());
	}
	else {
		std::cout << "w F";
		exit(0);
		//error
	}
}
std::shared_ptr<node> parser::F1(std::shared_ptr<node> tree) {
	if (token_squ[current]->get_type() == star) {
		current++;
		return std::make_shared<node>(star, tree);
	}
	else if (token_squ[current]->get_type() == connect || token_squ[current]->get_type() == or||token_squ[current]->get_type() == right_embrace || token_squ[current]->get_type() == end) {
		return tree;
	}
	else {
		std::cout << token_squ[current]->get_type() << "w F1";
		exit(0);
		//error
	}
}
std::shared_ptr<node> parser::H() {
	auto x = token_squ[current];
	if (token_squ[current]->get_type() == muitiple || token_squ[current]->get_type() == single)
	{
		current++;
		return std::make_shared<node>(leaf, token_squ[current - 1]->get_content());

	}
	else if (token_squ[current]->get_type() == left_embrace) {
		current++;
		auto x = E();
		current++;
		return x;
	}
	else {
		std::cout << "w H";
		exit(0);
		//error
	}

}
