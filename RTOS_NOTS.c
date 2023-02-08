
/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
/*-------------------⚫⚫⚫  Real-Time Systems   ⚫⚫⚫----------------------*/
/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/


/*
##### NOTS ####
bare metal system means >> without RTOS >> Without layer to handle...

program with timing >> called foreground/background system >> means program contain ISR & while(1)
	foreground system == loop [while(1)].
	background system == ISR .
*/


/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
/*
=================================================================================================
### Design patterns ###

[1]Static design >> the decision to call a particular block of code is done at compile time,
 in other words all the concern is about the functionality.

[2]Dynamic design >> the decision to call a particular block of code is done in run time.

=================================================================================================
### Design patterns Example ###

• In every embedded system design, we should start with static first then move to dynamic.
• One of the best solution for this exercise is to divide the project into tasks.
 Each task is just a void function that conations functional functions that have the same time constrains.

• Task1 (comes every 200msec) --> toggle the RED LED
• Task2 (comes every 350msec) --> toggles the GREEN LED
• Task3 (comes every 500msec) --> toggles the BLUE LED

=================================================================================================
• To calculate the time for each task, 
we can use only one timer for the whole system.
This timer actives each task's flag to be ready to work by counting how much time passed now. 
Counting process is done every system tick, which is the value of "biggest common divider" for all tasks. 
It's 50 msec here in our example. Here is how it should be implemented:

#####################
Design patterns

 ISR (//timer OV every 50 msec)
 {
 //T1_counter++; T2_counter++; T3_counter++;
 //if (T1 counter ==4) > T1_flag =1; T1_counter = 0
 //if (T2_counter == 7)-> T2_flag =1; T2_counter = 0
 //if (T3_counter == 10)-> T3_flag =1; T3_counter = 0
 }

 int main()
 {
 // loop
 {
 // if (T1_flag)--> call Task1: T1_flag = 0;
 //if (T2_flag)->call Task2; T2_flag = 0;
 //if (T3_flag)-> call Task3; T3_flag = 0;
 }
 }

######################
 • This method is called scheduling.
 It's one of the solutions that is used to solve the time constrains problem. 
 it's almost a generic solution. 
 And used easily in this example without any problem even if we add more LEDs.

 • If we have much more time constrains this can be called real time system.
=================================================================================================
=================================================================================================
*/

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

/*
=================================================================================================
### Foreground/Background Systems ###

• Small systems of low complexity
• These systems are also called "super-loops"
• An application consists of an infinite loop of desired operations (background)
• Interrupt service routines (ISRS) handle asynchronous events (foreground)
• Critical operations must be performed by the ISRS to ensure the timing correctness
• Thus, ISRS tend to take longer than they should
• Task-Level Response
• Information for a background module is not processed until the module gets its turn

###############################################
>>Foreground/Background Systems<<

• The execution time of typical code is not constant.
• If a code is modified, the timing of the loop is affected.
• Most high-volume microcontroller-based applications.

are F/B systems
• Microwave ovens
• Telephones
• Toys

• From a power consumption point of view, 
it might be better to halt and perform all processing in ISRs

###############################################

>>Foreground/Background Systems Design<< 

A simple foreground/background system architecture would be like:
              |----------------------------|
              |       Application          |
              |----------------------------|
              |         HAL/ECU            |
              |----------------------------|
              |          MCAL              |
              |----------------------------|
			  
###############################################
			  
=================================================================================================
*/
/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

/*
=================================================================================================
⚫⚫⚫ Real-Time Systems ⚫⚫⚫

What are the Real-Time Systems?

A true real-time system is one where whatever deadline has been set on an activity taking place,
 the deadline can always be satisfied.
 
⚫⚫⚫ Types Of Real Time Systems ⚫⚫⚫

[1] Hard real-time system:
• Also known as an immediate real-time system.
• The system that must operate within the confines of a stringent deadline. 
It is considered to have failed if it does not complete its function within the allowed time span.

>>> Examples:
• Car Air bag.
• anti-lock Braking Systems (ABS).
• aircraft control systems.
 
[2] Soft real-time system:
• The system that can operate with the presence of latency at deadline.
• It is not considered to have failed if it does not complete its function at deadline 
but that affects the quality of the output.

>>> Examples:
• Video Processing
• Audio processing
• Digital cameras
• Mobile phones 

#### Embedded Systems Vs. Real Time Systems ####

⚫:Real-Time Embedded Systems
|-----------------------------------|         
|       Embedded Svetams       |----|-------------------------------|
|                              | ⚫ | Real-Time Systems             |
|------------------------------|----|                               |
                               |------------------------------------|
//=================================================================================
#### Task ####
 Each task is a small program in its own right. 
 It has an entry point, will normall run forever within an infinite loop, and will not exit

 void task(void)
 {
 //Some Initialization Code
 for(;;)
 //Task Code
 }
//=================================================================================
 #### Multi-Tasking ####

 After separating the application into tasks another layer has to be added to manage 
 which task to be executed when based on the scheduling algorithm

              |------|------|------|------|
              |task1 |task2 |......|task n|
              |------|------|------|------|
              |---------------------------|
              |         scheduler         |
              |---------------------------|
              |         HAL/ECU           |
              |---------------------------|
              |          MCAL             |
              |---------------------------|
=================================================================================================
*/
/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
/*
=================================================================================================
#### Misconceptions about Real Time Systems ####

[1] Real-time computing is equivalent to fast computing. X
Truth-> Real-time computing is equivalent to PREDICTABLE computing.

[2]Real-time programming is assembly coding. X
Truth-> It is better to automate (as much possible) real-time system design, 
instead relying on a clever hand-crafted code.

[3] "Real time" means performance engineering X
Truth => In real-time computing, timeliness is always more important than performance.

[4] Real-time systems function in a static environment. X
Truth => Real-time systems consider systems in which the operating mode may change dynamically.
 On the other hand everything should be deterministic!"
=================================================================================================
*/
/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
/*
=================================================================================================

=================================================================================================
*/
/*
=================================================================================================
#### Real-Time Workload ####

 [+] Job (unit of work)
 • a computation, a file read, a message transmission, etc

 [+] Attributes
 • Resources required to make progress.
 •Timing parameters.

    
 Released       Execution time                Absolute deadline
    v           |-----------------------|          ^
----|-----------|-----------------------|----------|---->
    |<-------------Relative deadline-------------->|

####################################
#### Real-Time Task ####

>>> Task: a sequence of similar jobs

 [1] Periodic task (p,e)
 • Its jobs repeat regularly
 • Period p = inter-release time (0 <p)
 • Execution time e = maximum execution time (0 <e <p)
 • Utilization U=e/p

####################################
#### Back to Deadlines ####
⚫ Hard deadline
• Disastrous or very serious consequences may occur if the deadline is misse
• Validation is essential: can all the deadlines be met, even under worst-cas scenario?
• Deterministic guarantees

⚫ Soft deadline
• Ideally, the deadline should be met for maximum performance. 
  The performance degrades in case of deadline misses.
• Best effort approaches / statistical guarantees

####################################
#### Schedulability ####
• Property indicating whether a real-time system (a set of real-time tasks)
 can meet their deadlines.
 
####################################
#### RM (Rate Monotonic) ####

• Optimal static-priority scheduling
• It assigns priority according to period
• A task with a shorter period has a higher priority
• Executes a job with the shortest period

####################################
#### Response Time ####
⚫ Response time
• Duration from released time to finish time

####################################
#### EDF (Earliest Deadline First) ####

• Optimal dynamic priority scheduling
• A task with a shorter deadline has a higher priority
• Executes a job with the earliest deadline

=================================================================================================
*/
/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
/*
=================================================================================================
⚫ RTOS

 • If all tasks are waiting→ Idle task
 • Initialization task (creation).
 • TCB Task control block.
 • Layers with OS:
              |-------------|-------------|
              |Application  |OS_config.h  | 
              |-------------|-------------|
              |          OS               |
              |---------------------------|
              |         Port              |
              |---------------------------|
              |    Micro-Controller       |
              |---------------------------|
=================================================================================================
*/

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
/*
=================================================================================================

=================================================================================================
*/

/*
=================================================================================================

=================================================================================================
*/

/*
=================================================================================================

=================================================================================================
*/

/*
=================================================================================================

=================================================================================================
*/

/*
=================================================================================================

=================================================================================================
*/

