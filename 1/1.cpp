// 1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector> 
#include <string> 
#include <fstream> 
#include <iostream> 

using namespace std; //E:\c++\a.txt wc.exe-cfile.txt wc.exe-wfile.txt wc.exe-sfile.txt
int i = 0;
int j = 0;
int n = 0;
int temp;
int temp1 = 0;
int temp2 = 0;
char c[1000];
char a[16];
char b[16];
int temp3 = 0;
string cfile;
int main()
{
	cout << "请输入文件地址.txt: ";
	string file;
	cin >> file;
	ifstream myfile(file);

	myfile >> noskipws;
	if (!myfile.is_open())
	{
		cout << "未成功打开文件" << endl;
	}
	while (!myfile.eof())
	{
		i++;
		myfile >> c[i];

		cout << c[i];

	}
	cout << endl;
	cout << "请输入指令" << endl;
	for (temp = 1; temp <= i; temp++)
	{
		if (((c[temp] >= 65 && c[temp] <= 90) || (c[temp] >= 97 && c[temp] <= 122)) && (c[temp + 1] == ' ' || (c[temp + 1] >= 32 && c[temp + 1] <= 64)))
		{
			temp1++;

		}
		if (temp == i && ((c[temp - 1] >= 65 && c[temp - 1] <= 90) || (c[temp - 1] >= 97 && c[temp - 1] <= 122)))
		{
			cout << c[i];
			temp1++;
		}
		if (c[temp] != ' '&&c[temp] != '\n'&&c[temp] != '\t')
			temp2++;
		if (c[temp] == 33 || c[temp] == 63 || c[temp] == 46)
			temp3++;
	}
	while (1) {
		if (cin >> a) {

			if (strcmp(a, "wc.exe-wfile.txt") == 0)
				cout << "单词数: " << temp1 << endl;

			if (strcmp(a, "wc.exe-cfile.txt") == 0)
				cout << "字符数: " << temp2 - 1 << endl;
			if (strcmp(a, "wc.exe-sfile.txt") == 0)
				cout << "句子数: " << temp3 << endl;
		}
	}
	myfile.close(); //关闭文件输入流
	while (1);
	return 0;

}
