void __usercall mdct_butterflies(mdct_lookup *init@<eax>, float *x, int points)
{
  int v3; // esi
  int v4; // esi
  float *v5; // edi
  unsigned int v6; // esi
  float *trig; // [esp+8h] [ebp-14h]
  int v8; // [esp+Ch] [ebp-10h]
  float *v9; // [esp+10h] [ebp-Ch]
  char i; // [esp+18h] [ebp-4h]

  v3 = init->log2n - 6;
  trig = init->trig;
  if ( v3 > 0 )
    mdct_butterfly_first(init->trig, x, points);
  v4 = v3 - 1;
  for ( i = 1; v4 > 0; --v4 )
  {
    if ( 1 << i > 0 )
    {
      v9 = x;
      v8 = 1 << i;
      do
      {
        mdct_butterfly_generic(points >> i, trig, v9, 4 << i);
        v9 += points >> i;
        --v8;
      }
      while ( v8 );
    }
    ++i;
  }
  if ( points > 0 )
  {
    v5 = x;
    v6 = ((unsigned int)(points - 1) >> 5) + 1;
    do
    {
      mdct_butterfly_32(v5);
      v5 += 32;
      --v6;
    }
    while ( v6 );
  }
}
