#include"regex.h"
std::vector<std::pair<int, int>> regex::match(const std::string & text) {
	std::vector<std::pair<int, int>> offset;
	int count_move = 0;//��һ�ο��ܵ�ƥ�������˶��ٲ�
	int longest_matched = -1;
	int longset_matched_move = -1;
	for (int i = 0; i != text.size(); i++)
	{
		auto m1 = current_state->get_next(text[i]);
		if (m1) {
			count_move++;
			current_state = current_state->get_next(text[i]);
			if (D.find_finish(current_state))
			{
				longset_matched_move = count_move;
				longest_matched = i;
			}
			if (i == text.size() - 1)
			{
				if (longest_matched != -1)
					offset.push_back({ longest_matched,longset_matched_move });
			}
		}
		else
		{
			count_move = 0;
			current_state = D.get_start();
			if (longest_matched != -1)
			{
				offset.push_back({ longest_matched,longset_matched_move });
				i = i - (i - longest_matched);//��ƥ��ʱӦ�ûص���Զ���ܵĽ��
			}

			longest_matched = -1;
			longset_matched_move = -1;

		}
	}
	return offset;
}