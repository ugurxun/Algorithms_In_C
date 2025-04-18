#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    //Write your logic to print the tokens of the sentence here.
    int blank_flag = 0;

    for(int i=0; s[i] != '\0'; ++i)
        if(s[i] == ' ')
        {
            blank_flag = 1;
        }
        else
        {   if(blank_flag)
            {
                putchar('\n');
                blank_flag = 0;
            }    
            putchar(s[i]);
        }
    return 0;
}