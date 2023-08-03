
Matrix Matrix::operator*(Matrix x)
{ 
	Matrix c;
	int i,j,k;
	if(n==x.m)
	{ 
		c.m=m;
		c.n=x.n;
		for(i=0;i<m;i++)
		{
			for(j=0;j<x.n;j++)
			{ 
				c.a[i][j]=0;
			}