
/* 2021-12-11 , ����� ����Ǵ°� Ȯ���߽��ϴ�. �ڵ��� ��ȿ�����̶� ù �ε��� ��¦ �ð��� �ɸ��ϴ�.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>


int count = 0;
typedef struct sawon {
	int staff_no = 0;
	char name[10];
	char dep[20];
    int pfc1=0;
    int pfc2=0;
    int pfc3=0;
    int pfc4=0;
    int tot=0;
    int rank;
}sawon;
sawon saw[200], sil[200], temp;

void menu();

void rank() { // ����
    for (int i = 0; i < count; i++) {
        saw[i].rank = 1;
        for (int j = 0; j < count; j++) {
            if (saw[i].tot < saw[j].tot) {
                saw[i].rank++;
            }
        }
    }
}

void no_sort() { // �������
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
//*              ������               *
//**************************************/

void member_input(){
    int i, cnt=0, check=0, key;
    
    while (1){
        system("cls");
        printf("\t������\n\n");
        printf("\t%d��° ����Դϴ�\n\n.", count + 1);

        check = 0;
        printf("\t�����ȣ: ");
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
            printf("\n\t�̹� ��ϵ� ����Դϴ�.\n\n");
            cnt = 0;
            printf("\t����Ͻðڽ��ϱ�?(0: ����)");
            scanf("%d", &key);

            if (key == 0) {
                return;
            }
            else
                system("cls");
            continue;
        }

        printf("\t����: ");
        scanf("%s", &saw[count].name);
        printf("\t�μ���: ");
        scanf("%s", &saw[count].dep);
        count++;

        printf("\n\n\t����Ͻðڽ��ϱ�?(0: ����)");
        scanf("%d", &key);

        if (key == 0) {
            return;
        }
        else
            continue;
    }
}

///**************************************
//*              ��ü��ȸ               *
//**************************************/


void search_all() {

    int anykey, tot1 = 0, tot2 = 0, tot3 = 0, tot4 = 0, totking = 0, key, i, j;
    system("cls");
    no_sort();

    if (count == 0) {
        printf("�����Ͱ� �����ϴ�.\n\n");
        system("pause");
        return;
    }
    line(80, '=');
    printf("���\t����\t�μ�\t1�б�\t2�б�\t3�б�\t4�б�\t�հ�\t����\n");
    line(80, '-');

    for (i = 0; i < count; i++) {
        saw[i].tot = saw[i].pfc1 + saw[i].pfc2 + saw[i].pfc3 + saw[i].pfc4;
    }
    rank();
    for (i = 0; i < count; i++) {
        
        if (saw[i].tot == 0) {
            printf("%2d\t%s\t%s\t*****�� �� �� ��", saw[i].staff_no, saw[i].name, saw[i].dep);
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
    printf("�б��հ�\t\t%2d\t%2d\t%2d\t%2d\t%2d", tot1, tot2, tot3, tot4, totking);
    printf("\n");
    line(80, '-');
    printf("\n");

    key:;
    printf("������Ʈ:1, ����:0...[ ]\b\b");
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
        printf("���\t����\t�μ�\t1�б�\t2�б�\t3�б�\t4�б�\t�հ�\t����\n");
        line(80, '-');
        printf("\n");
        for (i = 0; i < count; i++) {
            if (saw[i].tot == 0) {
                printf("%2d\t%s\t%s\t*****�� �� �� ��", saw[i].staff_no, saw[i].name, saw[i].dep);
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
        printf("�б��հ�\t\t%2d\t%2d\t%2d\t%2d\t%2d", tot1, tot2, tot3, tot4, totking);
        printf("\n");
        line(80, '-');
        printf("\n");

        system("pause");
    }else if(key == 0) {
        return;
    }
    else {
        printf("�ٽ� �Է����ּ���  ");
        goto key;
    }
}

///**************************************
//*              �����Է�               *
//**************************************/

void performance_input() {

    int i, cnt = 0, no_key, key;
first:;
    while (1) {
        system("cls");
        printf("\t�������\n\n");
        
        while (1) {
            printf("\t�����ȣ: ");
            scanf("%d", &no_key);

            for (i = 0; i < count; i++) {
                if (saw[i].staff_no == no_key) {
                    cnt++;
                    printf("\n\t����: %s\t�μ�: %s\n\n", saw[i].name, saw[i].dep);
                    break;
                }
            }
            if (cnt != 0) {
                printf("\t1�б�: ");
                scanf("%d", &saw[i].pfc1);
                printf("\t2�б�: ");
                scanf("%d", &saw[i].pfc2);
                printf("\t3�б�: ");
                scanf("%d", &saw[i].pfc3);
                printf("\t4�б�: ");
                scanf("%d", &saw[i].pfc4);
                saw[i].tot = saw[i].pfc1 + saw[i].pfc2 + saw[i].pfc3 + saw[i].pfc4;
                break;
            }
            else {
                printf("\n\t%d �� ��ϵ��� ���� �����ȣ �Դϴ�.\n\n", no_key);
                printf("\t����Ͻðڽ��ϱ�?(0: ����)...[ ]\b\b");
                scanf("%d", &key);

                if (key == 0) {
                   return;
                }
                else
                    goto first;
            }
        }

        printf("����Ͻðڽ��ϱ�?(0: ����)");
        scanf("%d", &key);

        if (key == 0) {
            return;
        }
        else
            continue;
    }
}

///**************************************
//*              �μ���ȸ               *
//**************************************/

void search_department() {

    int i, j, cnt = 0, key, tot1=0, tot2=0, tot3=0, tot4=0, totking;
    char dp_key[20];
    system("cls");
    rank();
    no_sort();

    printf("\t�μ���ȸ\n\n");

    while (1) {
        printf("\t�μ���: ");
        scanf("%s", dp_key);
        line(80, '=');
        printf("���\t����\t1�б�\t2�б�\t3�б�\t4�б�\t�հ�\t����\n");
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
                    printf("%2d\t%s\t*****�� �� �� ��", saw[i].staff_no, saw[i].name);
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
        printf("�б��հ�\t%2d\t%2d\t%2d\t%2d\t%2d", tot1, tot2, tot3, tot4, totking);
        printf("\n");
        line(80, '-');
        printf("\n");

        if(cnt == 0) {
            printf("%s �μ��� ���� ����� �������� �ʽ��ϴ�.\n\n", dp_key);
            printf("����Ͻðڽ��ϱ�?(0: ����)");
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
    printf("������Ʈ:1, ����:0...[ ]\b\b");
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
        printf("���\t����\t1�б�\t2�б�\t3�б�\t4�б�\t�հ�\t����\n");
        line(80, '-');
        printf("\n");
        for (i = 0; i < count; i++) {
            if (strcmp(saw[i].dep, dp_key) == 0) {
                cnt++;
                saw[i].tot = saw[i].pfc1 + saw[i].pfc2 + saw[i].pfc3 + saw[i].pfc4;


                if (saw[i].tot == 0) {
                    printf("%2d\t%s\t*****�� �� �� ��", saw[i].staff_no, saw[i].name);
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
        printf("�б��հ�\t%2d\t%2d\t%2d\t%2d\t%2d", tot1, tot2, tot3, tot4, totking);
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
//*              ���ΰ˻�               *
//**************************************/

void search_oneman(){

    int i, j, cnt = 0, key, tot1 = 0, tot2 = 0, tot3 = 0, tot4 = 0, totking;
    char name_key[20];
    system("cls");
    rank();
    no_sort();

    printf("\t������ȸ\n\n");

    while (1) {
        printf("\t����: ");
        scanf("%s", name_key);

        line(80, '=');
        printf("���\t�μ�\t1�б�\t2�б�\t3�б�\t4�б�\t�հ�\t����\n");
        line(80, '-');
        printf("\n");

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
                    printf("%2d\t%s\t*****�� �� �� ��", saw[i].staff_no, saw[i].dep);
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
            printf("%s �� �̸��� ����� �������� �ʽ��ϴ�.\n\n", name_key);
            printf("����Ͻðڽ��ϱ�?(0: ����)");
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
    printf("�б��հ�\t%2d\t%2d\t%2d\t%2d\t%2d", tot1, tot2, tot3, tot4, totking);
    printf("\n");
    line(80, '-');
    printf("\n");

    printf("����Ͻðڽ��ϱ�?(0: ����)");
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
        printf("\t 1. ������\n\n");
        printf("\t 2. �������\n\n");
        printf("\t 3. ��ü��ȸ\n\n");
        printf("\t 4. �μ���ȸ\n\n");
        printf("\t 5. ������ȸ\n\n\n");
        printf("\t0. ����");
        printf("\t    .........[ ]\b\b");
        scanf("%d", &sel);

        if (sel == 0) break;
        switch (sel)
        {
        case 0: printf("\n\n ����\n");
            exit;
            
        case 1: printf("\n\n ������.\n");
            member_input();
            break;
        case 2: printf("\n\n �������\n");
            performance_input();
            break;
        case 3: printf("\n\n ��ü��ȸ\n");
            search_all();
            break;
        case 4: printf("\n\n �μ���ȸ\n");
            search_department();
            break;
        case 5: printf("\n\n ������ȸ\n");
            search_oneman();
            break;
        }
    }


}
int main() {

    // ������ �ø��� �����͸� ��� �߰������� ������ �����鼭 �ٷ� �����͸� �߰�
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