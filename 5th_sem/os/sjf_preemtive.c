/* Shortest Job First -- scheduling algorithm implementation (preemtive version!)
 * A very naive approach: 
    loop works as the clock pulse! 
    at each new pulse, program checks if there is a new job or not and proceeds accordinly
 * author: t3chn0tr0n 
 * date: 19-09-2018
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct job
{
    int id, arrival_time, execution_time, finishing_time, waiting_time, turn_around_time, last_in_cpu, execution_left;
}job;


typedef struct print_job_queue
{
    int len, jobs_left, jobs_getting_executed;
    float avg_wt;
    job jobs[50];
}job_queue;


job get_a_job(int);
void get_jobs_list(job_queue *);
void sort_queue(job_queue *);
void print_job_queue(job_queue);
int next_job(job_queue, int);
void sjf_preemtive(job_queue *);


job get_a_job(int i)
{
    job j;
    printf("Enter Details of Job No. %d\n", i);
    j.id = i;
    if(i==1)
    {
        printf("Arrival time: 0\n"); 
        j.arrival_time = 0;
    }
    else
    {
        printf("Arrival time: "); 
        scanf("%d",&j.arrival_time);
    }
    printf("Execution time: "); scanf("%d",&j.execution_time);
    j.finishing_time = -1;
    j.turn_around_time = -1;
    j.last_in_cpu = -1;
    j.execution_left = j.execution_time;
    printf("\n");
    return j;
}


void sort_queue(job_queue *q)
{
    int i, j;
    job temp;
    for(i=0; i<q->len-1; i++)
    {
        for(j=1; j<q->len-1; j++)
        {
            if(q->jobs[j].arrival_time > q->jobs[j+1].arrival_time)
            {
                temp = q->jobs[j];
                q->jobs[j] = q->jobs[j+1];
                q->jobs[j+1] = temp;
            }
            else if(q->jobs[j].arrival_time == q->jobs[j+1].arrival_time)
            {
                printf("ERROR: 2 jobs can't enter at same time!\nError at Jobs %d and %d\n",q->jobs[j].id,q->jobs[j+1].id);
                exit(1);
            }
        }
    }
}


void get_jobs_list(job_queue *q)
{
    int i;

    do
    {
        printf("Enter Number of jobs: "); scanf("%d",&q->len);
    }while(q->len <= 0);
    printf("\n");
    for(i=0; i<q->len; i++)
        q->jobs[i] = get_a_job(i+1);
    q->jobs_getting_executed = -1;
    q->jobs_left = q->len;
}


int next_job(job_queue q, int current_time)
{
    int i, min = 0;

    if(q.jobs_left == 0) // if all jobs are processed
        return -1;

    if(q.jobs_getting_executed == 0) // if only first job!
        return 0;

    else 
    {
        // finding the first unattended job -> taking it as the reference point
        for(i=0; i<=q.jobs_getting_executed; i++)
        {
           if(q.jobs[i].execution_left > 0)
            {
                min = i;
                break;
            }
        }
        // checking if this is the shortest job or not, if not, get the one
        for(i = min+1; i <= q.jobs_getting_executed; i ++)
        {
            if(q.jobs[i].execution_left == 0)   // if i'th job is done, skip!
                continue;
            else
            {
                if(q.jobs[i].execution_left < q.jobs[min].execution_left)
                    min = i;
            }
        }
    }
    return min;
}


void print_job_queue(job_queue q)
{
    int len = q.len, i;
    
    if(q.jobs_left) 
    {
        printf("----------------------------------------\n");
        printf("id\tarrival_time\texecution_time\n");
        printf("----------------------------------------\n");
    }
    else
    {
        printf("----------------------------------------------------------------------------------------\n");
        printf("id\tarrival_time\texecution_time\tfinishing_time\twaiting_time\tturn_around_time\n");
        printf("----------------------------------------------------------------------------------------\n");
    }

    for(i=0; i<len; i++)
    {
        printf("P%d\t\t%d\t\t%d",q.jobs[i].id, q.jobs[i].arrival_time, q.jobs[i].execution_time);
        if(!q.jobs_left)
            printf("\t\t%d\t\t%d\t\t%d",q.jobs[i].finishing_time,q.jobs[i].waiting_time,q.jobs[i].turn_around_time);
        printf("\n");
    }
}


void sjf_preemtive(job_queue *q)
{
    int clock_pulse=0, current_job = 0, total_waiting_time = 0, not_executing_last_job;
    while(1)
    {
        not_executing_last_job = 0;
        // if no job is left to execute
        if (q->jobs_left <=0)
            break;

        // if [a new job comes in, get next job] else [continue executing the previous one,i.e. current_job doesn't change!]
        else if(q->jobs[(q->jobs_getting_executed) + 1].arrival_time == clock_pulse)
        {
            (q->jobs_getting_executed) ++;
            current_job = next_job(*q, clock_pulse);
            not_executing_last_job = 1;
        }

        // else if, no new job comes, however my old job is done, find next job!
        else if(q->jobs[current_job].execution_left == 0)
        {
            q->jobs[current_job].finishing_time = clock_pulse - 1;
            q->jobs[current_job].turn_around_time = q->jobs[current_job].execution_time + q->jobs[current_job].waiting_time;
            q->jobs_left --;
            total_waiting_time += q->jobs[current_job].waiting_time;
            current_job = next_job(*q, clock_pulse);
            not_executing_last_job = 1;
        }  

        if(not_executing_last_job) // this is set to True when ever next job is called!
        {
            // if no job is left to execute
            if(current_job == -1)
                break;

            if(q->jobs[current_job].last_in_cpu == -1) // if this job is an unattended job
            {
                q->jobs[current_job].waiting_time = clock_pulse - q->jobs[current_job].arrival_time;
                q->jobs[current_job].turn_around_time = 0;
            }
            else // if job is an attended one
                q->jobs[current_job].waiting_time += clock_pulse - q->jobs[current_job].last_in_cpu;

        }  
        // execute the job for this clock-pulse
        q->jobs[current_job].execution_left -= 1;
        q->jobs[current_job].last_in_cpu = clock_pulse + 1; 

        clock_pulse ++;
    }
    q->avg_wt = total_waiting_time / q->len;
}


int main()
{
    job_queue j;

    get_jobs_list(&j);
    sort_queue(&j);

    printf("*** Current Job queue ***\n");
    print_job_queue(j);

    sjf_preemtive(&j);

    printf("\n\n*** Job queue after processing *** \n");
    print_job_queue(j);
    printf("The avarage waiting time = %f\n\n",j.avg_wt);

    return 0;
}
