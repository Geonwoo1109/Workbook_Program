#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <list>
#include <windows.h>

#define MAX 10 //�ִ� ���� ���� 
#define file_txt "Questions.txt" //Ȯ���� ���� 

void get_Question(); int i, j, index, arr[10], Q_number = 5;
char *txt[10][100] = { NULL, }, Q_arr[MAX][100], A_arr[MAX][6][100], okSign;

std :: list<int> L;
std :: list<int> :: iterator p;

main() {
	
	srand(time(NULL));
	
	for (i=1; i<=Q_number; i++) {
		L.push_back(i);
	}
	
	for (p=L.begin(); p!=L.end(); p++) {
		printf("%d", *p);
	}
	
	index = rand() % Q_number;
	printf("\nindex: %d\n", index);
	
	for (i=1, p=L.begin(); i<index; i++) {
		p++;
	}
	L.erase(p);
	for (p=L.begin(); p!=L.end(); p++) {
		printf("%d", *p);
	}
	
	for (i=0; i<Q_number; i++) {
		printf("%d", arr[i]);
	}
	
	get_Question();
	printf("\nQ_number: %d\n", Q_number);
	p = L.begin();
    for (i=1; i<=Q_number; i++) {
    	
    	for (j=0; j<6; j++) {
    		printf("\n%s", txt[*p][j]);
		}
		p++;
	}
	return 0;
}

void get_Question() {
	FILE *Q_file = fopen(file_txt, "r");
	if (Q_file == NULL) return;
	
	fscanf(Q_file, "���� ����: %d", &Q_number);
    
    for (i=0; i<=Q_number; i++) {
    	char *str = fgets(Q_arr[i], 100, Q_file);
    	
    	char *ptr = strtok(Q_arr[i], ",");
    	for (j=0; j<10; j++) {
    		
    		if (ptr == NULL) break; // �ڸ� ���ڿ��� ������ ���� ������ �ݺ�
       		txt[i][j] = ptr;             // ���ڿ��� �ڸ� �� �޸� �ּҸ� ���ڿ� ������ �迭�� ����

        	ptr = strtok(NULL, ",");   // ���� ���ڿ��� �߶� �����͸� ��ȯ
    		
		}

	}

	//for (i=0; i<Q_number; i++) Q_index_list.push_back(i);
	fclose(Q_file);
}
