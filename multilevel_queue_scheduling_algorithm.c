#include<stdio.h> 
int main() 
{ 
      int j, limit, total = 0, x, counter = 0, time_quantum,k; 
      
	  int wait_time = 0, turnaround_time = 0,pos,z,p[10],prio[10], a_time[10], b_time[10], temp[10],b; 
      
	  float average_wait_time, average_turnaround_time;
      
	  printf("\nEnter Total Number of Processes:"); 
      
	  scanf("%d", &limit); 
      
	  x = limit; 
      for(j = 0; j < limit; j++) 
      {
	    p[j]=j+1;
	   
	    prio[j]=0;
            printf("\nEnter total Details of Process[%d]\n", j + 1);
            printf("Arrival Time:\t");
            scanf("%d", &a_time[j]);
            printf("Burst Time:\t");
            scanf("%d", &b_time[j]); 
            temp[j] = b_time[j];
      }
	   
      printf("\nEnter the Time Quantum:"); 
      scanf("%d", &time_quantum); 
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\t Priority\n");
      for(total = 0, j = 0; x != 0;) 
      { 

		    for(z=0;z<limit;z++)
		    {
			int temp1;
			pos=z;
			for(k=z+1;k<limit;k++)
			{
			    if(prio[k]<prio[pos])
				pos=k;
			}
		 
		temp1=prio[z];
	
		prio[z]=prio[pos];
	
		prio[pos]=temp1;
		 
			temp1=b_time[z];
			b_time[z]=b_time[pos];
			b_time[pos]=temp1;
		 			temp1=a_time[z];
				a_time[z]=a_time[pos];
			a_time[pos]=temp1;

			temp1=p[z];
				p[z]=p[pos];
			p[pos]=temp1;

			temp1=temp[z];
				temp[z]=temp[pos];
			temp[pos]=temp1;
		    }
		{
		}
            
			if(temp[j] <= time_quantum && temp[j] > 0) 
            { 
                  total = total + temp[j]; 
                  temp[j] = 0; 
                  counter = 1; 
            } 
            
			else if(temp[j] > 0) 
            { 
                  temp[j] = temp[j] - time_quantum; 
                  total = total + time_quantum; 
            } 

	for(b=0;b<limit;b++)
		{
			if(b==j)
			prio[b]+=1;
			else
			prio[b]+=2;
		}

            if(temp[j] == 0 && counter == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\t\t%d", p[j], b_time[j], total - a_time[j], total - a_time[j] - b_time[j],prio[j]);
                  wait_time = wait_time + total - a_time[j] - b_time[j]; 
                  turnaround_time = turnaround_time + total - a_time[j]; 
                  counter = 0; 
            } 
            if(j == limit - 1) 
            {
                  j = 0; 
            
			}
            else if(a_time[j + 1] <= total) 
            {
                  j++;
            
			}
            else 
            {
                  j = 0;
            
			}		
      } 
      return 0; 
}
