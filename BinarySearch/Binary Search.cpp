ll l=1,r=n,mid;

    while(l<=r)
    {
        mid = (l+r)/2;

        if(zeros>=k)  //decrease mid
        {
            r = mid-1;
        }
        else          //incerase mid
        {
            l = mid+1;
        }
    }
