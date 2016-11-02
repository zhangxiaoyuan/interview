/*写一个函数找出一个整数数组中，第二大的数 （microsoft）*/
const int MINNUMBER = -32767 ;
int find_sec_max( int data[] , int count) //类似于1 4 4 4这样的序列将认为1是第二大数
{
    int maxnumber = data[0] ;
    int sec_max = MINNUMBER ;
    
    for ( int i = 1 ; i < count ; i++)
    {
        if ( data[i] > maxnumber )
        {
            sec_max = maxnumber ;
            maxnumber = data[i] ;
        }
        else
        {
           if ( data[i] > sec_max )
                sec_max = data[i] ;
        }
    }
    
    return sec_max ;
}
