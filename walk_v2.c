/*
ANOTHER VERSION
*/

#include <stdio.h>

typedef struct {
	int dogs;
	char area[10];
}stats;

int leash();
void player_stats(stats player);
void woods(stats player);
void street(stats player);
void choice();
void event();

int main() {
	stats player;
	int c;
	player.dogs = 1;
	strcpy(player.area, "???");
	player_stats(player);

	printf("nothing is happening yet\n");
	printf("You are walking your dog.\n");
	printf("Choose the path:\n");
	printf("1 - woods\n");
	printf("2 - street\n");
	scanf_s("%d", &c);
	if (c == 1) {
		//woods part;
		woods(player);
	}
	else if (c == 2) {
		//street part;
		street(player);
	}
	else {
		printf("\nwrong input\n");
	}

	system("PAUSE");
	return 0;
}

void player_stats(stats player) {
	printf("Dogs:%d\tArea:%s\n", player.dogs, player.area);

}
void woods(stats player) {
	strcpy(player.area, "woods");
	system("cls");
	player_stats(player);
	printf("you have entered area 'woods'\n");
	event();
}
void street(stats player) {
	strcpy(player.area, "street");
	system("cls");
	player_stats(player);
	printf("you have entered area 'street'\n");
}
void choice() {
	printf("\nchoose an action:\n");
}
void event() {
	int e = rand() % 2;
	switch (e) {
	case 0:
		printf("Nothing happened\n");
		break;
	case 1:
		int c;
		printf("A stray dog crossed your path!\n");
		printf("What is your action?\n");
		printf("1 - catch\n");
		printf("2 - do nothing\n");
		scanf_s("%d", &c);
		if (c == 1) {
			printf("\nThe dog slipped away!\n");
		}
		if (c == 0) {
			break;
		}
	}
}
