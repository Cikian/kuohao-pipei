#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h>
int main()
{
	using namespace std;							   	  
	string t1;											  //�½�����
	printf("��������Ҫ�������ţ�\n");					  //��ʾ��Ϣ
	getline(cin, t1);									  //��ȡ�û����������
	stack<char> leftBracket;								      //�½�ջ
	int g = 0;											  //�ɹ�����ʧ�ܵı��
	if (')' == t1[0] || ']' == t1[0] || '}' == t1[0] || '>' == t1[0])     //����һ������Ϊ�����ţ���1��ֵ��g�������жϽ��
	{
		printf("��һ��Ϊ�����š�%C����ƥ��ʧ��",t1[0]);
		g = 1;
	}
	else 
	{
		for (int i = 0; i < t1.size(); i++)							//��ʼ����������ַ���
		{
			if ('(' == t1[i] || '[' == t1[i] || '{' == t1[i] || '<' == t1[i])		//����������ţ���ջ
			{
				leftBracket.push(t1[i]);									
				printf("        ��%d����  ��������ջ: %c\n\n", i+1,leftBracket.top());
			}
			else if (t1[i] == ')')
			{
				if (leftBracket.empty())									 //ջΪ�ջ���ջ�����Ų���ƥ�������š�ƥ��ʧ�ܣ�����ѭ��
				{
					printf("        ��%d�����Ҳ����š�%c���ж��࣬ƥ��ʧ��\n",i+1, t1[i]);
					g = 1;
					break;
				}
				else if (leftBracket.top() != '(')							  //ջΪ�ջ���ջ�����Ų���ƥ�������š�ƥ��ʧ�ܣ�����ѭ��
				{
					printf("        ��%c���������������Ų�ƥ�䣬ƥ��ʧ��\n", t1[i]);
					g = 1;
					break;
				}
				else if (leftBracket.top() == '(')						   	  //�ж������ź�ջ���������Ƿ���ƥ��
				{
					printf("        ��%d����  ������ %c, ƥ��������%c����%c����ջ\n\n",i+1, t1[i], leftBracket.top() ,leftBracket.top());
					leftBracket.pop();										  //ƥ���ɾ��ջ��Ԫ��
				}
			}
		
			else if (t1[i] == ']')
			{
				if (leftBracket.empty())									  //ջΪ�ջ���ջ�����Ų���ƥ�������š�ƥ��ʧ�ܣ�����ѭ��
				{
					printf("        �Ҳ����š�%c���ж��࣬ƥ��ʧ��\n", t1[i]);
					g = 1;
					break;
				}
				else if (leftBracket.top() != '[')							   //ջΪ�ջ���ջ�����Ų���ƥ�������š�ƥ��ʧ�ܣ�����ѭ��
				{
					printf("        ��%c���������������Ų�ƥ�䣬ƥ��ʧ��\n", t1[i]);
					g = 1;
					break;
				}
				else if (leftBracket.top() == '[')								//�ж������ź�ջ���������Ƿ���ƥ��
				{
					printf("        ��%d����  ������ %c, ƥ��������%c����%c����ջ\n\n", i + 1, t1[i], leftBracket.top(), leftBracket.top());
					leftBracket.pop();											//ƥ���ɾ��ջ��Ԫ��
				}
			}
			else if (t1[i] == '}')
			{
				if (leftBracket.empty())										//ջΪ�ջ���ջ�����Ų���ƥ�������š�ƥ��ʧ�ܣ�����ѭ��
				{
					printf("        �Ҳ����š�%c���ж��࣬ƥ��ʧ��\n", t1[i]);
					g = 1;
					break;
				}
				else if (leftBracket.top() != '{')								//ջΪ�ջ���ջ�����Ų���ƥ�������š�ƥ��ʧ�ܣ�����ѭ��
				{
					printf("        ��%c���������������Ų�ƥ�䣬ƥ��ʧ��\n", t1[i]);
					g = 1;
					break;
				}
				else if (leftBracket.top() == '{')								//�ж������ź�ջ���������Ƿ���ƥ��
				{
					printf("        ��%d����  ������ %c, ƥ��������%c����%c����ջ\n\n", i + 1, t1[i], leftBracket.top(), leftBracket.top());
					leftBracket.pop();											//ƥ���ɾ��ջ��Ԫ��
				}
			}
			else if (t1[i] == '>')
			{
				if (leftBracket.empty())										//ջΪ�ջ���ջ�����Ų���ƥ�������š�ƥ��ʧ�ܣ�����ѭ��
				{
					printf("        �Ҳ����š�%c���ж��࣬ƥ��ʧ��\n", t1[i]);
					g = 1;
					break;
				}
				else if (leftBracket.top() != '<')								//ջΪ�ջ���ջ�����Ų���ƥ�������š�ƥ��ʧ�ܣ�����ѭ��
				{
					printf("        ��%c���������������Ų�ƥ�䣬ƥ��ʧ��\n", t1[i]);
					g = 1;
					break;
				}
				else if (leftBracket.top() == '<')								//�ж������ź�ջ���������Ƿ���ƥ��
				{
					printf("        ��%d����  ������ %c, ƥ��������%c����%c����ջ\n\n", i + 1, t1[i], leftBracket.top(), leftBracket.top());
					leftBracket.pop();											//ƥ���ɾ��ջ��Ԫ��
				}
			}
		}
	}
	if (leftBracket.empty() && g==0)
		printf("\n  ƥ���\n\n\n");
	else if(g==1)
		printf("\n  �˴�����ƥ�䲻�Ϸ���\n\n\n");
	else if (!leftBracket.empty())
	{
		printf("\n  ������Ŷ���\n");
		printf("\n  �˴�����ƥ�䲻�Ϸ���\n\n\n");
	}
	else
		printf("\n  �˴�����ƥ�䲻�Ϸ���\n\n\n");
	system("pause");
	return 0;
}