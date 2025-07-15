BOOL __cdecl sub_655280(int a1, char *a2, char *a3, _BYTE *a4)
{
  while ( *a4 )
  {
    if ( a2 == a3 )
      return 0;
    if ( a2[1] || *a2 != (char)*a4 )
      return 0;
    a2 += 2;
    ++a4;
  }
  return a2 == a3;
}
