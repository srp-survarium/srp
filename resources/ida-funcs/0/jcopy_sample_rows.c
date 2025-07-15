void __cdecl jcopy_sample_rows(int a1, int a2, int a3, int a4, int a5, unsigned int count)
{
  int v6; // ebx
  const __m128i **v7; // esi
  int *i; // edi
  int v9; // [esp-10h] [ebp-1Ch]
  const __m128i *v10; // [esp-Ch] [ebp-18h]

  v6 = a5;
  v7 = (const __m128i **)(a1 + 4 * a2);
  for ( i = (int *)(a3 + 4 * a4); v6 > 0; --v6 )
  {
    v10 = *v7;
    v9 = *i;
    ++v7;
    ++i;
    memcpy(v9, v10, count);
  }
}
