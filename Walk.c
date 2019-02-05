/* 
	WALKING A DOG 
	2019-02-05
*/

#include <stdio.h>

int main() {
	int dog;
	int n, c, t;

	printf("How many dogs do you have?\n");
	scanf_s("%d", &dog);
	if (dog > 10) {
		printf("Why do you have so many dogs?\n");
		system("PAUSE");
		main();
	}
	
	if (dog == 0 || dog < 0) {
		printf("You are out of dogs\n");
		printf("Would you like to try again? (1 for YES, 0 for NO)\n");
		scanf_s("%d", &t);
		if (t == 1) {
			main();
		}
		else {
			return 0;
		}
	}
	else {
		printf("Do you have a leash? (1 for YES, 0 for NO)\n");
		scanf_s("%d", &n);
		if (n == 0) {
			printf("Your dog ran away ;-; \n");
			printf("would you like to call your dog? (1 for YES, 0 for NO)\n");
			scanf_s("%d", &c);
			if (c == 0) {
				printf("You are out of dogs\n");
				printf("Would you like to try again? (1 for YES, 0 for NO)\n");
				scanf_s("%d", &t);
				if (t == 1) {
					main();
				}
				else {
					return 0;
				}

			}
			else {
				printf("You got your dog back\n");
			}
		}
		else
			printf("You succesfully walked your dog\n");
	}


	system("PAUSE");
	return 0;
}
