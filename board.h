void fillboard(char board[24][40])
{
   int n=0,n2=0,c,j,j2,i=-1,i2,d;
   for(j2=0;j2<8;j2++)
   {
        if(n2==0)
        {
            for(i2=0;i2<3;i2++)
            {
                i++;
                c=-1;
                for(j=0;j<8;j++)
                {
                    if(n==0)
                    {
                        for(d=0;d<5;d++)
                        {
                            c++;
                            board[i][c]=(char)219u;
                        }
                    }
                    else if(n==1)
                    {
                        for(d=0;d<5;d++)
                        {
                           c++;
                           board[i][c]=' ';
                        }
                    }
                    n==1 ? n=0 : n=1;
                }
            }
        }
    else if(n2==1)
        {
                for(i2=0;i2<3;i2++)
                {
                    i++;
                    c=-1;
                    for(j=0;j<8;j++)
                    {
                        if(n==0)
                        {
                            for(d=0;d<5;d++)
                            {
                                c++;
                                board[i][c]='p';
                            }
                        }
                        else if(n==1)
                        {
                            for(d=0;d<5;d++)
                            {
                               c++;
                               board[i][c]=(char)219u;
                            }
                        }
                        n==1 ? n=0 : n=1;
                    }
                }
        }
    n2==0 ? n2=1 : n2=0;
   }
}
