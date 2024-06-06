#include <unistd.h>

char *ft_strchr(const char *str, int c)
{
    int i;
    i = 0;

    char result[50];
    
    while (*str != '\0')
    {
        if (*str == c)
        {
            while (*str == c && i < 50)
            {
                result[i] = *str;
                str++;
                i++;
            }
            return (result);
        }
        else
            str++;
    }
    return (0);
}

#include <stdio.h>
int main () {
   const char str[] = "Hello World!";
   const char ch = 'o';
   char *ret;

   ret = ft_strchr(str, ch);

   printf(ret);
   
   return(0);
}