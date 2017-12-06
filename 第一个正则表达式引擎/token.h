#ifndef __TOKEN__
#define __TOKEN__
#include<memory>
#include"content.h"
enum token_type
{
	single,muitiple,connect,or,star,left_embrace,right_embrace,leaf,end
};
class token {
	int type;
	std::shared_ptr<content> entry;
public:
	token(int type):type(type){}
	token(int type, std::shared_ptr<content> entry):type(type),entry(entry){}
	int get_type() { return type; }
	std::shared_ptr<content> get_content() { return entry; }
};
#endif // !__TOKEN__
