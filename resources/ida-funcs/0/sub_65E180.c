int __cdecl sub_65E180(_DWORD *a1, int a2)
{
  if ( a2 == 15 )
    return 0;
  if ( a2 != 25 )
    return sub_65E280(a1, a2);
  *a1 = sub_65D0B0;
  ++a1[3];
  return 0;
}
