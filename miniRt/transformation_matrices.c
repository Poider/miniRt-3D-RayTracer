#include "./includes/miniRt.h"

//check if rotating by negative theta is the same as inverse of that matrix with positive theta
t_matrices *rotation_x(float angle)
{
	t_matrices *matrix;
	float **m;

	matrix = identity_matrix(DEFAULT_DIMENSION);
	m = matrix->matrix;
	m[1][1] = cos(angle) ;
	m[1][2] = -sin(angle);
	m[2][1] = sin(angle);
	m[2][2] = cos(angle);
	return matrix;
}

t_matrices *rotation_y(float angle)
{
	t_matrices *matrix;
	float **m;

	matrix = identity_matrix(DEFAULT_DIMENSION);
	m = matrix->matrix;
	m[0][0] = cos(angle);
	m[0][2] = sin(angle);
	m[2][0] = -sin(angle);
	m[2][2] = cos(angle);
	return matrix;
}

t_matrices *rotation_z(float angle)
{
	t_matrices *matrix;
	float **m;

	matrix = identity_matrix(DEFAULT_DIMENSION);
	m = matrix->matrix;
	m[0][0] = cos(angle);
	m[0][1] = -sin(angle);
	m[1][0] = sin(angle);
	m[1][1] = cos(angle);
	return matrix;
}

t_matrices *translation(t_tuple vector)
{
	t_matrices *matrix;
	float **m;

	matrix = identity_matrix(DEFAULT_DIMENSION);
	m = matrix->matrix;
	m[0][3] = vector.x;
	m[1][3] = vector.y;
	m[2][3] = vector.z;
	return matrix;
}

t_matrices *scaling(t_tuple vector)
{
	t_matrices *matrix;
	float **m;

	matrix = identity_matrix(DEFAULT_DIMENSION);
	m = matrix->matrix;
	m[0][0] = vector.x;
	m[1][1] = vector.y;
	m[2][2] = vector.z;
	return matrix;
}

t_matrices *shearing(t_shear shear)
{
	t_matrices *matrix;
	float **m;

	matrix = identity_matrix(DEFAULT_DIMENSION);
	m = matrix->matrix;
	m[0][1] = shear.Hxy;
	m[0][2] = shear.Hxz;
	m[1][0] = shear.Hyx;
	m[1][2] = shear.Hyz;
	m[2][0] = shear.Hzx;
	m[2][1] = shear.Hzy;
	return matrix;
}
