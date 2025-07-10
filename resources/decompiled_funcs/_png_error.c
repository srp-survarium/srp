void __cdecl __noreturn png_error(int a1, int a2)
{
  if ( a1 )
  {
    if ( *(_DWORD *)(a1 + 68) )
      (*(void (__cdecl **)(int, int))(a1 + 68))(a1, a2);
  }
  sub_355DF0(a1, a2);
}
