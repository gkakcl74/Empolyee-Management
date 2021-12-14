
/* 2021-12-14 , 제대로 실행되는거 확인했습니다. 코딩이 비효율적이라 첫 로딩에 살짝 시간이 걸립니다.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>


int count = 0;
typedef struct sawon {
	int staff_no = 0;
	char name[10];
	char dep[20];
    int pfc1;
    int pfc2;
    int pfc3;
    int pfc4;
    int tot = 0;
    int rank;
}sawon;
sawon saw[200], sil[200], temp;

void menu();

void rank() { // 순위
    for (int i = 0; i < count; i++) {
        saw[i].rank = 1;
        for (int j = 0; j < count; j++) {
            if (saw[i].tot < saw[j].tot) {
                saw[i].rank++;
            }
        }
    }
}

void no_sort() { // 사번정렬
    for (int i = 0; i < count; i++) {
        for (int j = i+1; j < count; j++) {
            if (saw[i].staff_no > saw[j].staff_no) {
                temp = saw[i];
                saw[i] = saw[j];
                saw[j] = temp;
            }
        }
    }
}

void line(int cnt, char a) {
    for (int i = 0; i < cnt; i++) {
        printf("%c", a);
    }
    printf("\n");
}

///**************************************
//*              사원등록               *
//**************************************/

void member_input(){
    int i, cnt=0, check=0, key;
    
    while (1){
        system("cls");
        printf("\t사원등록\n\n");
        printf("\t%d번째 사원입니다\n\n.", count + 1);

        check = 0;
        printf("\t사원번호: ");
        scanf("%d", &saw[count].staff_no);

        while (check < count) {
            for (i = 0; i < count; i++) {
                if (saw[count].staff_no == saw[i].staff_no && count != i) {
                    cnt++;
                }
            }
            check++;
        }
        if (cnt != 0) {
            printf("\n\t이미 등록된 사번입니다.\n\n");
            cnt = 0;
            printf("\t계속하시겠습니까?(0: 종료)");
            scanf("%d", &key);

            if (key == 0) {
                return;
            }
            else
                system("cls");
            continue;
        }

        printf("\t성명: ");
        scanf("%s", &saw[count].name);
        printf("\t부서명: ");
        scanf("%s", &saw[count].dep);
        count++;

        printf("\n\n\t계속하시겠습니까?(0: 종료)");
        scanf("%d", &key);

        if (key == 0) {
            return;
        }
        else
            continue;
    }
}

///**************************************
//*              전체조회               *
//**************************************/


void search_all() {

    int anykey, tot1 = 0, tot2 = 0, tot3 = 0, tot4 = 0, totking = 0, key, i, j;
    system("cls");
    no_sort();

    if (count == 0) {
        printf("\t데이터가 없습니다.\n\n");
        system("pause");
        return;
    }
    line(80, '=');
    printf("사번\t성명\t부서\t1분기\t2분기\t3분기\t4분기\t합계\t순위\n");
    line(80, '-');

    for (i = 0; i < count; i++) {
        saw[i].tot = saw[i].pfc1 + saw[i].pfc2 + saw[i].pfc3 + saw[i].pfc4;
    }
    rank();
    for (i = 0; i < count; i++) {
        
        if (saw[i].tot == 0) {
            printf("%2d\t%s\t%s\t*****실 적 없 음", saw[i].staff_no, saw[i].name, saw[i].dep);
            printf("\n");
        }
        else {
            printf("%d\t%s\t%s\t%2d\t%2d\t%2d\t%2d\t%2d\t", saw[i].staff_no, saw[i].name, saw[i].dep,
                saw[i].pfc1, saw[i].pfc2, saw[i].pfc3, saw[i].pfc4, saw[i].tot);
            printf("%2d", saw[i].rank);
            printf("\n");
        }

        tot1 += saw[i].pfc1;
        tot2 += saw[i].pfc2;
        tot3 += saw[i].pfc3;
        tot4 += saw[i].pfc4;
    }
    totking = tot1 + tot2 + tot3 + tot4;

    line(80, '-');
    printf("\n");
    printf("분기합계\t\t%2d\t%2d\t%2d\t%2d\t%2d", tot1, tot2, tot3, tot4, totking);
    printf("\n");
    line(80, '-');
    printf("\n");

    key:;
    printf("순위소트:1, 종료:0...[ ]\b\b");
    scanf("%d", &key);

    if (key == 1) {
        system("cls");

        for (i = 0; i < count; i++) {
            for (j = 0; j < count; j++) {
                if (saw[i].tot > saw[j].tot) {
                    temp = saw[j];
                    saw[j] = saw[i];
                    saw[i] = temp;
                }
            }
        }
        printf("\n\n");
        line(80, '=');
        printf("사번\t성명\t부서\t1분기\t2분기\t3분기\t4분기\t합계\t순위\n");
        line(80, '-');
        printf("\n");
        for (i = 0; i < count; i++) {
            if (saw[i].tot == 0) {
                printf("%2d\t%s\t%s\t*****실 적 없 음", saw[i].staff_no, saw[i].name, saw[i].dep);
                printf("\n");
            }
            else {
                printf("%d\t%s\t%s\t%2d\t%2d\t%2d\t%2d\t%2d\t%2d", saw[i].staff_no, saw[i].name, saw[i].dep,
                    saw[i].pfc1, saw[i].pfc2, saw[i].pfc3, saw[i].pfc4, saw[i].tot, saw[i].rank);
                printf("\n");
            }
        }
        line(80, '-');
        printf("\n");
        printf("분기합계\t\t%2d\t%2d\t%2d\t%2d\t%2d", tot1, tot2, tot3, tot4, totking);
        printf("\n");
        line(80, '-');
        printf("\n");

        system("pause");
    }else if(key == 0) {
        return;
    }
    else {
        printf("\t다시 입력해주세요  ");
        goto key;
    }
}

///**************************************
//*              실적입력               *
//**************************************/

void performance_input() {

    int i, cnt = 0, no_key, key;
first:;
    while (1) {
        system("cls");
        printf("\t실적등록\n\n");
        
        while (1) {
            printf("\t사원번호: ");
            scanf("%d", &no_key);

            for (i = 0; i < count; i++) {
                if (saw[i].staff_no == no_key && saw[i].tot != 0) {
                    printf("이미 실적이 등록된 사원 입니다.\n\n");
                    goto how;
                }

                if (saw[i].staff_no == no_key) {
                    cnt++;
                    printf("\n\t성명: %s\t부서: %s\n\n", saw[i].name, saw[i].dep);
                    break;
                }
            }
            if (cnt != 0) {
                printf("\t1분기: ");
                scanf("%d", &saw[i].pfc1);
                printf("\t2분기: ");
                scanf("%d", &saw[i].pfc2);
                printf("\t3분기: ");
                scanf("%d", &saw[i].pfc3);
                printf("\t4분기: ");
                scanf("%d", &saw[i].pfc4);
                saw[i].tot = saw[i].pfc1 + saw[i].pfc2 + saw[i].pfc3 + saw[i].pfc4;
                break;
            }
            else {
                printf("\n\t%d 는 등록되지 않은 사원번호 입니다.\n\n", no_key);
                printf("\t계속하시겠습니까?(0: 종료)...[ ]\b\b");
                scanf("%d", &key);

                if (key == 0) {
                   return;
                }
                else
                    goto first;
            }
        }

    how:;
        printf("\t계속하시겠습니까?(0: 종료)");
        scanf("%d", &key);

        if (key == 0) {
            return;
        }
        else
            continue;
    }
}

///**************************************
//*              부서조회               *
//**************************************/

void search_department() {

    int i, j, cnt = 0, key, tot1=0, tot2=0, tot3=0, tot4=0, totking;
    char dp_key[20];
    system("cls");
    rank();
    no_sort();

    printf("\t부서조회\n\n");

    while (1) {
        system("cls");

        printf("\t부서명: ");
        scanf("%s", dp_key);
        line(80, '=');
        printf("사번\t성명\t1분기\t2분기\t3분기\t4분기\t합계\t순위\n");
        line(80, '-');
        printf("\n");
        
        for (i = 0; i < count; i++) {
            if (strcmp(saw[i].dep, dp_key) == 0) {
                saw[i].tot = saw[i].pfc1 + saw[i].pfc2 + saw[i].pfc3 + saw[i].pfc4;
            }
        }

        for (i = 0; i < count; i++) {
            saw[i].rank = 1;
            for (j = 0; j < count; j++) {
                if (saw[i].tot < saw[j].tot && strcmp(saw[i].dep, saw[j].dep) == 0 && strcmp(saw[i].dep, dp_key) == 0) {
                    saw[i].rank++;
                }
            }
        }

        for (i = 0; i < count; i++) {
            if (strcmp(saw[i].dep, dp_key) == 0){
                cnt++;

                if (saw[i].tot == 0) {
                    printf("%2d\t%s\t*****실 적 없 음", saw[i].staff_no, saw[i].name);
                    printf("\n");
                }
                else {
                    printf("%2d\t%s\t%2d\t%2d\t%2d\t%2d\t%2d\t%2d\n", saw[i].staff_no, saw[i].name,
                        saw[i].pfc1, saw[i].pfc2, saw[i].pfc3, saw[i].pfc4, saw[i].tot, saw[i].rank);
                    printf("\n");
                }

                tot1 += saw[i].pfc1;
                tot2 += saw[i].pfc2;
                tot3 += saw[i].pfc3;
                tot4 += saw[i].pfc4;
            }
        }
        totking = tot1 + tot2 + tot3 + tot4;

        line(80, '-');
        printf("\n");
        printf("분기합계\t%2d\t%2d\t%2d\t%2d\t%2d", tot1, tot2, tot3, tot4, totking);
        printf("\n");
        line(80, '-');
        printf("\n");

        if(cnt == 0) {
            printf("\t%s 부서에 속한 사원은 존재하지 않습니다.\n\n", dp_key);
            printf("\t계속하시겠습니까?(0: 종료)");
            scanf("%d", &key);

            if (key == 0) {
                return;
            }
            else
                continue;
        }
        break;
    }
    line(80, '-');
    printf("\n");

    key:;
    printf("순위소트:1, 종료:0...[ ]\b\b");
    scanf("%d", &key);

    if (key == 1) {
        system("cls");

        for (i = 0; i < count; i++) {
            for (j = 0; j < count; j++) {
                if (saw[i].tot > saw[j].tot) {
                    temp = saw[j];
                    saw[j] = saw[i];
                    saw[i] = temp;
                }
            }
        }
        printf("\n\n");
        line(80, '=');
        printf("사번\t성명\t1분기\t2분기\t3분기\t4분기\t합계\t순위\n");
        line(80, '-');
        printf("\n");
        for (i = 0; i < count; i++) {
            if (strcmp(saw[i].dep, dp_key) == 0) {
                cnt++;
                saw[i].tot = saw[i].pfc1 + saw[i].pfc2 + saw[i].pfc3 + saw[i].pfc4;


                if (saw[i].tot == 0) {
                    printf("%2d\t%s\t*****실 적 없 음", saw[i].staff_no, saw[i].name);
                    printf("\n");
                }
                else {
                    printf("%2d\t%s\t%2d\t%2d\t%2d\t%2d\t%2d\t%2d\n", saw[i].staff_no, saw[i].name,
                        saw[i].pfc1, saw[i].pfc2, saw[i].pfc3, saw[i].pfc4, saw[i].tot, saw[i].rank);
                    printf("\n");
                }
            }
        }
        line(80, '-');
        printf("\n");
        printf("분기합계\t%2d\t%2d\t%2d\t%2d\t%2d", tot1, tot2, tot3, tot4, totking);
        printf("\n");
        line(80, '-');
        printf("\n");

        system("pause");
    }
    else if (key == 0) {
        return;
    }
    else
        search_department();;

}

///**************************************
//*              개인검색               *
//**************************************/

void search_oneman(){

    int i, j, cnt = 0, key, tot1 = 0, tot2 = 0, tot3 = 0, tot4 = 0, totking;
    char name_key[20];
    system("cls");
    rank();
    no_sort();

    printf("\t개인조회\n\n");

    while (1) {
        printf("\t성명: ");
        scanf("%s", name_key);

        line(80, '=');
        printf("사번\t부서\t1분기\t2분기\t3분기\t4분기\t합계\t순위\n");
        line(80, '-');
        printf("\n");

        for (i = 0; i < count; i++) {
            if (strcmp(saw[i].name, name_key) == 0) {
                saw[i].tot = saw[i].pfc1 + saw[i].pfc2 + saw[i].pfc3 + saw[i].pfc4;
            }
        }

        for (i = 0; i < count; i++) {
            saw[i].rank = 1;
            for (j = 0; j < count; j++) {
                if (saw[i].tot < saw[j].tot && strcmp(saw[i].name, saw[j].name) == 0) {
                    saw[i].rank++;
                }
            }
        }

        for (i = 0; i < count; i++) {
            if (strcmp(saw[i].name, name_key) == 0) {
                cnt++;
                saw[i].tot = saw[i].pfc1 + saw[i].pfc2 + saw[i].pfc3 + saw[i].pfc4;

                if (saw[i].tot == 0) {
                    printf("%2d\t%s\t*****실 적 없 음", saw[i].staff_no, saw[i].dep);
                    printf("\n");
                }
                else {
                    printf("%2d\t%s\t%2d\t%2d\t%2d\t%2d\t%2d\t%2d\n", saw[i].staff_no, saw[i].dep,
                        saw[i].pfc1, saw[i].pfc2, saw[i].pfc3, saw[i].pfc4, saw[i].tot, saw[i].rank);
                    printf("\n");
                }                

                tot1 += saw[i].pfc1;
                tot2 += saw[i].pfc2;
                tot3 += saw[i].pfc3;
                tot4 += saw[i].pfc4;
            }
        }
        totking = tot1 + tot2 + tot3 + tot4;

        if (cnt == 0) {
            printf("\t%s 란 이름의 사원은 존재하지 않습니다.\n\n", name_key);
            printf("\t계속하시겠습니까?(0: 종료)");
            scanf("%d", &key);

            if (key == 0) {
                return;
            }
            else
                search_oneman();
        }
        break;
    }

    line(80, '-');
    printf("\n");
    printf("분기합계\t%2d\t%2d\t%2d\t%2d\t%2d", tot1, tot2, tot3, tot4, totking);
    printf("\n");
    line(80, '-');
    printf("\n");

    printf("\t계속하시겠습니까?(0: 종료)");
    scanf("%d", &key);

    if (key == 0) {
        return;
    }
    else
        search_oneman();

}

void menu() {
	int sel, i=0, key, key2, p1, p2, p3, p4, name, dep;
	char anykey;
    rank();
    
    system("cls");
    for (;;)
    {

        system("cls");
        printf("\n\n");
        printf("\t 1. 사원등록\n\n");
        printf("\t 2. 실적등록\n\n");
        printf("\t 3. 전체조회\n\n");
        printf("\t 4. 부서조회\n\n");
        printf("\t 5. 개인조회\n\n\n");
        printf("\t0. 종료");
        printf("\t    .........[ ]\b\b");
        scanf("%d", &sel);

        if (sel == 0) break;
        switch (sel)
        {
        case 0: printf("\n\n 종료\n");
            exit;
            
        case 1: printf("\n\n 사원등록.\n");
            member_input();
            break;
        case 2: printf("\n\n 실적등록\n");
            performance_input();
            break;
        case 3: printf("\n\n 전체조회\n");
            search_all();
            break;
        case 4: printf("\n\n 부서조회\n");
            search_department();
            break;
        case 5: printf("\n\n 개인조회\n");
            search_oneman();
            break;
        }
    }


}
int main() {

    // 위에다 올리면 데이터를 계속 추가해지기 때문에 켜지면서 바로 데이터를 추가
    int i, j, cnt=0;
    FILE* sawonF = fopen("c:\\data\\sawon.txt", "r");
    FILE* siljukF = fopen("c:\\data\\siljuk.txt", "r");

    while (1) {
        fscanf(sawonF, "%d%s%s", &saw[count].staff_no, &saw[count].name, &saw[count].dep);
        count++;
        if (feof(sawonF)) break;
    }

    
    while (1) {
        fscanf(siljukF, "%d%d%d%d%d", &sil[cnt].staff_no, &sil[cnt].pfc1, &sil[cnt].pfc2, &sil[cnt].pfc3, &sil[cnt].pfc4);
        if (feof(siljukF)) break;
        cnt++;
    }

    for (i = 0; i < count; i++) {
        for (j = 0; j < count; j++) {
            if (saw[i].staff_no == sil[j].staff_no) {
                saw[i].pfc1 = sil[j].pfc1;
                saw[i].pfc2 = sil[j].pfc2;
                saw[i].pfc3 = sil[j].pfc3;
                saw[i].pfc4 = sil[j].pfc4;
                saw[i].tot = saw[j].pfc1 + saw[j].pfc2 + saw[j].pfc3 + saw[j].pfc4;
                break;
            }
        }
    }
    rank();
    fclose(sawonF);
    fclose(siljukF);

    menu();
    return 0;
}
