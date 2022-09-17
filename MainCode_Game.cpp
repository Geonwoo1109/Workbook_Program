#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <list>
#include <windows.h>

#define MAX 10 //�ִ� ���� ���� 
//#define file_txt "Questions.txt" //Ȯ���� ���� 

char fileName[100], *txt[10][100] = { NULL, }, Q_arr[MAX][100], okSign;

int i, j, index, rand_num, rand_data[10], A_user, Num_correct, Q_number, Q_number_e, wNum, Q_wrong_arr[MAX];

std :: list<int> Q_index_list;
std :: list <int> :: iterator p;

void Reset();

void get_Question();
void gotoxy(int x, int y);
void giveQuestion();
void file_write();
void TheEnd();


int getList(int n);
int B_sort(int n, int arr[]);

main() {
	Reset();
	get_Question();
	
	giveQuestion();
	
	gotoxy(30, 10);
	Sleep(300);
	printf("���� ����: %d", Num_correct);
	
	gotoxy(30, 12);
	Sleep(300);
	printf("Ʋ�� ����: %d", Q_number_e - Num_correct);
	
	gotoxy(30, 14);
	Sleep(300);
	printf("Ʋ�� ����: ");
	
	
	B_sort(Q_number_e - Num_correct, Q_wrong_arr);
	for (i=0; i<Q_number_e - Num_correct; i++)
		printf("%d%s", Q_wrong_arr[i], i==Q_number_e-Num_correct-1 ? " ":", ");
		
	gotoxy(30, 18);
	Sleep(300);
	printf("Ʋ�� ������ �޸��� �����[y]: ");
	
	scanf("%s", &okSign);
	if (okSign == 'y') file_write();
	
	Sleep(1000);
	TheEnd();
		
}

void gotoxy(int x, int y) {
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

void Reset() {
	system("title Geonwoo's �������");
	system("mode con cols=100 lines=30");
	system("color F0");
	system("cls");
	
	gotoxy(37, 2);
	printf("--== �߱��� ��������! ==--");
	
	gotoxy(2, 28);
	printf("Made by Geonwoo_Kim");
	
	gotoxy(85, 28);
	printf("Version.1.0.0");
	
	gotoxy(42, 13);
	printf("���� ����:  ");
	
	gotoxy(35, 9);
	printf("���ϸ�(txt) -> ");
	
	gets(fileName);
}

void get_Question() {
	

	
	FILE *Q_file = fopen(strcat(fileName, ".txt"), "r");
	if (Q_file == NULL) return;
	
	fscanf(Q_file, "���� ����: %d", &Q_number);
    Q_number_e = Q_number;
    
    gotoxy(53, 13);
	printf("%d", Q_number);
	
    gotoxy(35, 20);
	printf("�ƹ� Ű�� ���� �����ϼ���");
	getchar();
	system("cls");
	
    for (i=0; i<=Q_number; i++) {
    	char *str = fgets(Q_arr[i], 100, Q_file);
    	
    	char *ptr = strtok(Q_arr[i], ",");
    	for (j=0; j<10; j++) {
    		
    		if (ptr == NULL) break;           // �ڸ� ���ڿ��� ������ ���� ������ �ݺ�
       		txt[i][j] = ptr;             // ���ڿ��� �ڸ� �� �޸� �ּҸ� ���ڿ� ������ �迭�� ����
        		

        	ptr = strtok(NULL, ",");   // ���� ���ڿ��� �߶� �����͸� ��ȯ
    		
		}

	}
	for (i=1; i<=Q_number; i++) Q_index_list.push_back(i);
	fclose(Q_file);
}



int getList(int n) {
	//printf("\n n: %d\n", n);
	p = Q_index_list.begin();
	for (i=1; i<n; i++) p++;
	//Q_index_list.erase(p);
	return *p;
}
void giveQuestion() { while(1) {
	srand(time(NULL));
	//system("cls");
	
	printf("���� ����: %d / %d\n\n", Q_number, Q_number_e);
	p = Q_index_list.begin();
	//for (p = Q_index_list.begin(); p != Q_index_list.end(); p++) printf("%d, ", *p);
	
	
	/*
	printf("\n");
	for (i=1; i<=100; i++) printf("%d", rand() % Q_number);
	*/
	
	//���� ��ȣ ���� 
	//for (i=0; i<5; i++) printf("%d, ", Q_index_arr[i]);
	
	rand_num = rand() % Q_number + 1;
    index = getList(rand_num);
	//printf("\nindex: %d\n", index);         //���ľ��� Q_index_arr
    printf("Q.%s\n\n", txt[index][0]);
    
    //�񺹿����� 
    srand(time(NULL));
    for (i=1; i<6; i++) {
    	
    	rand_data[i] = (rand() % 5) + 1;
    	for (int sub_i=0; sub_i<i; sub_i++) {
    		if (rand_data[i] == rand_data[sub_i]) {
    			i--;
    			break;
			}
		}
	}
	//for (i=1; i<=5; i++) printf("%d", rand_data[i]);
	for (i=1; i<=5; i++) printf("%d. %s\n", i, txt[index][rand_data[i]]);
	
	printf("\n\n");
	
	scanf("%d", &A_user);
	
	system("cls");
	gotoxy(45, 13);
	if (rand_data[A_user] == 1) {
		printf("�����Դϴ�!");
		Num_correct++;
	} else {
		printf("�����Դϴ�!");
		Q_wrong_arr[wNum] = index;
		wNum++;
	}
	Sleep(1000);
	system("cls");
	
	if (Q_number > 1) Q_number--;
	else return;
		
	p = Q_index_list.begin();
	for (i=1; i<rand_num; i++) {
			//printf("%d", i+100);
		p++;
			//printf("%d", i);
	}
		
		//printf("\n %d %s \n", *p, &p);
	Q_index_list.erase(p);
	
} }

int B_sort(int n, int arr[]) {
	int temp;
	for (i=0; i<n; i++) {
		for (j=0; j<n-1; j++) {
			if (arr[j] > arr[j+1]) {
            	temp = arr[j];
            	arr[j] = arr[j+1];
            	arr[j+1] = temp;
         	}
		}
	}
	return arr[n];
}

void file_write() {
	//printf("%s", fileName);
	FILE *fp = fopen(strcat(strtok(fileName, "."), "_r.txt"), "w");

    fprintf(fp, "���� ����: %d", Q_number_e - Num_correct);
    for (i=0; i<Q_number_e - Num_correct; i++) {
		fprintf(fp, "\n");
    	for (j=0; j<6; j++) {
    		fprintf(fp, "%s,", txt[Q_wrong_arr[i]][j]);
		}
		
	}
	
    fclose(fp);
}

void TheEnd() {
	printf("The End");
	/*
	for (i=30; i>2; i--) {
		printf("%c", (char)i);
		char temp[100] = "mode con cols=100 lines=";
		system( strcat(temp, i+'0') );
		Sleep(100);
	}
	
	for (i=100; i<2; i--) {
		//system( "mode con cols=%d lines=1", i );
	}
	*/
	/*
	system("cls");
	system("color F0");
	Sleep(1000);
	system("color 80");
	Sleep(1000);
	system("mode con cols=50 lines=15");
	system("color 00");
	Sleep(1000);
	system("mode con cols=25 lines=7");
	*/
}
















