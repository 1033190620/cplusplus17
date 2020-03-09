#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

#include <windows.h>
void gotoxy(int x, int y) {
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hideCursor() {
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}


int main() {
	//1. ��ʼ����Ϸ�е�����
	auto WIDTH{ 90 }, HEIGHT{ 25 }; //���ڳ���
	auto ball_x{ WIDTH / 2 }, ball_y{ HEIGHT / 2 }, ball_vec_x{ 0 }, ball_vec_y{ 0 }; //��λ�ü��ٶ�
	auto paddle_w{ 3 }, paddle_h{ 8 };   //����ĳ���
	auto paddle1_x{ 0 }, paddle1_y{ HEIGHT / 2 - paddle_h / 2 }, paddle1_vec{ 3 }; //����1λ�ü��ٶ�
	auto paddle2_x{ WIDTH - paddle_w },
		paddle2_y{ HEIGHT / 2 - paddle_h / 2 }, paddle2_vec{ 3 }; //����2λ�ü��ٶ�
	auto score1{ 0 }, score2{ 0 }, score1_x{ paddle_w + 8 }, score1_y{ 2 },
		score2_x{ WIDTH - 8 - paddle_w }, score2_y{ 2 };


	srand((unsigned)time(0));  //�������������	
	ball_vec_x = rand() % 5 + 1; //����һ���������
	ball_vec_y = rand() % 5 + 1;
	if (rand() % 2 == 1) ball_vec_x = -ball_vec_x;
	if (rand() % 2 == 1) ball_vec_y = -ball_vec_y;


	while (true) {
		// 1. �����¼�
		char key;
		if (_kbhit()) {                          //����������
			key = _getch();                    //�õ�����ļ�ֵ
			if ((key == 'w' || key == 'W') && paddle1_y > paddle1_vec)
				paddle1_y -= paddle1_vec;
			else if ((key == 's' || key == 'S') && paddle1_y + paddle1_vec + paddle_h
				< HEIGHT)
				paddle1_y += paddle1_vec;
			else if (key == 72 && paddle2_y > paddle2_vec)
				paddle2_y -= paddle2_vec;
			else if ((key == 80) && paddle2_y + paddle2_vec + paddle_h < HEIGHT)
				paddle2_y += paddle2_vec;
		}


		// 2. �������� 	
		std::string s1{std::to_string(score1) }, s2{ std::to_string(score2) };

		ball_x += ball_vec_x;
		ball_y += ball_vec_y;
		if (ball_y < 0 || ball_y >= HEIGHT)           //������ǽ��ײ���ı䴹ֱ�ٶȷ���
			ball_vec_y = -ball_vec_y;

		if (ball_x < paddle_w && ball_y >= paddle1_y && ball_y < paddle1_y + paddle_h)
		{ //���󵲰���ײ���ı�ˮƽ�ٶȵķ���
			ball_vec_x = -ball_vec_x;
			score1 += 1;
		}
		else if (ball_x > WIDTH - paddle_w && ball_y >= paddle2_y
			&& ball_y < paddle2_y + paddle_h)
		{ //���ҵ�����ײ���ı�ˮƽ�ٶȵķ���
			ball_vec_x = -ball_vec_x;
			score2 += 1;
		}
		bool is_out{ false };              //�Ƿ��ܳ�������bool��־
		if (ball_x < 0) { score2 += 1; is_out = true; }
		else if (ball_x > WIDTH ) { score1 += 1; is_out = true; }
		if (is_out) {                  //�ܳ����ҹ�������ص����Ĳ����µ�����ٶȳ���
			ball_x = WIDTH / 2; ball_y = HEIGHT / 2;
			ball_vec_x = rand() % 5 + 1;
			ball_vec_y = rand() % 5 + 1;
			if (rand() % 2 == 1) ball_vec_x = -ball_vec_x;
			if (rand() % 2 == 1) ball_vec_y = -ball_vec_y;
		}

		gotoxy(0, 0);  //��λ��(0,0)���൱�������Ļ
		hideCursor();  //���ع��

		//3. ���Ƴ���
		//3.1���Ʊ���
		//3.1.1 �Ȼ��Ʊ����еĶ���ǽ	
		for (auto x = 0; x <= WIDTH; x++)
			std::cout << '=';
		std::cout << '\n';
		//2.1.2 ���Ʊ����е�3��������	
		for (auto y = 0; y <= HEIGHT; y++) {
			for (auto x = 0; x <= WIDTH; x++) {
				if (x == ball_x && y == ball_y)                     //���λ��
					std::cout << 'O';
				else if (y >= paddle1_y && y < paddle1_y + paddle_h
					&& x >= paddle1_x && x < paddle1_x + paddle_w) {   //�󵲰�λ��
					std::cout << 'Z';
				}
				else if (y >= paddle2_y && y < paddle2_y + paddle_h
					&& x >= paddle2_x && x < paddle2_x + paddle_w) {   //�ҵ���λ��
					std::cout << 'Z';
				}
				else if (y == score1_y && x == score1_x) { //�����λ��
					std::cout << s1;
					//while (x < score1_x + s1.size()) x++;
					x += s1.size();
					x--;
				}
				else if (y == score2_y && x == score2_x) {//�ҷ���λ��
					std::cout << s2;
					//while (x < score2_x + s2.size()) x++;
					x += s2.size();
					x--;
				}
				else if (x == 0 || x == WIDTH / 2 || x == WIDTH) //����
					std::cout << '|';
				else std::cout << ' ';
			}
			std::cout << '\n';
		}
		//2.1.3 ���Ʊ����еĵײ�ǽ	
		for (auto x = 0; x <= WIDTH; x++)
			std::cout << '=';
		std::cout << '\n';

	}

	return 0;
}
