/*
* an array of function pointers
* ����ָ������Ķ���
* auto �Զ��������͵�ʹ��
* �������ĵ�ַ��������av��Ԫ�صĵ�ַ�����Ǻ�����ַ��
*/

# include <iostream>

const double * fn1(const double ar[], int n);
const double * fn2(const double [], int n);
const double * fn3(const double *ar, int n);
// �������������ͱ�����һģһ���ģ�����?=ָ��

int main()
{
	using namespace std;
	
	double av[3] = {1.1, 0.2, 1.3};
	
	// pointer to a function
	const double * (*pfun1)(const double *, int) = fn1;	// �滻�����庯��ָ�룬ͬʱ��ʼ��
	const double * (*pfun2)(const double *, int) = fn2;	// 	auto pfun2 = fn2;	// automatic type deduction. The same as 
	
	cout << "Using pointers to functions: \n";
	cout << "Address Value: \n";
	cout << (*pfun1)(av, 3) << " : " << *(*pfun1)(av, 3) << endl;
	cout << pfun2(av, 3) << " : " << *pfun2(av, 3) << endl;
	
	// pfunarr an array of pointers
	const double * (*pfunarr[3])(const double*, int) = {fn1, fn2, fn3};
	// Auto does not work with list initialization which only is used for a single value initialization
	// auto pfunb = pfunarr;
	cout << "\n--------------------------------------------\n";
	cout << "Using an array of pointers to functions: \n";
	cout << "Address value\n";
	for (int i = 0; i < 3; i++)
	{
		cout << pfunarr[i](av, 3) << " : " << *pfunarr[i](av, 3) << endl;
	}
	
	cout << "\nUsing pointers to an array of function pointers:\n";
	cout << "Address value:\n";
	const double * (*(*pfunc)[3])(const double *, int) = &pfunarr;	// auto pfunc = &pfunarr;	// 
	cout << (*pfunc)[0](av, 3) << " : " << *(*pfunc)[0](av, 3) << endl;
	
	cin.get();
	
	return 0;
	
}

const double * fn1(const double ar[], int n)
{
	return ar;
}

const double * fn2(const double ar[], int n)
{
	return ar + 1;
}

const double * fn3(const double *ar, int n)
{
	return ar + 2;
}
