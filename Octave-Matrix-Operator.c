#include<stdio.h>
#include<stdlib.h>
void FREE_SPACE(int **a,int linie)
{
    int i;
    for(i=0;i<linie;i++)
    {
        free(a[i]);
    }
    free(a);

}
void MODIFY_VALUES(int ***a,int *linie,int*coloana,int *sum,int val)
{


    a[val-1] = (int**)malloc(sizeof(int*)*linie[val]);
    for(int i=0;i<linie[val];i++)
    {
        a[val-1][i] = (int*)malloc(sizeof(int)*coloana[val]);
        //printf("??");
        for(int j=0;j<coloana[val];j++)
        {
            a[val-1][i][j]=a[val][i][j];
        }
    }
    linie[val-1]=linie[val];
    coloana[val-1]=coloana[val];
    sum[val-1]=sum[val];
}
void power_matrix(int **a,int**b,int linie,int *suma)
{
    int i,j,z;
    long long val=0;
    int **elem;
    *suma=0;
    elem = (int**) malloc(sizeof(int*)*linie);
    for(i=0;i<linie;i++)
    {
        elem[i] = (int*) malloc(sizeof(int)*linie);
        for(j=0;j<linie;j++)
        {
            for(z=0;z<linie;z++)
            {
                val+=(a[i][z]*b[z][j]);

            }
            if(val>=10007)
                elem[i][j]=val%10007;

        }
    }
    for(i=0;i<linie;i++)
    {
        for(j=0;j<linie;j++)
         {
            a[i][j]=elem[i][j];
            *suma+=a[i][j];
         }
        free(elem[i]);
    }
    if(*suma>=10007)
        *suma%=10007;

    free(elem);

}
void swap(int*** a,int i,int j, int *linie,int *coloana,int *sum)
{
    int **copy, linie_copy, coloana_copy,sum_copy;
    copy = (int**) malloc(linie[i]*sizeof(int*));
    int m,n;
    for(m=0;m<linie[i];m++)
    {
        copy[m] = (int*) malloc(coloana[i] *sizeof(int));

        for(n=0;n<coloana[i];n++)
        {
            copy[m][n]=a[i][m][n];
        }
    }
    linie_copy = linie[i];
    coloana_copy = coloana[i];
    sum_copy = sum[i];


    for(m=0;m<linie[i];m++)
    {
        free(a[i][m]);
    }
    free(a[i]);
    a[i] = (int**) malloc(linie[j]*sizeof(int*));
    for(m=0;m<linie[j];m++)
    {
     a[i][m] = (int*) malloc(coloana[j] *sizeof(int));
     for(n=0;n<coloana[j];n++)
     {
         a[i][m][n]=a[j][m][n];
     }
    }

    linie[i]=linie[j];
    coloana[i]=coloana[j];
    sum[i]=sum[j];

    for(m=0;m<linie[j];m++)
    {
        free(a[j][m]);
    }
    free(a[j]);
    a[j] = (int**) malloc(linie_copy*sizeof(int*));

    for(m=0;m<linie_copy;m++)
    {
     a[j][m] = (int*) malloc(coloana_copy *sizeof(int));
     for(n=0;n<coloana_copy;n++)
     {
         a[j][m][n]=copy[m][n];
     }
    }


    linie[j]=linie_copy;
    coloana[j]=coloana_copy;
    sum[j]=sum_copy;
   // printf("FHFH");
    for(m=0;m<linie_copy;m++)
    {
      free(copy[m]);
    }
    free(copy);




}
int partition(int ***a,int *linie,int *coloana,int *sum, int start, int end)
{

    int pivot = sum[end];
    int i = (start - 1);
    for (int j = start; j <= end - 1; j++) {
        if (sum[j] < pivot) {
             i++;
            swap(a,i,j,linie,coloana,sum);

        }
    }
    swap(a,i+1,end,linie,coloana,sum);
    return (i + 1);
}
void quickSort(int ***a,int *linie,int *coloana,int *sum, int start, int end)
{
    if(start<end)
    {
        int pi = partition(a,linie,coloana,sum,start,end);
        quickSort(a,linie,coloana,sum,start,pi-1);
        quickSort(a,linie,coloana,sum,pi+1,end);
    }
}
void add(int n, int **A,int **B, int **C) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j]=A[i][j]+B[i][j];
            if(C[i][j]>=10007)
                C[i][j]=C[i][j]%10007;
        }
    }
}
void subtract(int n, int **A,int **B, int **C) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
                C[i][j]=A[i][j]-B[i][j];

        }
    }
}
void Strassen(int **A,int **B,int **C,int n,int *suma)
{
    if (n == 1) {
           // printf("FFHH\n");
        C[0][0] = A[0][0] * B[0][0];
        if(C[0][0]>=10007)
            C[0][0]%=10007;

        return;
    }
   // printf("!!\n");
    int **a,**b,**c,**d,**e,**f,**g,**h;
    int **p1,**p2,**p3,**p4,**p5,**p6,**p7;

    int **a1,**b1,**c1,**d1,**copy1,**copy2;
    a = (int**)malloc(sizeof(int*)*(n/2+1));
    b = (int**)malloc(sizeof(int*)*(n/2+1));
    c = (int**)malloc(sizeof(int*)*(n/2+1));
    d = (int**)malloc(sizeof(int*)*(n/2+1));

    e = (int**)malloc(sizeof(int*)*(n/2+1));
    f = (int**)malloc(sizeof(int*)*(n/2+1));
    g = (int**)malloc(sizeof(int*)*(n/2+1));
    h = (int**)malloc(sizeof(int*)*(n/2+1));

    a1 = (int**)malloc(sizeof(int*)*(n/2+1));
    b1 = (int**)malloc(sizeof(int*)*(n/2+1));
    c1 = (int**)malloc(sizeof(int*)*(n/2+1));
    d1 = (int**)malloc(sizeof(int*)*(n/2+1));

    p1 = (int**)malloc(sizeof(int*)*(n/2+1));
    p2 = (int**)malloc(sizeof(int*)*(n/2+1));
    p3 = (int**)malloc(sizeof(int*)*(n/2+1));
    p4 = (int**)malloc(sizeof(int*)*(n/2+1));
    p5 = (int**)malloc(sizeof(int*)*(n/2+1));
    p6 = (int**)malloc(sizeof(int*)*(n/2+1));
    p7 = (int**)malloc(sizeof(int*)*(n/2+1));

    copy1 = (int**)malloc(sizeof(int*)*(n/2+1));
    copy2 = (int**)malloc(sizeof(int*)*(n/2+1));


    for(int i=0;i<n/2;i++)
    {
        a[i]=(int*)malloc(sizeof(int)*(n/2));
        b[i]=(int*)malloc(sizeof(int)*(n/2));
        c[i]=(int*)malloc(sizeof(int)*(n/2));
        d[i]=(int*)malloc(sizeof(int)*(n/2));

        e[i]=(int*)malloc(sizeof(int)*(n/2));
        f[i]=(int*)malloc(sizeof(int)*(n/2));
        g[i]=(int*)malloc(sizeof(int)*(n/2));
        h[i]=(int*)malloc(sizeof(int)*(n/2));

        a1[i]=(int*)malloc(sizeof(int)*(n/2));
        b1[i]=(int*)malloc(sizeof(int)*(n/2));
        c1[i]=(int*)malloc(sizeof(int)*(n/2));
        d1[i]=(int*)malloc(sizeof(int)*(n/2));

        p1[i] = (int*)malloc(sizeof(int)*(n/2));
        p2[i] = (int*)malloc(sizeof(int)*(n/2));
        p3[i] = (int*)malloc(sizeof(int)*(n/2));
        p4[i] = (int*)malloc(sizeof(int)*(n/2));
        p5[i] = (int*)malloc(sizeof(int)*(n/2));
        p6[i] = (int*)malloc(sizeof(int)*(n/2));
        p7[i] = (int*)malloc(sizeof(int)*(n/2));

        copy1[i] = (int*)malloc(sizeof(int)*(n/2));
        copy2[i] = (int*)malloc(sizeof(int)*(n/2));
      //  printf("FGFG");
        for(int j=0;j<n/2;j++)
        {
            //printf("%d\n",j);
            a[i][j]=A[i][j];
            //printf("%d %d",n,A[i][j+(n/2)]);
            b[i][j]=A[i][j+(n/2)];
            c[i][j]=A[i+(n/2)][j];
            d[i][j]=A[i+(n/2)][j+(n/2)];
            e[i][j]=B[i][j];
            f[i][j]=B[i][j+(n/2)];
            g[i][j]=B[i+(n/2)][j];
            h[i][j]=B[i+(n/2)][j+(n/2)];
            //printf("%d %d %d %d\n",a[i][j],b[i][j],c[i][j],d[i][j]);

        }
       // printf("\n");

       // printf("HFHF");


    }
  //  printf("DDHH");
    add(n/2,a,d,copy1);
    add(n/2,e,h,copy2);
    Strassen(copy1,copy2,p1,n/2,suma);

    subtract(n/2,g,e,copy1);
    Strassen(d,copy1,p2,n/2,suma);

    add(n/2,a,b,copy1);
    Strassen(copy1,h,p3,n/2,suma);

    subtract(n/2,b,d,copy1);
    add(n/2,g,h,copy2);
    Strassen(copy1,copy2,p4,n/2,suma);

    subtract(n/2,f,h,copy1);
    Strassen(a,copy1,p5,n/2,suma);

    add(n/2,c,d,copy1);
    Strassen(copy1,e,p6,n/2,suma);

    subtract(n/2,a,c,copy1);
    add(n/2,e,f,copy2);
    Strassen(copy1,copy2,p7,n/2,suma);

    add(n/2,p3,p5,b1);
    add(n/2,p2,p6,c1);

    add(n/2,p1,p2,copy1);
    add(n/2,copy1,p4,copy2);
    subtract(n/2,copy2,p3,a1);

    add(n/2,p1,p5,copy1);
    subtract(n/2,copy1,p6,copy2);
    subtract(n/2,copy2,p7,d1);

  //  *suma=0;
    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<n/2;j++)
        {
            C[i][j]=a1[i][j];
            C[i][j+(n/2)]=b1[i][j];
            C[i+(n/2)][j]=c1[i][j];
            C[i+(n/2)][j+(n/2)]=d1[i][j];
            if(C[i][j]>=10007)
                C[i][j]%=10007;
            if(C[i][j+(n/2)]>=10007)
                C[i][j+(n/2)]%=10007;
            if(C[i+(n/2)][j]>=10007)
                C[i+(n/2)][j]%=10007;
            if(C[i+(n/2)][j+(n/2)]>=10007)
                C[i+(n/2)][j+(n/2)]%=10007;
          //  *suma+=C[i][j];
           // *suma+=C[i][j+(n/2)];
           // *suma+=C[i+(n/2)][j];
            //*suma+=C[i+(n/2)][j+(n/2)];
        }
    }
   // if(*suma>=10007)
      //  *suma=*suma%10007;
   for(int i=0;i<n/2;i++)
    {
        free(a[i]);
        free(b[i]);
        free(c[i]);
        free(d[i]);

        free(a1[i]);
        free(b1[i]);
        free(c1[i]);
        free(d1[i]);

        free(e[i]);
        free(f[i]);
        free(g[i]);
        free(h[i]);

        free(copy1[i]);
        free(copy2[i]);

        free(p1[i]);
        free(p2[i]);
        free(p3[i]);
        free(p4[i]);
        free(p5[i]);
        free(p6[i]);
        free(p7[i]);


    }
        free(a);
        free(b);
        free(c);
        free(d);

        free(a1);
        free(b1);
        free(c1);
        free(d1);

        free(e);
        free(f);
        free(g);
        free(h);

        free(copy1);
        free(copy2);

        free(p1);
        free(p2);
        free(p3);
        free(p4);
        free(p5);
        free(p6);
        free(p7);


}
void Octave(FILE *pf,int ***a)
{
    char caract;
    int count=0,val;
    int *linie, *coloana, *sum;


    int i,j,ok=0;

    a = (int ***)malloc(1 * sizeof(int **));
    linie = (int *)malloc(1 * sizeof(int));
    coloana = (int *)malloc(1 * sizeof(int));
    sum = (int *)malloc(1* sizeof(int));

    while(!feof(pf) && caract!='Q')
    {
        fscanf(pf,"%c",&caract);
        if(caract=='L')
        {
            a = (int ***)realloc(a,(count+1) * sizeof(int **));
            linie = (int*)realloc(linie,(count+1)*sizeof(int));
            coloana = (int*)realloc(coloana,(count+1)*sizeof(int));
            sum = (int*)realloc(sum,(count+1)*sizeof(int));
            sum[count]=0;
            fscanf(pf,"%d",&linie[count]);
            fscanf(pf,"%d",&coloana[count]);
            a[count] = (int**)malloc(linie[count]*sizeof(int*));

            for(i=0;i<linie[count];i++)
            {
                a[count][i] = (int*)malloc(coloana[count]*sizeof(int));
                for(j=0;j<coloana[count];j++)
                {
                 fscanf(pf,"%d",&val);
                 val=val%10007;
                 sum[count]+=val;
                 a[count][i][j]=val;
                 if(a[count][i][j]>=10007)
                    a[count][i][j]%=10007;
                }
            }
            if(sum[count]>=10007)
                sum[count]%=10007;
            count++;


        }
        else if(caract=='P' )
        {
            fscanf(pf,"%d",&val);
            if(val>=count)
                printf("No matrix with the given index\n");
            else
            {
                for(i=0;i<linie[val];i++)
                {
                    for(j=0;j<coloana[val];j++)
                    {
                       printf("%d ",a[val][i][j]);
                    }
                    printf("\n");
                }

            }

        }
        else if(caract=='O')
        {
            for(i=0;i<count-1;i++)
            {
                for(j=i+1;j<count;j++)
                {
                    if(sum[i]>sum[j])
                        swap(a,i,j,linie,coloana,sum);
                }
            }

        }
        else if(caract=='D')
        {

        fscanf(pf,"%d",&val);
        printf("%d %d\n",linie[val],coloana[val]);

        }
        else if(caract=='T')
        {
             fscanf(pf,"%d",&val);

             int **copy;
             int m=0,n=0;
             copy = (int**)malloc(sizeof(int*)*coloana[val]);

             for(i=0;i<coloana[val];i++)
             {
                 copy[i] = (int*)malloc(sizeof(int)*linie[val]);

                 for(j=0;j<linie[val];j++)
                 {
                    copy[i][j]=a[val][m][n];
                    m++;
                 }
                 n++;
                 m=0;
             }
             for(i=0;i<linie[val];i++)
             {
                 free(a[val][i]);
             }
             free(a[val]);



             n=linie[val];
             linie[val]=coloana[val];
             coloana[val]=n;
             a[val] = (int**)malloc(sizeof(int*)*linie[val]);

             for(i=0;i<linie[val];i++)
             {
                 a[val][i] = (int*)malloc(sizeof(int)*coloana[val]);

                 for(j=0;j<coloana[val];j++)
                 {
                    a[val][i][j]=copy[i][j];
                   // printf("%d ",a[val][i][j]);
                 }
               //  printf("\n");
             }
             for(i=0;i<linie[val];i++)
             {
                 free(copy[i]);
             }
             free(copy);


        }
        else if(caract=='M')
        {
            int val2;
            long long val_finala=0;
            fscanf(pf,"%d %d",&val,&val2);
            a = (int ***)realloc(a,(count+2) * sizeof(int **));
            linie = (int*)realloc(linie,(count+2)*sizeof(int));
            coloana = (int*)realloc(coloana,(count+2)*sizeof(int));
            sum = (int*)realloc(sum,(count+2)*sizeof(int));
            sum[count]=0;
            if(coloana[val]!=linie[val2])
                printf("Cannot perform matrix multiplication\n");
            else
            {
                linie[count]=linie[val];
                coloana[count]=coloana[val2];
                a[count] = (int**)malloc(linie[count]*sizeof(int*));
                for(i=0;i<linie[count];i++)
                {
                    a[count][i] = (int*)malloc((coloana[count])*sizeof(int));

                    for(j=0;j<coloana[count];j++)
                    {
                        val_finala=0;
                        for(int z=0;z<linie[val2];z++)
                        {

                            val_finala+=((a[val][i][z]*a[val2][z][j]));

                        }
                        if(val_finala>=10007)
                                a[count][i][j]=val_finala%10007;

                        sum[count]+=a[count][i][j];


                    }
                }
                if(sum[count]>=10007)
                    sum[count]%=10007;
                count++;
                ok=2;
            }



        }
        else if(caract=='Z')
        {
            printf("Nu exista\n");
        }
        else if(caract=='C')
        {
            fscanf(pf,"%d ",&val);
            int nr_linii, nr_coloane;
            fscanf(pf,"%d ",&nr_linii);
            int *linie2,*coloana2,val2;
            linie2 = (int*)malloc((nr_linii)*sizeof(int));
            for(i=0;i<nr_linii;i++)
                fscanf(pf,"%d ",&linie2[i]);
            fscanf(pf,"%d ",&nr_coloane);
            coloana2 = (int*) malloc(sizeof(int)*(nr_coloane));
            for(i=0;i<nr_coloane;i++)
                fscanf(pf,"%d ",&coloana2[i]);
            int **copys;
            copys = (int**) malloc(sizeof(int*)*(nr_linii));
            for(i=0;i<nr_linii;i++)
            {
                copys[i] = (int*) malloc(sizeof(int)*(nr_coloane));
                for(j=0;j<nr_coloane;j++)
                {
                    copys[i][j]=a[val][linie2[i]][coloana2[j]];
                }
            }
            for(i=0;i<linie[val];i++)
            {
                free(a[val][i]);
            }
            free(a[val]);


            a[val] = (int**) malloc(sizeof(int*)*(nr_linii));

            for(i=0;i<nr_linii;i++)
            {
                a[val][i] = (int*) malloc(sizeof(int)*(nr_coloane));

                for(j=0;j<nr_coloane;j++)
                {
                    val2=copys[i][j];
                    val2=val2%10007;
                    sum[val]+=val2;
                    a[val][i][j]=val2;
                    if(a[val][i][j]>=10007)
                        a[val][i][j]%=10007;
                }
            }
            if(sum[val]>=10007)
                sum[val]%=10007;
            free(linie2);
            free(coloana2);
            for(i=0;i<nr_linii;i++)
                free(copys[i]);
            free(copys);

            linie[val]=nr_linii;
            coloana[val]=nr_coloane;
            ok=3;

        }
        else if(caract=='F')
        {
            fscanf(pf,"%d ",&val);

            int i,j,z;
            FREE_SPACE(a[val],linie[val]);


            for(i=val+1;i<count;i++)
            {
                MODIFY_VALUES(a,linie,coloana,sum,i);
                FREE_SPACE(a[i],linie[i]);

            }
            count--;






        }
        else if(caract=='R')
        {
            fscanf(pf,"%d ",&val);
            int put;
            fscanf(pf,"%d ",&put);
            if(put<0)
            {
                printf("No negative power\n");
            }
            else if(linie[val]==coloana[val])
            {
                int **copy;
                copy = (int**) malloc(sizeof(int*)*linie[val]);
                for(i=0;i<linie[val];i++)
                {
                    copy[i]=(int*)malloc(sizeof(int)*coloana[val]);
                    for(j=0;j<coloana[val];j++)
                    {
                        if(i==j)
                            copy[i][j]=1;
                        else
                            copy[i][j]=0;
                    }
                }
                if(put>0)
                {
                    while(put>0)
                    {
                        if(put%2==1)
                            power_matrix(copy,a[val],linie[val],&sum[val]);
                        power_matrix(a[val],a[val],linie[val],&sum[val]);
                        put=put/2;
                    }


                }
                else if(put==0)
                {
                    for(i=0;i<linie[val];i++)
                    {
                        for(j=0;j<linie[val];j++)
                        {
                            if(i==j)
                                a[val][i][j]=1;
                            else
                                a[val][i][j]=0;
                        }
                    }
                }


            }

        }
        else if(caract=='S')
        {
            int val2;
            fscanf(pf,"%d %d",&val,&val2);
          //  printf(">>");
            a = (int ***)realloc(a,(count+1) * sizeof(int **));
            linie = (int*)realloc(linie,(count+1)*sizeof(int));
            coloana = (int*)realloc(coloana,(count+1)*sizeof(int));
            sum = (int*)realloc(sum,(count+1)*sizeof(int));
            a[count] = (int**)malloc(sizeof(int*)*linie[count]);

            sum[count]=0;
            //a[count]=0;
            linie[count]=linie[val];
            coloana[count]=coloana[val];
            for(i=0;i<linie[count];i++)
            {
                a[count][i] = (int*)malloc(sizeof(int)*coloana[count]);
                for(j=0;j<linie[count];j++)
                    a[count][i][j]=0;
            }
           // printf("<<");

            Strassen(a[val],a[val2],a[count],linie[val],&sum[count]);
            count++;

        }

    }
}
int main(int argc, char *argv[])
{
    int ***a;

    FILE *pf;

    if((pf=fopen(argv[1],"r+t"))==NULL)
    {
      printf("Unul sau ambele fisiere nu poate/pot fi deschis/e !\n");
    }

    Octave(pf,a);



    return 0;
}
