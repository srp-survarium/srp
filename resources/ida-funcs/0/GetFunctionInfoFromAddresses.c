int __cdecl GetFunctionInfoFromAddresses(unsigned __int64 fnAddress, unsigned __int64 stackAddress)
{
  _IMAGEHLP_SYMBOL64 *v2; // edi
  HANDLE CurrentProcess; // eax
  char _Src[2]; // [esp+10h] [ebp-4014h] BYREF
  unsigned __int8 dst[8190]; // [esp+12h] [ebp-4012h] BYREF
  char src[2]; // [esp+2010h] [ebp-2014h] BYREF
  unsigned __int8 v8[8190]; // [esp+2012h] [ebp-2012h] BYREF
  unsigned __int64 v9; // [esp+4010h] [ebp-14h] BYREF
  int v10; // [esp+401Ch] [ebp-8h]

  strcpy(_Src, "?");
  v10 = 0;
  v9 = 0;
  memset((int)dst, 0, sizeof(dst));
  strcpy(src, "?");
  memset((int)v8, 0, sizeof(v8));
  v2 = (_IMAGEHLP_SYMBOL64 *)GlobalAlloc(0, 0x2710u);
  memset((int)v2, 0, 0x2710u);
  v2->SizeOfStruct = 10000;
  v2->MaxNameLength = 9976;
  strcpy_s((char *)stackAddress, 0x2000u, "?");
  CurrentProcess = GetCurrentProcess();
  if ( s_SymGetSymFromAddr64(CurrentProcess, fnAddress, &v9, v2) )
  {
    s_UnDecorateSymbolName(v2->Name, src, 0x2000u, 0x42E2u);
    memcpy_s(0, (unsigned __int8 *)_Src, 0x2000u, (unsigned __int8 *)src, 0x2000u);
    *(_BYTE *)stackAddress = 0;
    strcat_s((char *)stackAddress, 0x2000u, _Src);
    v10 = 1;
  }
  GlobalFree(v2);
  return v10;
}
