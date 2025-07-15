void __usercall __noreturn _invoke_watson(unsigned int a1@<ebx>, unsigned int a2@<edi>, unsigned int a3@<esi>)
{
  unsigned int v3; // ecx
  unsigned int v4; // edx
  unsigned int v5; // kr00_4
  BOOL v6; // ebx
  HANDLE CurrentProcess; // eax
  _EXCEPTION_RECORD ExceptionRecord; // [esp+4h] [ebp-328h] BYREF
  _EXCEPTION_POINTERS ExceptionPointers; // [esp+54h] [ebp-2D8h] BYREF
  _CONTEXT ContextRecord; // [esp+5Ch] [ebp-2D0h] BYREF
  unsigned int savedregs; // [esp+32Ch] [ebp+0h]
  void *retaddr; // [esp+330h] [ebp+4h] BYREF

  memset((int)&ExceptionRecord.ExceptionFlags, 0, 0x4Cu);
  ExceptionPointers.ExceptionRecord = &ExceptionRecord;
  ExceptionPointers.ContextRecord = &ContextRecord;
  ContextRecord.Eax = (unsigned int)&ContextRecord;
  ContextRecord.Ecx = v3;
  ContextRecord.Edx = v4;
  ContextRecord.Ebx = a1;
  ContextRecord.Esi = a3;
  ContextRecord.Edi = a2;
  LOWORD(ContextRecord.SegSs) = __SS__;
  LOWORD(ContextRecord.SegCs) = __CS__;
  LOWORD(ContextRecord.SegDs) = __DS__;
  LOWORD(ContextRecord.SegEs) = __ES__;
  LOWORD(ContextRecord.SegFs) = __FS__;
  LOWORD(ContextRecord.SegGs) = __GS__;
  v5 = __readeflags();
  ContextRecord.EFlags = v5;
  ContextRecord.ContextFlags = 65537;
  ContextRecord.Eip = (unsigned int)retaddr;
  ContextRecord.Esp = (unsigned int)&retaddr;
  ContextRecord.Ebp = savedregs;
  ExceptionRecord.ExceptionCode = -1073740777;
  ExceptionRecord.ExceptionFlags = 1;
  ExceptionRecord.ExceptionAddress = retaddr;
  v6 = IsDebuggerPresent();
  SetUnhandledExceptionFilter(0);
  if ( !UnhandledExceptionFilter(&ExceptionPointers) && !v6 )
    _crt_debugger_hook(2);
  CurrentProcess = GetCurrentProcess();
  TerminateProcess(CurrentProcess, 0xC0000417);
}
