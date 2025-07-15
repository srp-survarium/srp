bool __userpurge vostok::render::hw_buffer_pool_chunk::gather_free_ranges@<al>(
        vostok::render::hw_buffer_pool_chunk *this@<ecx>,
        vostok::render::hw_buffer_pool_range **a2@<eax>,
        vostok::render::hw_buffer_pool_range *out_array)
{
  vostok::render::hw_buffer_pool_range *owner; // ecx
  vostok::render::hw_buffer_pool_range *v5; // ebx
  vostok::render::hw_buffer_pool_range *v6; // eax
  int v8; // eax
  int v9; // edx
  vostok::render::hw_buffer_pool_range *v10; // ebx
  vostok::render::hw_buffer_pool_range *v11; // edi
  vostok::render::hw_buffer_pool_range *v12; // edi
  int v13; // eax
  vostok::buffer_vector<vostok::render::hw_buffer_pool_range> *v14; // ecx
  vostok::render::hw_buffer_pool_range *begin_offset; // ebx
  vostok::render::hw_buffer_pool_range *v16; // esi
  int v17; // eax
  int v18; // ecx
  vostok::render::hw_buffer_pool_range v19; // [esp-4h] [ebp-28h]
  vostok::render::hw_buffer_pool_range **v20; // [esp+10h] [ebp-14h] BYREF
  int v21; // [esp+14h] [ebp-10h]
  vostok::buffer_vector<vostok::render::hw_buffer_pool_range> *v22; // [esp+18h] [ebp-Ch]
  vostok::render::hw_buffer_pool_range *__last; // [esp+1Ch] [ebp-8h]
  vostok::render::allocation_sort_predicate __comp[4]; // [esp+20h] [ebp-4h] BYREF

  owner = a2[1];
  v5 = *a2;
  v20 = a2;
  __last = owner;
  if ( v5 == owner )
  {
    v6 = a2[200];
    v21 = 0;
    v22 = (vostok::buffer_vector<vostok::render::hw_buffer_pool_range> *)((char *)&v6[-1].end_offset + 3);
    vostok::buffer_vector<vostok::render::hw_buffer_pool_range>::push_back(
      (vostok::buffer_vector<vostok::render::hw_buffer_pool_range> *)owner,
      out_array,
      &v20);
    return 1;
  }
  else
  {
    if ( (unsigned int)(owner - v5) > 1 )
    {
      __comp[0] = 0;
      if ( v5 != owner )
      {
        v8 = owner - v5;
        v9 = 0;
        while ( v8 != 1 )
        {
          ++v9;
          v8 >>= 1;
        }
        stlp_std::priv::__introsort_loop<vostok::render::hw_buffer_pool_range *,vostok::render::hw_buffer_pool_range,int,vostok::render::allocation_sort_predicate>(
          (vostok::render::allocation_sort_predicate)12,
          v5,
          owner,
          0,
          2 * v9,
          *(vostok::render::hw_buffer_pool_range **)__comp);
        v19.owner = *(vostok::render::hw_buffer_pool_chunk **)__comp;
        stlp_std::priv::__final_insertion_sort<vostok::render::hw_buffer_pool_range *,vostok::render::allocation_sort_predicate>(
          __last,
          v19);
        owner = (vostok::render::hw_buffer_pool_range *)v19.owner;
      }
    }
    v10 = *a2;
    v11 = a2[1];
    v21 = 0;
    v12 = v11 - 1;
    v22 = (vostok::buffer_vector<vostok::render::hw_buffer_pool_range> *)(v10->begin_offset - 1);
    if ( (int)v22 > 0 )
      vostok::buffer_vector<vostok::render::hw_buffer_pool_range>::push_back(
        (vostok::buffer_vector<vostok::render::hw_buffer_pool_range> *)owner,
        out_array,
        &v20);
    v13 = v12->end_offset + 1;
    v22 = (vostok::buffer_vector<vostok::render::hw_buffer_pool_range> *)((char *)&a2[200][-1].end_offset + 3);
    v21 = v13;
    if ( v13 < (int)v22 )
      vostok::buffer_vector<vostok::render::hw_buffer_pool_range>::push_back(
        (vostok::buffer_vector<vostok::render::hw_buffer_pool_range> *)owner,
        out_array,
        &v20);
    while ( v10 != v12 )
    {
      v14 = (vostok::buffer_vector<vostok::render::hw_buffer_pool_range> *)(v10[1].begin_offset - 1);
      v21 = v10->end_offset + 1;
      v22 = v14;
      if ( v21 < (int)v14 )
        vostok::buffer_vector<vostok::render::hw_buffer_pool_range>::push_back(v14, out_array, &v20);
      ++v10;
    }
    begin_offset = (vostok::render::hw_buffer_pool_range *)out_array->begin_offset;
    v16 = (vostok::render::hw_buffer_pool_range *)out_array->owner;
    if ( (unsigned int)(((char *)begin_offset - (char *)out_array->owner) / 12) > 1 )
    {
      __comp[0] = 0;
      if ( v16 != begin_offset )
      {
        v17 = begin_offset - v16;
        v18 = 0;
        while ( v17 != 1 )
        {
          ++v18;
          v17 >>= 1;
        }
        stlp_std::priv::__introsort_loop<vostok::render::hw_buffer_pool_range *,vostok::render::hw_buffer_pool_range,int,vostok::render::ranges_sort_predicate>(
          (vostok::render::ranges_sort_predicate)&__comp[1],
          v16,
          begin_offset,
          0,
          2 * v18,
          *(vostok::render::hw_buffer_pool_range **)__comp);
        v19.owner = *(vostok::render::hw_buffer_pool_chunk **)__comp;
        stlp_std::priv::__final_insertion_sort<vostok::render::hw_buffer_pool_range *,vostok::render::ranges_sort_predicate>(
          begin_offset,
          v19);
      }
    }
    return out_array->owner != (vostok::render::hw_buffer_pool_chunk *)out_array->begin_offset;
  }
}
