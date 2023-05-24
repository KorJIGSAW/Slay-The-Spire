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
	int menucode;
	SetTitle("Slay the Spire"); //���ڷ� ��µȴ�.
	FirstDraw();
	Music_Start();
	menucode = MenuDraw();
	if (menucode == 3) { //���� ����
		//goto GameOver
		GameOverDraw();
		Sleep(37000); //GameOver.mp3�� �뷡 ����ð� 37�ʵ��� ��� �� ����
		exit(1);
	}
	else if (menucode == 2) { //ī�� ��Ͻ���
		CardListDraw();
	}
	else if (menucode == 1) { //���� �������
		PlayExampleDraw();
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