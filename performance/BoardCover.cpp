#include "pch.h"
#include "BoardCover.h"

BoardCover::BoardCover()
	: Problem(), _input(), _result()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}

BoardCover::~BoardCover()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}

void BoardCover::Input()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}

void BoardCover::Solve()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);

	int h = _input.size();
	int w = _input[0].size();

	vector<vector<int>> board(h, vector<int>(w, 0));
	int whiteCount = 0;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (_input[i][j] == '#') {
				board[i][j] = 1;
			}
			else {
				whiteCount++;
			}
		}
	}

	if (whiteCount % 3 != 0) _result = 0;

	// y, x
	vector<vector<pair<int, int>>> move;
	move.push_back({ {0, 0},{1, 0}, {0, 1} });
	move.push_back({ {0, 0},{0, 1}, {1, 1} });
	move.push_back({ {0, 0},{1, 0}, {1, 1} });
	move.push_back({ {0, 0},{1, 0}, {1, -1} });

	function<bool()> allCover = [&]()->bool {
		bool ret = true;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!board[i][j]) {
					ret = false;
					break;
				}
			}
		}
		return ret;
	};

	//function<bool (int, int, int, bool, vector<pair<int, int>>&)> mask = [&](int y, int x, int index, bool fill, vector<pair<int,int>>& done)->bool {
	//	bool ret = true;
	//	int val = fill ? 1 : 0;
	//	//board[y][x] = val;
	//	auto movePos = move[index];
	//	
	//	if (fill == false) {
	//		for (const auto& val : done) {
	//			board[val.first][val.second] = 0;
	//		}
	//		return true;
	//	}

	//	for (int i = 0; i < movePos.size(); i++) {
	//		int newY = y + movePos[i].first;
	//		int newX = x + movePos[i].second;

	//		if (newY < 0 || newX < 0 || newY > h - 1 || newX > w - 1) {
	//			ret = false;		
	//			continue;
	//		}

	//		if (fill && board[newY][newX] == 1) {
	//			ret = false;
	//			continue;
	//		}
	//		board[newY][newX] = val;
	//		done.push_back(make_pair(newY, newX));
	//	}
	//	
	//	return ret;
	//};

	//function<int()> cover = [&]()->int {
	//	//if (y > h - 1 || x > w - 1 || y < 0 || x < 0) return 0;

	//	if (allCover()) return 1;

	//	int ret = 0;
	//	for (int i = 0; i < h; i++) {
	//		for (int j = 0; j < w; j++) {
	//			if (board[i][j] == 0) {
	//				board[i][j] = 1;
	//				for (int k = 0; k < move.size(); k++) {
	//					vector<pair<int, int>> done;
	//					if (mask(i, j, k, true, done)) {
	//						ret += cover();
	//					}
	//					mask(i, j, k, false, done);
	//				}
	//				board[i][j] = 0;
	//			}
	//		}
	//	}	

	//	return ret;
	//};

	//int ret = cover();
	
	function<bool(int, int, int, bool)> mask2 = [&](int y, int x, int index, bool fill)->bool {
		bool ret = true;
		int val = fill ? 1 : -1;
		
		auto movePos = move[index];

		for (int i = 0; i < movePos.size(); i++) {
			int newY = y + movePos[i].first;
			int newX = x + movePos[i].second;

			if (newY < 0 || newX < 0 || newY > h - 1 || newX > w - 1) {
				ret = false;
				continue;
			}
			else if ((board[newY][newX] += val) > 1) {
				ret = false;
				continue;
			}
		}

		return ret;
	};

	function<int()> cover2 = [&]()->int {
		int y = -1, x = -1;
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (board[i][j] == 0) {
					y = i;
					x = j;
					break;
				}
			}
			if (y != -1) break;
		}

		if (y == -1) return 1;

		int ret = 0;
		
		//board[y][x] = 1;
		for (int k = 0; k < move.size(); k++) {			
			if (mask2(y, x, k, true)) {
				ret += cover2();
			}
			mask2(y, x, k, false);			
		}
		//board[y][x] = 0;
		return ret;
	};

	int ret2 = cover2();
}

void BoardCover::Result()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}

void BoardCover::TestInput()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);

	/*_input.push_back("#.....#");
	_input.push_back("#.....#");
	_input.push_back("##...##");
*/
	_input.push_back("#...#");
	_input.push_back("#...#");
	
}
