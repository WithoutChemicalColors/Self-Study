# It's an example domo.
# reference
# #https://juliadata.github.io/DataFrames.jl/stable/man/getting_started.html


# Julia : DataFrames  is similar to Python : pandas
# However if you want to read csv, module CSV is recommanded.
using DataFrames, CSV, PyPlot, StatsBase, Printf
#--------------------------------------------------------------------------
path = "..\\OtherFiles\\data1.txt"
# ?CSV.read is your good friend.
# df = CSV.read(path, delim=" ", header=true);
# However it doesn't work here...
#--------------------------------------------------------------------------
# you can skip this part( create array used to generate dataframe )
lines = [ ];
open(path) do f
    for line in eachline(f)
        push!(lines, split(line)); end end

buffer = Dict{ String, Array{Float32} }(key=>[] for key in lines[1]);

for row in 2:length(lines)
    for (key, col) in zip(lines[1], lines[row])
        try
            append!(buffer[key], parse(Float32, col));
        catch
            println(row, " : ", key," : ", col) end end end
#--------------------------------------------------------------------------
#
# Start from here
#
df = DataFrame(buffer);
df = df[[:HCHO, :catalyst, :temp, :time, :press]];
println( head(df) );
plot(df.HCHO, df.press);
@printf("%.4f", variation(df.press));
