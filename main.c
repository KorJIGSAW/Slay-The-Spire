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
#include "game.h"

void StartGame() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetCursorVisible(0);
	int menucode;
	SetTitle(TEXT("Slay the Spire.exe")); //���� ���� �ذ�Ϸ�
	Music_Start();
MainMonitor:
	FirstDraw();
	menucode = MenuDraw();
	if (menucode == 3) { //���� ����
		//goto GameOver
		StopSound();
		Music_GameOver();
		GameOverDraw();
		Sleep(37000); //GameOver.mp3�� �뷡 ����ð� 37�ʵ��� ��� �� ����
		exit(1);
	}
	else if (menucode == 2) { //ī�� ��Ͻ���
		CardListDraw();
		SET_GREEN
		printf("R�� �����ø� ����ȭ������ ���ư��ϴ�.");
		SET_WHITE
		while (1) { //����ȭ������ ���ư���.
			if (kbhit())
			{
				char temp = getch();
				if (temp == 'R' || temp == 'r')
				{
					Music_Select();
					//system("cls");
					Clear();
					goto MainMonitor;
				}
			}
		}
	}
	else if (menucode == 1) { //���� �������
	Example1:
		PlayExampleDraw1(hConsole);
		while (1) {
			if (kbhit())
			{
				char temp = getch();
				if (temp == 'R' || temp == 'r') //����ȭ������ ���ư���.
				{
					Music_Select();
					//system("cls");
					Clear();
					goto MainMonitor;
				}
				else if (temp == 'N' || temp == 'n') { // ���� ���丮�� ����
					Music_Select();
					//system("cls");
					Clear();
					goto Example2;
					break;
				}
				else if (temp == 'D' || temp == 'd') { //�ڽ��� ī�嵦 Ȯ��
					Music_Select();
					//system("cls");
					Clear();
					break;
					//�ڽ��� ī�嵦 ����Ʈ�Լ�
				}
			}
		}
	Example2:
		PlayExampleDraw2(hConsole);
		while (1) {
			if (kbhit())
			{
				char temp = getch();
				if (temp == 'B' || temp == 'b') //����ȭ������ ���ư���.
				{
					Music_Select();
					//system("cls");
					Clear();
					goto Example1; //2��° ���� -> 1��° ���� ���ư���
					break;
				}
				else if (temp == 'R' || temp == 'r') //����ȭ������ ���ư���.
				{
					Music_Select();
					//system("cls");
					Clear();
					goto MainMonitor;
				}
				else if (temp == 'N' || temp == 'n') { // ���� ���丮�� ����
					Music_Select();
					//system("cls");
					Clear();
					goto Example3;
					break;
				}
				else if (temp == 'D' || temp == 'd') { //�ڽ��� ī�嵦 Ȯ��
					Music_Select();
					//system("cls");
					Clear();
					break;
					//�ڽ��� ī�嵦 ����Ʈ�Լ�
				}
			}
		}
	Example3:
		PlayExampleDraw3(hConsole); 
		while (1) {
			if (kbhit())
			{
				char temp = getch();
				if (temp == 'B' || temp == 'b'){ //����ȭ������ ���ư���
					Music_Select();
					//system("cls");
					Clear();
					goto Example2; //3��° ���� -> 2��° ���� ���ư���
					break;
				}
				else if (temp == 'R' || temp == 'r') //����ȭ������ ���ư���.
				{
					Music_Select();
					//system("cls");
					Clear();
					goto MainMonitor;
				}
				else if (temp == 'D' || temp == 'd') { //�ڽ��� ī�嵦 Ȯ��
					Music_Select();
					//system("cls");
					Clear();
					break;
					//�ڽ��� ī�嵦 ����Ʈ�Լ�
				}
			}
		}
	}
	else if (menucode == 0) { //���� ���۽���
		SetGame();
	}
}

int main() {
	//SetConsoleSize(120, 30);
	StartGame();
	
    Sleep(100000);
	//system("pause");
	Clear();
}