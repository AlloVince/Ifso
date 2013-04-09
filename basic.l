%{

#include <stdio.h>
#include <string.h>
#include <locale.h>
int yywrap( void ) { return(1) ; }
#define      pr_text     printf("%s",yytext)

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

%}

shuzi 零|一|二|三|四|五|六|七|八|九|十|百|千|万|亿

%%

{shuzi}+ {
    printf(shuziToNumber(yytext));
}
"加"        { printf("+"); }
"减"        { printf("-"); }
"乘"        { printf("*"); }
"除"        { printf("/"); }
"等于"      { printf("="); }
.                { pr_text; }
\n               { pr_text; }


%%

void main()
{
    yylex();
}
