char __userpurge vostok::render::hw_buffer_pool::allocate@<al>(
        vostok::render::hw_buffer_pool *this@<ecx>,
        int a2@<esi>,
        vostok::render::hw_buffer_pool_range *out_range,
        unsigned __int8 *initial_data,
        unsigned int num_bytes,
        unsigned int stride)
{
  vostok::render::hw_buffer_pool_chunk **v6; // ebx
  vostok::render::hw_buffer_pool_chunk **v7; // ecx
  vostok::render::hw_buffer_pool_chunk **v8; // ebx
  int v9; // eax
  int v10; // edi
  int j; // edx
  vostok::render::hw_buffer_pool_chunk **k; // ebx
  vostok::render::hw_buffer_pool_chunk **m; // ebx
  vostok::render::hw_buffer_pool_chunk **v15; // [esp-4h] [ebp-2Ch]
  vostok::render::hw_buffer_pool_range v16; // [esp+Ch] [ebp-1Ch] BYREF
  vostok::render::chunks_sort_predicate __comp[4]; // [esp+18h] [ebp-10h] BYREF
  vostok::render::hw_buffer_pool_chunk **i; // [esp+1Ch] [ebp-Ch]
  vostok::render::hw_buffer_pool_chunk **__last; // [esp+20h] [ebp-8h]
  vostok::render::hw_buffer_pool_chunk *v20; // [esp+24h] [ebp-4h] BYREF

  v6 = *(vostok::render::hw_buffer_pool_chunk ***)a2;
  for ( i = *(vostok::render::hw_buffer_pool_chunk ***)(a2 + 4); v6 != i; ++v6 )
  {
    memset(&v16, 0, sizeof(v16));
    vostok::render::hw_buffer_pool_chunk::allocate_range(
      *v6,
      &v16,
      (vostok::render::hw_buffer_pool_chunk *)this,
      0,
      num_bytes,
      stride,
      0,
      0);
  }
  v7 = *(vostok::render::hw_buffer_pool_chunk ***)(a2 + 4);
  v8 = *(vostok::render::hw_buffer_pool_chunk ***)a2;
  v9 = 0;
  __comp[0] = 0;
  __last = v7;
  if ( v8 != v7 )
  {
    v10 = v7 - v8;
    for ( j = v10; j != 1; j >>= 1 )
      ++v9;
    stlp_std::priv::__introsort_loop<vostok::render::hw_buffer_pool_chunk * *,vostok::render::hw_buffer_pool_chunk *,int,vostok::render::chunks_sort_predicate>(
      (vostok::render::chunks_sort_predicate)v10,
      v8,
      v7,
      0,
      2 * v9,
      *(vostok::render::hw_buffer_pool_chunk ***)__comp);
    if ( v10 <= 16 )
    {
      LOBYTE(v20) = __comp[0];
      stlp_std::priv::__insertion_sort<vostok::render::hw_buffer_pool_chunk * *,vostok::render::hw_buffer_pool_chunk *,vostok::render::chunks_sort_predicate>(
        v8,
        __last,
        &v20);
    }
    else
    {
      stlp_std::priv::__insertion_sort<vostok::render::hw_buffer_pool_chunk * *,vostok::render::hw_buffer_pool_chunk *,vostok::render::chunks_sort_predicate>(
        v8,
        v8 + 16,
        (vostok::render::hw_buffer_pool_chunk **)__comp);
      for ( k = v8 + 16; k != __last; ++k )
      {
        v15 = *(vostok::render::hw_buffer_pool_chunk ***)__comp;
        stlp_std::priv::__unguarded_linear_insert<vostok::render::hw_buffer_pool_chunk * *,vostok::render::hw_buffer_pool_chunk *,vostok::render::chunks_sort_predicate>(
          k,
          *k);
        v7 = v15;
      }
    }
  }
  for ( m = *(vostok::render::hw_buffer_pool_chunk ***)a2; ; ++m )
  {
    if ( m == i )
      return 0;
    if ( vostok::render::hw_buffer_pool_chunk::allocate_range(
           *m,
           out_range,
           (vostok::render::hw_buffer_pool_chunk *)v7,
           initial_data,
           num_bytes,
           stride,
           *(ID3D11Buffer **)(a2 + 4216),
           1) )
    {
      break;
    }
  }
  return 1;
}
