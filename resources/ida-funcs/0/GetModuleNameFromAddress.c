int __usercall GetModuleNameFromAddress@<eax>(int a1@<ebx>, unsigned __int64 address, char *lpszModule)
{
  int v3; // edi
  HANDLE CurrentProcess; // eax
  _IMAGEHLP_MODULE64 dst; // [esp+8h] [ebp-68Ch] BYREF

  v3 = 0;
  memset((int)&dst, 0, sizeof(dst));
  dst.SizeOfStruct = 1672;
  CurrentProcess = GetCurrentProcess();
  if ( s_SymGetModuleInfo64(CurrentProcess, (unsigned int)address, &dst) )
  {
    PCSTR2LPTSTR(a1, dst.ModuleName, lpszModule, 0x100u);
    return 1;
  }
  else
  {
    strcpy_s(lpszModule, 0x100u, "?");
  }
  return v3;
}
