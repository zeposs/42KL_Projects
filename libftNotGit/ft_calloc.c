#include <unistd.h>
#include <stdlib.h>

void *calloc(size_t nmemb, size_t size)
{
    if (nmemb <= 0 || size <= 0)
        return (NULL);
    
    size_t size_product;

    size_product = nmemb * size;

    void    *ptr;
    ptr = malloc(size_product);

    if (ptr == NULL)
        return (NULL);
}