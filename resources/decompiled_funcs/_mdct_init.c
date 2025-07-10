void __cdecl mdct_init(mdct_lookup *lookup, int n)
{
  vostok::memory::doug_lea_mt_allocator *v2; // ecx
  int v3; // ebx
  int v4; // ebp
  int *v5; // esi
  float *v6; // edi
  int v7; // eax
  double v8; // st7
  int v9; // esi
  float *v10; // ebx
  int v11; // ebp
  float *v12; // edi
  int v13; // esi
  int v14; // esi
  int i; // edx
  int v16; // edi
  char v17; // cl
  int v18; // eax
  vostok::memory *v19; // [esp+8h] [ebp-44h]
  float v20; // [esp+18h] [ebp-34h]
  int v21; // [esp+1Ch] [ebp-30h]
  int v22; // [esp+20h] [ebp-2Ch]
  char v23; // [esp+24h] [ebp-28h]
  long double n2; // [esp+28h] [ebp-24h]
  long double n2a; // [esp+28h] [ebp-24h]
  int *bitrev; // [esp+34h] [ebp-18h]
  long double v27; // [esp+40h] [ebp-Ch]
  int na; // [esp+54h] [ebp+8h]

  if ( !vostok::memory::g_crt_allocator.__vftable )
    vostok::memory::initialize_crt_allocator(v19);
  v3 = n;
  v4 = n / 4;
  v5 = (int *)vostok::memory::doug_lea_mt_allocator::malloc_impl(v2, 4 * (n / 4));
  bitrev = v5;
  if ( !vostok::memory::g_crt_allocator.__vftable )
    vostok::memory::initialize_crt_allocator(v19);
  v6 = (float *)vostok::memory::doug_lea_mt_allocator::malloc_impl(
                  (vostok::memory::doug_lea_mt_allocator *)(4 * (n + v4)),
                  4 * (n + v4));
  v20 = (float)n;
  v7 = (int)floor(log(v20) / log(2.0) + 0.5);
  v8 = 3.141592741012573;
  lookup->bitrev = v5;
  v9 = 0;
  v23 = v7;
  lookup->log2n = v7;
  lookup->n = n;
  lookup->trig = v6;
  if ( v4 > 0 )
  {
    v21 = 0;
    v10 = &v6[n >> 1];
    v22 = 1;
    do
    {
      n2 = (double)v21 * (3.141592741012573 / v20);
      v6[2 * v9] = cos(n2);
      v6[2 * v9 + 1] = -sin(n2);
      n2a = (double)v22 * (3.141592741012573 / (double)(2 * n));
      *v10 = cos(n2a);
      v10[1] = sin(n2a);
      v21 += 4;
      v22 += 2;
      ++v9;
      v10 += 2;
    }
    while ( v9 < v4 );
    v8 = 3.141592741012573;
    v3 = n;
  }
  v11 = v3 / 8;
  if ( v3 / 8 > 0 )
  {
    na = 2;
    v12 = &v6[v3];
    v13 = v3 / 8;
    do
    {
      v27 = (double)na * (v8 / v20);
      *v12 = cos(v27) * 0.5;
      na += 4;
      v12 += 2;
      --v13;
      *(v12 - 1) = sin(v27) * -0.5;
    }
    while ( v13 );
  }
  v14 = 1 << (v7 - 2);
  for ( i = 0; i < v11; ++i )
  {
    v16 = 0;
    v17 = 0;
    if ( v14 )
    {
      v18 = 1 << (v23 - 2);
      do
      {
        if ( (v18 & i) != 0 )
          v16 |= 1 << v17;
        v18 = v14 >> ++v17;
      }
      while ( v14 >> v17 );
    }
    bitrev[2 * i] = (((1 << (v23 - 1)) - 1) & ~v16) - 1;
    bitrev[2 * i + 1] = v16;
  }
  lookup->scale = 4.0 / v20;
}
