#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h>
int main()
{
	using namespace std;							   	  
	string t1;											  //新建数组
	printf("请输入需要检测的括号：\n");					  //提示信息
	getline(cin, t1);									  //获取用户输入的括号
	stack<char> leftBracket;								      //新建栈
	int g = 0;											  //成功或者失败的标记
	if (')' == t1[0] || ']' == t1[0] || '}' == t1[0] || '>' == t1[0])     //若第一个括号为右括号，将1赋值给g，用于判断结果
	{
		printf("第一个为右括号“%C”，匹配失败",t1[0]);
		g = 1;
	}
	else 
	{
		for (int i = 0; i < t1.size(); i++)							//开始遍历输入的字符串
		{
			if ('(' == t1[i] || '[' == t1[i] || '{' == t1[i] || '<' == t1[i])		//如果是左括号，入栈
			{
				leftBracket.push(t1[i]);									
				printf("        第%d个：  左括号入栈: %c\n\n", i+1,leftBracket.top());
			}
			else if (t1[i] == ')')
			{
				if (leftBracket.empty())									 //栈为空或者栈顶括号不能匹配右括号→匹配失败，跳出循环
				{
					printf("        第%d个：右侧括号“%c”有多余，匹配失败\n",i+1, t1[i]);
					g = 1;
					break;
				}
				else if (leftBracket.top() != '(')							  //栈为空或者栈顶括号不能匹配右括号→匹配失败，跳出循环
				{
					printf("        “%c”与左侧最近的括号不匹配，匹配失败\n", t1[i]);
					g = 1;
					break;
				}
				else if (leftBracket.top() == '(')						   	  //判断右括号和栈顶的括号是否能匹配
				{
					printf("        第%d个：  右括号 %c, 匹配左括号%c，“%c”出栈\n\n",i+1, t1[i], leftBracket.top() ,leftBracket.top());
					leftBracket.pop();										  //匹配→删除栈顶元素
				}
			}
		
			else if (t1[i] == ']')
			{
				if (leftBracket.empty())									  //栈为空或者栈顶括号不能匹配右括号→匹配失败，跳出循环
				{
					printf("        右侧括号“%c”有多余，匹配失败\n", t1[i]);
					g = 1;
					break;
				}
				else if (leftBracket.top() != '[')							   //栈为空或者栈顶括号不能匹配右括号→匹配失败，跳出循环
				{
					printf("        “%c”与左侧最近的括号不匹配，匹配失败\n", t1[i]);
					g = 1;
					break;
				}
				else if (leftBracket.top() == '[')								//判断右括号和栈顶的括号是否能匹配
				{
					printf("        第%d个：  右括号 %c, 匹配左括号%c，“%c”出栈\n\n", i + 1, t1[i], leftBracket.top(), leftBracket.top());
					leftBracket.pop();											//匹配→删除栈顶元素
				}
			}
			else if (t1[i] == '}')
			{
				if (leftBracket.empty())										//栈为空或者栈顶括号不能匹配右括号→匹配失败，跳出循环
				{
					printf("        右侧括号“%c”有多余，匹配失败\n", t1[i]);
					g = 1;
					break;
				}
				else if (leftBracket.top() != '{')								//栈为空或者栈顶括号不能匹配右括号→匹配失败，跳出循环
				{
					printf("        “%c”与左侧最近的括号不匹配，匹配失败\n", t1[i]);
					g = 1;
					break;
				}
				else if (leftBracket.top() == '{')								//判断右括号和栈顶的括号是否能匹配
				{
					printf("        第%d个：  右括号 %c, 匹配左括号%c，“%c”出栈\n\n", i + 1, t1[i], leftBracket.top(), leftBracket.top());
					leftBracket.pop();											//匹配→删除栈顶元素
				}
			}
			else if (t1[i] == '>')
			{
				if (leftBracket.empty())										//栈为空或者栈顶括号不能匹配右括号→匹配失败，跳出循环
				{
					printf("        右侧括号“%c”有多余，匹配失败\n", t1[i]);
					g = 1;
					break;
				}
				else if (leftBracket.top() != '<')								//栈为空或者栈顶括号不能匹配右括号→匹配失败，跳出循环
				{
					printf("        “%c”与左侧最近的括号不匹配，匹配失败\n", t1[i]);
					g = 1;
					break;
				}
				else if (leftBracket.top() == '<')								//判断右括号和栈顶的括号是否能匹配
				{
					printf("        第%d个：  右括号 %c, 匹配左括号%c，“%c”出栈\n\n", i + 1, t1[i], leftBracket.top(), leftBracket.top());
					leftBracket.pop();											//匹配→删除栈顶元素
				}
			}
		}
	}
	if (leftBracket.empty() && g==0)
		printf("\n  匹配√\n\n\n");
	else if(g==1)
		printf("\n  此串括号匹配不合法×\n\n\n");
	else if (!leftBracket.empty())
	{
		printf("\n  左侧括号多余\n");
		printf("\n  此串括号匹配不合法×\n\n\n");
	}
	else
		printf("\n  此串括号匹配不合法×\n\n\n");
	system("pause");
	return 0;
}