#ifndef __PROCESS_H_
#define __PROCESS_H_

#include <ntifs.h>

#include "Common.h"

#define _START_DEBUG

/*
	获取某个进程的pid	
*/
ULONG Proc_GetPid(IN PEPROCESS process);
ULONG Proc_GetPidByName(IN PSTR procName);
ULONG Proc_GetCurrentPid();

/*
	获取某个进程的镜像文件名（进程名）
*/
PSTR GetImageFileName(IN PEPROCESS process);

/*
	获取当前进程的镜像文件名（进程名）
*/
PSTR GetCurrentImageFileName();

/*
	遍历进程
*/
VOID TraverseProcess();

/*
	进程断链
*/
VOID CutProcessLink(IN PCSTR procName, IN BOOLEAN IsAll);

/*
	判断当前进程是不是指定的进程
*/
BOOLEAN IsSpecifiedProcess(IN PSTR procName);
BOOLEAN IsCE();
BOOLEAN IsOD();
BOOLEAN IsSelfDebug();
BOOLEAN IsDNFFamily();
BOOLEAN IsDNFFamilyByPid();
BOOLEAN IsDNFClient();
BOOLEAN IsDNF();
BOOLEAN IsTASLogin();
BOOLEAN IsNtQueryInformationProcess();

VOID IsNotepad(IN Type_TestCallFun callFun);

/*
	根据进程名获取eprocess
*/
ULONG64 GetProcessByName(IN PSTR procName);

ULONG64 GetProcessCr3ByName(IN PSTR procName);
ULONG64 GetProcessCr3ByPid(IN ULONG64 pid);

/*
	根据pid获取eprocess
*/
ULONG GetProcessByPid(IN ULONG pid);

/*
	获取某个进程的_HANDLE_TABLE

	win7 x32：eprocess + 0x0f4
*/
ULONG GetProcessObjectTableByName(IN PSTR procName);
ULONG GetProcessObjectTableByPid(IN ULONG pid);

/*
	获取进程的页目录表基址
*/
ULONG GetCurrentProcessDirectoryTableBase();
VOID SetCurrentProcessDirectoryTableBase(IN ULONG val);
ULONG GetProcessDirectoryTableBase(IN ULONG64 process);
ULONG GetDirectoryTableBaseByPid(IN ULONG pid);
ULONG GetDirectoryTableBaseByProcNameA(IN PSTR procName);
ULONG GetDirectoryTableBaseByProcNameW(IN PWSTR procName);

NTSTATUS AttachProcess(IN PEPROCESS process);
NTSTATUS UnAttachProcess(IN PEPROCESS process);

#endif
