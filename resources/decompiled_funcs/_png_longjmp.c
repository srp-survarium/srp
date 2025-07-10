void __cdecl __noreturn png_longjmp(int a1, int a2)
{
  if ( a1 )
  {
    if ( *(_DWORD *)(a1 + 64) )
      (*(void (__cdecl **)(int, int))(a1 + 64))(a1, a2);
  }
  ExitProcess(0);
}
