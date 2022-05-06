#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char Todo[100];
    char Schedule_name[20];  //맡은 사람 이름
    char Date[20];       //시작날짜
    char Due[20];        //종료날짜
    int Importance;              //중요도
} Schedule;
//함수 

int createSchedule(Schedule *s);                  // 일정을 추가하는 함수
void readSchedule(Schedule s);                    // 하나의 일정 출력 함수
int updateSchedule(Schedule *s);                  // 이미 추가된 일정을 수정하는 함수
int deleteSchedule(Schedule *s[], int count);     // 일정 삭제를 하기 위한 함수

void searchName(Schedule *s[], int count);    // 맡은사람 이름 검색
void searchImportance(Schedule *s[], int count);      // 중요도 범위 검색

void saveData(Schedule *s[], int count);         // 파일로 저장
int loadData(Schedule *s[]);                     // 파일 불러오기

void listSchedule(Schedule *s[], int count);      // 전체 등록된 스케줄 리스트 출력
int selectMenu();   //메뉴 선택
