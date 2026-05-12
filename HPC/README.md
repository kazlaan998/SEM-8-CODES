If colab, do Runtime->Change Runtime type->GPU else it wont run. \

IF CODE NOT RUNNING, its because compiler doesnt support OpenMP\
Instead of installing C++, do it on online compiler.
Use this one as you can set it up to support openmp: https://www.onlinegdb.com/online_c++_compiler \ \
Steps: \
1. On top right, click on settings icon
2. Click on compiler flags
3. Enter -fopenmp in dialog box
4. CLick ok and run
\ \

OpenMP is an API/library used for parallel programming on CPUs i.e use multiple CPU cores at same time.\
It stands for Open Multi Processing\
You write a normal program. Then you add small OpenMP instructions called pragmas.\
Example: #pragma omp parallel\
This tells the compiler: “Run this part using multiple threads.”\
