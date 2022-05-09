#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "schedule.h"


int selectMenu(){
    int menu;
    printf("\n*** 할 일을 고르세요 ***\n");
    printf("1. 일정 조회하기\n");
    printf("2. 일정 추가하기\n");
    printf("3. 일정 수정하기\n");
    printf("4. 일정 삭제하기\n");
    printf("5. 이름으로 일정 검색\n");
    printf("6. 데이터 저장하기\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}


int createSchedule(Schedule *s){
    printf("해야 할 일정을 입력해주세요! ");
    scanf(" %[^\n]s", s->Todo);
    printf("작성자의 이름을 입력해주세요! ");
    scanf(" %s", s->Schedule_name);
    printf("시작 날짜는 언제입니까? (20XX XX XX 형식으로) ");
    scanf(" %[^\n]s", s->Date);
    printf("종료 날짜는 언제입니까? (20XX XX XX 형식으로) ");
    scanf(" %[^\n]s", s->Due);
    printf("중요도는? (1~5 범위) ");
    scanf("%d", &s->Importance);
    printf("\n=>추가됨!");
    return 1;
}

void readSchedule(Schedule s){

    printf ("%20s %8s %8s %8s %d\n", s.Todo, s.Schedule_name,s.Date, s.Due,s.Importance);

}

int updateSchedule(Schedule *s){
    printf("업데이트 할 일정을 입력해주세요! ");
    scanf(" %[^\n]s", s->Todo);
    printf("업데이트 한 작성자의 이름을 입력해주세요! ");
    scanf(" %s", s->Schedule_name);
    printf("<Update>시작 날짜는 언제입니까? (20XX XX XX 형식으로) ");
    scanf(" %[^\n]s", s->Date);
    printf("<Update>종료 날짜는 언제입니까? (20XX XX XX 형식으로)");
    scanf(" %[^\n]s", s->Due);
    printf("중요도는? (1~5 범위)");
    scanf("%d", &s->Importance);
    printf("=> 수정성공!\n");
    return 1;
}


int deleteSchedule(Schedule *s[], int count){
    int no;
    listSchedule(s, count);
    printf("번호는 (취소:0)? ");
    scanf("%d", &no);
    return no;
}


