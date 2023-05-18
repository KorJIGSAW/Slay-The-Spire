#pragma once
#ifndef STATUS_H
#define STATUS_H
#include <stdio.h>

typedef struct status {
	int energy; //에너지
	int stair;  //층수
	int Non_Picked_Card; //뽑지 않은 카드
	int Picked_Card; //뽑은 카드
	int Turn_End;
};
// 현재 스텟을 표기하기 위한 창분리 위쪽 체력창칸 분리 등.

// 캐릭터 이름 표기 위치 지정, 프린트 함수

// 에너지 표기 위치 지정, 프린트 함수

// 층수 표기 위치 지정, 프린트 함수

// 뽑지않은 카드 표기 위치 지정, 프린트 함수

// 뽑은 카드 표기 위치 지정, 프린트 함수

// 턴엔드 표기 위치 지정, 프린트 함수


#endif // !STATUS_H
