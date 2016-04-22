/*
	pointer to functions
	����ָ��Ĵ����͵��÷�����

*/

#include <iostream>

double betsy(int);
double pam(int);

void estimate(int lines, double (*pfun)(int));
// second argument is a pointer to a function, which must be the same as the function with return type and argument lists.

int main(void)
{
	using namespace std;
	
	int codes;
	cout << "How many lines of codes do you need?" << endl;
	while(cin >> codes)
	{
		cout << "Here is Betsy's estimate time: " << endl;
		estimate(codes, betsy);
		cout << "Here is Pam's estimate time: " << endl;
		estimate(codes, pam);
		cout << "How many lines of codes do you need?" << endl;
	}
	cout << "Estimating is ending! \n";
	
	return 0;
}

// ����һ����������������ú�������ͨ��
double betsy(int lines)
{
	return 0.05 * lines;
}

double pam(int lines)
{
	return 0.03 * lines + 0.0003 * lines * lines;
}

void estimate(int lines, double (*pf)(int))
{
	using namespace std;
	cout << lines << " lines will take ";
	cout << (*pf)(lines) << " seconds.\n";	// ͨ������ָ����ú��������������.
	// pf(lines)Ч��һ�������ַ�ʽ�����Ե��ú��������ؽ����������Щ��ͬ��*pfָ��������pf����ָ�룡
	// ��������ָ��������Ҳ��ָ���������׵�ַ�ĺ���ָ�룡
}