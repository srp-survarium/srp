int __cdecl sub_542D60(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  if ( a2 == 15 )
    return 0;
  if ( a2 != 18 )
    return sub_542EE0(a1, a2);
  if ( (*(int (__cdecl **)(int, int, int, const char *))(a5 + 28))(a5, a3, a4, "INCLUDE") )
  {
    *a1 = sub_542DF0;
    return 0;
  }
  if ( !(*(int (__cdecl **)(int, int, int, const char *))(a5 + 28))(a5, a3, a4, "IGNORE") )
    return sub_542EE0(a1, a2);
  *a1 = sub_542E40;
  return 0;
}
