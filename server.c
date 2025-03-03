#include "minitalk.h"
#include <string.h>

char *string;

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return(i);
}

char *ft_strjoin(char *s1, char letter)
{
	char	*temp;
	int		i;
	int		k;

	temp = (char *)malloc((ft_strlen(s1) + 1 + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = letter;
    temp[i + 1] = '\0';
	return (temp);
}

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
        // write (1, &letter, 1);
        handle_string(letter);
        k = -1;
        letter = 0;
    }
    k++;
}

int main(void)
{   
    printf("PID of server: %d\n", getpid());

    signal(SIGUSR1, handle_signal_SIGUSR1);
    signal(SIGUSR2, handle_signal_SIGUSR1);

    while (1)
    {
        //if (something signaling end of the message)
            //break;
    }
    return (0);
}