#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "schedule.h"



int createSchedule(Schedule *s){
    printf("해야 할 일정을 입력해주세요! ");
    scanf("%s", s->Todo);
    printf("작성자의 이름을 입력해주세요! ");
    scanf("%s", s->Schedule_name);
    printf("시작 날짜는 언제입니까? (20XX XX XX 형식으로) ");
    scanf("%s", s->Date);
    printf("종료 날짜는 언제입니까? (20XX XX XX 형식으로)");
    scanf("%s", s->Due);
    printf("중요도는? (1~5 범위)");
    scanf("%d", &s->Importance);
    printf("=>추가됨!");
    return 1;
}

void readSchedule(Schedule s){

    printf ("%20s %8s %8s %8s %d\n", s.Todo, s.Schedule_name,s.Date, s.Due,s.Importance);

}

int updateProduct(Schedule *s){
    printf("업데이트 할 일정을 입력해주세요! ");
    scanf("%s", s->Todo);
    printf("업데이트 한 작성자의 이름을 입력해주세요! ");
    scanf("%s", s->Schedule_name);
    printf("<Update>시작 날짜는 언제입니까? (20XX XX XX 형식으로) ");
    scanf("%s", s->Date);
    printf("<Update>종료 날짜는 언제입니까? (20XX XX XX 형식으로)");
    scanf("%s", s->Due);
    printf("중요도는? (1~5 범위)");
    scanf("%d", &s->Importance);
    printf("=> 수정성공!\n");
    return 1;
}

int selectDataNo(Schedule *s, int count){
  int no;
  listProduct(s,count);
  printf("번호는 (취소 :0)? ");
  scanf("%d", &no);
  return no;

}

int deleteProduct(Schedule *s){
    int i;

    s->Importance=-1;

    return 1;
}


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

int main(void){
    Schedule slist[50];
    int count = 0, menu,result=0;
    int index=0;//데이터번호



    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if(menu==1||menu==3 ||menu==4)
            if(count==0) continue;
        if (menu == 1){
            listSchedule(slist,index);
        }
        else if (menu == 2){
             count += createSchedule(&slist[index++]);
        }
        else if (menu == 3){
            int no = selectDataNo(slist, index);
            if(no==0){
              printf("=> 취소됨!\n");
              continue;
            }
          updateSchedule(&slist[no-1]);
        }
        else if (menu == 4){
            int no =selectDataNo(slist, index);
            if(no==0){
              printf("=>취소됨");
              continue;
            }
          int deleteok;
          printf("정말로 삭제하시겠습니까?(삭제 :1)");
          scanf("%d", &deleteok);
          if(deleteok ==1){
            if(deleteSchedule(&slist[no-1]))
             count--;
          }
          printf("=> 삭제됨\n");
            count--;
            
        }
        else if (menu ==5){
            searchName(slist , index);
        }
        else if (menu ==6){
            saveData(slist , index);
        }
    }
    printf("종료됨!\n");
    return 0;
}
    

