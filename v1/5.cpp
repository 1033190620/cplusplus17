/* ----------hwdong�Ľ�ѧ��Դ---------------
   ��ѧ���ͣ�https://hwdong.net
   youtubeƵ���� hwdong
   twitter�� hwdong
   Bվ��΢����hw-dong
   ΢�Ź��ںţ�hwdong���
*/

#if 0
#include <iostream>
int main() {
	int i{0};
	int *const p = &i;
	const int *q = &i;
	int const *s = &i;
	*p = 2;  //p���ܱ��޸ģ�����ָ���int���ͱ����ǿ��Ա��޸ĵ�
	std::cout << *p << '\t' << *q << '\t' << *s << '\n';
	int j{ 3 };
	q = &j;
	s = &j;
	std::cout << *p << '\t' << *q << '\t' << *s << '\n';
	p = &j;
	*q = 4;
	*s = 4;
}
#endif

#if 0
int main() {
	int a{ 3 }, b{ 4 };
	{
		int c{ 5 };
	}
	a = 2;
}
#endif 

#if 0
#include <iostream>
int main() {
	double *p{}; //��ʼ��ָ�����pΪ��ָ�룬�ȼ���double *p{nullptr}
	p = new double; //p�洢new�����ڴ�ĵ�ַ
	double *q{};
	q = new double[3]; //q�洢new�����ڴ�ĵ�ַ
	
	*p = 3.14; //*p����pָ����Ǹ�double����
	*q = 3.15; //*q����qָ����Ǹ�double����
	*(q + 1) = 3.16; //*(q+1������q+1ָ����Ǹ�double����
	*(q + 2) = 3.17; //*(q+2������q+2ָ����Ǹ�double����
	*(q + 3) = 3.17; //*(q+3������q+3ָ����Ǹ�double����
	                  //��q+3ָ����ڴ治���ڷ�����ڴ�飬�޷����ʣ���˳���
	*(p + 1) = 2.5; //��p+1���ڴ治���ڳ���
	*(q - 1) = 2.5; //��q-1���ڴ治���ڳ���
	for (auto i = 0; i < 3; i++)
		q[i] += 2;
	for (auto i = 0; i < 3; i++)
		std::cout << q[i] << '\t';
	delete p;
	delete[] q;
}
#endif
#if 0
#include <iostream>
int main() {
	double scores[100][4]; //�����Դ洢100��ѧ���ɼ�
	int n = 0; //ѧ������
	int cols; //ÿ��ѧ���ĳɼ�����
	std::cin >> n>> cols;
	//double *scores = new double[n][cols];

//	double (*p)[4] = new double[4]; //����һ��double[4]�Ŀռ�.

//	double (*scores)[4] = new double[n][4];
	auto scores = new double[n][4];
}
#endif

#if 0
#include <iostream>
int main() {	
	int n = 0; //ѧ������
	int cols; //ÿ��ѧ���ĳɼ�����
	std::cout << "����ѧ������\n";
	std::cin >> n ;
	auto scores{ new double[n][4]};
	std::cout << "����ѧ����ƽʱ��ʵ�顢��ĩ�������ɼ�\n";
	for (auto i = 0; i != n; i++) {
		std::cin >> scores[i][0] >> scores[i][1]
			>> scores[i][2] >> scores[i][3];
	}
	for (auto i = 0; i != n; i++) {
		std::cout << scores[i][0] <<'\t'<< scores[i][1]	<< '\t' 
			<< scores[i][2] << '\t' << scores[i][3] << '\n';
	}
}
#endif

#if 0
//const��������ã�reference to const
int main() {
	int i = 42;
	const int ci = 1024; //ci��const int���󣬼������޸ĵ�int��Ҳ��Ϊ����
	const int &r1 = ci;   // r1��const���������						
	const int &r2 = i;    // ��const int&��һ����ͨ��int����	
	const int &r3 = 42;   // ��const int&������
	const int &r4 = r1 * 2; // ��const int&�����ʽ 

	r1 = 42; // ��: const��������� ���������޸� 
	r4 = 42;

	int &r5 = ci; // ��: ��ͨ���������ò�������const����
	int &r6 = i * 2; // error: ��ͨ���������ò������ñ��ʽ
	int &r7 = 6; //��������������

	double dval = 3.14;
	const int &r8 = dval; //dval��double���ͣ���r8��const int���͵����á�

	const int temp = dval;
	const int &r8 = temp;

	int j = 4;
	int &r9 = j;
	const int &r10 = j;
	r9 = 0; //Ҳ����j = 0
	r10 = 0; //�����ԣ���Ϊr10��const int�����á�
}


#endif 

#if 0
//ָ���const
int main() {
	char *const cp; // ָ��char��constָ��
	char const* pc; // ָ��const char��ָ��
	const char* pc2; //ָ��const char��ָ��
	const char* const pc3; //ָ��const char��constָ��


	int a = 0;
	const int b = a;
	const int *pa = &a;
	*pa = 4;  //��ָ��const����
	pa = &b;  //ָ������޸�
	int *const pa2 = &a;
	pa2 = &b;  //��constָ�벻�ܱ��޸�
	int* pb = &b; //����ָͨ�벻��ָ��const����
				  //���򣬲��Ϳ�ͨ��*pb�޸�const�����ˣ�
	const int *pb2 = &b;
	pb2 = &a;
	const int *const pb3 = &b;
	const int *const pb4 = &a;
	pb4 = pb3; //��pb4���ܱ��޸�
	*pb4 = 9; //��pb4ָ���const���󣬲����޸�



	char s[] = "Gorm";
	const char* pc = s; // ָ��const char��ָ��
	pc[3] = 'g'; // �� : ָ��const char��ָ��
	pc = p; // OK
	char *const cp = s; // ָ��char��constָ��
	cp[3] = 'a'; // OK
	cp = p; // �� : cp ��constָ��
	const char *const cpc = s; // //ָ��const char��constָ��
	cpc[3] = 'a'; // ��: cpcָ��const char
	cpc = p;     // �� : cpc ��constָ��
}
#endif 

#if 0
int f() {
	int i{0};
	int *const p1 = &i;
	const int ci = 42;
	const int *p2 = &ci;
	const int *const p3 = p2;
	const int &r = ci;

	int *p = p3;
	p2 = p3;
	p2 = &i;
	int &r1 = ci;
	const int &r2 = i;
}
#endif

#if 0
#include <iostream>
using namespace std;
int main() {
	int ia[3][4];
	auto cnt{ 0 };
	for (auto &row : ia)  //��ia��ÿ��Ԫ�أ�ÿ�У�
		for (auto &col : row) {  //��row��ÿ��Ԫ�أ�ÿ�У�
			col = cnt;     cnt++; //���Ժϲ�Ϊһ�䣺 col = cnt++;
		}
	//���   
	for (auto &row : ia) {
		for (auto &col : row)
			cout << col << '\t';
		cout << '\n';
	}

	for (auto& row : ia) 
		for (auto col : row) //��row��һ��ָ�룬
				 //������ָ�����޷�ʹ��Range for��
			cout << col << '\t';
	

}

#endif

#if 0
#include <iostream>
using namespace std;
int main() {
	auto n{ 4 };
	//	auto INFINITY =  std::numeric_limits<double>::max();
	double D[][4]{ {0, 2, 6, 4},
				{INFINITY, 0, 3, INFINITY},
				{7, INFINITY, 0, 1 },
				{5, INFINITY, 12, 0} };

	unsigned int P[][4]{ {0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0} };
	for (auto u = 0; u < n; u++)
		for (auto v = 0; v < n; v++)
			P[u][v] = u;
	//��ӡD��P����
	for (auto& row : D) { //row������ia��ÿ��Ԫ�أ����row��һ��int[4]������
		for (auto col : row)
			cout << col << '\t';
		cout << '\n';
	}
	cout << '\n';
	for (auto& row : P) { //row������ia��ÿ��Ԫ�أ����row��һ��int[4]������
		for (auto col : row)
			cout << col << '\t';
		cout << '\n';
	}
	cout << std::endl;

	//Floyd�㷨
	for (auto w = 0; w < n; w++) 
		for (auto u = 0; u < n; u++)
			for (auto v = 0; v < n; v++)
				if (w != u and w != v and D[u][w] + D[w][v] < D[u][v]) {
					D[u][v] = D[u][w] + D[w][v];
					P[u][v] = P[w][v];
				}
	//��ӡD��P����
	for (auto& row : D) {
		for (auto col : row)
			cout << col << '\t';
		cout << '\n';
	}
	cout << '\n';
	for (auto& row : P) {
		for (auto col : row)
			cout << col << '\t';
		cout << '\n';
	}
	cout << std::endl;	
}
#endif