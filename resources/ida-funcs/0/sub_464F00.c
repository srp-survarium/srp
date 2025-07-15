unsigned int __cdecl sub_464F00(int a1, int *a2, char a3, int a4)
{
  unsigned int result; // eax
  unsigned int v5; // [esp+4h] [ebp-18h]
  int v6; // [esp+Ch] [ebp-10h]
  unsigned int v7; // [esp+10h] [ebp-Ch]
  unsigned int i; // [esp+14h] [ebp-8h]
  unsigned int j; // [esp+14h] [ebp-8h]
  unsigned int v10; // [esp+18h] [ebp-4h]

  v7 = 1 << (8 - a3);
  *a2 = png_calloc(a1, 4 * v7);
  v6 = *a2;
  for ( i = 0; i < v7; ++i )
    *(_DWORD *)(v6 + 4 * i) = png_malloc(a1, 0x200u);
  v10 = 0;
  for ( j = 0; j < 0xFF; ++j )
  {
    v5 = (((1 << (16 - a3)) - 1)
        * (unsigned int)(unsigned __int16)png_gamma_16bit_correct((unsigned __int16)(257 * j) + 128, a4)
        + 0x8000)
       / 0xFFFF
       + 1;
    while ( v10 < v5 )
    {
      *(_WORD *)(*(_DWORD *)(v6 + 4 * (v10 & (0xFFu >> a3))) + 2 * (v10 >> (8 - a3))) = 257 * j;
      ++v10;
    }
  }
  while ( 1 )
  {
    result = v7 << 8;
    if ( v10 >= v7 << 8 )
      break;
    *(_WORD *)(*(_DWORD *)(v6 + 4 * (v10 & (255 >> a3))) + 2 * (v10 >> (8 - a3))) = -1;
    ++v10;
  }
  return result;
}
