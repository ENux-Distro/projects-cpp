# KISS sh - written in C++

A super simple REPL shell, that uses write+read for the good looking input
and fork+execvp+waitid for command execution

The shell will support "ls", but not "ls -lh".