#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <fmod.h> //���� ��� �������
#include "console.h" //ȭ������ ���
#include "character.h" //ĳ����, ���� ����â
#include "status.h" //��ü ����â
#include "card.h"
#include "draw.h"
#include "CSound.h" //���� ��� �������
#include "input.h" //�� �Է� ���

void StartGame() {
	SetCursorVisible(0);
	int menucode;
	SetTitle(TEXT("Slay the Spire.exe")); //���� ���� �ذ�Ϸ�
	Music_Start();
MainMonitor:
	FirstDraw();
	menucode = MenuDraw();
	if (menucode == 3) { //���� ����
		//goto GameOver
		Music_GameOver();
		GameOverDraw();
		Sleep(37000); //GameOver.mp3�� �뷡 ����ð� 37�ʵ��� ��� �� ����
		exit(1);
	}
	else if (menucode == 2) { //ī�� ��Ͻ���
		CardListDraw(); 
		printf("R�� �����ø� ����ȭ������ ���ư��ϴ�.");
		while (1) { //����ȭ������ ���ư���.
			if (_kbhit())
			{
				char temp = _getch();
				if (temp == 'R' || temp == 'r')
				{
					Music_Select();
					system("cls");
					goto MainMonitor;
				}
			}
		}
	}
	else if (menucode == 1) { //���� �������
		
		PlayExampleDraw();
		printf("R�� �����ø� ����ȭ������ ���ư��ϴ�.");
		while (1) { //����ȭ������ ���ư���.
			if (_kbhit())
			{
				char temp = _getch();
				if (temp == 'R' || temp == 'r')
				{
					Music_Select();
					system("cls");
					goto MainMonitor;
				}
			}
		}
	}
	else if (menucode == 0) { //���� ���۽���
		
	}
}

int main() {
	//SetConsoleSize(120, 30);
	StartGame();
	
    Sleep(100000);
	system("pause");
}