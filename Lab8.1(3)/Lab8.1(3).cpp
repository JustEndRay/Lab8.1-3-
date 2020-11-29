#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int Check(char* str, int i, int count)
{
	if (strlen(str) < 2)
		return 0;
	if (i < strlen(str))
	{
		if ((str[i] == 'n' && str[i + 1] == 'o') || (str[i] == 'o' && str[i + 1] == 'n'))
			count++;
		return Check(str, i + 1, count);
	}
	else
		return count;
}
void* Change(char* str, int i)
{
	if (strlen(str) < 2)
		return 0;
	char* tmp = new char[strlen(str) * 4 / 3 + 1];
	char* t = tmp; tmp[0] = '\0';
	if (i < strlen(str))
	{
		if ((str[i] == 'n' && str[i + 1] == 'o') || (str[i] == 'o' && str[i + 1] == 'n'))
		{
			strcat(t, "****"); t += 3; i += 2;
		}
		else
		{
			*t++ = str[i++]; *t = '\0';
		}
		*t++ = str[i++]; *t++ = str[i++]; *t = '\0';
		strcpy(str, tmp);
		return Change(str, i + 1);
	}

}
int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "String contained " << Check(str, 0, 0) << " groups of 'no' or groups of 'on'" << endl;
	Change(str, 0);
	cout << "Modified string (param) : " << str << endl;
	return 0;
}
