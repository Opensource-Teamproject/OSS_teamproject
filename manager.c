
//manager.c file
#include "manager.h"

void listSchedule(Schedule *s[], int count){
    printf("\n NO 이름 중요도 해야 할 일     시작날짜    종료날짜\n");
    printf("==========================================================\n");
    for(int i=0; i<count; i++){
        if(s[i] == NULL) continue;
        printf("%2d ", i+1);
        readSchedule(*s[i]);
    }
    printf("\n");
}      // 전체 등록된 제품 리스트 출력

void searchName(Schedule *s[], int count){
    int scnt = 0;
    char search[20];
    
    printf("검색할 이름은? ");
    scanf(" %s", search);

    printf("************************\n");

    for(int i=0; i<count; i++){
       if(s[i]==NULL) continue;  
            if(strstr(s[i]->Schedule_name, search)){
                printf("%2d ", i+1);
                readSchedule(*s[i]);
                scnt++;
            }
    }

    if(scnt == 0) {
        printf("=>검색된 데이터 없음!");
    }
    printf("\n");

}

void searchImportance(Schedule *s[], int count){
	int scnt = 0;
	int min=0, max=0;
	printf("검색할 중요도의 범위는?\n");
	printf("최소 중요도: ");
	scanf("%d", &min);
	printf("최대 중요도: ");
	scanf("%d", &max);
    printf("\n NO 이름 중요도 해야 할 일     시작날짜    종료날짜\n");
    printf("==========================================================\n");
	for(int i =0; i<count; i++){
		if(s[i]->Importance >= min && s[i]->Importance <= max){
			printf("%2d", i+1);
			readSchedule(*s[i]);
			printf("\n");
			scnt++;
		}
	}
	if(scnt == 0){
		printf("검색된 데이터 없음!\n");
	}
} 
