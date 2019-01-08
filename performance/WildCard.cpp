#include "pch.h"
#include "WildCard.h"


WildCard::WildCard()
	: Problem()
{
}


WildCard::~WildCard()
{
}

void WildCard::Input()
{
}

void WildCard::Solve()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);

	string pattern;
	int keyIndex = 0;

	function<void(char, string, int, vector<string>&)> findPattern = [&](char key, string name, int pos, vector<string>& result) {
		if (pos == name.size()) {
			result.push_back(name);
			return;
		}
		
		if (key == '*') {
			char subKey = 0x00;
			for (int i = keyIndex + 1; i < pattern.size(); i++) {
				if (pattern[i] != '*') {
					subKey = pattern[i];
					keyIndex = i;
					break;
				}
			}

			if (subKey != 0x00) {				
				for (int i = pos; i < name.size(); i++) {
					if (name[pos] == subKey) {
						return findPattern(pattern[keyIndex], name, i, result);
					}
				}

				return;
			}

			// *만 있을 때
			result.push_back(name);
			return;
		}
		
		if (key != '?' && key != name[pos]) {
			return;
		}

		return findPattern(pattern[keyIndex], name, pos++, result);
	};
}

void WildCard::Result()
{
}

void WildCard::TestInput()
{
}
