
float bessy(n,x)
float x;
int n;
{
	float bessy0(),bessy1();
	void nrerror();
	int j;
	float by,bym,byp,tox;

	if (n < 2) nrerror("Index n less than 2 in bessy");
	tox=2.0/x;
	by=bessy1(x);
	bym=bessy0(x);
	for (j=1;j<n;j++) {
		byp=j*tox*by-bym;
		bym=by;
		by=byp;
	}
	return by;
}
