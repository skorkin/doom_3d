#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>

typedef struct s_vec_d
{
	double		x;
	double		y;
}				t_vec_d;

typedef struct s_vec_int
{
	int	x;
	int	y;
}				t_vec_int;

t_vec_int	sum_v_i(t_vec_int v1, char symb, t_vec_int v2);
t_vec_int	mult_v_i(t_vec_int vec, int coef);
t_vec_int	construct_v_i(int x, int y);

t_vec_d		sum_v_d(t_vec_d v1, t_vec_d v2);
t_vec_d		dif_v_d(t_vec_d v1, t_vec_d v2);
t_vec_d		mult_v_d(t_vec_d vec, double coef);
t_vec_d		construct_v_d(double x, double y);
t_vec_d		vec_i_into_d(t_vec_int vec_int);
t_vec_d		construct_v_d(double x, double y);
t_vec_d		copy_v_d(t_vec_d v1);

#endif