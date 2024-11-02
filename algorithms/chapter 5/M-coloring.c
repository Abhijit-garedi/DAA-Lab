// M Coloring Algorithm
{
    repeat
    {
        NEXT VALUE(k);

        if(x[k]= 0) then return;

        if(x = n) then write(x[1:n])

        else MCOLOURING(k + 1)
    }
     until(false);
}