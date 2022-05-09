#include "schedule.h"
#include "manager.h"
#include "saveload.h"

int main(void){
    int count = 0, menu,result=0;
    int index=0;//데이터번호
    Schedule *fp[100];

    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if(menu==1||menu==3 ||menu==4)
            if(count==0) continue;

        if (menu == 1){
            if(count > 0)
                listSchedule(fp, index);
            else
                printf("데이터가 없습니다.\n");
        }
        else if (menu == 2){
            fp[index] = (Schedule *)malloc(sizeof(Schedule));
             count += createSchedule(fp[index++]);
        }
        else if (menu == 3){
            int no = selectDataNo(fp, index);
            if(no==0){
              printf("=> 취소됨!\n");
              continue;
            }
          updateSchedule(fp[no-1]);
        }
        else if (menu == 4){
            int no = deleteProduct(fp, index);
             int deleteok;
             printf("정말로 삭제하시겠습니까?(삭제 : 1)");
            scanf("%d", &deleteok);
            if(deleteok == 1){
                if(fp[no-1])
                    free(fp[no-1]);
                fp[no-1] = NULL;
                count --;
                printf("=> 삭제됨!\n");
            }
        }
        else if (menu ==5){
            int searchMenu;
			printf("어떤 것을 검색 하시겠습니까?\n1.이름 검색\n2.중요도 범위 검색\n\n");
			printf("번호를 고르세요");
			scanf("%d", &searchMenu);
			switch(searchMenu){
				case 1 : searchName(fp, index); break;
				case 2 : searchImportance(fp, index); break;
				default: break;
			}
        }
        else if (menu ==6){
            if(count ==0){
				printf("데이터가 없습니다!\n");
			}
			else{
				saveData(fp, index);
			}
        }
    }
    printf("종료됨!\n");
    return 0;
}