//=============3. ���������ʽ===============
//����������ݽ�����ѧ���߼�������������ţ�
//������� + �� * �� || �ֱ��ʾ�ӡ��ˡ��߼���
//����������ݽ�������͹����˱��ʽ����
/*
  2+3/5
  3.14*2.5*2.5
*/

// -----------3.1 �����------------
//�����ܵĲ�ͬ���ɷ�Ϊ���������Ƚϡ��߼���λ���㡢��ֵ��
//������+��-��*��/��%������������++����������--���Լ���
//�Ƚϣ�==��!=��>��<��>=��<=
//�߼���&&���߼��룩��||���߼��򣩡� �����߼��ǣ�
//λ���㣺&���룩��|���򣩡�^(���)��~��������<<�����ƣ���>>�����ƣ�
//��ֵ��=��+=��*=��|=��...

// ���������������ɷ�Ϊ��һԪ����Ԫ����Ԫ
#if 0
#include <iostream>
int main() {
	int a, b, c;
	std::cin >> a >> b >> c;
	int min = a < b ? (a < c ? a : c) : (b < c ? b : c);
	std::cout << a << "," << b << "," << c << "��3��������Сֵ�ǣ�"
		<< min << std::endl;
}
#endif

//----------�������--------------
#if 0
#include <iostream>
int main() {
	short value = 32767;
	std::cout << value << std::endl;
	value = value + 1;    // value����short���͵�ֵ�ķ�Χ���������Ԥ�ڣ�
	std::cout << value << std::endl;
}
#endif

//----------�����͸������������--------------
#if 0
#include <iostream>
int main() {
	auto val3 = 21.0 / 6;  //��������ת��

	std::cout << "21.0/6 = :" << 21.0 / 6 << std::endl;
	int a = 3, b = 4;
	std::cout << "int/int=:" << a / b << std::endl;
	std::cout << "double/int=:" << static_cast<double>(a) / b << std::endl;
	std::cout << "int/double=:" << a / static_cast<double>(b) << std::endl;
	std::cout << "double/double=:" << static_cast<double>(a) / static_cast<double>(b) << std::endl;
}
#endif

//----------���������� %--------------
#if 0
#include <iostream>
int main() {
	int ival = 10;
	double dval = 3.14;
	auto val = ival % 4;
//	auto val2 = dval % 4;  //��%��������ʵ��
	std::cout << "val:" << val << std::endl;

	std::cout << "21 % 6:" << 21 % 6 << std::endl; //�����3  
	std::cout << "21 % 7:" << 21 % 7 << std::endl;  //�����0 
	std::cout << "-21 % (-8):" << -21 % (-8) << std::endl; //�����-5  
	std::cout << "21 % (-5):" << 21 % (-8) << std::endl; //�����5
}
#endif

//-----------����++���Լ�------------------
#if 0
#include <iostream>
int main() {
	int a = 3, b = 3;
	std::cout << "a++��ֵ" << a++ << ", a��ֵ��" << a << std::endl;
	std::cout << "++b��ֵ" << ++b << ", b��ֵ��" << b << std::endl;
}
#endif

#if 0
#include <iostream>
using namespace std;
int main() {
	int x = 1;
	int a = ++x;         //x������1Ϊ2�����ʽ++xΪ���º��xֵ2,a��ֵΪ2
	int b = x++;         //���ʽx++��ֵΪx��ֵ2,��b = 2,Ȼ��x����1Ϊ3
	int c = ++ ++x;      //c��x�Ķ���5
	int d = x + ++x;      //��Ϊx��++x��+��2������������x��++x�ĸ��ȼ���ֵ�ǲ�ȷ���ģ�
						// ���������5+6��Ҳ������6+6
//	int e = x++ ++;      //���ֱ������:��Ҫ��ֵ
	cout << a << endl << b << endl << c << endl << d << endl;
	return 0;
}

#endif

//-------cmath-------
#if 0
#include <cmath>
#include <iostream>
int main() {
	double d = 3.5;
	std::cout << sqrt(3.5) << std::endl;// ���3.5��ƽ����

	double base = 3.5, exp = 6.4;;
	std::cout << base << "^" << exp << "����" << pow(base, exp);
	return 0;
}
#endif


#if 0
#include <iostream>
#include <cmath>
using namespace std;
int main(){
	double x = 20.5, result;
	result = log10(x);
	cout << "log10(x) = " << result << endl;

	x = -2.5;
	result = log10(x);
	cout << "log10(x) = " << result << endl;

	return 0;
}
#endif

#if 0
#include <cmath>
#include <iostream>
int main() {
	float angle_deg{ 60.0f };      //�Ƕ�
	const float pi{ 3.14159265f };
	const float pi_degrees{ 180.0f };
	float tangent{ std::tan(pi * angle_deg / pi_degrees) };
	float angle(std::atan(tangent));
	float angle_deg2{ angle * pi_degrees / pi };
	std::cout << angle << '\t' << angle_deg2 << '\t' << angle_deg << '\n';
}
#endif

//------λ����--------
/*
      a = 0 0 1 0 0 1 0 1
	  b = 0 0 0 1 0 1 1 0
*/
#if 0
//~x �Ľ����: -(x+1)
#include <iostream>
#include <bitset>
#include <iomanip>
int main() {
	char a{ 37 }, b{ 22 };
	std::cout << std::left;
	std::cout << std::setw(5) << "a:" << std::setw(5)<< +a << std::bitset<8>(a) << '\n'
		<< std::setw(5) << "b:" << std::setw(5) << +b << std::bitset<8>(b) << '\n';

	std::cout << std::setw(5) << "a&b" << std::setw(5) << (a & b)  << std::bitset<8>(a & b) << '\n';
	std::cout << std::setw(5) << "a|b" << std::setw(5) << (a | b)  << std::bitset<8>(a | b) << '\n';
	std::cout << std::setw(5) << "a^b" << std::setw(5) << (a ^ b) << std::bitset<8>(a ^ b) << '\n';

	std::cout << std::setw(5) << "~a" << std::setw(5) << (~a)  << std::bitset<8>(~a) << '\n';
	std::cout << std::setw(5) << "a<<2" << std::setw(5) << (a << 2)  << std::bitset<8>(a<<2) << '\n';
	std::cout << std::setw(5) << "a>>2" << std::setw(5) << (a >> 2)  << std::bitset<8>(a>>2) << '\n';

	a = -37;
	std::cout << std::setw(5) << "a:" << std::setw(5) << +a << std::bitset<8>(a) << '\n';
	std::cout << std::setw(5) << "~a" << std::setw(5) << (~a) << std::bitset<8>(~a) << '\n';
	std::cout << std::setw(5) << "a<<2" << std::setw(5) << (a << 2) << std::bitset<8>(a << 2) << '\n';
	std::cout << std::setw(5) << "a>>2" << std::setw(5) << (a >> 2) << std::bitset<8>(a >> 2) << '\n';
}
#endif


//----------��ֵ�����-----------
#if 0
#include <iostream>
int main() {
	//�ҽ����
	int a{}, b{ 3 }, c{ 4 };
	a = b = c = 2;
	std::cout << a << '\t' << b << '\t' << c << '\n';
	//����������������ֵ
	3 = a; //��
	a+b == 5;
	//�����޸�const����
	const int d = 5;
	d = 1; //
}
#endif

#if 0
#include <iostream>
#include <bitset>
#include <iomanip>
int main() {
	int a(3), b{ 4 },c;
	a *= b;
	std::cout << a << std::endl;
	a = 3;
	std::cout << std::left;
	std::cout << std::setw(5) << "a:" << std::setw(5) << +a << std::bitset<8>(a) << '\n'
		<< std::setw(5) << "b:" << std::setw(5) << +b << std::bitset<8>(b) << '\n';
	a |= b;
	std::cout << std::setw(5) << "a:" << std::setw(5) << +a << std::bitset<8>(a) << '\n';
	
}
#endif

//-----------��ϵ�����-------------
#if 0
//��ϵ�����(��<)�����ڸ�ֵ�����=
#include <iostream>
using namespace std;
int main() {
	int a = 4, b = 5;
	bool b1 = a < b;    // bool b1 = (a<b) 
	bool b2 = a == b;   // bool b2 = (a==b) 
	//boolalphaʹ�ú����bool�������"true"��"false"������1��0
	cout << boolalpha << b1 << '\t' << b2 << endl;
}
#endif

#if 0
//������������==�ж�2�����Ƿ����
#include <iostream>
#include<iomanip>
using namespace std;
int main() {
	double d1(100 - 99.99);
	double d2(10 - 9.99);
	bool b = d1 == d2; // bool b = (d1==d2)
	cout << boolalpha << b << endl;

	cout << setprecision(17); //�����������ʽ�޸�Ϊ����17λ
	cout << d1 << endl;
	cout << d2 << endl;
}
#endif

#if 0
//�þ��������������ж�2���������Ƿ����
#include <iostream>
#include<cmath>    // ����ֵ����fabs������cmathͷ�ļ���
#include<iomanip>
using namespace std;
int main() {
	double d1(100 - 99.99);
	double d2(10 - 9.99);
	bool b = fabs(d1 - d2) < 1e-10;   // ����Ƿ��㹻С��
	cout << boolalpha << b << endl;
	cout << setprecision(17);
	cout << d1 << endl;
	cout << d2 << endl;
}
#endif

//----------�߼�����------
#if 0
#include <iostream>
int main() {
	int a = 4, b = 0;
	std::cout << std::boolalpha;
	std::cout << (a || b) << std::endl
		<< (a && b) << std::endl
		<< (!a && b) << std::endl;

	std::cout << '\n';
	std::cout << (a or b) << std::endl
		<< (a and b) << std::endl
		<< (not a and b) << std::endl;
}
#endif

//-----------���������-----------
//1)
//   exp1, exp2
//  ���μ���exp1 ��exp2��ֵ���������ʽ��ֵ��exp2��ֵ��
//2) ע�⣺������������ȼ����ڸ�ֵ�����
#if 0
#include <iostream>
int main() {
	auto a{ 4 }, b{ 3 };
	//auto c = a, b;  //����������������ȼ�����=
	auto d = (a, b);
	std::cout << d << std::endl;
}

#endif