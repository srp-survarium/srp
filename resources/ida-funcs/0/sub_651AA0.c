int __cdecl sub_651AA0(int a1, char *a2, int a3, _DWORD *a4)
{
  int i; // [esp+0h] [ebp-4h]

  if ( a3 - (int)a2 < 12 )
    return -1;
  for ( i = 0; i < 6; ++i )
  {
    if ( a2[1] || *a2 != byte_72F000[i] )
    {
      *a4 = a2;
      return 0;
    }
    a2 += 2;
  }
  *a4 = a2;
  return 8;
}
