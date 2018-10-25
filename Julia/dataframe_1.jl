# Quick Start
# <b> reference </b> : 
# 1. https://juliadata.github.io/DataFrames.jl/stable/man/getting_started.html
using DataFrames

# Simple startup
df = DataFrame(A = 1:4, B = ["M", "F", "F", "M"]);

# Fill the empty dataframe
df = DataFrame();
df.A = 1:5;
df.B = ["1";"2";"3";"4";"5"];
df.C = [ 2,3,4,5,6];

print("Size of this dataframe is ", size(df))

# initialize with type declaration
df = DataFrame(A = Int[], B = String[]);

push!(df, (1, "M"));
push!(df, (2, "M"));