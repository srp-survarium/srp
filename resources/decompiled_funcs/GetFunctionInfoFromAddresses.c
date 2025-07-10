int __usercall GetFunctionInfoFromAddresses@<eax>(
        unsigned int a1@<ebx>,
        unsigned __int64 fnAddress,
        unsigned __int64 stackAddress,
        char *lpszSymbol,
        unsigned int lpszSymbolSize)
{
  survarium::game_camera *v5; // ecx
  HANDLE CurrentProcess; // eax
  int v8; // [esp+8h] [ebp-401Ch]
  char szIn[2]; // [esp+Ch] [ebp-4018h] BYREF
  unsigned __int8 v10[8190]; // [esp+Eh] [ebp-4016h] BYREF
  unsigned __int64 v11; // [esp+200Ch] [ebp-2018h] BYREF
  HGLOBAL hMem; // [esp+2018h] [ebp-200Ch]
  char *_Src; // [esp+201Ch] [ebp-2008h]
  SIZE_T dwBytes; // [esp+2020h] [ebp-2004h]
  char szOut[2]; // [esp+2024h] [ebp-2000h] BYREF
  unsigned __int8 dst[8190]; // [esp+2026h] [ebp-1FFEh] BYREF

  v8 = 0;
  v11 = 0;
  dwBytes = 10000;
  strcpy(szOut, "?");
  memset((int)dst, 0, sizeof(dst));
  strcpy(szIn, "?");
  memset((int)v10, 0, sizeof(v10));
  _Src = szOut;
  hMem = GlobalAlloc(0, 0x2710u);
  survarium::weapon_user_dead_state::finalize(v5);
  memset((int)hMem, 0, dwBytes);
  *(_DWORD *)hMem = dwBytes;
  *((_DWORD *)hMem + 6) = dwBytes - 24;
  strcpy_s(lpszSymbol, lpszSymbolSize, "?");
  CurrentProcess = GetCurrentProcess();
  if ( s_SymGetSymFromAddr64(CurrentProcess, fnAddress, &v11, (_IMAGEHLP_SYMBOL64 *)hMem) )
  {
    s_UnDecorateSymbolName((const char *)hMem + 28, szIn, 0x2000u, 0x42E2u);
    PCSTR2LPTSTR(a1, szIn, szOut, 0x2000u);
    *lpszSymbol = 0;
    strcat_s(lpszSymbol, lpszSymbolSize, _Src);
    v8 = 1;
  }
  GlobalFree(hMem);
  return v8;
}
