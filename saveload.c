#include "saveload.h"

void saveData(Schedule *s[], int count){
    FILE *fp;
     fp = fopen("product.txt", "wt");
     for(int i=0; i<count; i++){
                if(s[i] == NULL) continue;
                fprintf(fp,"%s %s %s %s %d\n", s[i]->Todo, s[i]->Schedule_name, s[i]->Date, s[i]->Due, s[i]->Importance);
        }
        fclose(fp);
        printf("저장됨!\n");
}


int loadData(Schedule *s[]){
        int count = 0;
        FILE *fp;
        fp = fopen("product.txt", "rt");
        if(fp == NULL){
                printf("=> 파일 없음\n");
                return 0;
        }
        else{ 
            for(int i=0; i< 100; i++){
                fscanf(fp,"%[^\n]s %s %[^\n]s %[^\n]s %d", s[i]->Todo, s[i]->Schedule_name, s[i]->Date, s[i]->Due, &s[i]->Importance);
                count++;
                if(feof(fp)){
                        break;
                }
            }
        }

        fclose(fp);
        printf("=>로딩 성공\n");
        return count;
}  // 전체 등록된 제품 리스트 출력



