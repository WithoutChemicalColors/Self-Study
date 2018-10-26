struct Cell
    dim::Int
    weights::Array
    name::String
end
    """
        Parameters
        ----------
        UnitCell(dim, init_weight, name="cell")

        Description
        ----------
        create unit cell for DNN

        return
        ----------
            unit::Cell
    """
    function UnitCell(dim::Int, init_weight=nothing, name="cell")
        if init_weight == nothing
            init_weight = zeros(dim, dim);
        end
        unit = Cell(dim, init_weight, name);
        return unit
    end
