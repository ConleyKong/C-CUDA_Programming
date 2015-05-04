 /**
  2   this program is the first program that uses the NVIDIA GPU to do some thing
  3   alrough this thing is really easy, but it really asked GPU to do things.
  4   and this thing will be modified to a more optimized status.
  5   james leng
  6   lengjiabing
  7   2015.4.25
	test if make change can successfully updated
  8  */
  9 #include<stdio.h>
 10 #include<stdlib.h>
 11 #include<cuda_runtime.h>
 12 
 13 #define DATA_SIZE 1048576
 14 
 15 int data[DATA_SIZE];
 16 
 17 void GenerateNumbers(int *number, int size)
 18 {
 19     for(int i = 0; i < size; i++)
 20     {
 21         number[i] = rand() % 10;
 22     }
 23 }
 24 
 25 //this defines a global function, we it is called, this piece of code will be executed on GPU
 26 __global__ static void sumOfSquares(int *num, int * result)
 27 {
 28     int sum = 0;
 29     int i;
 30     for(i = 0; i < DATA_SIZE; i++)
 31     {
 32         sum += num[i]*num[i];
 33     }
 34 
 35     *result = sum;
 36 }

int main(){
 40 
 41 
 42     GenerateNumbers(data, DATA_SIZE);
 43 
 44 
 45     //the variables must be defined to a pointer, beacuse they are pointers assigned on CPU's memory
 46     //and they just pointed to a memory block on GPU
 47 
 48     int * gpudata, *result;
 49     cudaMalloc((void**)&gpudata,sizeof(int)*DATA_SIZE);
 50     cudaMalloc((void**)&result,sizeof(int));
 51     cudaMemcpy(gpudata,data,sizeof(int)*DATA_SIZE,cudaMemcpyHostToDevice);
 52 
 53     sumOfSquares<<<1,1,0>>>(gpudata,result);
 54 
 55     int sum;
 56     cudaMemcpy(&sum,result,sizeof(int),cudaMemcpyDeviceToHost);
 57     cudaFree(gpudata);
 58     cudaFree(result);
 59 
 60     printf("the result did by GPU is:sum:%d\n",sum);
 61 
 62     //this piece of code is used to verify the result
 63     int sumCPU = 0;
 64     for(int i = 0; i < DATA_SIZE; i++)
 65     {
 66         sumCPU += data[i]*data[i];
 67     }
 68 
 69     printf("the result did by CPU is:sum:%d\n",sumCPU);
 70 }
