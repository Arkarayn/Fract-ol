//header
#include "../headers_2/first_layer.h"

double	ft_atof(char *str)
{
	int		i;
	double	res;
	int		sign;
	double	dec;

	i = 0;
	sign = 1;
	res = 0.0;
	dec = 1.0;
	if (str[i] == '-')
		sign = -1;
	i += (str[i] == '-' || str[i] == '+');
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		dec *= 10;
		i++;
	}
	return (res / dec * sign);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int i;
    double num;

    printf("Converting %d arguments to doubles:\n", argc - 1);

    for (i = 1; i < argc; i++) {
        num = ft_atof(argv[i]);
        printf("%s -> %f\n", argv[i], num);
    }

    // Test with positive and negative numbers
    num = ft_atof("123.456");
    printf("Positive number: %f\n", num);

    num = ft_atof("-987.654");
    printf("Negative number: %f\n", num);

    return 0;
}*/
