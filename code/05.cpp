#if 0

int main() {
	int& ref4{ 10 };  //�� ��������������
	double dval{ 3.14 };
	int& ref5{ dval };  //�����ñ������ͺͱ����ñ������Ͳ�һ��
}
#endif

#if 0

int main() {
	double* s;
	double& r;
}
#endif

#if 0
int main() {
	int zero{ 0 }, * p1;
	//int* p2{ zero };
	int* p{ 0 };
	int* p3{ 3 };

}
#endif

#if 0
#include <iostream>
int main() {
	int i;
	int* p{ &i }, * q{ 0 };
	bool b{ p };  // int*�ǿ�ָ��pת��Ϊbool��ֵtrue,
				  // Ȼ���b��ʼ������ˣ�b��ֵ��true
	std::cout << std::boolalpha << b << std::endl; //boolalpha����������bool������ʾ��ʽ
	b = q;       // int *��ָ��qת��Ϊbool��ֵfalse,
				  // Ȼ��ֵ��b����ˣ�b��ֵ��false;
	std::cout << std::boolalpha << b << std::endl;
}
#endif

#if 0
#include <iostream>
int main() {
	int* pi;
	void* pv = pi; // ok: int*�� void*����ʽ����ת��
	//*pv;    //�� :���ܽ����� void*
//	++pv;   //��: ����������ƫ�� void* (ָ�������ڴ��Сδ֪)
	int* pi2 = static_cast<int*>(pv); // void* ǿ������ת����int*
	double* pd1 = pv;   // ��:���ܽ�void*��ʼ����ֵ����void*ָ�����
	double* pd2 = pi; // ��ָ�����Ͳ�һ��
	double* pd3 = static_cast<double*>(pv); // ����ȫ
}
#endif

#if 0
#include <iostream>
int main() {
	int i = 3;
	int* pi = &i;
	std::cout << i << "\t" << *pi << std::endl;
	void* pv = pi; // ok: int*�� void*����ʽ����ת��
	//*pv=4;    //�� :���ܽ����� void*
//	++pv;   //��: ����������ƫ�� void* (ָ�������ڴ��Сδ֪)
	int* pi2 = static_cast<int*>(pv); // void* ǿ������ת����int*
	*pi2 = 4;
	std::cout << i << "\t" << *pi << "\t" << *pi2 << std::endl;

	//double* pd1 = pv;   // ��:���ܽ�void*��ʼ����ֵ����void*ָ�����
	//double* pd2 = pi; // ��ָ�����Ͳ�һ��
	double* pd3 = static_cast<double*>(pv); // ����ȫ
	*pd3 = 3.14;
}
#endif

#if 0
#include <iostream>
using namespace std;
int main() {
	int ival{ 1024 };
	int* pi{ &ival };  //pi �洢ival�ĵ�ַ
	int** ppi{ &pi }; // ppi�洢pi�ĵ�ַ�� pi��������int *��
				   // ����&pi������ (int *) *���� int **��int **����(int *)*
				   // ppi ---> pi -->ival  
	cout << "ival��ֵ�ǣ� " << ival << endl;
	cout << "ival��ֵ�ǣ� " << *pi << endl;    // *pi����ival
	cout << "ival��ֵ�ǣ�" << **ppi << endl;  // **ppi�� *(*ppi)����*ppi����pi��
 // ��ˣ�**ppi���� *(pi)��ival

	cout << "\nival�ĵ�ַ�ǣ�" << &ival << endl;
	cout << "ival�ĵ�ַ�ǣ�" << pi << endl;   //pi�������ival�ĵ�ַ
	cout << "ival�ĵ�ַ�ǣ�" << *ppi << endl; //*ppi����pi

	cout << "\npi�ĵ�ַ�ǣ�" << &pi << endl;
	cout << "pi�ĵ�ַ�ǣ�" << ppi << endl;   //pi�������ival�ĵ�ַ  
}

#endif

#if 1
int main() {
	auto i{ 0 }, j{ 1 };
	int* p;            //ָ�������һ��Ҫ��ʼ��
	int& r{ i };
	int &r1;     //�����ñ���r1û�г�ʼ����
	p = &i;          //pָ��i
	p = &j;        //pָ��j
	auto * &rp{ p };    // rp����p
//	int*& rp2;       //�����ñ���rp2û�г�ʼ��
//	int&* q;         //�� ���ܶ���ָ�����õĵ�ָ�룬
					// ��Ϊ���ñ���û�ж����ڴ�(��û�е�ַ)
	int&* q2 = &r;  //��ԭ��ͬ��. ���⣬ȡ��ַ�����&�������������ñ���r�� 
}
#endif