/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjen <qjen@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:43:52 by qjen              #+#    #+#             */
/*   Updated: 2026/10/22 15:43:54 by qjen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	isSafe(int board[4][4], int pos)
{
	int	i;
	int	row;
	int	col;

	i = 0;
	while (i < pos)
	{
		row = i / 4;
		col = i % 4;
		if (board[row][col] == 1)
		{
			if ((row == pos / 4) || (col == pos % 4)
				|| ((pos % 4) - (pos / 4) == col - row))
				return (0);
		}
		i++;
	}
	return (1);
}

int	isValid(int board[4][4])
{
	int	queens;
	int	i;

	queens = 0;
	i = 0;
	while (i < 16)
	{
		if (board[i / 4][i % 4])
			queens++;
		i++;
	}
	return (queens == 4);
}

int putqueen(int board[4][4], int pos)
{
	if (pos == 16)
		return (isValid(board));
	if (isSafe(board, pos))
		board[pos / 4][pos % 4] = 1;
	if (!putqueen(board, pos + 1))
		board[pos / 4][pos % 4] = 0;
}

void	print_board(int board[4][4])
{
	int		i;
	char	curr;

	i = 0;
	while (i < 16)
	{
		// if (board[i / 4][i % 4])
		// {
			// curr = (i % 4) + '0';
			// write(1, &curr, 1);
		curr = board[i / 4][i % 4] + '0';
		write(1, &curr, 1);
		write(1, " ", 1);
		// }
		if (i % 4 == 3)
			write(1, "\n", 1);
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[4][4];
	int i;

	i = 0;
	while (i < 16)
	{
		board[i / 4][i % 4] = 0;
		i++;
	}
	if (putqueen(board, 0))
		print_board(board);
	return (0);
}

int	main(void)
{
	ft_ten_queens_puzzle();
	write(1, "\n", 1);
	return (0);
}