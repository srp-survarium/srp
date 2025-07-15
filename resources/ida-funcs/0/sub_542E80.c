int __cdecl sub_542E80(_DWORD *a1, int a2)
{
  int (__cdecl *v3)(_DWORD *, int, int, int, int); // [esp+0h] [ebp-8h]

  if ( a2 == 15 )
    return a1[2];
  if ( a2 != 17 )
    return sub_542EE0(a1, a2);
  if ( a1[4] )
    v3 = sub_541870;
  else
    v3 = sub_541D20;
  *a1 = v3;
  return a1[2];
}
