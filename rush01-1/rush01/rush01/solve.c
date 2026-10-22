/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaryutki <aaryutki@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 14:57:25 by aaryutki          #+#    #+#             */
/*   Updated: 2026/10/18 14:57:26 by aaryutki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_cols(int box[4][4], int input[16]);
void	make_opt(int box[4][4], int input[16], int opt[4][24][4], int cnt[4]);

/*
1. take 4 rows that picked by next_pick (down)
2. copy them to the grid
*/
void	choose_rows(int box[4][4], int opt[4][24][4], int pick[4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			box[i][j] = opt[i][pick[i]][j];
			j++;
		}
		i++;
	}
}

pick =  {0, 0, 1, 0}


/*
1. increment the last row's pick by 1
2. return 1 if the value is still less then the row's candidates count
3. otherwise reset it to 0 
4. move the next row by 1
5. return 0 if no more combinations
*/
int	next_pick(int pick[4], int cnt[4])
{
	int	i;

	i = 3;
	while (i >= 0)
	{
		pick[i]++;
		if (pick[i] < cnt[i])
			return (1);
		pick[i] = 0;
		i--;
	}
	return (0);
}


/*
opt: array with 4 rows (for leading 1 to 4), 24 columns, each column holds a 4 digits 
1. call make_opt (see permutations.c) to set all possible candidates
2. if any cnt counters never moves, return 0 (as the input is wrong)
3. call choose_rows (up)
4. then check_cols (see check.c)
5. then next_pick (up) 
6. keep looping until no more next pick value then return 0
*/
int	solve(int box[4][4], int input[16])
{
	int	opt[4][24][4];
	int	cnt[4];
	int	pick[4];
	int	i;

	make_opt(box, input, opt, cnt);
	i = 0;
	while (i < 4)
	{
		if (cnt[i] == 0)
			return (0);
		pick[i] = 0;
		i++;
	}
	while (1)
	{
		choose_rows(box, opt, pick);
		if (check_cols(box, input))
			return (1);
		if (next_pick(pick, cnt) == 0)
			return (0);
	}
}
