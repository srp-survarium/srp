float *__usercall _book_unquantize@<eax>(const static_codebook *b@<esi>, int n, int *sparsemap)
{
  int maptype; // eax
  int q_min; // ecx
  long double x; // st7
  long double v7; // st7
  int q_delta; // ecx
  long double v9; // st7
  vostok::memory::doug_lea_mt_allocator *v10; // ecx
  int v11; // edi
  unsigned int v12; // edi
  float *v13; // ebp
  int v14; // edx
  int v15; // eax
  int k; // ecx
  int v17; // eax
  double v18; // st7
  double v19; // st6
  int dim; // ecx
  int v21; // edi
  int i; // ebx
  vostok::memory *v23; // [esp+Ch] [ebp-24h]
  int count; // [esp+1Ch] [ebp-14h]
  int j; // [esp+20h] [ebp-10h]
  int ja; // [esp+20h] [ebp-10h]
  float val; // [esp+24h] [ebp-Ch]
  float vala; // [esp+24h] [ebp-Ch]
  float last; // [esp+28h] [ebp-8h]
  float lasta; // [esp+28h] [ebp-8h]
  float quantvals; // [esp+2Ch] [ebp-4h]
  int quantvalsa; // [esp+2Ch] [ebp-4h]

  maptype = b->maptype;
  count = 0;
  if ( maptype != 1 && maptype != 2 )
    return 0;
  q_min = b->q_min;
  x = (double)(int)(((unsigned int)&loc_1FFFFE + 1) & q_min);
  if ( q_min < 0 )
    x = -x;
  v7 = ldexp(x, ((q_min >> 21) & 0x3FFu) - 788);
  q_delta = b->q_delta;
  val = v7;
  v9 = (double)(int)(((unsigned int)&loc_1FFFFE + 1) & q_delta);
  if ( q_delta < 0 )
    v9 = -v9;
  last = ldexp(v9, ((q_delta >> 21) & 0x3FFu) - 788);
  v11 = n * b->dim;
  if ( !vostok::memory::g_crt_allocator.__vftable )
    vostok::memory::initialize_crt_allocator(v23);
  v12 = 4 * v11;
  v13 = (float *)vostok::memory::doug_lea_mt_allocator::malloc_impl(v10, v12);
  memset((int)v13, 0, v12);
  if ( b->maptype == 1 )
  {
    quantvalsa = _book_maptype1_quantvals(b);
    v17 = 0;
    ja = 0;
    if ( b->entries > 0 )
    {
      v18 = val;
      v19 = last;
      do
      {
        if ( !sparsemap || b->lengthlist[v17] )
        {
          dim = b->dim;
          lasta = 0.0;
          v21 = 0;
          for ( i = 1; v21 < b->dim; ++v21 )
          {
            vala = fabs((double)b->quantlist[v17 / i % quantvalsa]) * v19 + v18 + lasta;
            if ( b->q_sequencep )
              lasta = vala;
            if ( sparsemap )
              v13[v21 + dim * sparsemap[count]] = vala;
            else
              v13[v21 + count * dim] = vala;
            dim = b->dim;
            i *= quantvalsa;
            v17 = ja;
          }
          ++count;
        }
        ja = ++v17;
      }
      while ( v17 < b->entries );
    }
    return v13;
  }
  if ( b->maptype != 2 )
    return v13;
  v14 = 0;
  if ( b->entries <= 0 )
    return v13;
  do
  {
    if ( !sparsemap || b->lengthlist[v14] )
    {
      v15 = b->dim;
      *(float *)&j = 0.0;
      for ( k = 0; k < b->dim; ++k )
      {
        quantvals = fabs((double)b->quantlist[k + v14 * v15]) * last + val + *(float *)&j;
        if ( b->q_sequencep )
          *(float *)&j = quantvals;
        if ( sparsemap )
          v13[k + v15 * sparsemap[count]] = quantvals;
        else
          v13[k + count * v15] = quantvals;
        v15 = b->dim;
      }
      ++count;
    }
    ++v14;
  }
  while ( v14 < b->entries );
  return v13;
}
