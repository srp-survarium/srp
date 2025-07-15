int (__stdcall *__stdcall __delayLoadHelper2(const ImgDelayDescr *pidd, int (__stdcall **ppfnIATEntry)()))()
{
  unsigned int rvaDLLName; // eax
  unsigned int rvaHmod; // ebx
  unsigned int rvaIAT; // ecx
  unsigned int rvaINT; // edx
  const char *v6; // eax
  volatile LONG *v7; // ebx
  char *v8; // ecx
  char *v9; // edx
  bool v10; // zf
  HMODULE LibraryA; // edi
  int v13; // edx
  HMODULE ModuleHandleA; // eax
  int v15; // eax
  _DWORD *v16; // eax
  _DWORD *v17; // eax
  DelayLoadInfo *ProcAddress; // esi
  DelayLoadInfo *rgpdli[1]; // [esp+28h] [ebp-154h] BYREF
  ULONG_PTR Arguments; // [esp+2Ch] [ebp-150h] BYREF
  DelayLoadInfo dli; // [esp+30h] [ebp-14Ch] BYREF
  InternalImgDelayDescr idd; // [esp+54h] [ebp-128h]
  char path[264]; // [esp+74h] [ebp-108h] BYREF

  rvaDLLName = pidd->rvaDLLName;
  rvaHmod = pidd->rvaHmod;
  rvaIAT = pidd->rvaIAT;
  rvaINT = pidd->rvaINT;
  idd.pBoundIAT = (const _IMAGE_THUNK_DATA32 *)((char *)&_sbh_sizeHeaderList + pidd->rvaBoundIAT);
  idd.dwTimeStamp = pidd->dwTimeStamp;
  v6 = (char *)&_sbh_sizeHeaderList + rvaDLLName;
  dli.ppfn = ppfnIATEntry;
  v7 = (int *)((char *)&_sbh_sizeHeaderList.unused + rvaHmod);
  v8 = (char *)&_sbh_sizeHeaderList + rvaIAT;
  v9 = (char *)&_sbh_sizeHeaderList + rvaINT;
  v10 = (pidd->grAttrs & 1) == 0;
  dli.cb = 36;
  dli.pidd = pidd;
  dli.szDll = v6;
  memset(&dli.dlp, 0, 20);
  if ( v10 )
  {
    rgpdli[0] = &dli;
    vostok::platform::log_error("error during delay loading library %s", v6);
    RaiseException(0xC06D0057, 0, 1u, (const ULONG_PTR *)rgpdli);
    return 0;
  }
  LibraryA = (HMODULE)*v7;
  v13 = *(_DWORD *)&v9[4 * (((char *)ppfnIATEntry - v8) >> 2)];
  Arguments = 4 * (((char *)ppfnIATEntry - v8) >> 2);
  dli.dlp.fImportByName = v13 >= 0;
  if ( v13 < 0 )
    dli.dlp.dwOrdinal = (unsigned __int16)v13;
  else
    dli.dlp.dwOrdinal = (unsigned int)&_sbh_sizeHeaderList.unused + v13 + 2;
  rgpdli[0] = 0;
  if ( !__pfnDliNotifyHook2 || (rgpdli[0] = (DelayLoadInfo *)__pfnDliNotifyHook2(0, &dli)) == 0 )
  {
    if ( !LibraryA )
    {
      if ( !__pfnDliNotifyHook2 || (LibraryA = (HMODULE)__pfnDliNotifyHook2(1u, &dli)) == 0 )
      {
        ModuleHandleA = GetModuleHandleA(vostok::g_delay_loading_libraries_reference_module);
        GetModuleFileNameA(ModuleHandleA, path, 0x104u);
        strrchr(path, 0x5Cu);
        if ( v15 )
          *(_BYTE *)(v15 + 1) = 0;
        strcat_s(path, 0x104u, (const char *)&buf);
        strcat_s(path, 0x104u, "../../binaries.prebuilt/win32/");
        strcat_s(path, 0x104u, dli.szDll);
        LibraryA = LoadLibraryA(path);
        if ( !LibraryA )
        {
          LibraryA = LoadLibraryA(dli.szDll);
          if ( !LibraryA )
          {
            dli.dwLastError = GetLastError();
            if ( !__pfnDliFailureHook2 || (LibraryA = (HMODULE)__pfnDliFailureHook2(3u, &dli)) == 0 )
            {
              MessageBoxA(0, dli.szDll, "error during delay loading library", 0);
              rgpdli[0] = &dli;
              vostok::platform::log_error("error during delay loading library %s", dli.szDll);
              RaiseException(0xC06D007E, 0, 1u, (const ULONG_PTR *)rgpdli);
              return dli.pfnCur;
            }
          }
        }
      }
      if ( (HMODULE)InterlockedExchange(v7, (LONG)LibraryA) == LibraryA )
      {
        FreeLibrary(LibraryA);
      }
      else if ( pidd->rvaUnloadIAT )
      {
        v16 = LocalAlloc(0x40u, 8u);
        if ( v16 )
        {
          v16[1] = pidd;
          *v16 = __puiHead;
          __puiHead = v16;
        }
      }
    }
    dli.hmodCur = LibraryA;
    if ( __pfnDliNotifyHook2 )
      rgpdli[0] = (DelayLoadInfo *)__pfnDliNotifyHook2(2u, &dli);
    if ( !rgpdli[0] )
    {
      if ( !pidd->rvaBoundIAT
        || !pidd->dwTimeStamp
        || (v17 = (_DWORD *)((char *)LibraryA + *((_DWORD *)LibraryA + 15)), *v17 != 17744)
        || v17[2] != idd.dwTimeStamp
        || LibraryA != (HMODULE)v17[13]
        || (rgpdli[0] = *(DelayLoadInfo **)((char *)&idd.pBoundIAT->u1.ForwarderString + Arguments)) == 0 )
      {
        ProcAddress = (DelayLoadInfo *)GetProcAddress(LibraryA, dli.dlp.szProcName);
        rgpdli[0] = ProcAddress;
        if ( !ProcAddress )
        {
          dli.dwLastError = GetLastError();
          if ( __pfnDliFailureHook2 )
          {
            rgpdli[0] = (DelayLoadInfo *)__pfnDliFailureHook2(4u, &dli);
            ProcAddress = rgpdli[0];
          }
          if ( !ProcAddress )
          {
            Arguments = (ULONG_PTR)&dli;
            vostok::platform::log_error("error during delay loading library %s", dli.szDll);
            vostok::platform::log_error("cannot find procedure %s", dli.dlp.szProcName);
            RaiseException(0xC06D007F, 0, 1u, &Arguments);
            rgpdli[0] = (DelayLoadInfo *)dli.pfnCur;
          }
        }
      }
    }
    *ppfnIATEntry = (int (__stdcall *)())rgpdli[0];
  }
  if ( __pfnDliNotifyHook2 )
  {
    dli.dwLastError = 0;
    dli.hmodCur = LibraryA;
    dli.pfnCur = (int (__stdcall *)())rgpdli[0];
    __pfnDliNotifyHook2(5u, &dli);
  }
  return (int (__stdcall *)())rgpdli[0];
}
