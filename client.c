#include "minitalk.h"

// use school pc, online over 1s per 100 words
int send_signal(char **bin, int pid)
{
    int i;
    int k;

    i = 0;
    while (bin[i] != NULL)
    {
        k = 0;
        while (bin[i][k] != '\0')
        {
            if (bin[i][k] == '1')
                kill(pid, SIGUSR1);
            else if (bin[i][k] == '0')
                kill(pid, SIGUSR2);
            usleep(500);
            k++;
        }
        i++;
    }
}

char *convert_to_bin(char letter)
{
    int i;
    int l;
    int k;
    char *bin;

    i = 7;
    bin = malloc(sizeof(char) * 8 + 1);
    if (bin == NULL)
        return (NULL);
    k = 7;
    while (i >= 0)
    {
        l = (letter >> i) & 0x1;
        if (l == 0)
            bin[k] = '0';
        else if (l == 1)
            bin[k] = '1';
        i--;
        k--;
    }
    bin[8] = '\0';
    return (bin);
}

int main(int argc, char *argv[])
{
    int i;
    char **bin;
    char *bi_value; 

    bin = malloc(sizeof(char *) * ft_strlen(argv[2]) * 8 + 1);
    if (bin == NULL || argc != 3)
        return (1);
    i = 0;
    while (argv[2][i] != '\0')
    {
        bi_value = convert_to_bin(argv[2][i]);
        bin[i] = bi_value;
        i++;
    }
    bi_value = convert_to_bin('\0');
    bin[i] = bi_value;
    bin[i + 1] = NULL;
    i = ft_atoi(argv[1]);
    send_signal(bin, i);
    i = 0;
    while (bin[i] != NULL) {
        free(bin[i]);
        i++;
    }
    return (free(bin), 0);
}
