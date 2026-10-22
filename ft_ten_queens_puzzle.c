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
	while(i < pos)
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

int putqueen(int board[4][4], int pos)
{
	if (isSafe(board, pos))
		board[pos / 4][pos % 4] = 1;
	putqueen(board, pos + 1);
	board[pos / 4][pos % 4] = 0;
	return (1);

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
	putqueen(board, 0);
}