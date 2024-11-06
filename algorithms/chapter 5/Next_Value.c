// algorithm for next value(k)

/*

{ repeat

 { x(k) := (X(k) + 1)mod(m + 1);

  f(X(k) = 0) then return;

     for j := 1 to n do 

      { if( GRAPH(k,j) and 

          X(k) = X(j))

          then break;
      
      }
       
       if( j = n + 1) then return;

  } until(false);
 
 }

*/