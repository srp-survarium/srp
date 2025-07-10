int __fastcall load__timeGetTime(int a1, int a2)
{
  return _tailMerge_WINMM_dll((int (__stdcall **)())&timeGetTime, a2, a1);
}
