#include"LEX.h"
std::vector<std::shared_ptr<token>> lex::analyse() {
	std::vector<std::shared_ptr<token>> arr;
	for (int i = 0; i != pattern.size(); i++)
	{
		if (pattern[i] == '(')
		{
			arr.push_back(std::make_shared<token>(left_embrace));
		}
		else if (pattern[i] == ')')
		{
			arr.push_back(std::make_shared<token>(right_embrace));
			if (i != pattern.size() - 1 && pattern[i + 1] != '*'&&pattern[i + 1] != '|')
				arr.push_back(std::make_shared<token>(connect));
		}
		else if (pattern[i] == '[')
		{
			auto Content = std::make_shared<content>();
			auto x = std::make_shared<token>(muitiple, Content);
			//不把方括号当作词法单元处理,这里会推进循环
			for (int x = i + 1; x != pattern.size() - 1; x++)
			{
				if (pattern[x] == ']')
				{
					i = x;
					break;
				}
				if (pattern[x] >= '!'  && pattern[x] <= '~'&&pattern[x] != '-'&&pattern[x + 1] == '-'&&'!' <= pattern[x + 2] <= '~')
				{
					Content->add_muitiple(pattern[x], pattern[x + 2]);
					x = x + 2;
				}
				else if (pattern[x] >= '!'&& pattern[x] <= '~')
				{
					Content->add_single(pattern[x]);

				}
			}
			arr.push_back(x);
			if (i != pattern.size() - 1 && pattern[i + 1] != '*'&&pattern[i + 1] != '|')
				arr.push_back(std::make_shared<token>(connect));
		}
		else if (pattern[i] == '*') {
			arr.push_back(std::make_shared<token>(star));
			if (i != pattern.size() - 1 && pattern[i + 1] != '|')
				arr.push_back(std::make_shared<token>(connect));
		}
		else if (pattern[i] == '|') {
			arr.push_back(std::make_shared<token>(or ));
		}
		else
		{
			arr.push_back(std::make_shared<token>(single, std::make_shared<content>(pattern[i])));
			if (i != pattern.size() - 1 && pattern[i + 1] != '*'&&pattern[i + 1] != '|'&&pattern[i + 1] != ')')
				arr.push_back(std::make_shared<token>(connect));
		}
		//	else
		//{ 
		//error
		//	}
	}
	arr.push_back(std::make_shared<token>(end));
	return arr;
}