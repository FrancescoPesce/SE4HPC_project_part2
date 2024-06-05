# SE4HPCproject - part 2
Repository for the second part of the second project of SE4HPC by Miotti Michele and Francesco Pesce.

## Contents
- The file `test/test_matrix_multiplication.cpp` contains the tests from part 1 that are passed by the
new implementation of the matrix multiplication function.
- The file `Singularity.def` contains a container descriptor for the program.
- The file `job.sh` is used to run the containerized application using SLURM and MPI.
- The file `.github/workflows/ci.yml` contains the Github actions used to execute the pipeline.
- The files `output.txt` and `error.txt` contain the expected output and error from the execution of the application. As an additional step in the Github actions, we compare them with the results from the cluster to make sure the execution worked correctly.
- We made minor changes to the rest of the repository to be able to use the file `src/matrix_mult.cpp` in the tests.
