/*#include"function.h"

void init() {

	//�öδ��빦�������ع�꣬������win32��̽ӿڣ�����Ҫ����
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ���ھ��
	CONSOLE_CURSOR_INFO cci;//ʵ�л�һ������̨�����Ϣ��
	GetConsoleCursorInfo(hOut, &cci);//��ȡ�����Ϣ
	cci.bVisible = FALSE;//���ع��
	SetConsoleCursorInfo(hOut, &cci);//���ù����Ϣ

	system("title ������1.0");//�趨��������
	system("mode con cols=120 lines=30");//�趨���ڴ�С
}
void mainloop() {
	int level;//��ǰ�ؿ�
	int level_option;//ѡ��Ĺؿ�
	int scenes;//����
	char option;//����ָ��
	int isEnd;//�Ƿ����

	//��ʼ������
	level = 0;//��ʼ����ǰ�ؿ�Ϊ��һ�أ���0���𣬷�ΧΪ0-maps_num��
	level_option = 1;//��ʼ��ѡ��ؿ�Ϊ��һ�أ���1����
	scenes = 0;//��ʼ������Ϊ������
	isEnd = 0;//��ʼ�������жϱ���Ϊ0��false��

	//���ƽ���
	//������
	char main_interface[50][50] = {
		"\n\n\n\n\n\n\n",
		"\t\t\t\t\t\t\t ������",
		"\t\t\t\t\t\t   |===============|",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |    ��ʼ(S)    |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |   �˳�(ESC)   |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |===============|",
	};

	//���˵�2
	char menu2[50][50] = {
		"\n\n\n\n\n\n\n\n",
		"\t\t\t\t\t\t\t ������\n",
		"\t\t\t\t\t\t   |===============|",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |   ��ͷ��ʼ(A) |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |    ѡ��(X)    |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |    ����(R)    |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |===============|"
	};
*/



#include"function.h"

void init() {

	//�öδ��빦�������ع�꣬������win32��̽ӿڣ�����Ҫ����
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ���ھ��
	CONSOLE_CURSOR_INFO cci;//ʵ�л�һ������̨�����Ϣ��
	GetConsoleCursorInfo(hOut, &cci);//��ȡ�����Ϣ
	cci.bVisible = FALSE;//���ع��
	SetConsoleCursorInfo(hOut, &cci);//���ù����Ϣ

	system("title ������1.0");//�趨��������
	system("mode con cols=120 lines=30");//�趨���ڴ�С
}

void mainloop() {

	//init

	char key = 0;

	int isEnd = 0;

	int scenes = 0;

	//������
	char main_interface[50][50] = {
		"\n\n\n\n\n\n\n",
		"\t\t\t\t\t\t\t ������",
		"\t\t\t\t\t\t   |===============|",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |    ��ʼ(S)    |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |   �˳�(ESC)   |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |===============|",
	};

	//���˵�2
	char menu2[50][50] = {
		"\n\n\n\n\n\n\n\n",
		"\t\t\t\t\t\t\t ������\n",
		"\t\t\t\t\t\t   |===============|",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |   ��ͷ��ʼ(A) |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |    ѡ��(X)    |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |    ����(ESC)  |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |===============|"
	};


	while (1)
	{

		//render
		system("cls");//�����Ļ
		switch (scenes)
		{
		case 0:
			for (int i = 0; i < 11; i++)
				puts(main_interface[i]);
			break;
		case 1:
			for (int i = 0; i < 11; i++)
				puts(menu2[i]);
			break;
		default:
			break;
		}


		//event
		key = getch();

		switch (scenes)
		{
		case 0:
			switch (key)
			{
			case 'S':
			case 's':
				scenes = 1;
				break;
			case 27:

				isEnd = 1;
				break;
			default:
				break;
			}
			break;
		case 1:
			switch (key)
			{
			case 'A':
			case 'a':
				gameloop(1);
				break;
			case 27:
				scenes = 0;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}


		//update
		switch (scenes)
		{
		case 0:

			break;
		case 1:

			break;
		default:
			break;
		}

		//delay

		//isend
		if (isEnd)
			break;
	}


	//clear

}


int gameloop(int level) {

	int x = 6;
	int y = 5;

	int aim_count = 4;
	int aimx[20] = {5,8,3,6};
	int aimy[20] = {2,4,5,7};

	//init

	char key = 0;

	int isEnd = 0;

	int scenes = 0;

	char maps[2][50][50] = { {
		"|==========|",
		"|== ### ===|",
		"|== #X# ===|",
		"|== # #### |",
		"| ###O OX# |",
		"| #X O@### |",
		"| ####O#== |",
		"|=== #X#== |",
		"|=== ###== |",
		"|==========|"
	},{
		"|=========|",
		"|#####====|",
		"|#@  #====|",
		"|# OO#=###|",
		"|# O #=#X#|",
		"|### ###X#|",
		"|=##    X#|",
		"|=#   #  #|",
		"|=#   ####|",
		"|=#####===|",
		"|=========|"
	} };

	char map[50][50];

	for (int i = 0; i < 50; i++)
		for (int j = 0; j < 50; j++)
			map[i][j] = maps[0][i][j];

	while (1)
	{

		//render
		system("cls");//�����Ļ
		switch (scenes)
		{
		case 0:
			for (int i = 0; i < 10; i++)
				puts(map[i]);
			break;
		case 1:
			printf("good game!\n�Ƿ�Ҫ������һ�أ�\n\t��");
			printf("");
			break;
		default:
			break;
		}

		system("cls");//�����Ļ
		switch (scenes)
		{
		case 0:
			for (int i = 0; i < 10; i++)
				puts(map[i]);
			break;
		case 1:
			printf("good game!");
			break;
		default:
			break;
		}

		//event
		key = getch();

		switch (scenes)
		{
		case 0:
			switch (key)
			{
			case 'W':
			case 'w':
				switch (map[y - 1][x])
				{
				case ' ':
				case 'X':
					map[y - 1][x] = '@';
					map[y][x] = ' ';
					y = y - 1;
					break;
				case 'O':
				case 'Q':
					if (map[y - 2][x] != '#'&&map[y - 2][x] != 'O'&&map[y - 2][x] != 'Q') {
						if(map[y - 2][x] == 'X')
							map[y - 2][x] = 'Q';
						else
							map[y - 2][x] = 'O';
						map[y - 1][x] = '@';
						map[y][x] = ' ';
						y = y - 1;
					}
					break;
				default:
					break;
				}

				break;
			case 'S':
			case 's':

				switch (map[y + 1][x])
				{
				case ' ':
				case 'X':
					map[y + 1][x] = '@';
					map[y][x] = ' ';
					y = y + 1;
					break;
				case 'O':
				case 'Q':
					if (map[y + 2][x] != '#'&&map[y + 2][x] != 'O'&&map[y + 2][x] != 'Q') {
						if (map[y + 2][x] == 'X')
							map[y + 2][x] = 'Q';
						else
							map[y + 2][x] = 'O';

						map[y + 1][x] = '@';
						map[y][x] = ' ';
						y = y + 1;
					}
					break;
				default:
					break;
				}

				break;
			case 'A':
			case 'a':
				switch (map[y][x - 1])
				{
				case ' ':
				case 'X':
					map[y][x - 1] = '@';
					map[y][x] = ' ';
					x = x - 1;
					break;
				case 'O':
				case 'Q':
					if (map[y][x - 2] != '#'&&map[y][x - 2] != 'O'&&map[y][x - 2] != 'Q') {
						if (map[y][x-2] == 'X')
							map[y][x-2] = 'Q';
						else
							map[y][x-2] = 'O';
						map[y][x - 1] = '@';
						map[y][x] = ' ';
						x = x - 1;
					}
					break;
				default:
					break;
				}

				break;
			case 'D':
			case 'd':
				switch (map[y][x + 1])
				{
				case ' ':
				case 'X':
					map[y][x + 1] = '@';
					map[y][x] = ' ';
					x = x + 1;
					break;
				case 'O':
				case 'Q':
					if (map[y][x + 2] != '#'&&map[y][x + 2] != 'O'&&map[y][x + 2] != 'Q') {
						if (map[y][x + 2] == 'X')
							map[y][x + 2] = 'Q';
						else
							map[y][x + 2] = 'O';
						map[y][x + 1] = '@';
						map[y][x] = ' ';
						x = x + 1;
					}
					break;
				default:
					break;
				}
				break;
			case 27:

				isEnd = 1;
				break;
			default:
				break;
			}
			break;
		case 1:
			switch (key)
			{
			case 'R':
			case'r':
				x = 6;
				y = 5;
				scenes = 0;

				for (int i = 0; i < 50; i++)
					for (int j = 0; j < 50; j++)
						map[i][j] = maps[0][i][j];

				break;
			case 'N':
			case 'n':
				x = 2;
				y = 2;
				scenes = 0;
				aim_count = 3;
				aimx[0]=8;
				aimy[0]=4;
				aimx[1] = 8;
				aimy[1] = 5;
				aimx[2] = 8;
				aimy[2] = 6;
				for (int i = 0; i < 50; i++)
					for (int j = 0; j < 50; j++)
						map[i][j] = maps[1][i][j];

				break;

			case 27:
				isEnd=1;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}


		//update
		int isOver = 1;
		switch (scenes)
		{
		case 0:


			for (int i = 0; i < aim_count; i++) {
				if (map[aimy[i]][aimx[i]] != 'O'&&map[aimy[i]][aimx[i]] != 'Q')
					isOver = 0;
			}
			if (isOver)
				scenes = 1;

			for (int i = 0; i < aim_count; i++) {
				if (map[aimy[i]][aimx[i]] == ' ')
					map[aimy[i]][aimx[i]] = 'X';
			}

			break;
		case 1:

			break;
		default:
			break;
		}

		//delay

		//isend
		if (isEnd)
			break;
	}


	//clear


	
}
/*
//�����ⲿ�ļ���C���ԵĽṹ�壩
struct Map* LoadMap(int level) {

	struct Map temp;
	char buff[256];

	FILE *fp;
	sprintf(buffer, "data/Map/%d.txt", level);
	fp = fopen(buffer, "r");


	for (int;;) {

	}

}
*/

//�ҵ�
/*
char maps[2][50][50] = { {
"|==========|",
"|== ### ===|",
"|== #X# ===|",
"|== # #### |",
"| ###O OX# |",
"| #X O@### |",
"| ####O#== |",
"|=== #X#== |",
"|=== ###== |",
"||=========|"
}
{
"|==========|",
"|== ### ===|",
"|== #X# ===|",
"|== # #### |",
"| ###O OX# |",
"| #X O@### |",
"| ####O#== |",
"|=== #X#== |",
"|=== ###== |",
"|==========|"
}
//event
key - getch();




//�����ƶ�
switch (sense) {
	case'W':
	case'w':
		if (map[y - 1][x] == ' ') {
			map[y - 1][x] = '@';
			map[y][x] = ' ';
			y = y - 1;
		}
		break;
	case'S':
	case's':
		if (map[y + 1][x] == ' ') {
			map[y + 1][x] = '@';
			map[y][x] = ' ';
			y = y + 1;
		
}

	...

//�ƶ����ӵķ���

switch (map[y - 1][x]) {
case' ':
	map[y - 1][x] = '@';
	map[y][x] = ' ';
	y = y - 1;
	break;
case'0':
	if (map[y - 2][x] != '#'&&map[y - 2][x] != '0') {
		map[y - 2][x] = '0';
		map[y - 1][x] = '@';
		map[y][x] = ' ';
		y = y - 1;
	}
	break;
default:
	break;
}


//�жϹ�������
	int aimx[] = { 5,8,4,6 };
	int aimy[] = { 2,4,5,7 };



	*/
