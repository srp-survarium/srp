void __cdecl GetStackTrace(
        HANDLE hThread,
        boost::function<bool __cdecl(unsigned int,unsigned int,char const *,char const *,int,char const *,unsigned int)> *callback,
        bool invert_order)
{
  int v3; // ecx
  int v4; // esi
  char *v5; // edi
  unsigned int v6; // esi
  int v7; // eax
  int v8; // eax
  unsigned int i; // esi
  unsigned int v10; // edi
  unsigned int v11; // ebx
  boost::function7<bool,unsigned int,unsigned int,char const *,char const *,int,char const *,unsigned int> *v12; // ecx
  unsigned __int64 v13; // [esp-1Ch] [ebp-3728h]
  char a5[2]; // [esp+10h] [ebp-36FCh] BYREF
  unsigned __int8 v15[12286]; // [esp+12h] [ebp-36FAh] BYREF
  char a3[2]; // [esp+3010h] [ebp-6FCh] BYREF
  unsigned __int8 v17[518]; // [esp+3012h] [ebp-6FAh] BYREF
  _CONTEXT dst; // [esp+3218h] [ebp-4F4h] BYREF
  char a2[2]; // [esp+34E8h] [ebp-224h] BYREF
  unsigned __int8 v20[254]; // [esp+34EAh] [ebp-222h] BYREF
  _tagSTACKFRAME64 v21; // [esp+35E8h] [ebp-124h] BYREF
  int a4; // [esp+36F4h] [ebp-18h] BYREF
  int v23; // [esp+36F8h] [ebp-14h]
  unsigned int a6; // [esp+36FCh] [ebp-10h] BYREF
  unsigned int a1; // [esp+3700h] [ebp-Ch]
  void *CurrentProcess; // [esp+3704h] [ebp-8h]

  v4 = v3;
  CurrentProcess = GetCurrentProcess();
  if ( v4 )
  {
    memcpy_s(0, (unsigned __int8 *)&dst, 0x2CCu, *(unsigned __int8 **)(v4 + 4), 0x2CCu);
  }
  else
  {
    memset((int)&dst, 0, sizeof(dst));
    dst.ContextFlags = 65543;
    if ( hThread == GetCurrentThread() )
    {
      RtlCaptureContext(&dst);
    }
    else
    {
      if ( SuspendThread(hThread) == -1 )
        return;
      if ( !GetThreadContext(hThread, &dst) )
      {
        ResumeThread(hThread);
        return;
      }
    }
  }
  memset((int)&v21, 0, sizeof(v21));
  v21.AddrPC.Offset = dst.Eip;
  v21.AddrPC.Mode = AddrModeFlat;
  v21.AddrFrame.Mode = AddrModeFlat;
  v21.AddrStack.Mode = AddrModeFlat;
  strcpy(a2, "?");
  v21.AddrFrame.Offset = dst.Ebp;
  v21.AddrStack.Offset = dst.Esp;
  memset((int)v20, 0, sizeof(v20));
  strcpy(a3, "?");
  memset((int)v17, 0, sizeof(v17));
  strcpy(a5, "?");
  memset((int)v15, 0, 0x1FFEu);
  v5 = 0;
  a1 = 0;
  v6 = 0;
  while ( s_StackWalk64(
            0x14Cu,
            CurrentProcess,
            hThread,
            &v21,
            &dst,
            CH_ReadProcessMemory,
            s_SymFunctionTableAccess64,
            s_SymGetModuleBase64,
            0)
       && v21.AddrFrame.Offset )
  {
    v7 = 8 * v6;
    *(_DWORD *)&v15[v7 + 10238] = v21.AddrPC.Offset;
    ++v6;
    *(_DWORD *)&v15[v7 + 10242] = HIDWORD(v21.AddrPC.Offset);
    if ( v6 >= 0x100 )
      goto LABEL_14;
  }
  v8 = 8 * v6;
  *(_DWORD *)&v15[v8 + 10238] = 0;
  *(_DWORD *)&v15[v8 + 10242] = 0;
  a1 = v6;
  v5 = (char *)v6;
LABEL_14:
  v23 = 2 * !invert_order - 1;
  if ( invert_order )
    CurrentProcess = (void *)-1;
  else
    CurrentProcess = v5;
  for ( i = invert_order ? (unsigned int)(v5 - 1) : 0; (void *)i != CurrentProcess; i += v23 )
  {
    v10 = *(_DWORD *)&v15[8 * i + 10242];
    v11 = *(_DWORD *)&v15[8 * i + 10238];
    GetSourceInfoFromAddress(__PAIR64__(v10, v11), a2, a3, (char *)&a4, &a6);
    LODWORD(v13) = a5;
    GetFunctionInfoFromAddresses(__PAIR64__(v10, v11), v13);
    boost::function7<bool,unsigned int,unsigned int,char const *,char const *,int,char const *,unsigned int>::operator()(
      v12,
      callback,
      i,
      a1,
      a2,
      a3,
      a4,
      a5,
      a6);
  }
  if ( hThread != GetCurrentThread() )
    ResumeThread(hThread);
}
