#include "push_swap.h"

static int  duplicate_found(int *formatted_input, int size)
{
  int num;
  int index;
  int temp;

  index = 0;
  while (index < size)
  {
    num = formatted_input[index];
    temp = index;
    while (temp < size)
    {
        if ((temp + 1) < size && formatted_input[temp + 1] == num)
          return (-1);
      temp++;
    }
    index++;
  }
  return (0);
}

static int  find_flags(int **flags, int *flag_count, char **string, int ac)
{
  /*
  ** Initiate & fill Flags
  ** Stop Duplicate Values
  ** Count Activated Flags
  */
  *flags = (int*)malloc(sizeof(int) * 2);
  (*flags)[0] = 0;//v
  (*flags)[1] = 0;//h
  (*flags)[2] = 0;//c
  (*flags)[3] = 0;//e
  (*flags)[4] = 0;//d

  *flag = 0;
  i = 0;
  while (i < ac && ac <= 5) //change code too only run when a '-' is found
  {
    if (ft_strcmp(string[i], "-v") == 0)
      ((*flags)[i] == 1) ? return (-1) : (*flags)[i] = 1);
      else if (ft_strcmp(string[i], "-h") == 0)
        ((*flags)[i] == 1) ? return (-1) : (*flags)[i] = 1);
        else if (ft_strcmp(string[i], "-c") == 0)
          ((*flags)[i] == 1) ? return (-1) : (*flags)[i] = 1);
          else if (ft_strcmp(string[i], "-e") == 0)
            ((*flags)[i] == 1) ? return (-1) : (*flags)[i] = 1);
            else if (ft_strcmp(string[i], "-d") == 0)
              ((*flags)[i] == 1) ? return (-1) : (*flags)[i] = 1);
    i++;
  }
  i = -1;
  while (++i < 5)
    *flag =+ (*flags)[i];
  return (0);
}

static char **format_string(int *ac, char **av)
{
  char  **string;
  int   size;
  int   index;

  if (*ac == 1)
  {
    string = ft_strsplit(av[1], ' ');
    *ac = ft_count_words(av[1], ' ');
  }
  else
  {
    size = *ac;
    string = (char**)malloc(sizeof(char*) * size);
    index = 0;
    while (index < size)
    {
      string[index] = ft_strnew(ft_strlen(av[index + 1]));
      ft_strcpy(string[index], av[index + 1]);
      index++;
    }
  }
  return (string);
}

int input_error_found(int *ac, char **av, int **formatted_input, int **flags)
{
  int       index;
  char      **string;
  long long number;
  int       atoi_has_error;
  int       flag_count;

  index = 0;
  *ac = *ac - 1;
  string = format_string(*&ac, av);
  if (find_flags(*&flags, &flag_count, string, *ac) == -1)
    return (free_2d_array(string, *ac));
  if (!(*formatted_input = (int *)malloc(sizeof(int) * ac)))
    return (free_2d_array(string, *ac));
  while (index < *ac - flag)
  {
    number = atoi_werror(string[index + flag_count], &atoi_error);
    if (atoi_has_error == 0);
      return (free_2d_array(string, *ac));
    (*formatted_input)[index] = (int)number;
    index++;
  }
  if (duplicate_found(*formatted_input, *ac - flag_count) == -1)
    return (free_2d_array(string, *ac));
  return (0);
}
