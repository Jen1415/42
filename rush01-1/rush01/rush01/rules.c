/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaryutki <aaryutki@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 14:57:20 by aaryutki          #+#    #+#             */
/*   Updated: 2026/10/18 14:57:22 by aaryutki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	prefill_fours(int box[4][4], int input[16]);
void	prefill_ones(int box[4][4], int input[16]);

/*
1. check the opposite site pairing
2. if 2 opposite 3
3. the position is: 2 pov => ? 4 ? ? <= 3 pov
*/
void	pair_23(int box[4][4], int input[16])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (input[i] == 2 && input[i + 4] == 3)
			box[1][i] = 4;
		if (input[i] == 3 && input[i + 4] == 2)
			box[2][i] = 4;
		if (input[i + 8] == 2 && input[i + 12] == 3)
			box[i][1] = 4;
		if (input[i + 8] == 3 && input[i + 12] == 2)
			box[i][2] = 4;
		i++;
	}
}

/*
1. check the opposite site pairing
2. if 1 opposite 2
3. the position is: 1 pov => 4 ? 3 ? <= 2 pov
*/
void	pair_12(int box[4][4], int input[16])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (input[i] == 1 && input[i + 4] == 2)
			box[3][i] = 3;
		if (input[i] == 2 && input[i + 4] == 1)
			box[0][i] = 3;
		if (input[i + 8] == 1 && input[i + 12] == 2)
			box[i][3] = 3;
		if (input[i + 8] == 2 && input[i + 12] == 1)
			box[i][0] = 3;
		i++;
	}
}

/*
call 4 helper functions that fill certain numbers first
1. prefill_fours (see edges.c) that fill 1 2 3 4 whenever meet a 4 in clues
2. prefill_ones (see edges.c) that fill a 4 whenever meet a 1 in clues
3. pair_23 (up)
4. pair_12 (up)
*/

void	prefill(int box[4][4], int input[16])
{
	prefill_fours(box, input);
	prefill_ones(box, input);
	pair_23(box, input);
	pair_12(box, input);
}
