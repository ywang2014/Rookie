/*
 Scope: ȫ�־�̬����(�ⲿ������)��ȫ�ֱ���(�ڲ�������)
 ODR: һ�ζ����ԭ��
 С����������Զ�����ȫ�ֱ���
 variables with external and internal linkage
 to be compiled with file2.c
 */
#include <iostream>
int tom = 3;	// define external variable 
int dick = 10;	// ...
static int harry = 100;	// static internal linkage
int var = 1000;

void remote_global();
void remote_local();

int main()
{
	using namespace std;
	cout << "main() reports following addresses: \n";
	cout << &tom << " = &tom, " << &dick << " = &dick, " << &harry << " = &harry. \n";
	remote_global();
	remote_local();
	return 0;
}