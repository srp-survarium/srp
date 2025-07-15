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


vostok::math::float2 *__userpurge vostok::render::effect_constant_storage::store_constant<vostok::math::float2>@<eax>(
        vostok::render::effect_constant_storage *this@<ecx>,
        stlp_std::priv::_Impl_vector<vostok::render::data_indexer,vostok::render::std_allocator<vostok::render::data_indexer> > *a2@<eax>,
        vostok::math::float2 value)
{
  vostok::render::data_indexer *M_finish; // ebx
  vostok::render::data_indexer *M_start; // edx
  int v6; // eax
  int v7; // ecx
  vostok::render::data_indexer *v8; // esi
  vostok::math::float2 *p_value; // ecx
  unsigned int v10; // eax
  vostok::render::data_indexer *v12; // eax
  vostok::render::data_indexer **v13; // eax
  vostok::render::data_indexer *v14; // eax
  unsigned int class_id; // edx
  float v16; // xmm0_4
  unsigned int *v17; // ebx
  vostok::render::data_indexer *v18; // esi
  vostok::render::data_indexer *v19; // edx
  int v20; // eax
  int v21; // ecx
  unsigned int v22; // eax
  unsigned int v23; // [esp+0h] [ebp-1Ch]
  bool v24; // [esp+4h] [ebp-18h]
  vostok::render::data_indexer to_insert; // [esp+10h] [ebp-Ch] BYREF

  M_finish = a2->_M_finish;
  M_start = a2->_M_start;
  v6 = M_finish - a2->_M_start;
  while ( v6 > 0 )
  {
    v7 = v6 >> 1;
    if ( M_start[v6 >> 1].class_id >= 8 )
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
      while ( *(_DWORD *)((char *)&p_value->x + (char *)v8->data_ptr - (char *)&value) == LODWORD(p_value->x) )
      {
        ++v10;
        p_value = (vostok::math::float2 *)((char *)p_value + 4);
        if ( v10 >= 2 )
          return (vostok::math::float2 *)v8->data_ptr;
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
  if ( a2[1]._M_start[128].class_id + 8 > 0x400 )
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
  v14[128].class_id = class_id + 8;
  if ( (vostok::render::data_indexer *)((char *)v14 + class_id) == (vostok::render::data_indexer *)-4 )
  {
    v17 = 0;
  }
  else
  {
    v16 = SNaN;
    *(float *)((char *)&v14->class_id + class_id) = SNaN;
    *(float *)((char *)&v14[1].data_ptr + class_id) = v16;
    v17 = (unsigned int *)((char *)&v14->class_id + class_id);
  }
  *(vostok::math::float2 *)v17 = value;
  v18 = a2->_M_finish;
  v19 = a2->_M_start;
  v20 = v18 - a2->_M_start;
  to_insert.data_ptr = v17;
  to_insert.class_id = 8;
  while ( v20 > 0 )
  {
    v21 = v20 >> 1;
    if ( v19[v20 >> 1].class_id >= 8 )
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
        &to_insert,
        (const stlp_std::__true_type *)1,
        v23,
        v24);
      return (vostok::math::float2 *)v17;
    }
    else
    {
      if ( v18 )
      {
        v22 = to_insert.class_id;
        v18->data_ptr = to_insert.data_ptr;
        v18->class_id = v22;
      }
      ++a2->_M_finish;
      return (vostok::math::float2 *)v17;
    }
  }
  else
  {
    if ( a2->_M_end_of_storage._M_data - v18 )
      stlp_std::priv::_Impl_vector<vostok::render::data_indexer,vostok::render::std_allocator<vostok::render::data_indexer>>::_M_fill_insert_aux(
        a2,
        v19,
        1u,
        &to_insert,
        (const stlp_std::__false_type *)&value);
    else
      stlp_std::priv::_Impl_vector<vostok::render::data_indexer,vostok::render::std_allocator<vostok::render::data_indexer>>::_M_insert_overflow(
        (stlp_std::priv::_Impl_vector<vostok::render::data_indexer,vostok::render::std_allocator<vostok::render::data_indexer> > *)&to_insert,
        (int)a2,
        v19,
        &to_insert,
        0,
        v23,
        v24);
    return (vostok::math::float2 *)v17;
  }
}


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


vostok::math::float4 *__userpurge vostok::render::effect_constant_storage::store_constant<vostok::math::float4>@<eax>(
        vostok::render::effect_constant_storage *this@<ecx>,
        stlp_std::priv::_Impl_vector<vostok::render::data_indexer,vostok::render::std_allocator<vostok::render::data_indexer> > *a2@<eax>,
        vostok::math::float4 value)
{
  vostok::render::data_indexer *M_finish; // esi
  vostok::render::data_indexer *M_start; // edx
  int v6; // eax
  int v7; // ecx
  vostok::math::float4 *p_value; // eax
  unsigned int v9; // ecx
  vostok::render::data_indexer *v11; // eax
  vostok::render::data_indexer **v12; // eax
  vostok::render::data_indexer *v13; // eax
  unsigned int class_id; // ecx
  unsigned int *v15; // ebx
  vostok::render::data_indexer *v16; // esi
  vostok::render::data_indexer *v17; // edx
  int v18; // eax
  int v19; // ecx
  unsigned int v20; // eax
  unsigned int v21; // [esp+0h] [ebp-1Ch]
  bool v22; // [esp+4h] [ebp-18h]
  vostok::render::data_indexer to_insert; // [esp+10h] [ebp-Ch] BYREF

  M_finish = a2->_M_finish;
  M_start = a2->_M_start;
  v6 = M_finish - a2->_M_start;
  while ( v6 > 0 )
  {
    v7 = v6 >> 1;
    if ( M_start[v6 >> 1].class_id >= 0x10 )
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
      while ( *(_DWORD *)((char *)&p_value->x + (char *)M_start->data_ptr - (char *)&value) == LODWORD(p_value->x) )
      {
        ++v9;
        p_value = (vostok::math::float4 *)((char *)p_value + 4);
        if ( v9 >= 4 )
          return (vostok::math::float4 *)M_start->data_ptr;
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
  if ( a2[1]._M_start[128].class_id + 16 > 0x400 )
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
  v13[128].class_id = class_id + 16;
  *(vostok::math::float4 *)v15 = value;
  v16 = a2->_M_finish;
  v17 = a2->_M_start;
  v18 = v16 - a2->_M_start;
  to_insert.data_ptr = v15;
  to_insert.class_id = 16;
  while ( v18 > 0 )
  {
    v19 = v18 >> 1;
    if ( v17[v18 >> 1].class_id >= 0x10 )
    {
      v18 >>= 1;
    }
    else
    {
      v18 += -1 - v19;
      v17 += v19 + 1;
    }
  }
  if ( v17 == v16 )
  {
    if ( v16 == a2->_M_end_of_storage._M_data )
    {
      stlp_std::priv::_Impl_vector<vostok::render::data_indexer,vostok::render::std_allocator<vostok::render::data_indexer>>::_M_insert_overflow(
        (stlp_std::priv::_Impl_vector<vostok::render::data_indexer,vostok::render::std_allocator<vostok::render::data_indexer> > *)&to_insert,
        (int)a2,
        v16,
        &to_insert,
        (const stlp_std::__true_type *)1,
        v21,
        v22);
      return (vostok::math::float4 *)v15;
    }
    else
    {
      if ( v16 )
      {
        v20 = to_insert.class_id;
        v16->data_ptr = to_insert.data_ptr;
        v16->class_id = v20;
      }
      ++a2->_M_finish;
      return (vostok::math::float4 *)v15;
    }
  }
  else
  {
    if ( a2->_M_end_of_storage._M_data - v16 )
      stlp_std::priv::_Impl_vector<vostok::render::data_indexer,vostok::render::std_allocator<vostok::render::data_indexer>>::_M_fill_insert_aux(
        a2,
        v17,
        1u,
        &to_insert,
        (const stlp_std::__false_type *)&value);
    else
      stlp_std::priv::_Impl_vector<vostok::render::data_indexer,vostok::render::std_allocator<vostok::render::data_indexer>>::_M_insert_overflow(
        (stlp_std::priv::_Impl_vector<vostok::render::data_indexer,vostok::render::std_allocator<vostok::render::data_indexer> > *)&to_insert,
        (int)a2,
        v17,
        &to_insert,
        0,
        v21,
        v22);
    return (vostok::math::float4 *)v15;
  }
}
