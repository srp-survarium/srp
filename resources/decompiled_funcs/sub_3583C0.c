char __cdecl sub_3583C0(int a1, int *a2, int a3)
{
  int v3; // eax
  int v5; // [esp+0h] [ebp-8h]
  unsigned int i; // [esp+4h] [ebp-4h]
  unsigned int j; // [esp+4h] [ebp-4h]

  *a2 = png_malloc(a1, 0x100u);
  v5 = *a2;
  v3 = png_gamma_significant(a3);
  if ( v3 )
  {
    for ( i = 0; i < 0x100; ++i )
    {
      LOBYTE(v3) = png_gamma_8bit_correct(i, a3);
      *(_BYTE *)(i + v5) = v3;
    }
  }
  else
  {
    for ( j = 0; j < 0x100; ++j )
    {
      *(_BYTE *)(j + v5) = j;
      LOBYTE(v3) = j + 1;
    }
  }
  return v3;
}
