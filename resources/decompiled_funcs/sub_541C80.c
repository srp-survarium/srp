int __cdecl sub_541C80(int (__cdecl **a1)(int, int, int, int, int), int a2, int a3, int a4, int a5)
{
  int (__cdecl *v6)(int, int, int, int, int); // [esp+0h] [ebp-8h]

  if ( a2 == 15 )
    return 11;
  if ( a2 == 17 )
  {
    if ( a1[4] )
      v6 = (int (__cdecl *)(int, int, int, int, int))sub_541870;
    else
      v6 = sub_541D20;
    *a1 = v6;
    return 15;
  }
  else if ( a2 == 18 && (*(int (__cdecl **)(int, int, int, const char *))(a5 + 28))(a5, a3, a4, "NDATA") )
  {
    *a1 = (int (__cdecl *)(int, int, int, int, int))sub_541E00;
    return 11;
  }
  else
  {
    return sub_542EE0(a1, a2);
  }
}
