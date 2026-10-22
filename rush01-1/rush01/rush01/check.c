/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaryutki <aaryutki@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 14:56:26 by aaryutki          #+#    #+#             */
/*   Updated: 2026/10/18 14:56:43 by aaryutki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
helper function for validate
1. check all the possible value pair (e.g. if left or top is 4 then right or bottom must == 1) 
*/

int	validate_3(int x, int y, char *arg)
{
	int	i;
	int	n;

	i = x;
	n = y;
	while (i <= x + 6 && n <= y + 6)
	{
		if (!(
		   (arg[i] == '4' && arg[n] == '1') 
		|| (arg[i] == '3' && arg[n] == '2') 
		|| (arg[i] == '3' && arg[n] == '1')
		|| (arg[i] == '2' && arg[n] == '3') 
		|| (arg[i] == '2' && arg[n] == '2') 
		|| (arg[i] == '2' && arg[n] == '1')
		|| (arg[i] == '1' && arg[n] == '4') 
		|| (arg[i] == '1' && arg[n] == '3') 
		|| (arg[i] == '1' && arg[n] == '2')))
			return (1);
		i = i + 2;
		n = n + 2;
	}
	return (0);
}

/*
validate the user input
1. user input length must == 31
2. even position must between [1, 4]
3. odd position must == ' '
4. call validate_3 to check each row/col
*/ 
int	validate(int argc, char **argv)
{
	int	a;

	if (argc != 2)
		return (1);
	a = 0;
	while (argv[1][a] != '\0')
	{
		if (a >= 31)
			return (1);
		if (a % 2 == 0 && (argv[1][a] < '1' || argv[1][a] > '4'))
			return (1);
		if (a % 2 == 1 && argv[1][a] != ' ')
			return (1);
		a++;
	}
	if (a != 31 || validate_3(0, 8, argv[1]) || validate_3(16, 24, argv[1]))
		return (1);
	return (0);
}

/*
check the visible block according to the rev (view position)
1. update max if found any
2. found a new max, add 1 count
3. return the quantity of visible block
*/
int	view(int line[4], int rev)
{
	int	i;
	int	max;
	int	count;
	int	n;

	i = 0;
	max = 0;
	count = 0;
	while (i < 4)
	{
		if (rev)
			n = line[3 - i];
		else
			n = line[i];
		if (n > max)
		{
			max = n;
			count++;
		}
		i++;
	}
	return (count);
}


/*
compare current number with each number after it
return 0 if found any duplicates
*/
int	unique_line(int line[4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 4)
		{
			if (line[i] == line[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*
1. copy columns into a line array
2. check for unique_line (up) and view (up)
3. return 0 if not fulfilling the requirements
*/
int	check_cols(int box[4][4], int input[16])
{
	int	i;
	int	j;
	int	line[4];

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			line[j] = box[j][i];
			j++;
		}
		if (unique_line(line) == 0 || view(line, 0) != input[i] || view(line,
				1) != input[i + 4])
			return (0);
		i++;
	}
	return (1);
}
