/*
	susigrazink Stats info is tu funkciju :+ (event, catch, woods)
*/

#include <stdio.h>

struct Stats {
	int dogs;
	char area[10];
};

int leash();
void player_stats(struct Stats player);
int woods(struct Stats player);
void street(struct Stats player);
void choice();
int event();
int catch (struct Stats player);

int main() {
	struct Stats player;
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

void player_stats(struct Stats player) {
	printf("Dogs:%d\tArea:%s\n", player.dogs, player.area);

}
int woods(struct Stats player) {
	strcpy(player.area, "woods");
	system("cls");
	player_stats(player);
	printf("you have entered area 'woods'\n");
	event(player);
	system("PAUSE");
	system("cls");
	player_stats(player);
}
void street(struct Stats player) {
	strcpy(player.area, "street");
	system("cls");
	player_stats(player);
	printf("you have entered area 'street'\n");
}
void choice() {
	printf("\nchoose an action:\n");
}
int event(struct Stats player) {
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
			catch(player);
			system("PAUSE");
			system("cls");
			player_stats(player);
			break;
		}
		if (c == 2) {
			system("cls");
			player_stats(player);
			printf("The dog ran away\n");
			break;
		}
	}
}
int catch (struct Stats player) {
	int a = 0;//rand() % 2;
	if (a == 1) {
		system("cls");
		printf("\nThe dog slipped away!\n");
	}
	else {
		player.dogs++;
		system("cls");
		player_stats(player);
		printf("\nYou got a new dog!\n");
		return ;
	}
}
