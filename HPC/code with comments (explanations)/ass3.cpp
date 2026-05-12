/*Implement Min, Max, Sum and Average operations using Parallel Reduction.*/

#include<iostream>
#include<omp.h> //openMP library
using namespace std;

/*
thread is a small worker inside a program
by default 1 thread is used i.e one task at a time as 1 thread performs all tasks
with multiple threads, work is faster as the workload is distributed among multiple threads

Parallel reduction is a technique used to combine the results of multiple threads in a parallel computation.
or many threads work together to reduce many values into one final value
here, we take an array of many elements. each thread gets few elements. for each operation, threads work and their 
results are combined. for sum operation, 
Thread	Elements
T1	      1,2
T2	      3,4
T3	      5,6
T4	      7,8

Each thread computes simultaneously then results are combined using reduction.

Thread	Partial Sum
T1	3
T2	7
T3	11
T4	15

so final sum is sum of all partial sums of threads. this reduces time taken
*/

int minval(int arr[], int n){ //find minimum value in array
  int minval = arr[0];
  #pragma omp parallel for reduction(min : minval)
  /*
  #pragma= special processor directive, provides additional instructions to compiler
  omp= tells compiler this pragma belongs to openmp
  parallel= run using multiple threads simultaneously.
  for = parallelize the upcoming for loop.
  reduction = combine results from multiple threads safely. this allows combining result and not overwriting
  (min : minval) = (inbuilt operator/function : variable)
  min= reduction operation (while combining thread results, use minimum operation.)
  minval = shared Variable being reduced whose final result is needed.
  */

  /*
  This tells OpenMP to Parallelize code below (loop), Use multiple threads, find min using reduction
  Each thread gets its own private copy of minval.
  Thread	Values Checked	Local Minimum
  T1	    1,2	             1
  T2	    3,4	             3
  T3	    5	               5
  Then OpenMP combines all local minimums: min(1,3,5) = 1
  Without reduction, threads may overwrite each other
  */

    for(int i = 0; i < n; i++){
      if(arr[i] < minval) minval = arr[i];
    }
  return minval;
}

int maxval(int arr[], int n){
  int maxval = arr[0];
  #pragma omp parallel for reduction(max : maxval)
    for(int i = 0; i < n; i++){
      if(arr[i] > maxval) maxval = arr[i];
    }
  return maxval;
}

int sum(int arr[], int n){
  int sum = 0;
  #pragma omp parallel for reduction(+ : sum)
    for(int i = 0; i < n; i++){
      sum += arr[i];
    }
  return sum;
}

double average(int arr[], int n){
  return (double)sum(arr, n) / n;
  //openmp not needed here directly as sum function is called which uses openmp
}

int main(){
  int n = 5;
  int arr[] = {1,2,3,4,4};
  cout << "The minimum value is: " << minval(arr, n) << '\n';
  cout << "The maximum value is: " << maxval(arr, n) << '\n';
  cout << "The summation is: " << sum(arr, n) << '\n';
  cout << "The average is: " << average(arr, n) << '\n';
  return 0;
}
