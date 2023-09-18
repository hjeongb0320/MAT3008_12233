
static float xsav,ysav;
static float (*nrfunc)();

float quad3d(func,x1,x2)
float (*func)(),x1,x2;
{
	float f1(),qgaus();

	nrfunc=func;
	return qgaus(f1,x1,x2);
}

float f1(x)
float x;
{
	float f2(),qgaus();
	float yy1(),yy2();

	xsav=x;
	return qgaus(f2,yy1(x),yy2(x));
}

float f2(y)
float y;
{
	float f3(),qgaus();
	float z1(),z2();

	ysav=y;
	return qgaus(f3,z1(xsav,y),z2(xsav,y));
}

float f3(z)
float z;
{
	return (*nrfunc)(xsav,ysav,z);
}
