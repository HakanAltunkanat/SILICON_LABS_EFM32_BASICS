/*
 * syscalls.h
 *
 *  Created on: 14 Nov 2024
 *      Author: Step
 */

#ifndef SRC_SYSCALLS_H_
#define SRC_SYSCALLS_H_

int _write(int file, char *ptr, int len);
int _read(int file, char *ptr, int len);
int _close(int file);
int _lseek(int file, int ptr, int dir);

#endif /* SRC_SYSCALLS_H_ */
