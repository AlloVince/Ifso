#include <stdio.h>
#include <string.h>
#include <locale.h>


void shuziTest(wchar_t *shuzi, int number)
{
    int res = 0;
    int output;
    output = shuziToNumber(shuzi);
    if(output == number){
        res = 1;
    }
    printf("RES : %d; Shuzi : %ls; Number : %d\n", res, shuzi, output);
}

int shuziToNumber(wchar_t* shuzi){
    wchar_t* shuziBase[] = { L"零", L"一", L"二", L"三", L"四", L"五", L"六", L"七", L"八", L"九", L"十" };
    wchar_t* shuziDigit[] = { L"十", L"百", L"千", L"万", L"亿"};
    int numberBase[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int numberDigit[] = { 10, 100, 1000, 1000, 100000000};
    int res = -1;
    int shuziStrCount;
    int i = 0;

    setlocale(LC_ALL, ""); 
    shuziStrCount = wcslen(shuzi);
    if(shuziStrCount < 1) {
        return res;
    }

    //零 ～ 十
    if(shuziStrCount == 1){
        for(i; i < 11; i++){
            if(wcscmp(shuziBase[i], shuzi) == 0){
                res = numberBase[i];
                break;
            }
        }
    }
    return res;
}
void main(void){
    shuziTest(L"一", 1);
    shuziTest(L"五", 5);
    shuziTest(L"十", 10);
    /*
    shuziTest(L"十一", 11);
    shuziTest(L"三十一", 31);
    shuziTest(L"一百", 100);
    shuziTest(L"一百零一", 101);
    shuziTest(L"一百二十", 120);
    shuziTest(L"二百三十五", 235);
    shuziTest(L"八百一十一", 811);
    shuziTest(L"一千", 1000);
    shuziTest(L"一千零七", 1007);
    shuziTest(L"一千零一十五", 1015);
    shuziTest(L"一千零三十", 1030);
    shuziTest(L"一千二百", 1200);
    shuziTest(L"一千二百零一", 1201);
    shuziTest(L"一千二百五十六", 1256);
    shuziTest(L"一万", 10000);
    shuziTest(L"一万零七", 10007);
    shuziTest(L"一万零八十八", 10088);
    shuziTest(L"一万零一百", 10100);
    shuziTest(L"一万零一百", 10100);
    */
}
