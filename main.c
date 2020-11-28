#include <stdio.h>
#include <stdlib.h>


int **user_data_input(int number_of_branches)
{
    int j= 12, i, branch_label=1,month_label=1;

    // The 2D array definition here
    int  **arr = malloc(number_of_branches * sizeof(int *));
    for (i=0; i<number_of_branches; i++)
         arr[i] = malloc(j * sizeof(int));


    //scan values of the array from user
    for(i=0; i<number_of_branches; i++)
    {
        printf(" sales for branch(%d) : \n",branch_label++);
        month_label=1;
        for(j=0; j<12; j++){
            printf("sales for month %d :",month_label++);
            scanf("%d", &arr[i][j]);
        }
    }

    return arr;
}

void display_user_data(int **arr,int number_of_branches, int branch_label)
{

    //test printing the array
    // int branch_label=1
     int i,j;

     for(i=0; i<number_of_branches; i++)
     {
        printf(" Branch %d : ",branch_label++);
        for(j=0; j<12; j++){
            printf(" %5d ",arr[i][j]);
       }
       printf("\n");
    }
}

int **add_record(int **arr, int number_of_branches,int branch_label,int n_added)
{
    int i,j,month_label,total_size,starting_point;
    j=12;
    total_size=number_of_branches+n_added;


    int  **arr_cpy = malloc( total_size* sizeof(int *));
    for (i=0; i<total_size; i++)
         arr_cpy[i] = malloc(j * sizeof(int));



    for(i=0; i<number_of_branches; i++)        //copying main array into another
    {
        for(j=0; j<12; j++)
        {

            arr_cpy[i][j] = arr[i][j];

        }
    }

        starting_point=(number_of_branches+n_added)-n_added;
        branch_label=number_of_branches+1;

        arr = arr_cpy;

      for(i= starting_point; i<total_size; i++)         //filling in the added branches
        {
        printf(" sales for branch(%d) : \n",branch_label++);
        month_label=1;

        for(j=0; j<12; j++)
            {
            printf("sales for month %d :",month_label++);
            scanf("%d", &arr_cpy[i][j]);
            }
        }

         arr = arr_cpy;       //====================>moving pointer from arr_cpy to arr

         branch_label=1;

    printf(" \n The NEW list of branches is: \n"
           "--------------------------------- \n");
    for(i=0; i<number_of_branches+n_added; i++)
    {

        printf("Sales of Branch (%d) is: ",branch_label);

        for(j=0; j<12; j++)
        {
            printf(" %5d ",arr[i][j]);
        }
        printf("\n");
        branch_label++;
    }


    return arr;
}

int **delete_record(int **arr,int number_of_branches,int branch_label)
{
     int n_branch_deleted,i,j;
     j=12;

     int  **arr_cpy = malloc( (number_of_branches-1)* sizeof(int *));
     for (i=0; i<number_of_branches-1; i++)
         arr_cpy[i] = malloc(j * sizeof(int));


     //total_size=number_of_branches+n_added;
     printf("\n el branch+added is %d abl fun el delete w abl ay 7aga \n ",number_of_branches);


     printf("enter the number of branch you want to delete(only one branch per time): \n");
     scanf("%d",&n_branch_deleted);

     //n_branch_deleted=i+1;

    //total_size=number_of_branches+n_added;
     branch_label=1;
     //printf("\n el total size is %d abl el loops \n ",total_size);    //==================>TEST
     printf("\n el branch+added is %d abl el loops \n ",number_of_branches);
     printf(" branch label is %d branch deleted is %d \n",branch_label,n_branch_deleted);

    int i_arr = 0;
     for(i=0; i<number_of_branches-1; i++)        //loop copying main array into another
     {
        for(j=0; j<12; j++)
         {
            if (i_arr != (n_branch_deleted-1))
                arr_cpy[i][j] = arr[i_arr][j];
            else
                i_arr++;
         }
         i_arr++;
     }

     arr = arr_cpy;       //====================>moving pointer from arr_cpy to arr

    branch_label=1;

    printf(" \n The NEW list of branches is: \n"
           "--------------------------------- \n");
    for(i=0; i<number_of_branches-1; i++)
    {
        //if (branch_label != n_branch_deleted)
        printf("Sales of Branch (%d) is: ",branch_label);

        for(j=0; j<12; j++)
        {
            printf(" %5d ",arr_cpy[i][j]);
        }
        printf("\n");

        //if (branch_label != n_branch_deleted)
        branch_label++;
    }

    return arr;

}

float total_sales(int **arr, int number_of_branches)
{
    int i,j;
    float total_sum;

    j=12;
    total_sum=0;

     for(i=0; i<number_of_branches; i++)
    {
        for(j=0; j<12; j++)
        {

        total_sum = total_sum + arr[i][j];

        }
    }
    printf("tala3 mn el etnen loop \n ");  //==============================================================

    printf("\n total revenue of the company is : %.2f dollars \n",total_sum );

    return total_sum;
}

void percentage_per_branch(int **arr, int branch_label, int number_of_branches, float total_company_sales)
{
    float percentage_of_branch,sum_of_branch;
    int i,j;


    branch_label=1;

      for(i=0; i<number_of_branches; i++)
    {
        for(j=0; j<12; j++)
        {
            sum_of_branch = sum_of_branch + arr[i][j];   //REACHING HERE WE HAVE THE RIGHT VALUES OF SUM OF BRANCH & TOTAL
        }

        percentage_of_branch = ((sum_of_branch/total_company_sales))*100;


        printf("percentage of shares for branch (%d) is: %.2f %% \n",branch_label,percentage_of_branch);

        sum_of_branch=0;
        branch_label++;
    }


}

void peak_month(int **arr, int branch_label, int number_of_branches)
{
    int sum_per_branch=0,max_sum,i,j;
    int j_max;

    for(i=0; i<number_of_branches; i++)           //MAKE FIRST COLUMN (MONTH) THE MAX
            {
                j=0;
                sum_per_branch = sum_per_branch + arr[i][j];
            }
    max_sum =sum_per_branch;

    for(j=1; j<12; j++)                     //MAKE J STARTS FROM 1 (=MONTH2)
    {

        for(i=0; i<number_of_branches; i++)
            {

            sum_per_branch = sum_per_branch + arr[i][j];
            }

            if (sum_per_branch > max_sum)           //CONDITION TO REPLACE MAX IF A BIGGER SUM IS FOUND
                {
                        max_sum = sum_per_branch;
                        j_max=j;
                }


        sum_per_branch=0;
    }
    printf("Month %d has the peak sales of %5d  dollars \n",j_max+1,max_sum);



}


int main()
{
    int number_of_branches,user_option_choice, x=1;
    int j= 12, i, branch_label=1,month_label=1,n_added,total_size;
    float total_company_sales,total_sum;


    printf("Welcome to our retail company, please before proceeding any further \n"
            "Enter the number of branches: \n");


    scanf("%d",&number_of_branches);
    total_size=number_of_branches+n_added;

    int **arr = user_data_input(number_of_branches);

    while (1)
    {
            printf("----------------------------------------------- \n"
                   "From the following menu, choose an option: \n"
                    "----------------------------------------------- \n"
                    "1. Display User Data \n"
                    "2. Add a record for a new branch \n"
                    " 3. Delete record of an existing branch\n"
                    " 4. Calculate total sales\n"
                    " 5. Calculate percentage share of each branch\n"
                    " 6. Determine the month of the peak sales\n"
                    " 7. Display sales of a specific month\n "
                    "8. Display sales of a specific branch \n"
                    " 0. Done \n");

            printf("your choice is number: ");
            scanf("%d \n",&user_option_choice);



            switch(user_option_choice){

                case 1:
                    //diplaying data for user                                     input: array... output:array display

                    display_user_data(arr,number_of_branches,branch_label);

                    break;
                case 2:
                    //adding a new branch(record)                                  input: array...output:extended array

                   printf("enter the number of branche(s) you want to add: \n");
                   scanf("%d",&n_added);

                   arr = add_record(arr,number_of_branches,branch_label,n_added);
                   total_size = number_of_branches + n_added;
                   number_of_branches=total_size;


                    break;

                case 3:
                    //deleting an existing branch                              input:array...output: updated array

                    arr = delete_record(arr,number_of_branches,branch_label);
                    number_of_branches = number_of_branches-1;
                    printf("\n number of branches gowa case 3 ba3d marege3 is %d \n",number_of_branches);

                    break;

                case 4:
                   //total_sales of the company                         input:array...output: sum of sales of the company

                   total_company_sales = total_sales(arr,number_of_branches);

                   break;

                case 5:
            //percentage of shares per each branch:you need to get total sum first then calculate percentage

                    total_company_sales = total_sales(arr,number_of_branches);

                    percentage_per_branch(arr,branch_label,number_of_branches,total_company_sales);

                    break;

                case 6:
                    //calculating and comparing to reach for the peak month value of sales

                    peak_month(arr, branch_label, number_of_branches);

                    break;

                case 7:
                    //arranging and displaying sales of a specified month using *BUBBLE SORTING*

                  // sales_of_month(arr, branch_label, number_of_branches, n_added, total_size);

                    break;

                case 8:
                    //arranging and displaying sales of a specified branch using *SLECTION SORTING*




                    break;

                case 0:
                    printf("exiting the program...");
                    exit(0);

            }

        }

    return 0;
}
