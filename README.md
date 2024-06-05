# SE4HPCproject - part 2
Repository for the second part of the second project of SE4HPC by Miotti Michele and Francesco Pesce.

## Contents
- The file `test/test_matrix_multiplication.cpp` contains the tests from part 1 that are passed by the
new implementation of the matrix multiplication function.
- The file `Singularity.def` contains a container descriptor for the program.
- The file `job.sh` is used to run the containerized application using SLURM and MPI. It is supposed to be executed using sbatch, as using srun may result in issues.
- The file `.github/workflows/ci.yml` contains the Github actions used to execute the pipeline. At the moment of the last commit, the workflow runs with no errors.
- The files `output.txt` and `error.txt` contain the expected output and error from the execution of the application. We verified that they match with the ones obtained on the cluster.
- We made minor changes to the rest of the repository to be able to use the file `src/matrix_mult.cpp` in the tests.
