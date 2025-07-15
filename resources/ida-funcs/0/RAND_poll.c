int __usercall RAND_poll@<eax>(unsigned int a1@<ebx>, int a2@<edi>, unsigned int a3@<esi>)
{
  void *v3; // esp
  HMODULE LibraryA; // edi
  HMODULE v5; // eax
  HMODULE v6; // ebx
  void *v7; // esp
  void *v8; // esp
  HMODULE v9; // ebx
  int (*v10)(void); // ebx
  void *v11; // esp
  void *v12; // esp
  HMODULE v13; // eax
  HMODULE v14; // ebx
  void *v15; // esp
  void *v16; // esp
  void *v17; // esp
  HANDLE (__stdcall *CreateToolhelp32Snapshot)(DWORD, DWORD); // ebx
  BOOL (__stdcall *Module32Next)(HANDLE, LPMODULEENTRY32); // eax
  BOOL (__stdcall *v20)(HCRYPTPROV *, LPCWSTR, LPCWSTR, DWORD, DWORD); // esi
  void *v21; // ebx
  void *v22; // esp
  int v23; // ebx
  DWORD (__stdcall *v24)(LPTSTR, LPTSTR, DWORD, DWORD, LPBYTE *); // esi
  void *v25; // esp
  DWORD (__stdcall *v26)(LPTSTR, LPTSTR, DWORD, DWORD, LPBYTE *); // ebx
  BOOL (__stdcall *v27)(HANDLE, LPPROCESSENTRY32); // esi
  void *v28; // esp
  DWORD (__stdcall *v29)(LPTSTR, LPTSTR, DWORD, DWORD, LPBYTE *); // ebx
  void *v30; // esp
  BOOL (__stdcall *v31)(HANDLE, LPMODULEENTRY32); // esi
  void *v32; // esp
  void *v33; // esp
  void *v34; // esp
  unsigned __int64 v36; // [esp+E8h] [ebp-E4h] BYREF
  unsigned __int64 entropy; // [esp+F0h] [ebp-DCh]
  _MEMORYSTATUS Buffer; // [esp+F8h] [ebp-D4h] BYREF
  tagTHREADENTRY32 v39; // [esp+118h] [ebp-B4h] BYREF
  int v40[9]; // [esp+134h] [ebp-98h] BYREF
  int v41; // [esp+158h] [ebp-74h]
  FARPROC CloseToolhelp32Snapshot; // [esp+15Ch] [ebp-70h]
  HMODULE v43; // [esp+160h] [ebp-6Ch]
  BOOL (__stdcall *Module32First)(HANDLE, LPMODULEENTRY32); // [esp+164h] [ebp-68h]
  BOOL (__stdcall *Thread32First)(HANDLE, LPTHREADENTRY32); // [esp+168h] [ebp-64h]
  BOOL (__stdcall *Process32Next)(HANDLE, LPPROCESSENTRY32); // [esp+16Ch] [ebp-60h]
  int num; // [esp+170h] [ebp-5Ch] BYREF
  int v48; // [esp+174h] [ebp-58h] BYREF
  int v49; // [esp+178h] [ebp-54h]
  int v50; // [esp+17Ch] [ebp-50h]
  int v51; // [esp+180h] [ebp-4Ch]
  BOOL (__stdcall *Thread32Next)(HANDLE, LPTHREADENTRY32); // [esp+184h] [ebp-48h]
  DWORD CurrentProcessId; // [esp+188h] [ebp-44h] BYREF
  BOOL (__stdcall *v54)(HANDLE, LPMODULEENTRY32); // [esp+18Ch] [ebp-40h] BYREF
  unsigned int v55; // [esp+190h] [ebp-3Ch] BYREF
  DWORD (__stdcall *NetApiBufferFree)(LPVOID); // [esp+194h] [ebp-38h]
  BOOL (__stdcall *CryptGenRandom)(HCRYPTPROV, DWORD, BYTE *); // [esp+198h] [ebp-34h]
  BOOL (__stdcall *CryptReleaseContext)(HCRYPTPROV, DWORD); // [esp+19Ch] [ebp-30h]
  HMODULE hModule; // [esp+1A0h] [ebp-2Ch]
  int v60; // [esp+1A4h] [ebp-28h]
  BOOL (__stdcall *CryptAcquireContextW)(HCRYPTPROV *, LPCWSTR, LPCWSTR, DWORD, DWORD); // [esp+1A8h] [ebp-24h]
  void *buf; // [esp+1ACh] [ebp-20h] BYREF
  DWORD (__stdcall *NetStatisticsGet)(LPTSTR, LPTSTR, DWORD, DWORD, LPBYTE *); // [esp+1B0h] [ebp-1Ch]
  unsigned __int64 *v64; // [esp+1B4h] [ebp-18h]
  _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp+1BCh] [ebp-10h]
  int (__cdecl *v66)(_EXCEPTION_RECORD *, _EXCEPTION_REGISTRATION_RECORD *, _CONTEXT *); // [esp+1C0h] [ebp-Ch]
  _EH4_SCOPETABLE *v67; // [esp+1C4h] [ebp-8h]
  int v68; // [esp+1C8h] [ebp-4h]
  tagMODULEENTRY32 v69; // [esp+1CCh] [ebp+0h] BYREF
  tagPROCESSENTRY32 v70; // [esp+3F0h] [ebp+224h] BYREF
  _OSVERSIONINFOA VersionInformation; // [esp+518h] [ebp+34Ch] BYREF
  _BYTE v72[64]; // [esp+5ACh] [ebp+3E0h] BYREF

  v68 = -2;
  v67 = stru_86ACE0;
  v66 = _except_handler4;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v3 = alloca(188);
  v67 = (_EH4_SCOPETABLE *)(__security_cookie ^ (unsigned int)stru_86ACE0);
  entropy = __PAIR64__(a1, a3);
  HIDWORD(v36) = a2;
  v64 = &v36;
  v55 = 0;
  v60 = 0;
  VersionInformation.dwOSVersionInfoSize = 148;
  GetVersionExA(&VersionInformation);
  hModule = LoadLibraryA("ADVAPI32.DLL");
  LibraryA = LoadLibraryA("KERNEL32.DLL");
  v43 = LibraryA;
  v5 = LoadLibraryA("NETAPI32.DLL");
  v6 = v5;
  CryptAcquireContextW = 0;
  CryptGenRandom = 0;
  CryptReleaseContext = 0;
  NetStatisticsGet = 0;
  NetApiBufferFree = 0;
  if ( v5 )
  {
    NetStatisticsGet = (DWORD (__stdcall *)(LPTSTR, LPTSTR, DWORD, DWORD, LPBYTE *))GetProcAddress(
                                                                                      v5,
                                                                                      "NetStatisticsGet");
    NetApiBufferFree = (DWORD (__stdcall *)(LPVOID))GetProcAddress(v6, "NetApiBufferFree");
  }
  if ( NetStatisticsGet && NetApiBufferFree )
  {
    if ( !((int (__stdcall *)(_DWORD, const wchar_t *, _DWORD, _DWORD, void **, _DWORD, _DWORD, _DWORD, _DWORD, unsigned int))NetStatisticsGet)(
            0,
            L"LanmanWorkstation",
            0,
            0,
            &buf,
            v36,
            HIDWORD(v36),
            entropy,
            HIDWORD(entropy),
            Buffer.dwLength) )
    {
      v7 = alloca(8);
      RAND_add((int)LibraryA, buf, 216, 45.0);
      NetApiBufferFree(buf);
    }
    Buffer.dwLength = (unsigned int)&buf;
    entropy = 0;
    HIDWORD(v36) = L"LanmanServer";
    LODWORD(v36) = 0;
    if ( !((int (*)(void))NetStatisticsGet)() )
    {
      v8 = alloca(8);
      RAND_add((int)LibraryA, buf, 68, 17.0);
      NetApiBufferFree(buf);
    }
  }
  if ( v6 )
    FreeLibrary(v6);
  if ( hModule )
  {
    v9 = hModule;
    CryptAcquireContextW = (BOOL (__stdcall *)(HCRYPTPROV *, LPCWSTR, LPCWSTR, DWORD, DWORD))GetProcAddress(
                                                                                               hModule,
                                                                                               "CryptAcquireContextW");
    CryptGenRandom = (BOOL (__stdcall *)(HCRYPTPROV, DWORD, BYTE *))GetProcAddress(v9, "CryptGenRandom");
    CryptReleaseContext = (BOOL (__stdcall *)(HCRYPTPROV, DWORD))GetProcAddress(v9, "CryptReleaseContext");
  }
  if ( CryptAcquireContextW && CryptGenRandom && CryptReleaseContext )
  {
    v10 = (int (*)(void))CryptAcquireContextW;
    if ( ((int (__stdcall *)(unsigned int *, _DWORD, _DWORD, int, int, _DWORD, _DWORD, _DWORD, _DWORD, unsigned int))CryptAcquireContextW)(
           &v55,
           0,
           0,
           1,
           -268435456,
           v36,
           HIDWORD(v36),
           entropy,
           HIDWORD(entropy),
           Buffer.dwLength) )
    {
      if ( ((int (__stdcall *)(unsigned int, int, _BYTE *, unsigned int, unsigned int))CryptGenRandom)(
             v55,
             64,
             v72,
             Buffer.dwMemoryLoad,
             Buffer.dwTotalPhys) )
      {
        v11 = alloca(8);
        RAND_add((int)LibraryA, v72, 64, 0.0);
        v60 = 1;
      }
      ((void (__cdecl *)(unsigned int, _DWORD))CryptReleaseContext)(v55, 0);
    }
    Buffer.dwLength = 0;
    HIDWORD(entropy) = 22;
    LODWORD(entropy) = L"Intel Hardware Cryptographic Service Provider";
    v36 = (unsigned int)&v55;
    if ( v10() )
    {
      if ( ((int (__stdcall *)(unsigned int, int, _BYTE *, _DWORD, _DWORD))CryptGenRandom)(
             v55,
             64,
             v72,
             v36,
             HIDWORD(v36)) )
      {
        v12 = alloca(8);
        RAND_add((int)LibraryA, v72, 64, 64.0);
        v60 = 1;
      }
      v36 = v55;
      ((void (*)(void))CryptReleaseContext)();
    }
  }
  if ( hModule )
    FreeLibrary(hModule);
  if ( VersionInformation.dwPlatformId != 2 || !OPENSSL_isservice() )
  {
    v13 = LoadLibraryA("USER32.DLL");
    v14 = v13;
    if ( v13 )
    {
      CryptAcquireContextW = (BOOL (__stdcall *)(HCRYPTPROV *, LPCWSTR, LPCWSTR, DWORD, DWORD))GetProcAddress(
                                                                                                 v13,
                                                                                                 "GetForegroundWindow");
      hModule = (HMODULE)GetProcAddress(v14, "GetCursorInfo");
      CryptReleaseContext = (BOOL (__stdcall *)(HCRYPTPROV, DWORD))GetProcAddress(v14, "GetQueueStatus");
      if ( CryptAcquireContextW )
      {
        v54 = (BOOL (__stdcall *)(HANDLE, LPMODULEENTRY32))((int (*)(void))CryptAcquireContextW)();
        v15 = alloca(8);
        RAND_add((int)LibraryA, &v54, 4, 0.0);
      }
      if ( hModule && (VersionInformation.dwPlatformId != 2 || VersionInformation.dwMajorVersion >= 5) )
      {
        num = 20;
        if ( ((int (__stdcall *)(int *))hModule)(&num) )
        {
          v16 = alloca(8);
          RAND_add((int)LibraryA, &num, num, 2.0);
        }
      }
      if ( CryptReleaseContext )
      {
        CurrentProcessId = ((int (__stdcall *)(int))CryptReleaseContext)(191);
        v17 = alloca(8);
        RAND_add((int)LibraryA, &CurrentProcessId, 4, 1.0);
      }
      FreeLibrary(v14);
    }
  }
  if ( LibraryA )
  {
    NetStatisticsGet = 0;
    CreateToolhelp32Snapshot = (HANDLE (__stdcall *)(DWORD, DWORD))GetProcAddress(LibraryA, "CreateToolhelp32Snapshot");
    CloseToolhelp32Snapshot = GetProcAddress(LibraryA, "CloseToolhelp32Snapshot");
    hModule = (HMODULE)GetProcAddress(LibraryA, "Heap32First");
    CryptReleaseContext = (BOOL (__stdcall *)(HCRYPTPROV, DWORD))GetProcAddress(LibraryA, "Heap32Next");
    CryptAcquireContextW = (BOOL (__stdcall *)(HCRYPTPROV *, LPCWSTR, LPCWSTR, DWORD, DWORD))GetProcAddress(
                                                                                               LibraryA,
                                                                                               "Heap32ListFirst");
    CryptGenRandom = (BOOL (__stdcall *)(HCRYPTPROV, DWORD, BYTE *))GetProcAddress(LibraryA, "Heap32ListNext");
    NetApiBufferFree = (DWORD (__stdcall *)(LPVOID))GetProcAddress(LibraryA, "Process32First");
    Process32Next = (BOOL (__stdcall *)(HANDLE, LPPROCESSENTRY32))GetProcAddress(LibraryA, "Process32Next");
    Thread32First = (BOOL (__stdcall *)(HANDLE, LPTHREADENTRY32))GetProcAddress(LibraryA, "Thread32First");
    Thread32Next = (BOOL (__stdcall *)(HANDLE, LPTHREADENTRY32))GetProcAddress(LibraryA, "Thread32Next");
    Module32First = (BOOL (__stdcall *)(HANDLE, LPMODULEENTRY32))GetProcAddress(LibraryA, "Module32First");
    Module32Next = (BOOL (__stdcall *)(HANDLE, LPMODULEENTRY32))GetProcAddress(LibraryA, "Module32Next");
    v54 = Module32Next;
    if ( CreateToolhelp32Snapshot )
    {
      if ( hModule )
      {
        if ( CryptReleaseContext )
        {
          v20 = CryptAcquireContextW;
          if ( CryptAcquireContextW )
          {
            if ( CryptGenRandom )
            {
              if ( NetApiBufferFree )
              {
                if ( Process32Next )
                {
                  if ( Thread32First )
                  {
                    if ( Thread32Next )
                    {
                      if ( Module32First )
                      {
                        if ( Module32Next )
                        {
                          buf = CreateToolhelp32Snapshot(15, 0);
                          if ( buf != (void *)-1 )
                          {
                            v49 = 0;
                            v50 = 0;
                            v51 = 0;
                            v48 = 16;
                            if ( v60 )
                              NetStatisticsGet = (DWORD (__stdcall *)(LPTSTR, LPTSTR, DWORD, DWORD, LPBYTE *))GetTickCount();
                            v21 = buf;
                            if ( ((int (__stdcall *)(void *, int *, _DWORD, _DWORD, _DWORD, _DWORD, unsigned int, unsigned int))v20)(
                                   buf,
                                   &v48,
                                   v36,
                                   HIDWORD(v36),
                                   entropy,
                                   HIDWORD(entropy),
                                   Buffer.dwLength,
                                   Buffer.dwMemoryLoad) )
                            {
                              CryptAcquireContextW = (BOOL (__stdcall *)(HCRYPTPROV *, LPCWSTR, LPCWSTR, DWORD, DWORD))42;
                              do
                              {
                                v22 = alloca(8);
                                RAND_add((int)LibraryA, &v48, v48, 3.0);
                                v68 = 0;
                                memset(&v40[1], 0, 32);
                                v40[0] = 36;
                                if ( ((int (__stdcall *)(int *, int, int, unsigned int, unsigned int))hModule)(
                                       v40,
                                       v49,
                                       v50,
                                       Buffer.dwTotalPhys,
                                       Buffer.dwAvailPhys) )
                                {
                                  v23 = 80;
                                  v41 = 80;
                                  v24 = NetStatisticsGet;
                                  do
                                  {
                                    v25 = alloca(8);
                                    RAND_add((int)LibraryA, v40, v40[0], 5.0);
                                    if ( !((int (__stdcall *)(int *))CryptReleaseContext)(v40)
                                      || v60 && GetTickCount() - (unsigned int)v24 >= 0x3E8 )
                                    {
                                      break;
                                    }
                                    v41 = --v23;
                                  }
                                  while ( v23 > 0 );
                                  v21 = buf;
                                }
                                v68 = -2;
                                Buffer.dwAvailPhys = (unsigned int)&v48;
                                Buffer.dwTotalPhys = (unsigned int)v21;
                              }
                              while ( ((int (*)(void))CryptGenRandom)()
                                   && (!v60 || GetTickCount() - (unsigned int)NetStatisticsGet < 0x3E8)
                                   && (int)CryptAcquireContextW > 0 );
                            }
                            v70.dwSize = 296;
                            if ( v60 )
                              NetStatisticsGet = (DWORD (__stdcall *)(LPTSTR, LPTSTR, DWORD, DWORD, LPBYTE *))GetTickCount();
                            if ( ((int (__cdecl *)(void *, tagPROCESSENTRY32 *))NetApiBufferFree)(v21, &v70) )
                            {
                              v26 = NetStatisticsGet;
                              v27 = Process32Next;
                              do
                              {
                                v28 = alloca(8);
                                RAND_add((int)LibraryA, &v70, v70.dwSize, 9.0);
                              }
                              while ( v27(buf, &v70) && (!v60 || GetTickCount() - (unsigned int)v26 < 0x3E8) );
                              v21 = buf;
                            }
                            v39.dwSize = 28;
                            if ( v60 )
                              NetStatisticsGet = (DWORD (__stdcall *)(LPTSTR, LPTSTR, DWORD, DWORD, LPBYTE *))GetTickCount();
                            entropy = __PAIR64__(&v39, (unsigned int)v21);
                            if ( ((int (*)(void))Thread32First)() )
                            {
                              v29 = NetStatisticsGet;
                              do
                              {
                                v30 = alloca(8);
                                RAND_add((int)LibraryA, &v39, v39.dwSize, 6.0);
                              }
                              while ( Thread32Next(buf, &v39) && (!v60 || GetTickCount() - (unsigned int)v29 < 0x3E8) );
                              v21 = buf;
                            }
                            v69.dwSize = 548;
                            if ( v60 )
                              NetStatisticsGet = (DWORD (__stdcall *)(LPTSTR, LPTSTR, DWORD, DWORD, LPBYTE *))GetTickCount();
                            v36 = __PAIR64__(&v69, (unsigned int)v21);
                            if ( ((int (*)(void))Module32First)() )
                            {
                              v31 = v54;
                              do
                              {
                                v32 = alloca(8);
                                RAND_add((int)LibraryA, &v69, v69.dwSize, 9.0);
                              }
                              while ( v31(v21, &v69)
                                   && (!v60 || GetTickCount() - (unsigned int)NetStatisticsGet < 0x3E8) );
                            }
                            if ( CloseToolhelp32Snapshot )
                              ((void (__stdcall *)(void *))CloseToolhelp32Snapshot)(v21);
                            else
                              CloseHandle(v21);
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    FreeLibrary(LibraryA);
  }
  readtimer((int)LibraryA);
  GlobalMemoryStatus(&Buffer);
  v33 = alloca(8);
  RAND_add((int)LibraryA, &Buffer, 32, 1.0);
  CurrentProcessId = GetCurrentProcessId();
  v34 = alloca(8);
  RAND_add((int)LibraryA, &CurrentProcessId, 4, 1.0);
  return 1;
}
