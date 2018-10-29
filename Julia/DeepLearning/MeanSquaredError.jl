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


y_pred = float.( [ x^2 for x in 1:5 ] );
y_true = zeros(5);
