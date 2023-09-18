
void slvsml(u,rhs)
double **rhs,**u;
{
	void fill0();
	double h=0.5;

	fill0(u,3);
	u[2][2] = -h*h*rhs[2][2]/4.0;
}
