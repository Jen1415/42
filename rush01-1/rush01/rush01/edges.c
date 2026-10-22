/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edges.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaryutki <aaryutki@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 14:56:49 by aaryutki          #+#    #+#             */
/*   Updated: 2026/10/18 14:56:50 by aaryutki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
return the sector accordingly
1. col top
2. col bot
3. row left
4. row right
*/
int	sector(int i)
{
	if (i / 2 <= 3)
		return (0);
	if (i / 2 <= 7)
		return (1);
	if (i / 2 <= 11)
		return (2);
	return (3);
}

/*
check the sector (up) and put the 1 2 3 4 accordingly
1. j = 0 1 2 3
*/

void	fill_four(int box[4][4], int i, int j)
{
	if (sector(i) == 0)
		box[j][i / 2] = j + 1;
	else if (sector(i) == 1)
		box[3 - j][(i % 8) / 2] = j + 1;
	else if (sector(i) == 2)
		box[(i / 2) % 4][j] = j + 1;
	else
		box[(i / 2) % 4][3 - j] = j + 1;
}


/*
check the sector (up) and put the 4 accordingly
*/
void	fill_one(int box[4][4], int i)
{
	if (sector(i) == 0)
		box[0][i / 2] = 4;
	else if (sector(i) == 1)
		box[3][(i % 8) / 2] = 4;
	else if (sector(i) == 2)
		box[(i / 2) % 4][0] = 4;
	else
		box[(i / 2) % 4][3] = 4;
}

/*
whenever meet a 4 in clues, call fill_four() (up)
*/
void	prefill_fours(int box[4][4], int input[16])
{
	int	i;
	int	j;

	i = 0;
	while (i < 32)
	{
		if (input[i / 2] == 4)
		{
			j = 0;
			while (j < 4)
			{
				fill_four(box, i, j);
				j++;
			}
		}
		i = i + 2;
	}
}

/*
if found any 1 in clues, fill the first cell with 4
*/
void	prefill_ones(int box[4][4], int input[16])
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (input[i / 2] == 1)
			fill_one(box, i);
		i = i + 2;
	}
}
