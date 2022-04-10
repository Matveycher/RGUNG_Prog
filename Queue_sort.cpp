void sortq(queue **pphead)
{
    int l=0;
    if (isEmpty(*pphead))
    {
        cout<<"queue is empty."<<endl;
    }
    else
    {
        queue *cptr=*pphead;
        while (cptr!=NULL)
        {
            ++l;
            cptr=cptr->nextEl;
        }
        int *tempA=new int [l];
        cptr=*pphead;
        int i=0;
        while (cptr!=NULL)
        {
            tempA[i]=cptr->info;
            cptr=cptr->nextEl;
            i++;
        }
        for (i=0;i<l-1;i++)
        {
            for (int j=0;j<l-i-1;j++)
            {
                if (tempA[j]>tempA[j+1])
                {
                    int temp=tempA[j];
                    tempA[j]=tempA[j+1];
                    tempA[j+1]=temp;
                }
            }
        }
        cptr=*pphead;
        i=0;
        while (cptr!=NULL)
        {
            cptr->info=tempA[i];
            cptr=cptr->nextEl;
            i++;
        }
	delete[] tempA;
    }

}
