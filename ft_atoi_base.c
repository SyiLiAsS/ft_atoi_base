#include <stdio.h>
#include <unistd.h>

int ft_strlen(char *str) {
  if (*str == '\0')
    return 0;

  return 1 + ft_strlen(str + 1);
}

int if_egal(char c, char *base) {

  int j = 0;

  while (base[j]) {
    if (c == base[j])
      return 1;
    j++;
  }
  return 0;
}

int get_value(char c, char *base) {

	int i = 0;
  	while(base[i])
	{
		if(c == base[i])
			return i;
	i++;
	}
  return -1;
}

int check_base(char *base) {
  int i = 0;
  int j = 0;

  if (ft_strlen(base) == 0)
    return 0;

  while (base[i]) {
    if (base[i] == '-' || base[i] == '+')
      return 1;
    j = 0;
    while (base[j]) {
      if (base[i] == base[j] && i != j)
        return 1;
      j++;
    }
    i++;
  }
  return 0;
}

int ft_atoi_base(char *str, char *base) {

  if (check_base(base))
    return 0;

  int i = 0;
  int sign = 1;
  int result = 0;
  int len_base = ft_strlen(base);

  while (str[i] == ' ' || str[i] == '\t')
    i++;

  while (str[i] == '-' || str[i] == '+') {
    if (str[i] == '-')
      sign = sign * -1;
    i++;
  }
  while (if_egal(str[i], base)) {
    result = result * len_base + get_value(str[i],base);
    i++;
  }

  return result * sign;
}

int main() { printf("%d\n", ft_atoi_base(" +ff", "0123456789abcdef")); }
