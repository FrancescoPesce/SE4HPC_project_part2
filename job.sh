#!/bin/bash
#SBATCH --partition=g100_all_serial ## Partition.
#SBATCH --job-name=matrixMult ## Name of the job.
#SBATCH --output=output.txt ## Output file.
#SBATCH --error=error.txt ## Error file.
#SBATCH --time=00:00:10 ## Job Duration.
#SBATCH --nodes=1 ## Number of nodes.
#SBATCH --ntasks-per-node=2 ## Number of MPI processes.

## Load MPI.
module load openmpi

## Define the path to the Singularity Image File.
SIF_FILE="myimage.sif"

## Run the application within the Singularity container using MPI.
srun singularity exec "$SIF_FILE" main
