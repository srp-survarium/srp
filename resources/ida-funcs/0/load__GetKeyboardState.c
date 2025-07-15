int __fastcall load__GetKeyboardState(int a1, int a2, int a3)
{
  return _tailMerge_USER32_dll((int (__stdcall **)())&GetKeyboardState, a2, a1);
}
