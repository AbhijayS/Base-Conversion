/*
CODR: Abhijay Saini
PARTENR:
DATE:
TIME:
*/

#include <stdio.h>
#include <stdlib.h>
int getInt(void);
int length(char* str);
char * getStr(void);
int expo(int base, int exponent);

int main(void)
{
    
    int decimal = getInt();
	printf("%d\n", decimal);
    int base = 1;
    int counter = 0;
    while (base <= decimal)
    {
        base = base*2;
        counter++;
    }
    base /= 2;
    printf("Base: %d\n", base);
    printf("Exponent: %d\n", counter);
	
	int i;
	int division;
    for (i = 0; i < counter; i++)
    {
        division = 0;
        if ((decimal) != 0)
        {
            while (base > decimal)
            {
                base /= 2;
    			division++;
            }
    		int j;
    		for (j = 0; j < (division-1); j++)
    		{
    			printf("0");
    			counter--;
    		}
            printf("1");
            decimal -= base;
        }else{
            printf("0");
        }
    }
    printf("\n");
}
int length(char* str)
{
    int i = 0;
    int count = 0;
    while (*(str+i) != '\0')
    {
        count++;
        i++;
    }
    return count;
}
void drawHash(int n)
{
    int hash_num = (2*n)-1;
        int i;
    for (i = 0; i < hash_num; i++)
    {
        printf("#");
    }
}
void drawSpace(int n, int height)
{
    int spaces = height-n;
    int i;
    for (i = 0; i < spaces; i++)
    {
        printf(" ");
    }
}
void drawPyramid(void)
{
    int i;
    for (i = 0; i < 22; i++)
    {
        drawSpace(i, 22);
        drawHash(i);
        printf("\n");
    }
}
char * getStr(void)
{
    char* s = malloc(sizeof(char));
    char inp;
    int len = 0;
    while ((inp = getchar()) != '\n')
    {
        *(s+len) = inp;
        s = realloc(s, len+1);
        len++;
    }
    int slen = length(s);
    if (len != slen)
    {
        *(s+(slen-1)) = *(s+slen);
        *(s+(slen-2)) = *(s+(slen-1));
        *(s+(slen-3)) = *(s+(slen-2));
    }
    return s;
}
int getInt(void)
{
    char* int_str = getStr();    
    int len = length(int_str);
    int int_out = 0;
    
    int i;
    for(i = 0; i < len; i++)
    {
        if (*(int_str+i)-'0' >= 48 && *(int_str+i)-'0' <= 57){
            return -1;
        }
        int_out += (*(int_str+i)-'0')*(expo(10, (len-1)-i));
    }
    return int_out;
}
int expo(int base, int exponent)
{
    int out = 1;
    int i;
    for (i = 0; i < exponent; i++)
    {
        out *= base;
    }
    return out;
}
char* flStr(FILE* file)
{
    char* s = malloc(sizeof(char));
    char inp;
    int len = 0;
    while ((inp = fgetc(file)) != '\n')
    {
        *(s+len) = inp;
        s = realloc(s, len+1);
        len++;
    }
    int slen = length(s);
    if (len != slen)
    {
        *(s+(slen-1)) = *(s+slen);
        *(s+(slen-2)) = *(s+(slen-1));
        *(s+(slen-3)) = *(s+(slen-2));
    }
    return s;
}