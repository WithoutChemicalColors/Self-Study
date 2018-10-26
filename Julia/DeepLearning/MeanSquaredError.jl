using LinearAlgebra
#Loss function
    """
        Description
        ----------
                    ∑(yₜ-yₚ)²
            MSE = ------------
                       n
    """
    function MSE(y_true::Vector{T}, y_pred::Vector{T}) where T <: Number
        dif = y_true - y_pred;
        dif = dot(dif, dif)/length(y_pred);
        return dif
    end

# Gradicent Descent
function GD(y_true::AbstractVector{<:Number}, y_pred::AbstractVector{<:Number}, lr=.001)
    println(y_true)
    dim = length(y_true);
    grad = float.(zeros(dim));
    for idx in 1:dim
        δᵥ = zeros(dim);
        δᵥ[idx] = 1;
        δᵥ[idx] = MSE(y_true, y_pred+δᵥ);
        δᵥ = δᵥ ./ dot(δᵥ, δᵥ);
        grad += δᵥ;
    end
    y_pred -= lr*grad;
    return y_pred
end

y_pred = float.( [ x^2 for x in 1:5 ] );
y_true = zeros(5);

ans = MSE(y_true, y_pred)

ans = GD(y_pred, y_true)
println(ans)
