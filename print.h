void printBoard(char board[24][40])
{
    int n=8;
    cout<<"      A    B    C    D    E    F    G    H  \n ";
    for(int i=0;i<46;i++)
        cout<<":";
    cout<<endl;
    for(int i=0;i<24;i++)
    {
        if(i%3==1)
        cout<<n<<":: ";
        else
        cout<<" :: ";
        for(int j=0;j<40;j++)
        {
            cout<<board[i][j];
        }
        cout<<" ::";
        if(i%3==1)
        {
            cout<<" "<<n;
            n--;
        }
        cout<<endl;
    }
        cout<<" ";
        for(int i=0;i<46;i++)
        cout<<":";
    cout<<"\n      A    B    C    D    E    F    G    H  \n";
}
