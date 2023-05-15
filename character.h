#ifndef CHARACTER_H
#define CHARACTER_H

typedef struct MyCharacter {
	int hp; //내 체력
	int power; //힘을 얻었을 때
	int shield; //내 방어도
}MyCharacter;

typedef struct EnemyCharacter {
	int hp;
	int power;
	int shield;
}EnemyCharacter;


#endif // !CHARACTER_H
