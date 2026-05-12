Dont forget to: Runtime-> Change runtime type-> GPU->Save (colab, makes runtime very much faster)
OpenMP is an API/library used for parallel programming on CPUs i.e use multiple CPU cores at same time.
It stands for Open Multi Processing
You write a normal program. Then you add small OpenMP instructions called pragmas.
Example: #pragma omp parallel
This tells the compiler: “Run this part using multiple threads.”
