int __cdecl sub_65D3F0(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  if ( a2 == 15 )
    return 17;
  if ( a2 != 18 )
    return sub_65E280(a1, a2);
  if ( (*(int (__cdecl **)(int, int, int, const char *))(a5 + 28))(a5, a3, a4, "SYSTEM") )
  {
    *a1 = sub_65D4E0;
    return 17;
  }
  if ( !(*(int (__cdecl **)(int, int, int, const char *))(a5 + 28))(a5, a3, a4, "PUBLIC") )
    return sub_65E280(a1, a2);
  *a1 = sub_65D490;
  return 17;
}
