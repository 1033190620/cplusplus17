/* ----------hwdong�Ľ�ѧ��Դ---------------
   ��ѧ���ͣ�https://hwdong.net
   youtubeƵ���� hwdong
   twitter�� hwdong
   Bվ��΢����hw-dong
   ΢�Ź��ںţ�hwdong���
*/

#include <iostream>
//scores��std::initializer_list<double>���͵ı���
double average(std::initializer_list<double> scores) {
	auto n{ 0 };
	double all{ 0 };
	for (auto score : scores) {
		all += score; n++;
	}
	if (n > 0)	return all /= n;
	return 0;
}


#if 0

int main() {
	std::cout << average({  }) << '\n';
	std::cout << average({ 60. }) << '\n';
	std::cout << average({ 50.,80 }) << '\n';
	std::cout << average({ 90,50.,80 }) << '\n';
}
#endif 

#if 0
#include <iostream>
auto binarySearch(int a[], const int L, const int H, int value) {
	if (L > H)           //������
		return -1;
	auto Middle = (L + H) / 2;
	if (a[Middle] == value) // 1���м�Ԫ��ֱ�ӱȽ�
		return Middle;
	else 	if (value < a[Middle])
		return binarySearch(a, L, Middle - 1, value);    // 2) ���������
	else
		return binarySearch(a, Middle + 1, H, value);  // 3) ���������
}
int main() {
	int arr[]{ 5, 7, 12, 25, 34, 37, 43, 46, 58, 80, 82, 105 };
	std::cout << binarySearch(arr, 0, 11, 25) << '\t';
	std::cout << binarySearch(arr, 0, 11, 13) << '\n';
}
#endif 

#if 0
#include <iostream>
// һ�����ӣ�ֱ���ƶ�
void moveDisk(int i, const char x, const char y) {
	std::cout << "moving disk" << i << " from " << x << " to " << y << '\n';
}

// ����������, ��ʼ��, ��ת��, Ŀ����
void move(int n, const char a, const char b, const char c) {
	if (n < 1) return;
	move(n - 1, a, c, b);  // n - 1�����Ӵ�A��������C���Ƶ�B��
	moveDisk(n, a, c);
	move(n - 1, b, a, c);   // n - 1�����Ӵ�B��������A���Ƶ�C��
}
int main() {
	move(3, 'A', 'B', 'C');
}

#endif
