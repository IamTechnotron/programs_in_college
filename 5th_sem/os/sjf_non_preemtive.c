/* Shortest Job First -- process/job scheduling algorithm implementation 
 * Note: This is a very naive approach */
 * author: t3chn0tr0n 
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct job
{
    int id, arrival_time, execution_order, execution_time, finishing_time, waiting_time;
}job;


typedef struct print_job_queue
{
    int len, jobs_left, all_processed, current_time;
    float avg_wt;
    job jobs[50];
}job_queue;


job get_a_job(int);
void get_jobs_list(job_queue *);
void sort_queue(job_queue *);
void print_job_queue(job_queue);
int next_job(job_queue);
void sjf(job_queue *);



job get_a_job(int i)
{
    job j;
    printf("Enter Details of Job No. %d\n", i);
    j.id = i;
    if(i==1)
        j.arrival_time = 0;
    else
    {
        printf("Arrival time: "); 
        scanf("%d",&j.arrival_time);
    }
    printf("Execution time: "); scanf("%d",&j.execution_time);
    j.finishing_time = -1;
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
        q->current_time = 0;
    }while(q->len <= 0);
    printf("\n");
    for(i=0; i<q->len; i++)
        q->jobs[i] = get_a_job(i+1);
    q->all_processed = 0;
    q->jobs_left = q->len;
}


int next_job(job_queue q)
{
    int i, min = 0;

    if(q.all_processed) // if all jobs are processed
        return -2;

    else if(q.jobs[0].finishing_time == -1) // if first one is not processed, process it!
        return 0;

    else // otherwise, find the first unattended job
    {
        for(i=1; i<q.len; i++)
        {
            if(q.jobs[i].arrival_time > q.current_time) // if no jobs are there at present, wait
                return -1;
            // getting the unfinished job from top of the queue
            else if(q.jobs[i].finishing_time == -1 && q.jobs[i].arrival_time <= q.current_time)
            {
                min = i;
                break;
            }
        }
        // checking if this is the shortest job or not, if not, get the one
        for(i=min; q.jobs[i].arrival_time <=q.current_time; i++)
        {
            if(q.jobs[i].finishing_time != -1)   // if i'th job is done, continue
                continue;
            else
            {
                if(q.jobs[i].execution_time < q.jobs[min].execution_time)
                    min = i;
            }
        }
    }
    return min;
}


void print_job_queue(job_queue q)
{
    int len = q.len,  processed = q.all_processed, i;
    printf("-----------------------------------------------------------------------------------\n");
    printf("id\tarrival_time\texecution_time");
    if(processed) printf("\texecution_order\tfinishing_time\twaiting_time");
    printf("\n\n");

    for(i=0; i<len; i++)
    {
        printf("%d\t\t%d\t\t%d",q.jobs[i].id, q.jobs[i].arrival_time, q.jobs[i].execution_time);
        if(processed)
            printf("\t\t%d\t\t%d\t\t%d",q.jobs[i].execution_order,q.jobs[i].finishing_time,q.jobs[i].waiting_time);
        printf("\n");
    }
}


void sjf(job_queue *q)
{
    int len = q->len, jobs_left = q->jobs_left, next, i=1;
    float avg_waiting_time = 0;

    while(q->jobs_left)
    {
        next = next_job(*q);
        if(next == -1)
        {
            q->current_time ++;
            continue;
        }
        else
        {
            q->jobs[next].execution_order = i++;
            q->jobs[next].waiting_time = q->current_time - q->jobs[next].arrival_time;
            avg_waiting_time += q->jobs[next].waiting_time;
            q->current_time += q->jobs[next].execution_time;
            q->jobs[next].finishing_time = q->current_time;

            q->jobs_left --;
        }
    }
    avg_waiting_time /= len;
    q->avg_wt = avg_waiting_time;
    q->all_processed = 1;
    q->jobs_left = 0;
}


int main()
{
    int i, no_of_jobs;
    job_queue j;

    get_jobs_list(&j);
    sort_queue(&j);

    printf("Current Job queue:-\n");
    print_job_queue(j);

    sjf(&j);

    printf("\nJob queue after processing:-\n");
    print_job_queue(j);
    printf("The avarage waiting time = %f",j.avg_wt);

    return 0;
}
