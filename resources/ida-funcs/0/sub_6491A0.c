int __cdecl sub_6491A0(_DWORD *a1, int a2, int a3, int a4)
{
  if ( !sub_649010(a1, a2, a3, a4) )
    return 0;
  if ( a1[3] == a1[2] && !(unsigned __int8)sub_649210(a1) )
    return 0;
  *(_BYTE *)a1[3]++ = 0;
  return a1[4];
}
