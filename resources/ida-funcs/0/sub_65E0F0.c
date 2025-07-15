int __cdecl sub_65E0F0(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  if ( a2 == 15 )
    return 0;
  if ( a2 != 18 )
    return sub_65E280(a1, a2);
  if ( (*(int (__cdecl **)(int, int, int, const char *))(a5 + 28))(a5, a3, a4, "INCLUDE") )
  {
    *a1 = sub_65E180;
    return 0;
  }
  if ( !(*(int (__cdecl **)(int, int, int, const char *))(a5 + 28))(a5, a3, a4, "IGNORE") )
    return sub_65E280(a1, a2);
  *a1 = sub_65E1D0;
  return 0;
}
