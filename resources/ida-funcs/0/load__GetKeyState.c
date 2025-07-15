int __fastcall load__GetKeyState(int a1, int a2, int a3)
{
  return _tailMerge_USER32_dll((int (__stdcall **)())&GetKeyState, a2, a1);
}
