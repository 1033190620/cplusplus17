/* ----------hwdong�Ľ�ѧ��Դ---------------
   ��ѧ���ͣ�https://hwdong.net
   youtubeƵ���� hwdong
   twitter�� hwdong
   Bվ��΢����hw-dong
   qqȺ��101132160
   ΢�Ź��ںţ�hwdong���
   C++17�����ŵ���ͨ��Դ���룩��https://github.com/hwdong-net/cplusplus17
*/

#include <iostream>
using color = char;  //����һ����ʾ��ɫ��color���ͣ�ÿ���ַ�����һ����ɫ
color* framebuffer{ nullptr };          //֡������
int framebuffer_width, framebuffer_height;
color clear_color{ ' ' };                //������ɫ  

bool initWindow(int width, int height);  //��ʼ��һ�����ڣ�����boolֵ��ʾ�ɹ�����ʧ��
void clearWindow();               //��մ�������
void destoryWindow();             //���ٴ��ڣ��ͷ�֡������ռ�õ��ڴ�
void show();                      //��ʾ֡��������ͼ��
void setPixel(const int x, const int y, color c = ' ');            //�������ص���ɫ
color getPixel(const int x, const int y);                       //�������ص���ɫ
void set_clear_color(color c) { clear_color = c; }
color get_clear_color() { return clear_color; }

//��ʼ��һ�����ڣ�����boolֵ��ʾ�ɹ�����ʧ��
bool initWindow(int width, int height) {

	framebuffer = new color[width*height];
	if (!framebuffer) return false;
	framebuffer_width = width;
	framebuffer_height = height;
	clearWindow();
	return true;
}

//��������ɫclear_color��մ�������
void clearWindow() {
	if (!framebuffer) return;
	for (int y = 0; y < framebuffer_height; y++)
		for (int x = 0; x < framebuffer_width; x++)
			framebuffer[y*framebuffer_width + x] = clear_color;

}

//���ٴ��ڣ��ͷ�֡������ռ�õ��ڴ�
void destoryWindow() {
	if (!framebuffer)return;
	delete[] framebuffer;
	framebuffer = nullptr;
}

//��ʾ֡��������ͼ��
void show() {
	for (int y = 0; y < framebuffer_height; y++) {
		for (int x = 0; x < framebuffer_width; x++)
			std::cout << framebuffer[y*framebuffer_width + x];
		std::cout << '\n';
	}
}

void setPixel(const int x, const int y, color c) {
	framebuffer[y*framebuffer_width + x] = c;
}

color getPixel(const int x, const int y) {
	return framebuffer[y*framebuffer_width + x];
}


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <string>

//1. ��ʼ����Ϸ�е�����
int ball_x, ball_y, ball_vec_x{0}, ball_vec_y{ 0 }; //��λ�ú��ٶ�
int paddle_w, paddle_h;   //����ĳ���
int paddle1_x, paddle1_y, paddle1_vec{0}; //�󵲰�λ�ú��ٶ�
int paddle2_x, paddle2_y, paddle2_vec{0};       //�ҵ���λ�ú��ٶ�
int score1{ 0 }, score2{0}, score1_x, score1_y, score2_x, score2_y; //�÷ּ��÷ֵ���ʾλ��
color boundary_color{'|'}, ball_color{ 'O' }, wall_color{ '=' }, paddle_color{ 'Z' };

//��ʼ�����λ�ú��ٶ�
void random_ball(const int window_width, const int window_height) {
	ball_x = window_width / 2; ball_y = window_height / 2;
	ball_vec_x = rand() % 3 + 1;    //����һ�����������ʾ��ĺ����ٶ�
	ball_vec_y = rand() % 3 + 1;    //����һ�����������ʾ��������ٶ�
	if (rand() % 2 == 1) ball_vec_x = -ball_vec_x;  //�ٶȿ���ʹ����
	if (rand() % 2 == 1) ball_vec_y = -ball_vec_y;  //�ٶȿ���ʹ����
}



bool init(const int window_width=100,const int window_height=40){
	if (!initWindow(window_width, window_height)) {  // ��ʼ������
		return false;
	}	
	
	ball_x = window_width / 2;
	ball_y = window_height / 2; 

	paddle_w = 4; paddle_h = 10;
	paddle1_x = 0; paddle1_y = window_height / 2 - paddle_h / 2;	
	paddle2_x = window_width - paddle_w; paddle2_y = paddle1_y;
	paddle1_vec = 3;  paddle2_vec = 3 ;

	score1 = 0; score2 = 0; 
	score1_x = paddle_w + 8;           score1_y = 2;
	score2_x = window_width - 8 - paddle_w; score2_y=2;
//	auto pong_circle_r2{ 40 };  //�����뾶��ƽ��
	
	srand((unsigned)time(0));  //�������������
	random_ball(window_width, window_height);
	return true;
}

//���Ʊ���:��������ǽ�ڡ����ҹ������м�ָ���

void draw_background() {
	clearWindow();               //���Ϊ������ɫ	

	int &window_width = framebuffer_width,
		&window_height = framebuffer_height;

	auto right{ window_width - 1 }, middle{ window_width / 2 };
	for (int y = 0; y < window_height; y++) {
		setPixel(0, y, boundary_color);	
		setPixel(middle, y, boundary_color);
		setPixel(right, y, boundary_color);
	}

	int bottom = window_height - 1;	
	for (int x = 0; x < window_width; x++) {
		setPixel(x,0, wall_color);
		setPixel(x,bottom,wall_color);		
	}
}

//draw_sprites()���Ƴ����еľ��飺�򡢵���͵÷֡�
void draw_sprites() {	
	//������
	setPixel(ball_x, ball_y, ball_color);	
	//�������ҵ���
	for (auto y = paddle1_y; y < paddle1_y + paddle_h; y++)
		for (auto x = paddle1_x; x < paddle1_x + paddle_w; x++)
			setPixel(x,y, paddle_color);	

	for (auto y = paddle2_y; y < paddle2_y + paddle_h; y++)
		for (auto x = paddle2_x; x < paddle2_x + paddle_w; x++)
			setPixel(x,y, paddle_color);
			
	//���Ʒ�����������һ���ַ���
	std::string s1{ std::to_string(score1) }, s2{ std::to_string(score2) };
	for (auto i = 0; i < s1.size(); i++)
		setPixel(score1_x + i, score1_y, s1[i]);
	for (auto i = 0; i < s2.size(); i++)
		setPixel(score2_x + i, score2_y, s2[i]);		
}


void gotoxy(int x, int y) {
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void hideCursor() {
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void render_scene() {
	gotoxy(0, 0);  //��λ��(0,0)���൱�������Ļ
	hideCursor();  //���ع��
	draw_background();   //�ڻ����ϻ��Ʊ���
	draw_sprites();        //�ڻ����ϻ��ƾ���
	show();              //����Ļ����ʾ�������ݣ�������
}

int processInput() {	
	int &height = framebuffer_height;
	//  �����¼�
	char key;
	if (_kbhit()) {
		key = _getch();
		if (key == 27) return -1;
		else if ((key == 'w' || key == 'W') && paddle1_y > paddle1_vec)
			paddle1_y -= paddle1_vec;
		else if ((key == 's' || key == 'S') && paddle1_y + paddle1_vec + paddle_h
			< height)
			paddle1_y += paddle1_vec;
		else if (key == 72 && paddle2_y > paddle2_vec)
			paddle2_y -= paddle2_vec;
		else if ((key == 80) && paddle2_y + paddle2_vec + paddle_h < height)
			paddle2_y += paddle2_vec;
	}
	return 0;
}

void update() {
	int &width = framebuffer_width;
	int &height = framebuffer_height;
	// 2. �������� 
	ball_x += ball_vec_x;
	ball_y += ball_vec_y;
	if (ball_y < 0 || ball_y >= height) {
		ball_vec_y = -ball_vec_y;
		ball_y += ball_vec_y;
	}
	if (ball_x < paddle_w&& ball_y >= paddle1_y && ball_y < paddle1_y + paddle_h) {
		ball_vec_x = -ball_vec_x;
		score1 += 1;
	}
	else if (ball_x > width - paddle_w && ball_y >= paddle2_y && ball_y < paddle2_y + paddle_h) {
		ball_vec_x = -ball_vec_x;
		score2 += 1;
	}
	bool is_out{ false };
	if (ball_x < 0) { score2 += 1; is_out = true; }
	else if (ball_x >= width) { score1 += 1; is_out = true; }
	if (is_out) {
		random_ball(width,height);
	}
}


//���Ա�дһ���򵥵ĺ�������һ�¡�
int Pong() {
	if (!init()) {
		std::cout << "��ʼ������ʧ�ܣ�\n";
		return 1; 
	}
	//2.  ��Ϸѭ��
	while (true) {
		if (processInput() < 0)break;
		update();
		render_scene();
	}
	return 0;
}

