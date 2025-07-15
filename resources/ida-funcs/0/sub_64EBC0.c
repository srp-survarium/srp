BOOL __cdecl sub_64EBC0(int a1, char *a2, char *a3, _BYTE *a4)
{
  while ( *a4 )
  {
    if ( a2 == a3 )
      return 0;
    if ( *a2 != (char)*a4 )
      return 0;
    ++a2;
    ++a4;
  }
  return a2 == a3;
}
