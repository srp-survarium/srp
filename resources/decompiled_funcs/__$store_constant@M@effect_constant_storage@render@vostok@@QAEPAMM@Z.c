float *__userpurge vostok::render::effect_constant_storage::store_constant<float>@<eax>(
        vostok::render::effect_constant_storage *this@<ecx>,
        stlp_std::priv::_Impl_vector<vostok::render::data_indexer,vostok::render::std_allocator<vostok::render::data_indexer> > *a2@<eax>,
        float value)
{
  vostok::render::data_indexer *M_finish; // ebx
  vostok::render::data_indexer *M_start; // edx
  int v6; // eax
  int v7; // ecx
  vostok::render::data_indexer *v8; // esi
  float *p_value; // eax
  int v10; // ecx
  vostok::render::data_indexer *v12; // eax
  vostok::render::data_indexer **v13; // eax
  vostok::render::data_indexer *v14; // eax
  unsigned int class_id; // ecx
  float v16; // xmm0_4
  int v17; // ebx
  vostok::render::data_indexer *v18; // esi
  vostok::render::data_indexer *v19; // edx
  int v20; // eax
  int v21; // ecx
  unsigned int v22; // eax
  unsigned int v23; // [esp+0h] [ebp-18h]
  bool v24; // [esp+4h] [ebp-14h]
  __int64 to_insert; // [esp+10h] [ebp-8h] BYREF

  M_finish = a2->_M_finish;
  M_start = a2->_M_start;
  v6 = M_finish - a2->_M_start;
  while ( v6 > 0 )
  {
    v7 = v6 >> 1;
    if ( M_start[v6 >> 1].class_id >= 4 )
    {
      v6 >>= 1;
    }
    else
    {
      M_start += v7 + 1;
      v6 += -1 - v7;
    }
  }
  v8 = M_start;
  if ( M_start != M_finish )
  {
    do
    {
      p_value = &value;
      v10 = 0;
      while ( *(_DWORD *)((char *)p_value + (char *)v8->data_ptr - (char *)&value) == *(_DWORD *)p_value )
      {
        ++v10;
        ++p_value;
        if ( v10 )
          return (float *)v8->data_ptr;
      }
      ++v8;
    }
    while ( v8 != a2->_M_finish );
  }
  if ( !a2[1]._M_start )
  {
    v12 = (vostok::render::data_indexer *)vostok::memory::doug_lea_allocator::malloc_impl(
                                            (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                            0x408u);
    if ( v12 )
    {
      v12->data_ptr = 0;
      v12[128].class_id = 0;
    }
    else
    {
      v12 = 0;
    }
    a2[1]._M_start = v12;
  }
  if ( a2[1]._M_start[128].class_id + 4 > 0x400 )
  {
    v13 = (vostok::render::data_indexer **)vostok::memory::doug_lea_allocator::malloc_impl(
                                             (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                             0x408u);
    if ( v13 )
    {
      *v13 = 0;
      v13[257] = 0;
    }
    else
    {
      v13 = 0;
    }
    *v13 = a2[1]._M_start;
    a2[1]._M_start = (vostok::render::data_indexer *)v13;
  }
  v14 = a2[1]._M_start;
  class_id = v14[128].class_id;
  v16 = value;
  v17 = (int)&v14->class_id + class_id;
  v14[128].class_id = class_id + 4;
  *(float *)v17 = v16;
  v18 = a2->_M_finish;
  v19 = a2->_M_start;
  v20 = v18 - a2->_M_start;
  to_insert = (unsigned int)v17 | 0x400000000LL;
  while ( v20 > 0 )
  {
    v21 = v20 >> 1;
    if ( v19[v20 >> 1].class_id >= 4 )
    {
      v20 >>= 1;
    }
    else
    {
      v20 += -1 - v21;
      v19 += v21 + 1;
    }
  }
  if ( v19 == v18 )
  {
    if ( v18 == a2->_M_end_of_storage._M_data )
    {
      stlp_std::priv::_Impl_vector<vostok::render::data_indexer,vostok::render::std_allocator<vostok::render::data_indexer>>::_M_insert_overflow(
        (stlp_std::priv::_Impl_vector<vostok::render::data_indexer,vostok::render::std_allocator<vostok::render::data_indexer> > *)&to_insert,
        (int)a2,
        v18,
        (const vostok::render::data_indexer *)&to_insert,
        (const stlp_std::__true_type *)1,
        v23,
        v24);
      return (float *)v17;
    }
    else
    {
      if ( v18 )
      {
        v22 = HIDWORD(to_insert);
        v18->data_ptr = (unsigned int *)to_insert;
        v18->class_id = v22;
      }
      ++a2->_M_finish;
      return (float *)v17;
    }
  }
  else
  {
    if ( a2->_M_end_of_storage._M_data - v18 )
      stlp_std::priv::_Impl_vector<vostok::render::data_indexer,vostok::render::std_allocator<vostok::render::data_indexer>>::_M_fill_insert_aux(
        a2,
        v19,
        1u,
        (const vostok::render::data_indexer *)&to_insert,
        (const stlp_std::__false_type *)&value);
    else
      stlp_std::priv::_Impl_vector<vostok::render::data_indexer,vostok::render::std_allocator<vostok::render::data_indexer>>::_M_insert_overflow(
        (stlp_std::priv::_Impl_vector<vostok::render::data_indexer,vostok::render::std_allocator<vostok::render::data_indexer> > *)&to_insert,
        (int)a2,
        v19,
        (const vostok::render::data_indexer *)&to_insert,
        0,
        v23,
        v24);
    return (float *)v17;
  }
}
