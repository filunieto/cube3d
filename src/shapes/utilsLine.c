#include "../../inc/shapes/Shapes.h"

//Function to get the integer part of a decimal number
int	i_part(float number)
{
	return (floor(number));
}

float	fractional_part(float number)
{
	return (number - i_part(number));
}

//Function to obtain the complementary to be value 1,
//i.e number + rfPart = 1
float	rf_part(float number)
{
	return (1 - fractional_part(number));
}

//Function to swap values
void	swap(int *n1, int *n2)
{
	int	aux;

	aux = *n1;
	*n1 = *n2;
	*n2 = aux;
}
