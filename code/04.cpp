#if 0
#include <iostream>
using namespace std;
int main() {
	double score;
	std::cin >> score;
	if (score < 60)
		std::cout << "������" << std::endl;
	else
		std::cout << "�����ˣ�" << std::endl;
		return 0;
}
#endif 


#if 0
#include <iostream>
using namespace std;
int main() {
	double score;
	std::cin >> score;
	if (score < 60)
		std::cout << "������" << std::endl;
	else if (score < 70)
		std::cout << "����" << std::endl;
	else if (score < 80)
		std::cout << "�еȣ�" << std::endl;
	else if (score < 90)
		std::cout << "���ã�" << std::endl;
	else
		std::cout << "���㣡" << std::endl

	return 0;
}
#endif 

#if  0
<iostream>
int main() {
    double score;
	std::cin >> score;
	if (score >= 60) {
		if (score >= 90)
			std::cout << "���㣡" << std::endl;
	}
	else
		std::cout << "������" << std::endl;
	return 0;
}
#endif 


#if 0
#include <iostream>

int main() {
	int a = -100;
	if (a < 0) {
		std::cout << "a�ľ���ֵ��";
		std::cout << -a;
	}
	else {
		std::cout << "a�ľ���ֵ��";
		std::cout << a;
	}
	return 0;
}
#endif 

#if 0
#include <iostream>

int main() {
	int x;
	std::cin >> x;
	switch (x) {
	case 0:
	case 1:
		std::cout << "x�� 0 ��1\n";
		break;   //break�ؼ�����������switch       
	case 2:
		std::cout << "x �� 2\n";
		break;   //break�ؼ�����������switch    
	default:
		std::cout << "x ���� 0��1�� 2\n";
		//break;   //break�ؼ�����������switch          
	}

	return 0;
}
#endif

#if 0
#include <iostream>
int main() {
	unsigned vowelCnt = 0, nonVowelCnt = 0;
	char ch;
	while (std::cin >> ch) {
		switch (ch) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			vowelCnt++;
			break;          //����switchѭ��
		default:
			nonVowelCnt++;
			break;          //����switchѭ��
		}
	}
	std::cout << vowelCnt << std::endl;
	std::cout << nonVowelCnt << std::endl;

	return 0;
}
#endif 

#if 0
#include <iostream>
int main() {
	unsigned v;
	std::cin >> v;
	switch (v) {
	case 1: {
		int x = 0;
		std::cout << x << '\n';
	
		  break;
	}
        //  'x' ���������ڴ˽���
	default: std::cout << "default\n"; // �޴���
		break;
	}
	return 0;
}
#endif 


#if 0
// ����n�Ľ׳�
// n�Ľ׳� n! = 1*2*3...*n
#include <iostream>
using namespace std;
int main() {
	int n, i{ 1 }, factorial{ 1 };
	cout << "������һ��������: ";
	cin >> n;

	while (i <= n) {       //ֻҪiС�ڵ���n����һֱִ��whileѭ����
		factorial *= i;       //factorial = factorial * i;
		++i;
	}

	cout << n << "�Ľ׳��ǣ�= " << factorial;
	return 0;
}
#endif 

#if 0
#include <iostream>
using namespace std;
int main() {
	auto score{ 0. }, sum{ 0. };
	auto num{ 0 };
	while (std::cin >> score) {
		sum += score;
		num++;
	}
	std::cout << "ƽ���ɼ��ǣ�" << sum / num << std::endl;

	return 0;
}
#endif 

#if 0
#include <iostream>
using namespace std;
int main() {
	auto score{ 0. }, sum{ 0. };
	auto num{ 0 };
	while (std::cin >> score) {
		if (score < 0)
			break;
		sum += score;
		num++;
	}
	std::cout << "ƽ���ɼ��ǣ�" << sum / num << std::endl;

	return 0;
}
#endif 

#if 0
#include <iostream>
using namespace std;
int main() {
	auto score{ 0. }, sum{ 0. };
	auto num{ 0 };
	std::cin >> score;
	do {
		if (score < 0)
			break;
		sum += score;
		num++;
	} while (std::cin >> score);

	std::cout << "ƽ���ɼ��ǣ�" << sum / num << std::endl;

	return 0;
}
#endif 


#if 0
#include <iostream>
using namespace std;
int main() {
	auto score{ 0. }, sum{ 0. };
	auto num{ 0 };
	
	while (std::cin >> score) {
		if (score < 0)
			continue;
		sum += score;
		num++;
	}

	std::cout << "ƽ���ɼ��ǣ�" << sum / num << std::endl;

	return 0;
}
#endif 


#if 0
#include <iostream>
using namespace std;
int main() {
	auto s{ 0 };
	for (auto i{ 1 }; i <= 100; i++)
		s += i;
	std::cout << "1��100֮�������֮���ǣ�" << s << std::endl;

	return 0;
}
#endif 

#if 0
#include <iostream>
using namespace std;
int main() {
	double score, sum{ 0 };
	auto num{ 0 };
	for (; std::cin >> score; ) {
		if (score < 0)
			break;  //����whileѭ��
		sum += score;
		num++;
	}
	std::cout << "ƽ���ɼ��ǣ�" << sum / num << std::endl;
	return 0;
}
#endif 



#if 0
#include <iostream>
using namespace std;
int main() {
	double score, sum{ 0 };
	auto num{ 0 };
	for (; std::cin >> score && score >= 0; ) {
		sum += score;
		num++;
	}

	std::cout << "ƽ���ɼ��ǣ�" << sum / num << std::endl;
	return 0;
}
#endif 
