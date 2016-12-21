#include<iostream>
// function prototype //
void copyMatrix(double source[10][10],double aim[10][10]);
void initialize(double matrix[10][10]);
void print(double matrix[10][10]);
void calculateinner(double source[10][10],double aim[10][10]);
void calculatebound(double source[10][10],double aim[10][10]);
void calculatecorner(double source[10][10],double aim[10][10]);
using namespace std;

int main()
{
	cout << fixed <<showpoint;
	cout.precision(5);
	
	//---------------question (a)------------------
	double a[10][10],b[10][10];
	
	initialize(a);
	initialize(b);
	
	cout << " (a)  The original matrix is "<<'\n';
	print(a);
    cout << "\n\n\n\n";
	
	
    for(int k=1;k<20;++k)
	{
		calculateinner(a,b);
		calculatebound(a,b);
		calculatecorner(a,b);
		copyMatrix(b,a);
	}
	
	cout << "      The final matrix is "<<'\n';
	print(b);
	cout << "\n\n\n\n";
	
	
	//----------------question (b)------------------
	double c[10][10];
	initialize(c);
	
	cout << " (b)  The original matrix is "<<'\n';
	print(c);
	cout << "\n\n\n\n";
	
	for(int k=1;k<20;++k)
	{
		calculateinner(c,c);
		calculatebound(c,c);
		calculatecorner(c,c);
		
	}
	
	
	cout << "       The final matrix is "<<'\n';
	print(c);
	return 0;		
	
}

void copyMatrix(double source[10][10],double aim[10][10])
{
	for(int i=0;i<10;++i)
	{
		for(int j=0;j<10;++j)
		{
			aim[i][j]=source[i][j];
		}
	}
	return ; 
}

void initialize(double matrix[10][10])
{
	for(int i=0;i<10;++i)
	{
		matrix[i][0]=1.0;
		for(int j=1;j<10;++j)
		{
			matrix[i][j]=0;
		}
	}
}

void print(double matrix[10][10])
{
	for(int i=0;i<10;++i)
	{
		for(int j=0;j<10;++j)
		{
			cout << matrix[i][j];
			cout << '\t';
		}
		cout << '\n';
		
	}
}

void calculateinner(double source[10][10],double aim[10][10])
{
	for(int i=1;i<9;++i)
	    {
			for(int j=1;j<9;++j)
			{
				aim[i][j]=(source[i-1][j]+source[i+1][j]+source[i][j-1]+source[i][j+1])/4;
		    }
	    }
}
void calculatebound(double source[10][10],double aim[10][10])
{
	for(int i=1;i<9;++i)
	{
		aim[0][i]=(source[0][i+1]+source[0][i-1]+source[1][i])/3;
	    aim[9][i]=(source[9][i+1]+source[9][i-1]+source[8][i])/3;
		aim[i][9]=(source[i-1][9]+source[i+1][9]+source[i][8])/3;
	}
}
void calculatecorner(double source[10][10],double aim[10][10])
{
	aim[0][9]=(source[0][8]+source[1][9])/2;
	aim[9][9]=(source[8][9]+source[9][8])/2;
}