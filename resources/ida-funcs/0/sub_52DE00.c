int __cdecl sub_52DE00(_DWORD *a1, int a2, int a3, int a4)
{
  if ( !sub_52DC70(a1, a2, a3, a4) )
    return 0;
  if ( a1[3] == a1[2] && !(unsigned __int8)sub_52DE70(a1) )
    return 0;
  *(_BYTE *)a1[3]++ = 0;
  return a1[4];
}
