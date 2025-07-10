void __cdecl bn_sqr_normal(unsigned int *r, const unsigned int *a, int n, unsigned int *tmp)
{
  int v4; // eax
  int v6; // esi
  const unsigned int *v7; // edi
  unsigned int *v8; // ebx
  unsigned int v9; // edx
  int v10; // [esp+10h] [ebp-4h]
  int v11; // [esp+18h] [ebp+4h]

  v4 = n;
  v6 = n - 1;
  v7 = a;
  r[2 * n - 1] = 0;
  v10 = 2 * n;
  *r = 0;
  v8 = r + 1;
  if ( n - 1 > 0 )
  {
    v7 = a + 1;
    v8[v6] = bn_mul_words(r + 1, a + 1, v6, *a);
    v4 = n;
    v8 = r + 3;
  }
  if ( v4 - 2 > 0 )
  {
    v11 = n - 2;
    do
    {
      v9 = *v7;
      --v11;
      ++v7;
      --v6;
      v8[v6] = bn_mul_add_words(v8, v7, v6, v9);
      v8 += 2;
    }
    while ( v11 > 0 );
  }
  bn_add_words(r, r, r, v10);
  bn_sqr_words(tmp, a, n);
  bn_add_words(r, r, tmp, v10);
}
