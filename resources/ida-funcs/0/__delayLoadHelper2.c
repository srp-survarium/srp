int (__stdcall *__stdcall __delayLoadHelper2(const ImgDelayDescr *pidd, int (__stdcall **ppfnIATEntry)()))()
{
  unsigned int rvaIAT; // ebx
  char *v3; // edi
  const char *v4; // ecx
  char *v5; // ebx
  char *v6; // edx
  HMODULE LibraryA; // edi
  int v9; // edx
  unsigned int v10; // eax
  HMODULE ModuleHandleA; // eax
  int v12; // eax
  _DWORD *v13; // eax
  _DWORD *v14; // eax
  ULONG_PTR Arguments; // [esp+28h] [ebp-154h] BYREF
  ULONG_PTR v16; // [esp+2Ch] [ebp-150h] BYREF
  DelayLoadInfo v17; // [esp+30h] [ebp-14Ch] BYREF
  volatile LONG *Target; // [esp+5Ch] [ebp-120h]
  char *v19; // [esp+68h] [ebp-114h]
  unsigned int dwTimeStamp; // [esp+70h] [ebp-10Ch]
  char Filename[264]; // [esp+74h] [ebp-108h] BYREF

  memset(&v17.dlp, 0, 20);
  rvaIAT = pidd->rvaIAT;
  v3 = (char *)&_sbh_sizeHeaderList + pidd->rvaBoundIAT;
  v4 = (char *)&_sbh_sizeHeaderList + pidd->rvaDLLName;
  Target = (int *)((char *)&_sbh_sizeHeaderList.unused + pidd->rvaHmod);
  v5 = (char *)&_sbh_sizeHeaderList + rvaIAT;
  v6 = (char *)&_sbh_sizeHeaderList + pidd->rvaINT;
  dwTimeStamp = pidd->dwTimeStamp;
  v19 = v3;
  v17.ppfn = ppfnIATEntry;
  v17.cb = 36;
  v17.pidd = pidd;
  v17.szDll = v4;
  if ( (pidd->grAttrs & 1) == 0 )
  {
    Arguments = (ULONG_PTR)&v17;
    vostok::platform::log_error("error during delay loading library %s", v4);
    RaiseException(0xC06D0057, 0, 1u, &Arguments);
    return 0;
  }
  LibraryA = (HMODULE)*Target;
  v9 = *(_DWORD *)&v6[4 * (((char *)ppfnIATEntry - v5) >> 2)];
  v16 = 4 * (((char *)ppfnIATEntry - v5) >> 2);
  v17.dlp.fImportByName = v9 >= 0;
  v10 = (unsigned int)&_sbh_sizeHeaderList.unused + v9 + 2;
  if ( v9 < 0 )
    v10 = (unsigned __int16)v9;
  v17.dlp.dwOrdinal = v10;
  Arguments = 0;
  if ( !__pfnDliNotifyHook2 || (Arguments = (ULONG_PTR)__pfnDliNotifyHook2(0, &v17)) == 0 )
  {
    if ( !LibraryA )
    {
      if ( !__pfnDliNotifyHook2 || (LibraryA = (HMODULE)__pfnDliNotifyHook2(1u, &v17)) == 0 )
      {
        ModuleHandleA = GetModuleHandleA(vostok::g_delay_loading_libraries_reference_module);
        GetModuleFileNameA(ModuleHandleA, Filename, 0x104u);
        strrchr(Filename, 0x5Cu);
        if ( v12 )
          *(_BYTE *)(v12 + 1) = 0;
        strcat_s(Filename, 0x104u, uri);
        strcat_s(Filename, 0x104u, "../../binaries.prebuilt/win32/");
        strcat_s(Filename, 0x104u, v17.szDll);
        LibraryA = LoadLibraryA(Filename);
        if ( !LibraryA )
        {
          LibraryA = LoadLibraryA(v17.szDll);
          if ( !LibraryA )
          {
            v17.dwLastError = GetLastError();
            if ( !__pfnDliFailureHook2 || (LibraryA = (HMODULE)__pfnDliFailureHook2(3u, &v17)) == 0 )
            {
              MessageBoxA(0, v17.szDll, "error during delay loading library", 0);
              Arguments = (ULONG_PTR)&v17;
              vostok::platform::log_error("error during delay loading library %s", v17.szDll);
              RaiseException(0xC06D007E, 0, 1u, &Arguments);
              return v17.pfnCur;
            }
          }
        }
      }
      if ( (HMODULE)InterlockedExchange(Target, (LONG)LibraryA) == LibraryA )
      {
        FreeLibrary(LibraryA);
      }
      else if ( pidd->rvaUnloadIAT )
      {
        v13 = LocalAlloc(0x40u, 8u);
        if ( v13 )
        {
          v13[1] = pidd;
          *v13 = __puiHead;
          __puiHead = v13;
        }
      }
    }
    v17.hmodCur = LibraryA;
    if ( __pfnDliNotifyHook2 )
      Arguments = (ULONG_PTR)__pfnDliNotifyHook2(2u, &v17);
    if ( !Arguments )
    {
      if ( !pidd->rvaBoundIAT
        || !pidd->dwTimeStamp
        || (v14 = (_DWORD *)((char *)LibraryA + *((_DWORD *)LibraryA + 15)), *v14 != 17744)
        || v14[2] != dwTimeStamp
        || LibraryA != (HMODULE)v14[13]
        || (Arguments = *(_DWORD *)&v19[v16]) == 0 )
      {
        Arguments = (ULONG_PTR)GetProcAddress(LibraryA, v17.dlp.szProcName);
        if ( !Arguments )
        {
          v17.dwLastError = GetLastError();
          if ( __pfnDliFailureHook2 )
            Arguments = (ULONG_PTR)__pfnDliFailureHook2(4u, &v17);
          if ( !Arguments )
          {
            v16 = (ULONG_PTR)&v17;
            vostok::platform::log_error("error during delay loading library %s", v17.szDll);
            vostok::platform::log_error("cannot find procedure %s", v17.dlp.szProcName);
            RaiseException(0xC06D007F, 0, 1u, &v16);
            Arguments = (ULONG_PTR)v17.pfnCur;
          }
        }
      }
    }
    *ppfnIATEntry = (int (__stdcall *)())Arguments;
  }
  if ( __pfnDliNotifyHook2 )
  {
    v17.pfnCur = (int (__stdcall *)())Arguments;
    v17.dwLastError = 0;
    v17.hmodCur = LibraryA;
    __pfnDliNotifyHook2(5u, &v17);
  }
  return (int (__stdcall *)())Arguments;
}
