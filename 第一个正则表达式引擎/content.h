#ifndef __CONTENT__
#define __CONTENT__
#include<vector>
#include<iostream>
struct range {
	char start;
	char end;
};
class content {
	std::vector<char> single;
	std::vector<range>muitiple;
public:
	auto s_begin()->std::vector<char>::iterator { return single.begin(); }
	auto s_end()->std::vector<char>::iterator { return single.end(); }
	auto m_begin()->std::vector<range>::iterator { return muitiple.begin(); }
	auto m_end()->std::vector<range>::iterator { return muitiple.end(); }
	content() = default;
	content(char c) {
		single.push_back(c);
	}
	void add_single(char a) {
		single.push_back(a);
	}
	void add_muitiple(char begin, char end) {
		//这里应该检查开始和结束的大小关系
		muitiple.push_back(range{ begin,end });
	}
	void show() {
		for (auto x = single.begin(); x != single.end(); x++)
		{
			std::cout << (*x) << " ";
		}
		std::cout << std::endl;
		for (auto x = muitiple.begin(); x != muitiple.end(); x++)
		{
			std::cout << x->start << "-" << x->end << " ";
		}
	}
};
#endif // !__CONTENT__
