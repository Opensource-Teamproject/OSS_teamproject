#include "saveload.h"

void saveData(Schedule *s[], int count){
    FILE *fp;
     fp = fopen("product.txt", "wt");
     for(int i=0; i<count; i++){
                if(s[i] == NULL) continue;
                fprintf(fp," %s %d %s %s %s\n", s[i]->Schedule_name, s[i]->Importance, s[i]->Todo, s[i]->Date, s[i]->Due);
        }
        fclose(fp);
        printf("저장됨!\n");
}

int loadData(Schedule *s[]){
        // int i =0;
        int count = 0;
        FILE *fp;
        fp = fopen("product.txt", "rt");
        if(fp == NULL){
                printf("=> 파일 없음\n");
                return 0;
        }
        for(; count < 100; count++){
                s[count] = (Schedule *)malloc(sizeof(Schedule));
                fscanf(fp," %s %d %[^\n]s %s %s", s[count]->Schedule_name, &s[count]->Importance, s[count]->Todo, s[count]->Date, s[count]->Due);
                // count++;
                if(feof(fp)){
                        break;
                }
        }

        fclose(fp);
        printf("=>로딩 성공\n");

        return count;
}