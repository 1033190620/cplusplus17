/* ----------hwdong�Ľ�ѧ��Դ---------------
   ��ѧ���ͣ�https://hwdong.net
   youtubeƵ���� hwdong
   twitter�� hwdong
   Bվ��΢����hw-dong
   ΢�Ź��ںţ�hwdong���
*/

#include "Vector.h"
#include <iostream>

#if 0
int main() {
	Vector<int> a;  // Vector<int>��Vector��ģ���ʵ�����࣬���е�����Ԫ��������int
	for (auto i = 0; i <= 6; i++)
		a.push_back(2 * i + 1);
	a[3] = 30;
	for (auto i = 0; i != a.size(); i++)
		std::cout << a[i] << '\t';
	std::cout << '\n';

	Vector<int> b;
	b = a;
	for (auto i = 0; i != a.size(); i++)
		std::cout << b[i] << '\t';
	return 0;
}
#endif

#if 0
int main() {
	Vector<Vector<int>> matrix{ {1,2,3,4},{5,6,7,8} };
	for (auto i = 0; i < matrix.size(); i++) {
		for (auto j = 0; j < matrix[i].size(); j++) {
			std::cout << matrix[i][j] << "  ";
		}
		std::cout << std::endl;
	}
}

#endif