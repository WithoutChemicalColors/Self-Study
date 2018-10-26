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

function _Activation_(_main_=false)
    if !_main_
        println('\n', "Import function:")
        println("----------")
        println(_List)
    else
        X = [-20 10 0 20 -30];
        print( sigmoid!(X) );

        print( ReLU!(X) );

        print( tanh.(X) );end
end

_List = ["sigmoid!" "ReLU!" "tanh!"];
