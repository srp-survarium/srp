void __cdecl __noreturn __report_gsfailure()
{
  unsigned int v0; // eax
  unsigned int v1; // edx
  unsigned int v2; // ecx
  unsigned int v3; // ebx
  unsigned int v4; // edi
  unsigned int v5; // esi
  unsigned int v6; // kr00_4
  HANDLE CurrentProcess; // eax
  unsigned int vars0; // [esp+328h] [ebp+0h]
  void *retaddr; // [esp+32Ch] [ebp+4h]
  char v10; // [esp+330h] [ebp+8h] BYREF

  GS_ContextRecord.Eax = v0;
  GS_ContextRecord.Ecx = v2;
  GS_ContextRecord.Edx = v1;
  GS_ContextRecord.Ebx = v3;
  GS_ContextRecord.Esi = v5;
  GS_ContextRecord.Edi = v4;
  LOWORD(GS_ContextRecord.SegSs) = __SS__;
  LOWORD(GS_ContextRecord.SegCs) = __CS__;
  LOWORD(GS_ContextRecord.SegDs) = __DS__;
  LOWORD(GS_ContextRecord.SegEs) = __ES__;
  LOWORD(GS_ContextRecord.SegFs) = __FS__;
  LOWORD(GS_ContextRecord.SegGs) = __GS__;
  v6 = __readeflags();
  GS_ContextRecord.EFlags = v6;
  GS_ContextRecord.Ebp = vars0;
  GS_ContextRecord.Eip = (unsigned int)retaddr;
  GS_ContextRecord.Esp = (unsigned int)&v10;
  GS_ContextRecord.ContextFlags = 65537;
  GS_ExceptionRecord.ExceptionAddress = retaddr;
  GS_ExceptionRecord.ExceptionCode = -1073740791;
  GS_ExceptionRecord.ExceptionFlags = 1;
  DebuggerWasPresent = IsDebuggerPresent();
  _crt_debugger_hook();
  SetUnhandledExceptionFilter(0);
  UnhandledExceptionFilter(&GS_ExceptionPointers);
  if ( !DebuggerWasPresent )
    _crt_debugger_hook();
  CurrentProcess = GetCurrentProcess();
  TerminateProcess(CurrentProcess, 0xC0000409);
}
