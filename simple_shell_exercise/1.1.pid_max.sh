<!--1. /proc/sys/kernel/pid_max
Write a shell script that prints the maximum value a process ID can be.-->

#!/bin/bash
# Script to print the maximum PID value
cat /proc/sys/kernel/pid_max
