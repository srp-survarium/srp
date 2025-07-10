int __fastcall load__WSAStartup(int a1, int a2, int a3, int a4)
{
  return _tailMerge_WS2_32_dll((int (__stdcall **)())&WSAStartup, a2, a1);
}
