# <Gauss Elimintaion with pivoting strategy>
using Printf

    """
    <Function>
    ----------
        GE!(Mat::Array{T}) where T <: Number

    <Description>
    ----------
        Ordinary Gauss Elimination ≝ Normal GE
    """
    function GE!(Mat::Array{T}) where T <: Number
        nrows, ncols = size(Mat);

        for step::Int in 1 : nrows-1
            pivot::Float32 = Mat[step,step];
            for row::Int in step+1 : nrows
                ratio::Float32 = Mat[row,step]/pivot;
                Mat[row,step] = 0;
                for col::Int in step+1 : ncols
                    Mat[row,col] = Mat[row,col] - ratio*Mat[step,col];
        end end end
    end


    """
    <Function>
    ----------
        pGE!(Mat::Array{T}) where T <: Number

    <Description>
    ----------
        Gauss Elimination with pivoting ≝ GE + partial pivoting
    """
    function pGE!(Mat::Array{T}) where T <: Number
        nrows, ncols = size(Mat);
        rv::Vector{Int} = Vector(1:nrows);

        for step::Int in 1 : nrows-1
            # choose the correct pivot -> by rearrange row vector: rv.

            max_ele, max_rv_id = findmax( abs.(Mat[rv[step:end],step]) );
            max_id::Int = rv[step:end][max_rv_id];
            rv[max_id] = rv[step];
            rv[step] = max_id;

            # Again get pivot
            pivot::Number = Mat[rv[step],step];
            for row::Int in step+1 : nrows
                ratio::Number = Mat[rv[row],step] / pivot;

                Mat[rv[row],step] = 0;
                for col::Int in step+1 : ncols
                    Mat[rv[row],col] = Mat[rv[row],col] - ratio*Mat[rv[step], col];
                end
            end
        end
    end

    """
    <Function>
    ----------
        spGE!(Mat::Array{T}) where T <: Number

    <Description>
    ----------
        Gauss Elimination with scaled pivoting ≝ GE + scaled partial pivoting
    """
    function spGE!(Mat::Array{T}) where T <: Number
        @error "Start New Term"
        nrows, ncols = size(Mat);
        rv::Vector{Int} = Vector(1:nrows);
        sv::Vector{Number} = [maximum(abs.(Mat[x,1:end-1])) for x in 1:nrows];
        for step::Int in 1 : nrows-1
            @warn "matrix:" Mat
            # choose the correct scaled pivot
            scale = abs.(Mat[rv[step:end],step] ./ sv[rv[step:end]]);
            @info "scale:" scale
            max_ele, max_rv_id = findmax(scale);
            max_id::Int = rv[step:end][max_rv_id];
            rv[max_id] = rv[step];
            rv[step] = max_id;

            # Again get pivot
            pivot::Float32 = Mat[rv[step],step];
            for row::Int in step+1 : nrows
                ratio::Float32 = Mat[rv[row],step] / pivot;

                Mat[rv[row],step] = 0;
                for col::Int in step+1 : ncols
                    Mat[rv[row],col] = Mat[rv[row],col] - ratio*Mat[rv[step], col];
                end
            end
        end
    end

A = [ 1 2;
      3 4; ]

B = float.([ 3  1  4 -1    7;
             2 -2 -1  2    1;
             5  7 14 -8   20;
             1  3  2  4   -4; ] );
# GE!(A);
# pGE!(B)
spGE!(B)

@error "Ans:" B
