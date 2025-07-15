void __cdecl __noreturn abort()
{
  unsigned int v0; // esi
  void (__cdecl *sigabrt)(int); // eax
  unsigned int v2; // edx
  unsigned int v3; // ecx
  unsigned int v4; // kr00_4
  unsigned int v5; // [esp-4h] [ebp-330h]
  _EXCEPTION_RECORD ExceptionRecord; // [esp+4h] [ebp-328h] BYREF
  _EXCEPTION_POINTERS ExceptionPointers; // [esp+54h] [ebp-2D8h] BYREF
  _CONTEXT ContextRecord; // [esp+5Ch] [ebp-2D0h] BYREF
  unsigned int savedregs; // [esp+32Ch] [ebp+0h]
  void *retaddr; // [esp+330h] [ebp+4h] BYREF

  if ( (__abort_behavior & 1) != 0 )
    _NMSG_WRITE(10);
  sigabrt = __get_sigabrt();
  if ( sigabrt )
  {
    sigabrt = (void (__cdecl *)(int))raise(v0, 22);
    v3 = v5;
  }
  if ( (__abort_behavior & 2) != 0 )
  {
    ContextRecord.Eax = (unsigned int)sigabrt;
    ContextRecord.Ecx = v3;
    ContextRecord.Edx = v2;
    ContextRecord.Esi = v0;
    LOWORD(ContextRecord.SegSs) = __SS__;
    LOWORD(ContextRecord.SegCs) = __CS__;
    LOWORD(ContextRecord.SegDs) = __DS__;
    LOWORD(ContextRecord.SegEs) = __ES__;
    LOWORD(ContextRecord.SegFs) = __FS__;
    LOWORD(ContextRecord.SegGs) = __GS__;
    v4 = __readeflags();
    ContextRecord.EFlags = v4;
    ContextRecord.Esp = (unsigned int)&retaddr;
    ContextRecord.ContextFlags = 65537;
    ContextRecord.Eip = (unsigned int)retaddr;
    ContextRecord.Ebp = savedregs;
    memset((int)&ExceptionRecord, 0, sizeof(ExceptionRecord));
    ExceptionPointers.ExceptionRecord = &ExceptionRecord;
    ExceptionRecord.ExceptionCode = 1073741845;
    ExceptionRecord.ExceptionAddress = retaddr;
    ExceptionPointers.ContextRecord = &ContextRecord;
    SetUnhandledExceptionFilter(0);
    UnhandledExceptionFilter(&ExceptionPointers);
  }
  _exit(3);
}
