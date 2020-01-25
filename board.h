void fillboard(char board[24][40])
{
   int n1=0,n2=0,c,j1,j2,i=-1,i2,d;
   for(j2=0;j2<8;j2++)
   {
        if(n2==0)
        {
            for(i2=0;i2<3;i2++)
            {
                i++;
                c=-1;
                for(j1=0;j1<8;j++)
                {
                    if(n1==0)
                    {
                        for(d=0;d<5;d++)
                        {
                            c++;
                            board[i][c]=(char)219u;
                        }
                    }
                    else if(n1==1)
                    {
                        for(d=0;d<5;d++)
                        {
                           c++;
                           board[i][c]=' ';
                        }
                    }
                    n1==1 ? n1=0 : n1=1;
                }
            }
        }
    else if(n2==1)
        {
                for(i2=0;i2<3;i2++)
                {
                    i++;
                    c=-1;
                    for(j1=0;j1<8;j1++)
                    {
                        if(n1==0)
                        {
                            for(d=0;d<5;d++)
                            {
                                c++;
                                board[i][c]='p';
                            }
                        }
                        else if(n1==1)
                        {
                            for(d=0;d<5;d++)
                            {
                               c++;
                               board[i][c]=(char)219u;
                            }
                        }
                        n1==1 ? n1=0 : n1=1;
                    }
                }
        }
    n2==0 ? n2=1 : n2=0;
   }
}
