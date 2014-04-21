// Leetcode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <unordered_set>
#include <string>
#include "use_me.h"
#include "use_solution.h"
#include <iostream>
using namespace std;

void testWordLader2()
{
	std::string tmp[] = {"a","b","c"};
	unordered_set<string> dict(tmp, tmp + sizeof(tmp) / sizeof(tmp[0]));
	//dict.insert("a");
	//dict.insert("b");
	//dict.insert("c");
	
	string start = "a",end = "c";
	Solution1 solution1;
	Solution solution;
	for (unordered_set<string>::iterator it = dict.begin();it!=dict.end();++it)
		cout<<*it<<","<<endl;
	char ch;
	cin.get(ch);
	vector<vector<string>> output = solution1.findLadders(start,end,dict);
	for (vector<vector<string>>::iterator itr = output.begin();itr!=output.end();++itr)
	{
		cout<<"[ ";
		for(vector<string>::iterator iter = (*itr).begin();iter!=(*itr).end();++iter)
		{
			cout<<*iter<<",";
		}
		cout<<" ]"<<endl;
	}
	cin.get(ch);
	output = solution.findLadders(start,end,dict);
	for (vector<vector<string>>::iterator itr = output.begin();itr!=output.end();++itr)
	{
		cout<<"[ ";
		for(vector<string>::iterator iter = (*itr).begin();iter!=(*itr).end();++iter)
		{
			cout<<*iter<<",";
		}
		cout<<" ]"<<endl;
	}
	cin.get(ch);
}
void testCountAndSay()
{
	Solution solution;
	string testStr = solution.countAndSay(9);
}
void testUniquePath()
{
	Solution solution;
	solution.uniquePaths(10,10);
}
void testMinPathSum()
{
	vector<vector<int>> grid;
	vector<int> row1;
	row1.push_back(1);
	row1.push_back(2);
	row1.push_back(5);
	vector<int> row2;
	row2.push_back(3);
	row2.push_back(2);
	row2.push_back(1);
	grid.push_back(row1);
	grid.push_back(row2);
	int x = grid.size();
	int y = grid[0].size();
	Solution solution;
	int i = solution.minPathSum(grid);
}

void A::foo(){
	cout<<"A"<<endl;
}

void B::foo(){
	cout<<"B"<<endl;
}

void bar()
{
    A *a = new B();
	a->foo();   // A::foo()被调用
	delete a;
}

void testCanJump()
{
	int input[3] = {1,2,3};
	int n = 3;
	Solution solution;
	bool output = solution.canJump(input,n);
}
void testCombinPhoneNum()
{
	Solution solution;
	vector<string> output = solution.letterCombinations("23");
}
void testPalindrome()
{
	int x = 100;
	x>1;
	cout<<x;
	int a=1,b=-5,c=0;
	c=a+ +b;
	cout<<c;
	Solution solution;
	vector<vector<string>> output = solution.partition("a");
}
void testSortList()
{
	ListNode *head = new ListNode(2);
	ListNode *tail = new ListNode(1);
	head->next = tail;
	Solution solution;
	ListNode *headNew = solution.sortList(head);
}
void testMaximalRect()
{
	vector<vector<char>> input;
	input.resize(1);
	input[0].resize(2);
	input[0][0] = '0';
	input[0][1] = '1';
	Solution solution;
	int output = solution.maximalRectangle(input);
}
void testSurroundedRegsion()
{
	vector<vector<char>> input;
	input.resize(2);
	input[0].resize(2);
	input[1].resize(2);
	for(int i=0;i<input.size();++i)
		for(int j=0;j<input[0].size();++j)
			input[i][j] = 'O';
	Solution solution;
	solution.solve(input);
}
void testReverseWord()
{
	string tempStr= "a, yqo! qjktum ym. .fumuhau";
	Solution solution;
	solution.reverseWords(tempStr);
}
void testQueen()
{
	Solution solution;
	vector<vector<string>> output = solution.solveNQueens(4);
}
void testSudoku()
{
	string strArray[9] = {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
	vector<vector<char>> input;
	input.resize(9);
	for(int i=0;i<9;i++)
	{
		string str = strArray[i];
		std::vector<char> data(str.begin(), str.end());
		input[i] = data;
	}
	Solution solution;
	solution.solveSudoku(input);
}
void testFindSubStr()
{
	string S = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
	vector<string> L;
	L.resize(5);
	L[0] = "fooo";L[1]="barr"; L[2] = "wing"; L[3]="ding";L[4] = "wing";
	Solution solution;
	vector<int> output = solution.findSubstring(S,L);

}
void testNumdec()
{
	Solution solution;
	solution.numDecodings("17");
}
void testDivide()
{
	Solution solution;
	solution.divide(2147483647, 1);
}
void testAtoi()
{
	string input = "    010";
	Solution s;
	s.atoi(input.c_str());
}
int _tmain(int argc, _TCHAR* argv[])
{
	//testWordLader2();
	//testUniquePath();
	//testMinPathSum();
	//testCanJump();
	//bar();
	//testCountAndSay();
	//testCombinPhoneNum();
	//testPalindrome();
	//testSortList();
	//testMaximalRect();
	//testSurroundedRegsion();
	//testReverseWord();
	//testQueen();
	//testSudoku();
	//testFindSubStr();
	//testNumdec();
	//testDivide();
	testAtoi();
	char ch;
	cin.get(ch);
	return 0;
}

