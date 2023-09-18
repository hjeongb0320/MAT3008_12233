
void quadct(x,y,xx,yy,nn,fa,fb,fc,fd)
float *fa,*fb,*fc,*fd,x,xx[],y,yy[];
unsigned long nn;
{
	unsigned long k,na,nb,nc,nd;
	float ff;
	na=nb=nc=nd=0;
	for (k=1;k<=nn;k++) {
		if (yy[k] > y) {
			xx[k] > x ? ++na : ++nb;
		} else {
			xx[k] > x ? ++nd : ++nc;
		}
	}
	ff=1.0/nn;
	*fa=ff*na;
	*fb=ff*nb;
	*fc=ff*nc;
	*fd=ff*nd;
}
