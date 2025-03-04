#include "minitalk.h"
#include <string.h>

char *string;

void handle_string(char letter)
{
    int j;

    if (letter != '\0')
    {
        if (string == NULL)
        {
            string = malloc(sizeof(char) * 2);
            string[0] = letter;
            string[1] = '\0';
        }
        else 
            string = ft_strjoin(string, letter);
    }
    else if (letter == '\0'){
        j = 0;
        while (string[j] != '\0')
        {
            write (1, &string[j], 1);
            j++;
        }
        free(string);
        string = NULL;
    }
}

void    handle_signal_SIGUSR1(int signal)
{
    static int k;
    static char letter;

    if (k <= 7 && signal == SIGUSR1){
        letter |= (1 << k);
    }
    if (k == 7){
        handle_string(letter);
        k = -1;
        letter = 0;
    }
    k++;
}
// PRINTF CHANGE!!

int main(void)
{   
    string = NULL;
    printf("PID of server: %d\n", getpid());

    signal(SIGUSR1, handle_signal_SIGUSR1);
    signal(SIGUSR2, handle_signal_SIGUSR1);

    while (1)
    {
        //sleep maybe
    }
    return (0);
}