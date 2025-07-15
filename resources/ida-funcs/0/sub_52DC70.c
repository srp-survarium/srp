int __cdecl sub_52DC70(_DWORD *a1, int a2, int a3, int a4)
{
  if ( !a1[3] && !(unsigned __int8)sub_52DE70(a1) )
    return 0;
  while ( 1 )
  {
    (*(void (__cdecl **)(int, int *, int, _DWORD *, _DWORD))(a2 + 60))(a2, &a3, a4, a1 + 3, a1[2]);
    if ( a3 == a4 )
      break;
    if ( !(unsigned __int8)sub_52DE70(a1) )
      return 0;
  }
  return a1[4];
}
