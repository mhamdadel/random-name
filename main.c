#include <stdio.h>
#include <stdlib.h>
#include "mylibrary.h"
#define arrSize 6

int main()
{
    char *words[arrSize] = { "mohamed", "kamal", "hashem", "ali", "hamza", "katkot" };
    int nelts = sizeof(words)/sizeof(*words);
    int randKey = 0;
    while (1)
    {
        char key = getch();
        if(key == 's')
        {
            system("cls");
            srand(time(NULL));
            for (int i=0; i < nelts;  ++i)
            {
                int r = (rand() % (nelts - i)) + i;
                const char * temp =  words[i];

                words[i] = words[r];
                words[r] = temp;
            }
            for (int i=0; i < nelts;  ++i)
            {
                puts(words[i]);

            }
        }
        else if(key == 13)
        {
            for(int x = 0 ; x < 3; x++)
            {
                for(int j=0; j<arrSize; j++)
                {
                    system("cls");
                    for (int i=0; i < nelts;  ++i)
                    {
                        if(i== j)
                        {
                            printf("\033[0;31m");
                            puts(words[i]);
                            printf("\033[0m");
                        }
                        else
                        {
                            puts(words[i]);
                        }

                    }
                    msleep(50);
                }

            }
            randKey = randNumber();
            system("cls");
            for (int i=0; i < nelts;  ++i)
            {
                if(i==randKey)
                {
                    printf("\033[0;31m");
                    puts(words[i]);
                    printf("\033[0m");
                }
                else
                {
                    puts(words[i]);
                }
                //msleep(250);

            }
        }

    }
    return 0;
}

void shuleArrStr()
{

}

void shuffle(int *array, size_t n)
{
    if (n > 1)
    {
        size_t i;
        for (i = 0; i < n - 1; i++)
        {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

int randNumber ()
{
    time_t tim;
    srand( time(NULL) );
    return (rand() % arrSize);
}
