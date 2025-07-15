vostok::resources::queries_result *__cdecl vostok::resources::resources_manager::create_queries_result(
        const vostok::resources::query_resource_params *params)
{
  unsigned int requests_count; // edi
  void *v3; // esp
  unsigned int v4; // esi
  const vostok::variant<32> *const *user_data; // eax
  const vostok::math::float4x4 *const *transforms; // eax
  const vostok::resources::creation_request *requests_create; // eax
  vostok::resources::class_id_enum id; // eax
  const char *path; // eax
  const char *v10; // edi
  vostok::resources::class_id_enum v11; // eax
  unsigned int v12; // kr00_4
  _DWORD *v13; // edx
  unsigned int v14; // kr04_4
  vostok::memory::base_allocator *allocator; // esi
  unsigned int v16; // edi
  char *v17; // eax
  vostok::resources::queries_result *v18; // esi
  vostok::resources::query_result_for_cook *parent; // eax
  bool v20; // zf
  vostok::resources::query_result_for_cook *v21; // eax
  vostok::resources::queries_result *m_parent; // eax
  DWORD CurrentThreadId; // eax
  unsigned int *out_queries_id; // eax
  vostok::variant<32> *v25; // eax
  vostok::variant<32> **p_m_user_data; // ecx
  const vostok::variant<32> *const *v27; // edi
  unsigned int v28; // edx
  vostok::variant<32> *v29; // eax
  const vostok::math::float4x4 *const *v30; // edi
  unsigned int v31; // edx
  vostok::variant<32> *v32; // edi
  const vostok::resources::creation_request *v33; // eax
  vostok::resources::class_id_enum v34; // eax
  unsigned __int8 *v35; // eax
  unsigned int v36; // eax
  unsigned __int8 *v37; // edx
  int v38; // eax
  char *v39; // eax
  vostok::variant<32> *v40; // edi
  unsigned int v41; // edi
  _DWORD v43[6]; // [esp+0h] [ebp-44h] BYREF
  unsigned int v44; // [esp+18h] [ebp-2Ch]
  vostok::resources::queries_result *v45; // [esp+1Ch] [ebp-28h]
  assert_on_fail_bool assert_on_fail; // [esp+20h] [ebp-24h]
  unsigned __int8 *src; // [esp+24h] [ebp-20h]
  vostok::variant<32> *v48; // [esp+28h] [ebp-1Ch]
  _DWORD *v49; // [esp+2Ch] [ebp-18h]
  unsigned int v50; // [esp+30h] [ebp-14h]
  vostok::variant<32> **v51; // [esp+34h] [ebp-10h]
  vostok::variant<32> *v52; // [esp+38h] [ebp-Ch]
  unsigned int v53; // [esp+3Ch] [ebp-8h]
  bool v54; // [esp+43h] [ebp-1h]
  int v55; // [esp+4Ch] [ebp+8h]
  char v56; // [esp+4Fh] [ebp+Bh]
  char v57; // [esp+4Fh] [ebp+Bh]

  requests_count = params->requests_count;
  v3 = alloca(4 * requests_count);
  v4 = 0;
  v49 = v43;
  v51 = 0;
  v52 = 0;
  v53 = 0;
  if ( requests_count )
  {
    v50 = 0;
    do
    {
      user_data = params->user_data;
      if ( user_data && user_data[v4] )
        v52 = (vostok::variant<32> *)((char *)v52 + 1);
      transforms = params->transforms;
      if ( transforms && transforms[v4] )
        ++v53;
      requests_create = params->requests_create;
      if ( requests_create
        && (id = *(vostok::resources::class_id_enum *)((char *)&requests_create->m_id + v50)) != unknown_data_class )
      {
        v56 = 1;
      }
      else
      {
        id = params->requests[v4].id;
        v56 = 0;
      }
      if ( id != raw_data_class
        && id != raw_data_class_no_reuse
        && id != fs_iterator_class
        && id != fs_iterator_recursive_class )
      {
        vostok::resources::resources_manager::find_cook(id);
      }
      if ( v56 )
        path = *(const char **)((char *)&params->requests_create->m_name + v50);
      else
        path = params->requests[v4].path;
      v10 = path;
      if ( !path )
        v10 = uri;
      if ( !s_resources_manager_buffer.m_num_cook_registrators
        && (v56
         || (v11 = params->requests[v4].id, v11 == raw_data_class)
         || v11 == raw_data_class_no_reuse
         || !vostok::resources::cook_base::does_create_resource_if_no_file(params->requests[v4].id)) )
      {
        v14 = strlen(v10);
        v13 = &v49[v4];
        *v13 = v14 + 1;
      }
      else
      {
        v12 = strlen(v10);
        v13 = &v49[v4];
        *v13 = v12 + 1 > 0x104 ? 260 - (v12 + 1) - 260 : -260;
      }
      if ( *v13 > 0x104u )
        v51 = (vostok::variant<32> **)((char *)v51 + *v13);
      v50 += 16;
      ++v4;
    }
    while ( v4 < params->requests_count );
  }
  allocator = params->allocator;
  v55 = 48 * (_DWORD)v52;
  v44 = 736 * params->requests_count + 80;
  v16 = v44;
  v50 = v53 << 6;
  v17 = type_info::raw_name(&char `RTTI Type Descriptor');
  v18 = (vostok::resources::queries_result *)allocator->call_malloc(
                                               allocator,
                                               (unsigned int)v51 + v16 + v55 + v50,
                                               v17,
                                               "vostok::resources::resources_manager::create_queries_result",
                                               ".\\resources_manager_user_thread.cpp",
                                               119u);
  parent = params->parent;
  v45 = v18;
  if ( parent
    && ((int)parent[1].m_memory_usage_self.vostok::resources::query_result_for_user::vostok::resources::resource_base::vostok::resources::resource_quality::type
      & 0x8000000) != 0
    || (v20 = params->query_type == query_type_helper_for_mount, src = 0, v20) )
  {
    src = (unsigned __int8 *)1;
  }
  assert_on_fail = params->assert_on_fail;
  v21 = params->parent;
  if ( v21 )
  {
    m_parent = v21->m_parent;
    if ( m_parent )
    {
      if ( m_parent->m_assert_on_fail == assert_on_fail_false )
        assert_on_fail = assert_on_fail_false;
    }
  }
  CurrentThreadId = GetCurrentThreadId();
  if ( v18 )
  {
    vostok::resources::queries_result::queries_result(
      v18,
      params->requests_count,
      (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&params->callback,
      params->allocator,
      CurrentThreadId,
      params->parent,
      params->target_satisfactions,
      (vostok::resources::query_result *)params->disable_cache,
      (char *)params->quality_indexes,
      (vostok::resources::query_type_enum)src,
      params->autoselect_quality,
      assert_on_fail);
    v18 = v45;
    v16 = v44;
  }
  out_queries_id = params->out_queries_id;
  if ( out_queries_id )
    *out_queries_id = (unsigned int)v18;
  _InterlockedExchangeAdd(&v18->m_reference_count, 1u);
  v48 = (vostok::variant<32> *)((char *)v18 + v16);
  assert_on_fail = (assert_on_fail_bool)((char *)v18 + v50 + v55 + v16);
  v44 = (unsigned int)v51;
  v25 = (vostok::variant<32> *)((char *)v18 + v55 + v16);
  v52 = v25;
  v53 = 0;
  if ( params->requests_count )
  {
    v50 = 0;
    p_m_user_data = &v18->m_queries[0].m_user_data;
    v51 = &v18->m_queries[0].m_user_data;
    while ( 1 )
    {
      v27 = params->user_data;
      if ( v27 )
      {
        v28 = v53;
        if ( v27[v53] )
        {
          v29 = v48;
          *p_m_user_data = v48;
          if ( v29 )
          {
            v29->m_helper = 0;
            v29->m_type_id = 0;
          }
          vostok::variant<32>::operator=(*p_m_user_data, params->user_data[v28], (vostok::variant<32> *)p_m_user_data);
          ++v48;
          p_m_user_data = v51;
          v25 = v52;
        }
      }
      v30 = params->transforms;
      if ( v30 )
      {
        v31 = v53;
        if ( v30[v53] )
        {
          v32 = v52;
          v52 = (vostok::variant<32> *)((char *)v52 + 64);
          p_m_user_data[13] = v25;
          qmemcpy(v32, params->transforms[v31], 0x40u);
          v18 = v45;
          p_m_user_data = v51;
        }
      }
      v33 = params->requests_create;
      if ( v33 && *(vostok::resources::class_id_enum *)((char *)&v33->m_id + v50) )
      {
        v57 = 1;
        v34 = *(vostok::resources::class_id_enum *)((char *)&v33->m_id + v50);
      }
      else
      {
        v34 = params->requests[v53].id;
        v57 = 0;
      }
      *(p_m_user_data - 33) = (vostok::variant<32> *)v34;
      if ( v57 )
        v35 = *(unsigned __int8 **)((char *)&params->requests_create->m_name + v50);
      else
        v35 = (unsigned __int8 *)params->requests[v53].path;
      src = v35;
      if ( !v35 )
        src = (unsigned __int8 *)uri;
      v36 = strlen((const char *)src);
      v54 = v36 < 0x104;
      v37 = (unsigned __int8 *)(p_m_user_data + 21);
      if ( v36 >= 0x104 )
        v37 = (unsigned __int8 *)assert_on_fail;
      v20 = !v54;
      *(p_m_user_data - 4) = (vostok::variant<32> *)v37;
      if ( v20 )
        v38 = v49[v53];
      else
        v38 = 260;
      p_m_user_data[86] = (vostok::variant<32> *)v38;
      if ( v57 )
      {
        v39 = (char *)params->requests_create + v50;
        v20 = *((_DWORD *)v39 + 2) == 0;
        v40 = (vostok::variant<32> *)*((_DWORD *)v39 + 1);
        v43[4] = v40;
        if ( !v20 )
        {
          *(p_m_user_data - 14) = v40;
          *(p_m_user_data - 13) = (vostok::variant<32> *)*((_DWORD *)v39 + 2);
        }
      }
      v41 = v49[v53];
      memcpy(v37, src, v41);
      if ( !v54 )
      {
        v44 -= v41;
        assert_on_fail += v41;
      }
      ++v53;
      v51 += 184;
      v50 += 16;
      if ( v53 >= params->requests_count )
        break;
      p_m_user_data = v51;
      v25 = v52;
    }
  }
  return v18;
}
