BOOL __cdecl sub_65AD70(int a1, _BYTE *a2, _BYTE *a3, _BYTE *a4)
{
  while ( *a4 )
  {
    if ( a2 == a3 )
      return 0;
    if ( *a2 || a2[1] != *a4 )
      return 0;
    a2 += 2;
    ++a4;
  }
  return a2 == a3;
}
