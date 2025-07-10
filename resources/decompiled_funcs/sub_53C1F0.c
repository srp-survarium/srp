int __cdecl sub_53C1F0(int a1, _BYTE *a2, int a3, _DWORD *a4)
{
  int i; // [esp+0h] [ebp-4h]

  if ( a3 - (int)a2 < 12 )
    return -1;
  for ( i = 0; i < 6; ++i )
  {
    if ( *a2 || (char)a2[1] != byte_88BB50[i] )
    {
      *a4 = a2;
      return 0;
    }
    a2 += 2;
  }
  *a4 = a2;
  return 8;
}
