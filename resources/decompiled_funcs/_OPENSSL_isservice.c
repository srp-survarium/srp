int __cdecl OPENSSL_isservice()
{
  int (*p)(void); // eax
  HMODULE ModuleHandleA; // eax
  HWINSTA ProcessWindowStation; // ebx
  void *v3; // esp
  wchar_t v5[6]; // [esp+0h] [ebp-14h] BYREF
  unsigned int nLengthNeeded; // [esp+Ch] [ebp-8h] BYREF

  p = (int (*)(void))OPENSSL_isservice_0.p;
  if ( OPENSSL_isservice_0.p
    || ((ModuleHandleA = GetModuleHandleA(0)) == 0
      ? (p = (int (*)(void))OPENSSL_isservice_0.p)
      : (int (*)(void))(p = GetProcAddress(ModuleHandleA, "_OPENSSL_isservice"), OPENSSL_isservice_0.p = p),
        p) )
  {
    if ( p != (int (*)(void))-1 )
      return p();
  }
  else
  {
    OPENSSL_isservice_0.p = (void *)-1;
  }
  GetDesktopWindow();
  ProcessWindowStation = GetProcessWindowStation();
  if ( !ProcessWindowStation )
    return -1;
  if ( GetUserObjectInformationW(ProcessWindowStation, 2, 0, 0, &nLengthNeeded) )
    return -1;
  if ( GetLastError() != 122 )
    return -1;
  if ( nLengthNeeded > 0x200 )
    return -1;
  nLengthNeeded = (nLengthNeeded + 1) & 0xFFFFFFFE;
  v3 = alloca(nLengthNeeded + 2);
  if ( !GetUserObjectInformationW(ProcessWindowStation, 2, v5, nLengthNeeded, &nLengthNeeded) )
    return -1;
  nLengthNeeded = (nLengthNeeded + 1) & 0xFFFFFFFE;
  v5[nLengthNeeded >> 1] = 0;
  return wcsstr(v5, L"Service-0x") != 0;
}
