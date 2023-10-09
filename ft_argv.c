#include "push_swap.h"
#include <stdio.h>

/*
 * Visualiser : https://github.com/elijahkash/push_swap_gui
 */
int     ft_argv_compliant(char **argv)
{
        int     i;
        int     j;
        int     len;

        i = 0;
        j = 1;
        len = 0;
        while (argv[j])
        {
                while (ft_isdigit(argv[j][i]) || argv[j][i] == ' ')
                {
                        if (argv[j][i] == '-' || argv[j][i] == '+')
                                if (!argv[j][i + 1] || argv[j][i + 1] == '-' || argv[j][i + 1] == '+' || argv[j][i + 1] == ' ')
                                        return (0);
                        i++;
                        len ++;
                }
                if (argv[j][i] == '\0')
                {
                        j++;
                        i = 0;
                }
                else
                        return (0);
        }
        return (len);
}

int     ft_len_argv(char **argv)
{
        int     i;
        int     j;
        int     len;

        i = 0;
        j = 1;
        len = 0;
        while (argv[j])
        {
                while (argv[j][i])
                {
                        len++;
                        i++;
                }
                i = 0;
                j++;
                if (argv[j])
                        len++;
        }
        return (len);
}
