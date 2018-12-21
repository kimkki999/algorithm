#pragma once
#include "Problem.h"

const int ALPHABET = 26;
inline int toNumber(const char& ch) 
{ 
	return ch - 'A'; 
}
inline char toChar(const int& val)
{
	return val + 'A';
}

class TrieNode {
public:
	TrieNode() : _terminal(false) 
	{
		memset(_children, 0x00, sizeof(_children));
	}
	~TrieNode()
	{
		for (const auto& val : _children) {
			if (val)
				delete val;
		}
	}

	void insert(const char* key) {
		/*if (key == nullptr) {
			_terminal = true;
			return;
		}*/
		if (*key == 0) {
			_terminal = true;
		}
		else {
			int next = toNumber(*key);
			if (_children[next] == nullptr) {
				_children[next] = new TrieNode();
			}
			_children[next]->insert(key + 1);
		}
	}
	TrieNode* find(const char* key) {
		if (*key == 0) {
			return this;
		}

		int next = toNumber(*key);
		if (_children[next] == nullptr) {
			return nullptr;
		}
		return _children[next]->find(key + 1);
	}
	void addChildren(vector<string>& result, string prefix) {
		if (_terminal) {
			result.push_back(prefix);
		}

		for (int i = 0; i < sizeof(_children) / sizeof(TrieNode*); i++) {
			if (_children[i] != NULL) {
				string str = prefix + toChar(i);
				_children[i]->addChildren(result, str);
			}
		}					
	}
private:
	TrieNode *_children[ALPHABET];
	bool _terminal;

};

class SoLong :
	public Problem
{
public:
	SoLong();
	~SoLong();

	virtual void Input();
	virtual void Solve();
	virtual void Result();

	virtual void TestInput();

private:
	TrieNode _root;
	vector<string> _input;
	vector<string> _find;
	vector<string> _result;
};

