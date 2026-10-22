/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaryutki <aaryutki@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 14:57:13 by aaryutki          #+#    #+#             */
/*   Updated: 2026/10/18 14:57:15 by aaryutki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		view(int line[4], int rev);
int		unique_line(int line[4]);

/*
iterate through all posible combinations from 1111 to 4444
1. go to next possible value and return 1
*/
int	next_perm(int p[4])
{
	int	i;

	i = 3;
	while (i >= 0)
	{
		if (p[i] < 4)
		{
			p[i]++;
			return (1);
		}
		p[i] = 1;
		i--;
	}
	return (0);
}

/*
call view (see check.c)
1. return 0 if view from 0 (forward) or 1 (backward) didn't match the input number
2. return 0 if the cell is prefilled by another value
*/
int	check_row(int box[4][4], int input[16], int r, int p[4])
{
	int	i;

	if (view(p, 0) != input[r + 8] || view(p, 1) != input[r + 12])
		return (0);
	i = 0;
	while (i < 4)
	{
		if (box[r][i] != 0 && box[r][i] != p[i])
			return (0);
		i++;
	}
	return (1);
}

/*
1. save the row into opt
2. *cnt moves the columns forward, each element in cnt array holds up to 24 permutations
*/
void	save_row(int opt[24][4], int *cnt, int p[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		opt[*cnt][i] = p[i];
		i++;
	}
	(*cnt)++;
}

/*
1. create p array with {1, 1, 1, 1}
2. call unique_line (see check.c) and check_row (up)
3. save_row if it's unique enough (up) and matching the left right clues
4. each row will have at most 24 permutations
5. else call next_perm (up)
*/
void	add_opt(int box[4][4], int input[16], int opt[4][24][4], int cnt[4])
{
	int	p[4];
	int	r;
	int	more;

	p[0] = 1;
	p[1] = 1;
	p[2] = 1;
	p[3] = 1;
	more = 1;
	while (more)
	{
		r = 0;
		while (r < 4)
		{
			if (unique_line(p) && check_row(box, input, r, p))
				save_row(opt[r], &cnt[r], p);
			r++;
		}
		more = next_perm(p);
	}
}

/*
set the cnt array to {0, 0, 0, 0}
1. call add_opt (up)
*/
void	make_opt(int box[4][4], int input[16], int opt[4][24][4], int cnt[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		cnt[i] = 0;
		i++;
	}
	add_opt(box, input, opt, cnt);
}
