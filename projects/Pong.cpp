/* ----------hwdong�Ľ�ѧ��Դ---------------
   ��ѧ���ͣ�https://hwdong.net
   youtubeƵ���� hwdong
   twitter�� hwdong
   Bվ��΢����hw-dong
   ΢�Ź��ںţ�hwdong���
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <string>
using namespace std;

void gotoxy(int x, int y) {
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void hideCursor() {
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}


int main_() {
	//1. ��ʼ����Ϸ�е�����
	auto WIDTH{ 120 }, HEIGHT{ 40 }; //���ڳ���
	auto ball_x {WIDTH/2}, ball_y{HEIGHT/2}, ball_vec_x{0}, ball_vec_y{0};
	auto paddle_w{4}, paddle_h{10};
	auto paddle1_x{0}, paddle1_y{HEIGHT/2-paddle_h/2}, paddle1_vec{3};
	auto paddle2_x{ WIDTH - paddle_w }, paddle2_y{ HEIGHT / 2 - paddle_h / 2 }, paddle2_vec{3};
	auto score1{ 0 }, score2{ 0 }, score1_x{ paddle_w+8 }, score1_y{ 2 },
		score2_x{ WIDTH- 8- paddle_w }, score2_y{ 2 };
	auto pong_circle_r2{40};  //�����뾶��ƽ��
	
	srand((unsigned)time(0));  //�������������	
	ball_vec_x = rand() % 3 + 1; //����һ���������
	ball_vec_y = rand() % 3 + 1;
	if (rand() % 2 == 1) ball_vec_x = -ball_vec_x;
	if (rand() % 2 == 1) ball_vec_y = -ball_vec_y;
	
	//��Ϸѭ��
	while (true) {
		// 1. �����¼�
		char key;
		if (_kbhit()) {
			key = _getch();
			if ((key == 'w'|| key == 'W')&& paddle1_y > paddle1_vec)			
				paddle1_y-=paddle1_vec;
			else if ((key == 's' || key == 'S')&& paddle1_y + paddle1_vec + paddle_h < HEIGHT)
				paddle1_y += paddle1_vec;				
			else if (key == 72&& paddle2_y > paddle2_vec)
				paddle2_y -= paddle2_vec;
			else if ((key == 80)&& paddle2_y + paddle2_vec + paddle_h < HEIGHT)
				paddle2_y += paddle2_vec;			
		}


		// 2. �������� 
		ball_x += ball_vec_x;
		ball_y += ball_vec_y;
		if (ball_y < 0 || ball_y >= HEIGHT)
			ball_vec_y = -ball_vec_y;
		if (ball_x < paddle_w&& ball_y >= paddle1_y && ball_y < paddle1_y + paddle_h){
			ball_vec_x = -ball_vec_x;
			score1 += 1;
		}
		else if(ball_x >WIDTH - paddle_w && ball_y >= paddle2_y && ball_y < paddle2_y + paddle_h) {
			ball_vec_x = -ball_vec_x;
			score2 += 1;
		}
		bool is_out{ false };
		if (ball_x < 0) {score2 += 1; is_out = true;		}
		else if (ball_x >WIDTH-paddle_w) {score1 += 1; is_out = true;	}
		if (is_out) {
			ball_x = WIDTH / 2; ball_y = HEIGHT / 2;
			ball_vec_x = rand() % 3 + 1;
			ball_vec_y = rand() % 3 + 1;
			if (rand() % 2 == 1) ball_vec_x = -ball_vec_x;
			if (rand() % 2 == 1) ball_vec_y = -ball_vec_y;
		}

		
		gotoxy(0, 0);
		hideCursor();
		// 3. ���Ƴ���
		std::string s1{ std::to_string(score1) }, s2{ std::to_string(score2) } ;
		//3.1���Ʊ���
		//3.1.1 �Ȼ��Ʊ����еĶ���ǽ	
		for(auto x = 0; x <= WIDTH; x++)
			std::cout << '=';
		std::cout << '\n';
		//3.1.2 ���Ʊ����е�3��������	
		for (auto y = 0; y <= HEIGHT; y++) {
			for (auto x = 0; x <= WIDTH; x++) {
				/*
				int  xdiff{ x - WIDTH/2 }, y_diff{ y - HEIGHT/2 },
					diff = xdiff * xdiff + y_diff * y_diff;
				if (abs(diff -pong_circle_r2)<2)
					std::cout << '|';
				else */
				if (ball_x == x && ball_y == y)
					std::cout << 'O';
				else if (y >= paddle1_y && y < paddle1_y + paddle_h
					&& x >= paddle1_x && x < paddle1_x + paddle_w) {
					std::cout << 'Z';
				}
				else if (y >= paddle2_y && y < paddle2_y + paddle_h
					&& x >= paddle2_x && x < paddle2_x + paddle_w) {
					std::cout << 'Z';
				}
				else if (y == score1_y && x == score1_x) {
					std::cout << s1;
					while (x < score1_x + s1.size()) x++;
					x--;
				}	
				else if (y == score2_y && x == score2_x) {
					std::cout << s2;
					while (x < score2_x + s2.size()) x++; 
					x--;
				}
				else if (x == 0 || x == WIDTH / 2 || x == WIDTH)
					std::cout << '|';
				else std::cout << ' ';
			}
			std::cout << '\n';
		}

		//3.1.3 ���Ʊ����еĵײ�ǽ	
		for (auto x = 0; x <= WIDTH; x++)
			std::cout << '=';
		std::cout << '\n';
	}
	return 0;
}