vostok::math::float3 *__userpurge vostok::render::effect_constant_storage::store_constant<vostok::math::float3>@<eax>(
        vostok::render::effect_constant_storage *this@<ecx>,
        stlp_std::priv::_Impl_vector<vostok::render::data_indexer,vostok::render::std_allocator<vostok::render::data_indexer> > *a2@<eax>,
        __int128 value)
{
  vostok::render::data_indexer *M_finish; // esi
  vostok::render::data_indexer *M_start; // edx
  int v6; // eax
  int v7; // ecx
  __int128 *p_value; // ecx
  unsigned int v9; // eax
  vostok::render::data_indexer *v11; // eax
  vostok::render::data_indexer **v12; // eax
  vostok::render::data_indexer *v13; // eax
  unsigned int class_id; // ecx
  unsigned int *v15; // ebx
  int v16; // ecx
  vostok::render::data_indexer *v17; // esi
  vostok::render::data_indexer *v18; // edx
  int v19; // eax
  unsigned int v20; // edx
  unsigned int v21; // [esp+0h] [ebp-18h]
  bool v22; // [esp+4h] [ebp-14h]
  vostok::render::data_indexer to_insert; // [esp+10h] [ebp-8h] BYREF

  M_finish = a2->_M_finish;
  M_start = a2->_M_start;
  v6 = M_finish - a2->_M_start;
  while ( v6 > 0 )
  {
    v7 = v6 >> 1;
    if ( M_start[v6 >> 1].class_id >= 0xC )
    {
      v6 >>= 1;
    }
    else
    {
      M_start += v7 + 1;
      v6 += -1 - v7;
    }
  }
  if ( M_start != M_finish )
  {
    do
    {
      p_value = &value;
      v9 = 0;
      while ( *(_DWORD *)((char *)p_value + (char *)M_start->data_ptr - (char *)&value) == *(_DWORD *)p_value )
      {
        ++v9;
        p_value = (__int128 *)((char *)p_value + 4);
        if ( v9 >= 3 )
          return (vostok::math::float3 *)M_start->data_ptr;
      }
      ++M_start;
    }
    while ( M_start != a2->_M_finish );
  }
  if ( !a2[1]._M_start )
  {
    v11 = (vostok::render::data_indexer *)vostok::memory::doug_lea_allocator::malloc_impl(
                                            (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                            0x408u);
    if ( v11 )
    {
      v11->data_ptr = 0;
      v11[128].class_id = 0;
    }
    else
    {
      v11 = 0;
    }
    a2[1]._M_start = v11;
  }
  if ( a2[1]._M_start[128].class_id + 12 > 0x400 )
  {
    v12 = (vostok::render::data_indexer **)vostok::memory::doug_lea_allocator::malloc_impl(
                                             (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                             0x408u);
    if ( v12 )
    {
      *v12 = 0;
      v12[257] = 0;
    }
    else
    {
      v12 = 0;
    }
    *v12 = a2[1]._M_start;
    a2[1]._M_start = (vostok::render::data_indexer *)v12;
  }
  v13 = a2[1]._M_start;
  class_id = v13[128].class_id;
  v15 = (unsigned int *)((char *)&v13->class_id + class_id);
  v16 = class_id + 12;
  v13[128].class_id = v16;
  *(vostok::math::float3 *)v15 = (vostok::math::float3)value;
  v17 = a2->_M_finish;
  v18 = a2->_M_start;
  v19 = v17 - a2->_M_start;
  to_insert.data_ptr = v15;
  to_insert.class_id = 12;
  while ( v19 > 0 )
  {
    v16 = v19 >> 1;
    if ( v18[v19 >> 1].class_id >= 0xC )
    {
      v19 >>= 1;
    }
    else
    {
      v19 += -1 - v16;
      v18 += v16 + 1;
    }
  }
  if ( v18 == v17 )
  {
    if ( v17 == a2->_M_end_of_storage._M_data )
    {
      stlp_std::priv::_Impl_vector<vostok::render::data_indexer,vostok::render::std_allocator<vostok::render::data_indexer>>::_M_insert_overflow(
        (stlp_std::priv::_Impl_vector<vostok::render::data_indexer,vostok::render::std_allocator<vostok::render::data_indexer> > *)v16,
        (int)a2,
        v17,
        &to_insert,
        (const stlp_std::__true_type *)1,
        v21,
        v22);
      return (vostok::math::float3 *)v15;
    }
    else
    {
      if ( v17 )
      {
        v20 = to_insert.class_id;
        v17->data_ptr = to_insert.data_ptr;
        v17->class_id = v20;
      }
      ++a2->_M_finish;
      return (vostok::math::float3 *)v15;
    }
  }
  else
  {
    if ( a2->_M_end_of_storage._M_data - v17 )
      stlp_std::priv::_Impl_vector<vostok::render::data_indexer,vostok::render::std_allocator<vostok::render::data_indexer>>::_M_fill_insert_aux(
        a2,
        v18,
        1u,
        &to_insert,
        (const stlp_std::__false_type *)&value);
    else
      stlp_std::priv::_Impl_vector<vostok::render::data_indexer,vostok::render::std_allocator<vostok::render::data_indexer>>::_M_insert_overflow(
        0,
        (int)a2,
        v18,
        &to_insert,
        0,
        v21,
        v22);
    return (vostok::math::float3 *)v15;
  }
}
