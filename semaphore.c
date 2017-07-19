/*************************************************************************          
    * semaphore.c : Program to show how Binary Semaphore works.    *   
    *                                                                    *   
    * Author:  Sandeep P, Singh                                          *   
    *                                                                    *   
    * Purpose:  Demonstration of a simple program,						 *
	* to show how Binary Semaphore works. Used VxWork Enviroment    							 *
    *                                                                    *   
    * Usage:                                               				 *   
    *      Runs the program and the task runs synchronously (VxWorks Env)*      			    *   
    *********************************************************************/  
	
	/* includes */
#include "vxWorks.h"
#include "taskLib.h"
#include "semLib.h"
#include "stdio.h"

/* function Declaration */
void taskOne(void);
void taskTwo(void);

/* globals variables*/
#define ITERATION 10
SEM_ID semBinary;
int global = 0;

void binary(void)
{
int taskIdOne, taskIdTwo;

//SEM_FULL will just let the task run and make semaphore empty
semBinary = semBCreate(SEM_Q_FIFO, SEM_FULL);

/* spawn the two tasks */
tidOne = taskSpawn("myCpuTask1",90,0x100,2000,(FUNCPTR)taskOne,0,0,0,0,0,0,0,0,0,0);
tidTwo = taskSpawn("myCpuTask2",90,0x100,2000,(FUNCPTR)taskTwo,0,0,0,0,0,0,0,0,0,0);
}


void taskOne(void)
{
int i;
semBinary = semBCreate(SEM_Q_FIFO, SEM_EMPTY);
for (i=0; i < ITERATION; i++)
	{
	/* wait indefinitely for semaphore */
	semTake(semBinary,WAIT_FOREVER); 
	printf("I am taskOne and global = %d......................\n", ++global);
	/* give up semaphore */
	semGive(semBinary); 
	} 
}

void taskTwo(void)
{
int i;
/* Give up semaphore(Make tasks run synchronously) */
semGive(semBinary); 
for (i=0; i < ITERATION; i++)
	{
	/* wait indefinitely for semaphore */
	semTake(semBinary,WAIT_FOREVER); 
	printf("I am taskTwo and global = %d----------------------\n", ++global);
	global -=2;
	 /* give up semaphore */
	semGive(semBinary);
	} 
}
