unsigned int *__thiscall vostok::render::effect_constant_storage::store_constant<unsigned int>(
        vostok::render::effect_constant_storage *this,
        vostok::render::data_indexer *value,
        unsigned int b_ptr)
{
  vostok::buffer_vector<vostok::render::data_indexer> *v3; // ebx
  unsigned int *data_ptr; // ecx
  vostok::render::data_indexer *class_id; // eax
  vostok::render::data_indexer *i; // esi
  vostok::render::data_indexer *v7; // eax
  vostok::render::data_indexer **v9; // eax
  vostok::render::data_indexer *m_end; // eax
  unsigned int v11; // edx
  unsigned int *v12; // esi
  vostok::render::data_indexer *v13; // eax
  vostok::render::data_indexer *m_begin; // ecx
  vostok::buffer_vector<vostok::render::data_indexer> *v15; // [esp-4h] [ebp-24h]
  const char *v16; // [esp+0h] [ebp-20h]
  const char *v17; // [esp+4h] [ebp-1Ch]
  unsigned int v18; // [esp+8h] [ebp-18h]
  vostok::render::data_indexer v19; // [esp+Ch] [ebp-14h] BYREF
  vostok::render::data_indexer v20; // [esp+14h] [ebp-Ch] BYREF
  unsigned int *v21; // [esp+1Ch] [ebp-4h]

  v3 = (vostok::buffer_vector<vostok::render::data_indexer> *)value;
  data_ptr = value->data_ptr;
  v19.data_ptr = &b_ptr;
  class_id = (vostok::render::data_indexer *)value->class_id;
  v19.class_id = 4;
  for ( i = stlp_std::lower_bound<vostok::render::data_indexer *,vostok::render::data_indexer,bool (__cdecl *)(vostok::render::data_indexer const &,vostok::render::data_indexer const &)>(
              (vostok::render::data_indexer *)data_ptr,
              class_id,
              &v19); i != v3->m_end; ++i )
  {
    if ( vostok::render::effect_constant_storage::is_equal(
           i->data_ptr,
           &b_ptr,
           (vostok::render::effect_constant_storage *)1,
           (const unsigned int)v16) )
    {
      return i->data_ptr;
    }
  }
  if ( !v3[1366].m_end )
  {
    v7 = (vostok::render::data_indexer *)vostok::memory::new_helper<vostok::render::fixed_constants_data_buffer>::call<vostok::memory::doug_lea_allocator>(
                                           vostok::render::g_allocator,
                                           v16,
                                           v17,
                                           v18);
    if ( v7 )
    {
      v7->data_ptr = 0;
      v7[1024].class_id = 0;
    }
    else
    {
      v7 = 0;
    }
    v3[1366].m_end = v7;
  }
  if ( v3[1366].m_end[1024].class_id + 4 > 0x2000 )
  {
    v9 = (vostok::render::data_indexer **)vostok::memory::new_helper<vostok::render::fixed_constants_data_buffer>::call<vostok::memory::doug_lea_allocator>(
                                            vostok::render::g_allocator,
                                            v16,
                                            v17,
                                            v18);
    if ( v9 )
    {
      *v9 = 0;
      v9[2049] = 0;
    }
    else
    {
      v9 = 0;
    }
    *v9 = v3[1366].m_end;
    v3[1366].m_end = (vostok::render::data_indexer *)v9;
  }
  m_end = v3[1366].m_end;
  v11 = m_end[1024].class_id;
  v12 = (unsigned int *)((char *)&m_end->class_id + v11);
  m_end[1024].class_id = v11 + 4;
  *v12 = b_ptr;
  v13 = v3->m_end;
  m_begin = v3->m_begin;
  v21 = v12;
  v20.data_ptr = v12;
  v20.class_id = 4;
  value = stlp_std::lower_bound<vostok::render::data_indexer *,vostok::render::data_indexer,bool (__cdecl *)(vostok::render::data_indexer const &,vostok::render::data_indexer const &)>(
            m_begin,
            v13,
            &v20);
  if ( value == v3->m_end )
  {
    vostok::buffer_vector<vostok::render::data_indexer>::push_back(v3, &v20);
    return v21;
  }
  else
  {
    vostok::buffer_vector<vostok::render::data_indexer>::insert(
      v15,
      (int)v3,
      &value,
      &v20,
      (const vostok::render::data_indexer *)v16);
  }
  return v12;
}


float *__thiscall vostok::render::effect_constant_storage::store_constant<float>(
        vostok::render::effect_constant_storage *this,
        float value,
        unsigned int b_ptr)
{
  float v3; // ebx
  vostok::render::data_indexer *v4; // ecx
  vostok::render::data_indexer *v5; // eax
  vostok::render::data_indexer *i; // esi
  vostok::render::data_indexer *v7; // eax
  vostok::render::data_indexer **v9; // eax
  vostok::render::data_indexer *v10; // eax
  unsigned int class_id; // edx
  unsigned int *v12; // esi
  vostok::render::data_indexer *v13; // eax
  vostok::render::data_indexer *v14; // ecx
  vostok::buffer_vector<vostok::render::data_indexer> *v15; // [esp-4h] [ebp-24h]
  const char *v16; // [esp+0h] [ebp-20h]
  const char *v17; // [esp+4h] [ebp-1Ch]
  unsigned int v18; // [esp+8h] [ebp-18h]
  vostok::render::data_indexer v19; // [esp+Ch] [ebp-14h] BYREF
  vostok::render::data_indexer v20; // [esp+14h] [ebp-Ch] BYREF
  unsigned int *v21; // [esp+1Ch] [ebp-4h]

  v3 = value;
  v4 = *(vostok::render::data_indexer **)LODWORD(value);
  v19.data_ptr = &b_ptr;
  v5 = *(vostok::render::data_indexer **)(LODWORD(value) + 4);
  v19.class_id = 4;
  for ( i = stlp_std::lower_bound<vostok::render::data_indexer *,vostok::render::data_indexer,bool (__cdecl *)(vostok::render::data_indexer const &,vostok::render::data_indexer const &)>(
              v4,
              v5,
              &v19); i != *(vostok::render::data_indexer **)(LODWORD(v3) + 4); ++i )
  {
    if ( vostok::render::effect_constant_storage::is_equal(
           i->data_ptr,
           &b_ptr,
           (vostok::render::effect_constant_storage *)1,
           (const unsigned int)v16) )
    {
      return (float *)i->data_ptr;
    }
  }
  if ( !*(_DWORD *)(LODWORD(v3) + 16396) )
  {
    v7 = (vostok::render::data_indexer *)vostok::memory::new_helper<vostok::render::fixed_constants_data_buffer>::call<vostok::memory::doug_lea_allocator>(
                                           vostok::render::g_allocator,
                                           v16,
                                           v17,
                                           v18);
    if ( v7 )
    {
      v7->data_ptr = 0;
      v7[1024].class_id = 0;
    }
    else
    {
      v7 = 0;
    }
    *(_DWORD *)(LODWORD(v3) + 16396) = v7;
  }
  if ( (unsigned int)(*(_DWORD *)(*(_DWORD *)(LODWORD(v3) + 16396) + 8196) + 4) > 0x2000 )
  {
    v9 = (vostok::render::data_indexer **)vostok::memory::new_helper<vostok::render::fixed_constants_data_buffer>::call<vostok::memory::doug_lea_allocator>(
                                            vostok::render::g_allocator,
                                            v16,
                                            v17,
                                            v18);
    if ( v9 )
    {
      *v9 = 0;
      v9[2049] = 0;
    }
    else
    {
      v9 = 0;
    }
    *v9 = *(vostok::render::data_indexer **)(LODWORD(v3) + 16396);
    *(_DWORD *)(LODWORD(v3) + 16396) = v9;
  }
  v10 = *(vostok::render::data_indexer **)(LODWORD(v3) + 16396);
  class_id = v10[1024].class_id;
  v12 = (unsigned int *)((char *)&v10->class_id + class_id);
  v10[1024].class_id = class_id + 4;
  *v12 = b_ptr;
  v13 = *(vostok::render::data_indexer **)(LODWORD(v3) + 4);
  v14 = *(vostok::render::data_indexer **)LODWORD(v3);
  v21 = v12;
  v20.data_ptr = v12;
  v20.class_id = 4;
  value = COERCE_FLOAT(
            stlp_std::lower_bound<vostok::render::data_indexer *,vostok::render::data_indexer,bool (__cdecl *)(vostok::render::data_indexer const &,vostok::render::data_indexer const &)>(
              v14,
              v13,
              &v20));
  if ( LODWORD(value) == *(_DWORD *)(LODWORD(v3) + 4) )
  {
    vostok::buffer_vector<vostok::render::data_indexer>::push_back(
      (vostok::buffer_vector<vostok::render::data_indexer> *)LODWORD(v3),
      &v20);
    return (float *)v21;
  }
  else
  {
    vostok::buffer_vector<vostok::render::data_indexer>::insert(
      v15,
      SLODWORD(v3),
      (vostok::render::data_indexer *const *)&value,
      &v20,
      (const vostok::render::data_indexer *)v16);
  }
  return (float *)v12;
}


vostok::math::float2 *__thiscall vostok::render::effect_constant_storage::store_constant<vostok::math::float2>(
        vostok::render::effect_constant_storage *this,
        const vostok::math::float2 value,
        unsigned int a3)
{
  float x; // ebx
  vostok::render::data_indexer *v4; // ecx
  vostok::render::data_indexer *v5; // eax
  vostok::render::data_indexer *i; // esi
  _DWORD *v7; // eax
  _DWORD *v9; // eax
  int v10; // eax
  int v11; // edx
  unsigned int *v12; // esi
  float v13; // xmm0_4
  vostok::render::data_indexer *v14; // eax
  vostok::render::data_indexer *v15; // ecx
  vostok::buffer_vector<vostok::render::data_indexer> *v16; // [esp-4h] [ebp-28h]
  const char *v17; // [esp+0h] [ebp-24h]
  const char *v18; // [esp+4h] [ebp-20h]
  unsigned int v19; // [esp+8h] [ebp-1Ch]
  vostok::render::data_indexer v20; // [esp+Ch] [ebp-18h] BYREF
  vostok::render::data_indexer v21; // [esp+14h] [ebp-10h] BYREF
  vostok::render::data_indexer *v22; // [esp+1Ch] [ebp-8h] BYREF

  x = value.x;
  v4 = *(vostok::render::data_indexer **)LODWORD(value.x);
  v20.data_ptr = (unsigned int *)&value.y;
  v5 = *(vostok::render::data_indexer **)(LODWORD(value.x) + 4);
  v20.class_id = 8;
  for ( i = stlp_std::lower_bound<vostok::render::data_indexer *,vostok::render::data_indexer,bool (__cdecl *)(vostok::render::data_indexer const &,vostok::render::data_indexer const &)>(
              v4,
              v5,
              &v20); i != *(vostok::render::data_indexer **)(LODWORD(value.x) + 4); ++i )
  {
    if ( vostok::render::effect_constant_storage::is_equal(
           i->data_ptr,
           (const unsigned int *)&value.y,
           (vostok::render::effect_constant_storage *)2,
           (const unsigned int)v17) )
    {
      return (vostok::math::float2 *)i->data_ptr;
    }
  }
  if ( !*(_DWORD *)(LODWORD(value.x) + 16396) )
  {
    v7 = vostok::memory::new_helper<vostok::render::fixed_constants_data_buffer>::call<vostok::memory::doug_lea_allocator>(
           vostok::render::g_allocator,
           v17,
           v18,
           v19);
    if ( v7 )
    {
      *v7 = 0;
      v7[2049] = 0;
    }
    else
    {
      v7 = 0;
    }
    *(_DWORD *)(LODWORD(value.x) + 16396) = v7;
  }
  if ( (unsigned int)(*(_DWORD *)(*(_DWORD *)(LODWORD(value.x) + 16396) + 8196) + 8) > 0x2000 )
  {
    v9 = vostok::memory::new_helper<vostok::render::fixed_constants_data_buffer>::call<vostok::memory::doug_lea_allocator>(
           vostok::render::g_allocator,
           v17,
           v18,
           v19);
    if ( v9 )
    {
      *v9 = 0;
      v9[2049] = 0;
    }
    else
    {
      v9 = 0;
    }
    *v9 = *(_DWORD *)(LODWORD(value.x) + 16396);
    *(_DWORD *)(LODWORD(value.x) + 16396) = v9;
  }
  v10 = *(_DWORD *)(LODWORD(value.x) + 16396);
  v11 = *(_DWORD *)(v10 + 8196);
  v12 = (unsigned int *)(v11 + v10 + 4);
  *(_DWORD *)(v10 + 8196) = v11 + 8;
  if ( v11 + v10 == -4 )
  {
    value.x = 0.0;
    v12 = 0;
  }
  else
  {
    v13 = SNaN;
    *v12 = LODWORD(SNaN);
    *(float *)(v11 + v10 + 8) = v13;
    LODWORD(value.x) = v11 + v10 + 4;
  }
  *v12 = LODWORD(value.y);
  v12[1] = a3;
  v14 = *(vostok::render::data_indexer **)(LODWORD(x) + 4);
  v15 = *(vostok::render::data_indexer **)LODWORD(x);
  v21.data_ptr = v12;
  v21.class_id = 8;
  v22 = stlp_std::lower_bound<vostok::render::data_indexer *,vostok::render::data_indexer,bool (__cdecl *)(vostok::render::data_indexer const &,vostok::render::data_indexer const &)>(
          v15,
          v14,
          &v21);
  if ( v22 == *(vostok::render::data_indexer **)(LODWORD(x) + 4) )
  {
    vostok::buffer_vector<vostok::render::data_indexer>::push_back(
      (vostok::buffer_vector<vostok::render::data_indexer> *)LODWORD(x),
      &v21);
    return (vostok::math::float2 *)LODWORD(value.x);
  }
  else
  {
    vostok::buffer_vector<vostok::render::data_indexer>::insert(
      v16,
      SLODWORD(x),
      &v22,
      &v21,
      (const vostok::render::data_indexer *)v17);
  }
  return (vostok::math::float2 *)v12;
}


vostok::math::float3 *__thiscall vostok::render::effect_constant_storage::store_constant<vostok::math::float3>(
        vostok::render::effect_constant_storage *this,
        const vostok::math::float3 value,
        int a3)
{
  float x; // ebx
  vostok::render::data_indexer *v4; // ecx
  vostok::render::data_indexer *v5; // eax
  vostok::render::data_indexer *i; // esi
  vostok::render::data_indexer *v7; // eax
  vostok::render::data_indexer **v9; // eax
  vostok::render::data_indexer *v10; // eax
  unsigned int *p_class_id; // ecx
  unsigned int class_id; // edx
  int v13; // eax
  vostok::render::data_indexer *v14; // ecx
  vostok::render::data_indexer *v15; // eax
  vostok::buffer_vector<vostok::render::data_indexer> *v16; // [esp-4h] [ebp-24h]
  const char *v17; // [esp+0h] [ebp-20h]
  const char *v18; // [esp+4h] [ebp-1Ch]
  unsigned int v19; // [esp+8h] [ebp-18h]
  vostok::render::data_indexer v20; // [esp+Ch] [ebp-14h] BYREF
  vostok::render::data_indexer v21; // [esp+14h] [ebp-Ch] BYREF
  int v22; // [esp+1Ch] [ebp-4h]

  x = value.x;
  v4 = *(vostok::render::data_indexer **)LODWORD(value.x);
  v20.data_ptr = (unsigned int *)&value.y;
  v5 = *(vostok::render::data_indexer **)(LODWORD(value.x) + 4);
  v20.class_id = 12;
  for ( i = stlp_std::lower_bound<vostok::render::data_indexer *,vostok::render::data_indexer,bool (__cdecl *)(vostok::render::data_indexer const &,vostok::render::data_indexer const &)>(
              v4,
              v5,
              &v20); i != *(vostok::render::data_indexer **)(LODWORD(x) + 4); ++i )
  {
    if ( vostok::render::effect_constant_storage::is_equal(
           i->data_ptr,
           (const unsigned int *)&value.y,
           (vostok::render::effect_constant_storage *)3,
           (const unsigned int)v17) )
    {
      return (vostok::math::float3 *)i->data_ptr;
    }
  }
  if ( !*(_DWORD *)(LODWORD(x) + 16396) )
  {
    v7 = (vostok::render::data_indexer *)vostok::memory::new_helper<vostok::render::fixed_constants_data_buffer>::call<vostok::memory::doug_lea_allocator>(
                                           vostok::render::g_allocator,
                                           v17,
                                           v18,
                                           v19);
    if ( v7 )
    {
      v7->data_ptr = 0;
      v7[1024].class_id = 0;
    }
    else
    {
      v7 = 0;
    }
    *(_DWORD *)(LODWORD(x) + 16396) = v7;
  }
  if ( (unsigned int)(*(_DWORD *)(*(_DWORD *)(LODWORD(x) + 16396) + 8196) + 12) > 0x2000 )
  {
    v9 = (vostok::render::data_indexer **)vostok::memory::new_helper<vostok::render::fixed_constants_data_buffer>::call<vostok::memory::doug_lea_allocator>(
                                            vostok::render::g_allocator,
                                            v17,
                                            v18,
                                            v19);
    if ( v9 )
    {
      *v9 = 0;
      v9[2049] = 0;
    }
    else
    {
      v9 = 0;
    }
    *v9 = *(vostok::render::data_indexer **)(LODWORD(x) + 16396);
    *(_DWORD *)(LODWORD(x) + 16396) = v9;
  }
  v10 = *(vostok::render::data_indexer **)(LODWORD(x) + 16396);
  p_class_id = &v10[1024].class_id;
  class_id = v10[1024].class_id;
  v13 = (int)&v10->class_id + class_id;
  *p_class_id = class_id + 12;
  *(float *)v13 = value.y;
  *(float *)(v13 + 4) = value.z;
  *(_DWORD *)(v13 + 8) = a3;
  v14 = *(vostok::render::data_indexer **)LODWORD(x);
  v22 = v13;
  v21.data_ptr = (unsigned int *)v13;
  v15 = *(vostok::render::data_indexer **)(LODWORD(x) + 4);
  v21.class_id = 12;
  LODWORD(value.x) = stlp_std::lower_bound<vostok::render::data_indexer *,vostok::render::data_indexer,bool (__cdecl *)(vostok::render::data_indexer const &,vostok::render::data_indexer const &)>(
                       v14,
                       v15,
                       &v21);
  if ( LODWORD(value.x) == *(_DWORD *)(LODWORD(x) + 4) )
    vostok::buffer_vector<vostok::render::data_indexer>::push_back(
      (vostok::buffer_vector<vostok::render::data_indexer> *)LODWORD(x),
      &v21);
  else
    vostok::buffer_vector<vostok::render::data_indexer>::insert(
      v16,
      SLODWORD(x),
      (vostok::render::data_indexer *const *)&value,
      &v21,
      (const vostok::render::data_indexer *)v17);
  return (vostok::math::float3 *)v22;
}


vostok::math::float4 *__thiscall vostok::render::effect_constant_storage::store_constant<vostok::math::float4>(
        vostok::render::effect_constant_storage *this,
        const vostok::math::float4 value,
        int a3)
{
  float x; // ebx
  vostok::render::data_indexer *v4; // ecx
  vostok::render::data_indexer *v5; // eax
  vostok::render::data_indexer *i; // esi
  vostok::render::data_indexer *v7; // eax
  vostok::render::data_indexer **v9; // eax
  vostok::render::data_indexer *v10; // eax
  unsigned int *p_class_id; // ecx
  unsigned int class_id; // edx
  int v13; // eax
  vostok::render::data_indexer *v14; // ecx
  vostok::render::data_indexer *v15; // eax
  vostok::buffer_vector<vostok::render::data_indexer> *v16; // [esp-4h] [ebp-28h]
  const char *v17; // [esp+0h] [ebp-24h]
  const char *v18; // [esp+4h] [ebp-20h]
  unsigned int v19; // [esp+8h] [ebp-1Ch]
  vostok::render::data_indexer v20; // [esp+Ch] [ebp-18h] BYREF
  vostok::render::data_indexer v21; // [esp+14h] [ebp-10h] BYREF
  int v22; // [esp+1Ch] [ebp-8h]

  x = value.x;
  v4 = *(vostok::render::data_indexer **)LODWORD(value.x);
  v20.data_ptr = (unsigned int *)&value.y;
  v5 = *(vostok::render::data_indexer **)(LODWORD(value.x) + 4);
  v20.class_id = 16;
  for ( i = stlp_std::lower_bound<vostok::render::data_indexer *,vostok::render::data_indexer,bool (__cdecl *)(vostok::render::data_indexer const &,vostok::render::data_indexer const &)>(
              v4,
              v5,
              &v20); i != *(vostok::render::data_indexer **)(LODWORD(x) + 4); ++i )
  {
    if ( vostok::render::effect_constant_storage::is_equal(
           i->data_ptr,
           (const unsigned int *)&value.y,
           (vostok::render::effect_constant_storage *)4,
           (const unsigned int)v17) )
    {
      return (vostok::math::float4 *)i->data_ptr;
    }
  }
  if ( !*(_DWORD *)(LODWORD(x) + 16396) )
  {
    v7 = (vostok::render::data_indexer *)vostok::memory::new_helper<vostok::render::fixed_constants_data_buffer>::call<vostok::memory::doug_lea_allocator>(
                                           vostok::render::g_allocator,
                                           v17,
                                           v18,
                                           v19);
    if ( v7 )
    {
      v7->data_ptr = 0;
      v7[1024].class_id = 0;
    }
    else
    {
      v7 = 0;
    }
    *(_DWORD *)(LODWORD(x) + 16396) = v7;
  }
  if ( (unsigned int)(*(_DWORD *)(*(_DWORD *)(LODWORD(x) + 16396) + 8196) + 16) > 0x2000 )
  {
    v9 = (vostok::render::data_indexer **)vostok::memory::new_helper<vostok::render::fixed_constants_data_buffer>::call<vostok::memory::doug_lea_allocator>(
                                            vostok::render::g_allocator,
                                            v17,
                                            v18,
                                            v19);
    if ( v9 )
    {
      *v9 = 0;
      v9[2049] = 0;
    }
    else
    {
      v9 = 0;
    }
    *v9 = *(vostok::render::data_indexer **)(LODWORD(x) + 16396);
    *(_DWORD *)(LODWORD(x) + 16396) = v9;
  }
  v10 = *(vostok::render::data_indexer **)(LODWORD(x) + 16396);
  p_class_id = &v10[1024].class_id;
  class_id = v10[1024].class_id;
  v13 = (int)&v10->class_id + class_id;
  *p_class_id = class_id + 16;
  *(float *)v13 = value.y;
  *(float *)(v13 + 4) = value.z;
  *(float *)(v13 + 8) = value.w;
  *(_DWORD *)(v13 + 12) = a3;
  v14 = *(vostok::render::data_indexer **)LODWORD(x);
  v22 = v13;
  v21.data_ptr = (unsigned int *)v13;
  v15 = *(vostok::render::data_indexer **)(LODWORD(x) + 4);
  v21.class_id = 16;
  LODWORD(value.x) = stlp_std::lower_bound<vostok::render::data_indexer *,vostok::render::data_indexer,bool (__cdecl *)(vostok::render::data_indexer const &,vostok::render::data_indexer const &)>(
                       v14,
                       v15,
                       &v21);
  if ( LODWORD(value.x) == *(_DWORD *)(LODWORD(x) + 4) )
    vostok::buffer_vector<vostok::render::data_indexer>::push_back(
      (vostok::buffer_vector<vostok::render::data_indexer> *)LODWORD(x),
      &v21);
  else
    vostok::buffer_vector<vostok::render::data_indexer>::insert(
      v16,
      SLODWORD(x),
      (vostok::render::data_indexer *const *)&value,
      &v21,
      (const vostok::render::data_indexer *)v17);
  return (vostok::math::float4 *)v22;
}
