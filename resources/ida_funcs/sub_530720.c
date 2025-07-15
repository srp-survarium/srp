int __cdecl sub_530720(int a1, char *a2, int a3, _DWORD *a4)
{
  int i; // [esp+0h] [ebp-4h]

  if ( a3 - (int)a2 < 6 )
    return -1;
  for ( i = 0; i < 6; ++i )
  {
    if ( *a2 != byte_88AA00[i] )
    {
      *a4 = a2;
      return 0;
    }
    ++a2;
  }
  *a4 = a2;
  return 8;
}
