// queens algorithm |

sos(k,s,r,w,n,d)
{
    if(s+r<d) return;

    if(s+w[k]>d) return;

    if(s == d) write(x[1:n])

    x[k]=0; if(k<n) sos(k+1, s, r-w[k], w, n, d)

    x[k]=1; if(k<n) sos(k+1, s+w[k], r-w[k], w, n, d)
}