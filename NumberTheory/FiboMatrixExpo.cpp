#include<bits/stdc++.h>
using namespace std;

/*fibo(n) return nth Fibonacci number */


void multiply(int F[2][2], int M[2][2]) 
{ 
  int x =  ((F[0][0])*(M[0][0])) + ((F[0][1])*(M[1][0])); 
  int y =  ((F[0][0])*(M[0][1])) + ((F[0][1])*(M[1][1])); 
  int z =  ((F[1][0])*(M[0][0])) + ((F[1][1])*(M[1][0])); 
  int w =  ((F[1][0])*(M[0][1])) + ((F[1][1])*(M[1][1])); 
  
  F[0][0] = x; 
  F[0][1] = y; 
  F[1][0] = z; 
  F[1][1] = w; 
} 

int power(int F[2][2], int n) 
{ 
  int M[2][2] = {{1,1},{1,0}}; 
  if(n==1)return F[0][0];
  power(F,n/2);
  multiply(F,F);
  if(n&1)multiply(F,M);
  return F[0][0];
}

int fibo(int n) 
{ 
  int F[2][2] = {{1,1},{1,0}}; 
  if (n == 1) 
      return 0;
  if(n==2){
  	return 1;
  }
  power(F, n-2); 
  return F[0][0]; 
} 

int main(){
	return 0;
}