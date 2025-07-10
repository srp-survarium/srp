int __fastcall load__WSASetLastError(int a1, int a2, int a3)
{
  return _tailMerge_WS2_32_dll((int (__stdcall **)())&WSASetLastError, a2, a1);
}
