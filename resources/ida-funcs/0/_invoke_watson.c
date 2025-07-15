void __usercall __noreturn _invoke_watson(int a1@<ebx>, int a2@<edi>, int a3@<esi>)
{
  int v3; // ecx
  int v4; // edx
  unsigned int v5; // kr00_4
  BOOL v6; // ebx
  HANDLE CurrentProcess; // eax
  _DWORD v8[20]; // [esp+4h] [ebp-328h] BYREF
  struct _EXCEPTION_POINTERS ExceptionInfo; // [esp+54h] [ebp-2D8h] BYREF
  _DWORD v10[35]; // [esp+5Ch] [ebp-2D0h] BYREF
  __int16 v11; // [esp+E8h] [ebp-244h]
  __int16 v12; // [esp+ECh] [ebp-240h]
  __int16 v13; // [esp+F0h] [ebp-23Ch]
  __int16 v14; // [esp+F4h] [ebp-238h]
  int v15; // [esp+F8h] [ebp-234h]
  int v16; // [esp+FCh] [ebp-230h]
  int v17; // [esp+100h] [ebp-22Ch]
  int v18; // [esp+104h] [ebp-228h]
  int v19; // [esp+108h] [ebp-224h]
  _DWORD *v20; // [esp+10Ch] [ebp-220h]
  int v21; // [esp+110h] [ebp-21Ch]
  void *v22; // [esp+114h] [ebp-218h]
  __int16 v23; // [esp+118h] [ebp-214h]
  unsigned int v24; // [esp+11Ch] [ebp-210h]
  void **v25; // [esp+120h] [ebp-20Ch]
  __int16 v26; // [esp+124h] [ebp-208h]
  int savedregs; // [esp+32Ch] [ebp+0h]
  void *retaddr; // [esp+330h] [ebp+4h] BYREF

  memset((int)&v8[1], 0, 76);
  ExceptionInfo.ExceptionRecord = (_EXCEPTION_RECORD *)v8;
  ExceptionInfo.ContextRecord = (_CONTEXT *)v10;
  v20 = v10;
  v19 = v3;
  v18 = v4;
  v17 = a1;
  v16 = a3;
  v15 = a2;
  v26 = __SS__;
  v23 = __CS__;
  v14 = __DS__;
  v13 = __ES__;
  v12 = __FS__;
  v11 = __GS__;
  v5 = __readeflags();
  v24 = v5;
  v10[0] = 65537;
  v22 = retaddr;
  v25 = &retaddr;
  v21 = savedregs;
  v8[0] = -1073740777;
  v8[1] = 1;
  v8[3] = retaddr;
  v6 = IsDebuggerPresent();
  SetUnhandledExceptionFilter(0);
  if ( !UnhandledExceptionFilter(&ExceptionInfo) && !v6 )
    _crt_debugger_hook();
  CurrentProcess = GetCurrentProcess();
  TerminateProcess(CurrentProcess, 0xC0000417);
}
