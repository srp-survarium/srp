void __usercall mdct_butterflies(mdct_lookup *init@<eax>, float *x, int points)
{
  int v3; // esi
  int v4; // ebx
  int v5; // ebx
  int v6; // ecx
  float *v7; // ebx
  unsigned int v8; // edi
  int v9; // esi
  int v10; // ebp
  float *v11; // edi
  unsigned int v12; // esi
  int i; // [esp+Ch] [ebp-Ch]
  int stages; // [esp+10h] [ebp-8h]
  float *T; // [esp+14h] [ebp-4h]

  v3 = points;
  v4 = init->log2n - 6;
  T = init->trig;
  if ( v4 > 0 )
    mdct_butterfly_first(init->trig, x, points);
  v5 = v4 - 1;
  v6 = 1;
  i = 1;
  for ( stages = v5; v5 > 0; stages = v5 )
  {
    if ( 1 << v6 > 0 )
    {
      v7 = x;
      v8 = 4 << v6;
      v9 = v3 >> v6;
      v10 = 1 << v6;
      do
      {
        mdct_butterfly_generic(v9, T, v7, v8);
        v7 += v9;
        --v10;
      }
      while ( v10 );
      v3 = points;
      v5 = stages;
      v6 = i;
    }
    --v5;
    i = ++v6;
  }
  if ( v3 > 0 )
  {
    v11 = x;
    v12 = ((unsigned int)(v3 - 1) >> 5) + 1;
    do
    {
      mdct_butterfly_32(v11);
      v11 += 32;
      --v12;
    }
    while ( v12 );
  }
}
