const int mod = 1e9+7;

const int MatSize = 2;
struct Matrix
{
	long long mat[MatSize][MatSize];
};

Matrix MatMul(Matrix &a , Matrix &b)
{
	Matrix res;
    for(int i = 0 ; i<MatSize ; i++)
	for(int j = 0 ; j<MatSize ; j++)
    {
        res.arr[i][j] = 0;
        for(int k = 0 ; k<MatSize ; k++)
        {
            long long sum = a.arr[i][k] * b.arr[k][j];
            sum%=mod;
            res.arr[i][j] +=sum;
            res.arr[i][j]%=mod;
        }
   }
   return res;
}

Matrix MatIdentity()
{
	Matrix res;
	for(int i = 0 ; i<MatSize ; i++)
    	for(int j = 0 ; j<MatSize ; j++)
     	res.arr[i][j] = (i==j);
	return res;
}

Matrix MatPower(Matrix a , long long x)
{
	Matrix res = MatIdentity();
	while(x)
	{
    	if(x&1)
    	{
        	res = MatMul(res , a);
    	}
    	a = MatMul(a,a);
    	x>>=1;
	}
	return res;
}