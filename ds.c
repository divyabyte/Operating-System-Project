#include<stdio.h> 
 
int main() 
{ 
      int i, b, z, j, x, noProcess, pos, total = 0, counter = 0, time_quantum; 
      
	  int wait_time = 0, turnaround_time = 0, p[10], priority[10], arrival_time[10], brust_time[10], temp[10], total_wait_time; 
      
	  float average_wait_time, average_turnaround_time;
      
	  printf("\nEnter Total Number of Processes:"); 
      
	  scanf("%d", &noProcess); 
      
	  x = noProcess; 
      for(i = 0; i < noProcess; i++) 
      {
	    p[i]=i+1;
	   
	    priority[i]=0;
            printf("\nEnter total Details of Process[%d]\n", i + 1);
            printf("Arrival Time:\t");
            scanf("%d", &arrival_time[i]);
            printf("Brust Time:\t");
            scanf("%d", &brust_time[i]); 
            temp[i] = brust_time[i];
      }
	   
      printf("\nEnter the Time Quantum:"); 
      scanf("%d", &time_quantum); 
      printf("\nProcess ID %d\t\tBurst Time %d\t Turnaround Time %d\t Waiting Time %d\t\t Priority %d\n", i, brust_time, turnaround_time, wait_time, priority);
      for(total = 0, i = 0; x != 0;)
      { 

		    for(z=0; z<noProcess; z++)
		    {
			int temp1;
			pos=z;
			for(j=z+1;j<noProcess;j++)
			{
			    if(priority[j]<priority[pos])
				pos=j;
			}
		 
		temp1=priority[z];
	
		priority[z]=priority[pos];
	
		priority[pos]=temp1;
		 
			temp1=brust_time[z];
			brust_time[z]=brust_time[pos];
			brust_time[pos]=temp1;
		 			temp1=arrival_time[z];
				arrival_time[z]=arrival_time[pos];
			arrival_time[pos]=temp1;

			temp1=p[z];
				p[z]=p[pos];
			p[pos]=temp1;

			temp1=temp[z];
				temp[z]=temp[pos];
			temp[pos]=temp1;
		    }
		{
		}
            
			if(temp[i] <= time_quantum && temp[i] > 0) 
            { 
                  total = total + temp[i]; 
                  temp[i] = 0; 
                  counter = 1; 
            } 
            
			else if(temp[i] > 0) 
            { 
                  temp[i] = temp[i] - time_quantum; 
                  total = total + time_quantum; 
            } 

	for(b=0; b<noProcess; b++)
		{
			if(b==i)
			priority[b]+=1;
			else
			priority[b]+=2;
		}

            if(temp[i] == 0 && counter == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t\t%d\t\t\t %d\t\t\t %d\t\t\t\t%d", p[i], brust_time[i], total - arrival_time[i], total - arrival_time[i] - brust_time[i], priority[i]);
                  wait_time = abs(wait_time + total - arrival_time[i] - brust_time[i]); 
                  total_wait_time = wait_time + total_wait_time ;
                  turnaround_time = turnaround_time + total - arrival_time[i]; 
                  counter = 0; 
            } 
            if(i == noProcess - 1) 
            {
                  i = 0; 
            
			}
            else if(arrival_time[i + 1] <= total) 
            {
                  i++;
            
			}
            else 
            {
                  i = 0;
            
			}		
      } 
       average_wait_time = total_wait_time / noProcess;
      average_turnaround_time = turnaround_time / noProcess;
      printf("\n\nAverage waiting time:\t%f\n", average_wait_time);
      printf("Average Turnaround Time:\t%f\n", average_turnaround_time);
      return 0; 
}
