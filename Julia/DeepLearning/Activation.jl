
    """
        sigmoid!(x::Array)

    ---------
                  1
        σ(x) = --------
                1 + eˣ
    """
    function sigmoid!(x::Array)
        return 1 ./ 1 .+ exp.(-x); end

    """
    ReLU!(x::Array)

    ---------
        ReLu(x) = max(0, x)

    """
    function ReLU!(x::Array)
        killer = (x .<= 0);
        x[killer] .= 0;
    return x end

    """
        tanh!(x::Array)

    ---------
               eˣ - e⁻ˣ
        tanh = --------
               eˣ + e⁻ˣ
    """
    function tanh!(x::Array)
        return tanh.(x) end


X = [-20 10 0 20 -30];
print( sigmoid!(X) );

print( ReLU!(X) )

print( tanh.(X) );
