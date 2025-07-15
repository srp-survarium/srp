void __usercall GetStackTrace(
        unsigned int a1@<ebx>,
        HANDLE hThread,
        _EXCEPTION_POINTERS *pointers,
        vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *callback,
        bool invert_order)
{
  unsigned int v5; // ecx
  unsigned int v6; // edx
  unsigned int v7; // ecx
  unsigned int v8; // ecx
  const std::exception *v9; // eax
  unsigned __int64 v10; // [esp-20h] [ebp-3880h]
  unsigned __int64 v11; // [esp-18h] [ebp-3878h]
  unsigned __int64 v12; // [esp-10h] [ebp-3870h]
  int v13; // [esp+0h] [ebp-3860h]
  unsigned int v14; // [esp+4h] [ebp-385Ch]
  unsigned int v15; // [esp+8h] [ebp-3858h]
  int v16; // [esp+Ch] [ebp-3854h]
  boost::bad_function_call v17; // [esp+30h] [ebp-3830h] BYREF
  unsigned int address_out; // [esp+140h] [ebp-3720h] BYREF
  int line; // [esp+144h] [ebp-371Ch] BYREF
  unsigned int j; // [esp+148h] [ebp-3718h]
  unsigned int i; // [esp+14Ch] [ebp-3714h]
  char szSourceInfo[2]; // [esp+150h] [ebp-3710h] BYREF
  unsigned __int8 v23[518]; // [esp+152h] [ebp-370Eh] BYREF
  int v24; // [esp+35Ch] [ebp-3504h]
  _CONTEXT dst; // [esp+360h] [ebp-3500h] BYREF
  unsigned int v26; // [esp+634h] [ebp-322Ch]
  int v27; // [esp+638h] [ebp-3228h]
  int v28; // [esp+63Ch] [ebp-3224h]
  char szModuleInfo[2]; // [esp+640h] [ebp-3220h] BYREF
  unsigned __int8 v30[254]; // [esp+642h] [ebp-321Eh] BYREF
  _DWORD address[513]; // [esp+740h] [ebp-3120h]
  unsigned int v32; // [esp+F44h] [ebp-291Ch]
  _DWORD stackAddress[512]; // [esp+F48h] [ebp-2918h]
  int v34; // [esp+1748h] [ebp-2118h]
  unsigned int v35; // [esp+174Ch] [ebp-2114h]
  _tagSTACKFRAME64 v36; // [esp+1750h] [ebp-2110h] BYREF
  void *CurrentProcess; // [esp+185Ch] [ebp-2004h]
  char szSymbol[2]; // [esp+1860h] [ebp-2000h] BYREF
  unsigned __int8 v39[8190]; // [esp+1862h] [ebp-1FFEh] BYREF

  CurrentProcess = GetCurrentProcess();
  if ( pointers )
  {
    memcpy_s(a1, (unsigned __int8 *)&dst, 0x2CCu, (unsigned __int8 *)pointers->ContextRecord, 0x2CCu);
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
  memset((int)&v36, 0, sizeof(v36));
  v26 = 332;
  v36.AddrPC.Offset = dst.Eip;
  v36.AddrPC.Mode = AddrModeFlat;
  v36.AddrFrame.Offset = dst.Ebp;
  v36.AddrFrame.Mode = AddrModeFlat;
  v36.AddrStack.Offset = dst.Esp;
  v36.AddrStack.Mode = AddrModeFlat;
  v28 = 0;
  strcpy(szModuleInfo, "?");
  memset((int)v30, 0, sizeof(v30));
  strcpy(szSourceInfo, "?");
  memset((int)v23, 0, sizeof(v23));
  strcpy(szSymbol, "?");
  memset((int)v39, 0, sizeof(v39));
  v35 = 0;
  for ( i = 0; i < 0x100; ++i )
  {
    v27 = s_StackWalk64(
            v26,
            CurrentProcess,
            hThread,
            &v36,
            &dst,
            CH_ReadProcessMemory,
            s_SymFunctionTableAccess64,
            s_SymGetModuleBase64,
            0);
    if ( !v27 || !v36.AddrFrame.Offset )
    {
      v5 = i;
      address[2 * i] = 0;
      address[2 * v5 + 1] = 0;
      v6 = i;
      stackAddress[2 * i] = 0;
      stackAddress[2 * v6 + 1] = 0;
      v35 = i;
      break;
    }
    v7 = i;
    address[2 * i] = v36.AddrPC.Offset;
    address[2 * v7 + 1] = HIDWORD(v36.AddrPC.Offset);
    v8 = i;
    stackAddress[2 * i] = v36.AddrFrame.Offset;
    stackAddress[2 * v8 + 1] = HIDWORD(v36.AddrFrame.Offset);
  }
  if ( invert_order )
    v14 = v35 - 1;
  else
    v14 = 0;
  v32 = v14;
  v34 = invert_order ? -1 : 1;
  if ( invert_order )
    v13 = -1;
  else
    v13 = v35;
  v24 = v13;
  for ( j = v32; j != v24; j += v34 )
  {
    HIDWORD(v10) = address[2 * j + 1];
    LODWORD(v10) = address[2 * j];
    GetSourceInfoFromAddress(a1, v10, szModuleInfo, 0x100u, szSourceInfo, 0x208u, &line, &address_out);
    HIDWORD(v12) = stackAddress[2 * j + 1];
    LODWORD(v12) = stackAddress[2 * j];
    HIDWORD(v11) = address[2 * j + 1];
    LODWORD(v11) = address[2 * j];
    GetFunctionInfoFromAddresses(a1, v11, v12, szSymbol, 0x2000u);
    v15 = address_out;
    v16 = line;
    if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!(callback) )
    {
      boost::bad_function_call::bad_function_call(&v17);
      boost::throw_exception(v9);
      boost::bad_function_call::~bad_function_call(&v17);
    }
    (*(void (__cdecl **)(vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *, unsigned int, unsigned int, char *, char *, int, char *, unsigned int))(((int)callback->m_object & 0xFFFFFFFE) + 4))(
      callback + 2,
      j,
      v35,
      szModuleInfo,
      szSourceInfo,
      v16,
      szSymbol,
      v15);
  }
  if ( hThread != GetCurrentThread() )
    ResumeThread(hThread);
}
