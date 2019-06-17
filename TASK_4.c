#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct client{
	char name[10];
	char surname[10];
	char address[50];
	struct client *next;
};


struct client *New_client(struct client *start) {
	struct client *new_client, *ptr;
	//User data input
	char name[10];
	char surname[10];
	char address[50];
	printf("\nEnter your first name: \n");
	scanf("%s", &name);

	printf("\nEnter your surname: \n");
	scanf("%s", &surname);

    printf("\nEnter your address: \n");
	scanf("%s", &address);


    new_client = (struct client*)malloc(sizeof(struct client));
    strcpy(new_client->name, name);
    strcpy(new_client->surname, surname);
    strcpy(new_client->address, address);
    if (start == NULL) {
        new_client->next = NULL;
        start = new_client;
    }
    else {
        ptr = start;
        while (ptr->next != NULL) ptr = ptr->next;
        ptr->next = new_client;
        new_client->next = NULL;
    }

	return start;
}

struct client *sort_by_name(struct client *start) {
	struct client *ptr1, *ptr2;
	char temp_name[50];
	char temp_surname[50];
	char temp_address[50];
	ptr1 = start;
	while (ptr1->next != NULL) {
		ptr2 = ptr1->next;
		while (ptr2 != NULL) {
			if (ptr1->name < ptr2->name) {
                //switch names
				strcpy(temp_name, ptr1->name);
				strcpy(ptr1->name, ptr2->name);
				strcpy(ptr2->name, temp_name);
                //switch surnames
                strcpy(temp_surname, ptr1->surname);
				strcpy(ptr1->surname, ptr2->surname);
				strcpy(ptr2->surname, temp_surname);
				//switch addresses
				strcpy(temp_address, ptr1->address);
				strcpy(ptr1->address, ptr2->address);
				strcpy(ptr2->address, temp_address);
			}
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
	return start;
}

void search_keyword(struct client *start){
    struct client *ptr;
    int a, b, c;
    char keyword[50];
    ptr = start;
    printf("\nEnter the keyword: ");
    scanf("%s", &keyword);

    while (ptr!= NULL){
        a = strcmp(ptr->name, keyword);
        b = strcmp(ptr->surname, keyword);
        c = strcmp(ptr->address, keyword);
        if (a == 0 || b == 0 || c == 0){
            printf("\nname: %s", ptr->name);
            printf(" surname: %s", ptr->surname);
            printf(" address: %s", ptr->address);
            ptr = ptr->next;
        }
        else{
            ptr = ptr->next;
        }
    }
};

void display(struct client *start) {
	struct client *ptr;
	ptr = start;
	while (ptr != NULL) {
		printf("\nname: %s", ptr->name);
		printf(" %s", ptr->surname);
		printf("  address: %s", ptr->address);
		ptr = ptr->next;
	}
}


void menu_text(){
    printf("Choose an option:\n");
    printf("1 - New client\n");
    printf("2 - Show client list\n");
    printf("3 - Sort by name\n");
    printf("4 - Search by keyword\n");
    printf("5 - Exit\n");
}
void menu(){
    int choice;
    menu_text();
    int running = 1;
    struct client *start = NULL;

    do{
        printf("\nInput: ");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            start = New_client(start);
            break;
        case 2:
            display(start);
            break;
        case 3:
            start = sort_by_name(start);
            display(start);
            break;
        case 4:
            search_keyword(start);
            break;
        case 5:
            running = 0;
            break;
        }
    }while(running);

}

int main() {

    menu();

	return 0;
}
