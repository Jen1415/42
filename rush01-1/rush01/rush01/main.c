/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaryutki <aaryutki@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 14:57:02 by aaryutki          #+#    #+#             */
/*   Updated: 2026/10/18 14:57:04 by aaryutki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		validate(int argc, char **argv);
void	prefill(int box[4][4], int input[16]);
int		solve(int box[4][4], int input[16]);


// initialize the 4x4 grid, each filled with zero
// parse the argv to input array
void	init_box(int box[4][4], int input[16], char *arg)
{
	int	i;
	int	j;

	i = 0;
	while (i < 16)
	{
		input[i] = arg[i * 2] - '0';
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			box[i][j] = 0;
			j++;
		}
		i++;
	}
}

// simply print an error message
int	print_error(void)
{
	write(1, "Error\n", 6);
	return (1);
}

// write out the numbers to the grid
void	print_grid(int box[4][4])
{
	int		i;
	int		j;
	char	digit;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			digit = box[i][j] + '0';
			write(1, &digit, 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}


// drive the program, 
// validate (see check.c) the user input first
// prefill the grid (see rules.c) if the answer is obvious (e.g. if 4 then fill "1 2 3 4")
// try to solve the grid (see solve.c), if pass then print out the grid
int	main(int argc, char **argv)
{
	int	box[4][4];
	int	input[16];

	if (validate(argc, argv))
		return (print_error());
	init_box(box, input, argv[1]);
	prefill(box, input);
	if (solve(box, input) == 0)
		return (print_error());
	print_grid(box);
	return (0);
}
