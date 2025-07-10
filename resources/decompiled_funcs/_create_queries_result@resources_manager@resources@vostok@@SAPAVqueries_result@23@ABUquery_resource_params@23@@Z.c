vostok::resources::queries_result *__cdecl vostok::resources::resources_manager::create_queries_result(
        const vostok::resources::query_resource_params *params)
{
  unsigned int requests_count; // esi
  void *v3; // esp
  int v4; // edi
  vostok::resources::queries_result *v5; // esi
  const vostok::variant<32> **user_data; // eax
  const vostok::math::float4x4 **transforms; // eax
  const vostok::resources::creation_request *requests_create; // eax
  vostok::resources::class_id_enum v9; // eax
  vostok::resources::class_id_enum id; // edx
  const char *path; // eax
  const char *v12; // esi
  vostok::resources::class_id_enum v13; // edx
  vostok::resources::cook_base *cook; // eax
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // esi
  vostok::memory::base_allocator *allocator; // ecx
  vostok::memory::base_allocator_vtbl *v19; // edx
  vostok::vfs::base_node<1> *m_link_target; // edi
  unsigned int v21; // esi
  vostok::resources::query_result_for_cook *parent; // eax
  bool v23; // al
  bool v24; // cl
  vostok::resources::query_result_for_cook *v25; // eax
  vostok::resources::queries_result *m_parent; // eax
  DWORD CurrentThreadId; // eax
  vostok::resources::autoselect_quality_bool *autoselect_quality; // edx
  const unsigned int *quality_indexes; // edx
  const bool *disable_cache; // ecx
  float *target_satisfactions; // edx
  vostok::resources::query_result_for_cook *v32; // ecx
  vostok::memory::base_allocator *v33; // edx
  vostok::resources::queries_result *v34; // ecx
  boost::detail::function::vtable_base *vtable; // eax
  unsigned int *out_queries_id; // ecx
  vostok::resources::queries_result *result; // eax
  char *v38; // ecx
  unsigned int v39; // esi
  const vostok::variant<32> **v40; // eax
  vostok::variant<32> *v41; // eax
  const vostok::math::float4x4 **v42; // eax
  char *v43; // eax
  const vostok::resources::creation_request *v44; // eax
  vostok::resources::class_id_enum v45; // eax
  char v46; // dl
  const char *v47; // eax
  unsigned int v48; // eax
  vostok::variant<32> **v49; // edi
  bool v50; // al
  vostok::resources::query_type_enum v51; // ecx
  int v52; // eax
  const vostok::resources::creation_request *v53; // eax
  vostok::vfs::base_node<1> *v54; // edi
  const vostok::resources::creation_request *v55; // eax
  vostok::variant<32> **v56; // ecx
  int *v57; // edi
  int v58; // eax
  boost::function<void __cdecl(vostok::resources::queries_result &)> v59; // [esp-44h] [ebp-80h] BYREF
  vostok::memory::base_allocator *v60; // [esp-24h] [ebp-60h]
  DWORD v61; // [esp-20h] [ebp-5Ch]
  vostok::resources::query_result_for_cook *v62; // [esp-1Ch] [ebp-58h]
  float *v63; // [esp-18h] [ebp-54h]
  const bool *v64; // [esp-14h] [ebp-50h]
  const unsigned int *v65; // [esp-10h] [ebp-4Ch]
  vostok::resources::query_type_enum v66; // [esp-Ch] [ebp-48h]
  vostok::resources::autoselect_quality_bool *v67; // [esp-8h] [ebp-44h]
  assert_on_fail_bool v68; // [esp-4h] [ebp-40h]
  int v69; // [esp+0h] [ebp-3Ch] BYREF
  vostok::vfs::vfs_iterator v70; // [esp+Ch] [ebp-30h] BYREF
  vostok::variant<32> *v71; // [esp+1Ch] [ebp-20h]
  vostok::resources::query_type_enum queries_type; // [esp+20h] [ebp-1Ch]
  vostok::variant<32> *v73; // [esp+24h] [ebp-18h]
  vostok::resources::queries_result *i; // [esp+28h] [ebp-14h]
  vostok::vfs::base_node<1> *v75; // [esp+2Ch] [ebp-10h]
  int *v76; // [esp+30h] [ebp-Ch]
  vostok::variant<32> **p_m_user_data; // [esp+34h] [ebp-8h]
  assert_on_fail_bool assert_on_fail; // [esp+44h] [ebp+8h]
  assert_on_fail_bool assert_on_faila; // [esp+44h] [ebp+8h]
  char assert_on_fail_3; // [esp+47h] [ebp+Bh]
  bool assert_on_fail_3a; // [esp+47h] [ebp+Bh]

  requests_count = params->requests_count;
  v3 = alloca(4 * requests_count);
  v4 = 0;
  v76 = &v69;
  v75 = 0;
  p_m_user_data = 0;
  v73 = 0;
  if ( requests_count )
  {
    v5 = 0;
    for ( i = 0; ; v5 = i )
    {
      user_data = params->user_data;
      if ( user_data && user_data[v4] )
        p_m_user_data = (vostok::variant<32> **)((char *)p_m_user_data + 1);
      transforms = params->transforms;
      if ( transforms && transforms[v4] )
        v73 = (vostok::variant<32> *)((char *)v73 + 1);
      requests_create = params->requests_create;
      if ( requests_create
        && (v9 = *(vostok::resources::class_id_enum *)((char *)&v5->m_callback.functor.vostok_pointer_size_alignment[1]
                                                     + (_DWORD)requests_create)) != unknown_data_class )
      {
        assert_on_fail_3 = 1;
        id = v9;
      }
      else
      {
        id = params->requests[v4].id;
        assert_on_fail_3 = 0;
      }
      if ( id != raw_data_class
        && id != raw_data_class_no_reuse
        && id != fs_iterator_class
        && id != fs_iterator_recursive_class )
      {
        vostok::resources::resources_manager::find_cook(id);
      }
      if ( assert_on_fail_3 )
        path = *(const char **)((char *)&v5->m_callback.vtable + (unsigned int)params->requests_create);
      else
        path = params->requests[v4].path;
      v12 = path;
      if ( !path )
        v12 = (const char *)&buf;
      if ( !vostok::resources::g_resources_manager.m_variable->m_num_cook_registrators
        && (assert_on_fail_3
         || (v13 = params->requests[v4].id, v13 == raw_data_class)
         || v13 == raw_data_class_no_reuse
         || (cook = vostok::resources::resources_manager::find_cook(v13)) == 0
         || !vostok::resources::cook_base::does_create_resource_if_no_file(cook)) )
      {
        v76[v4] = strlen(v12) + 1;
      }
      else
      {
        v15 = vostok::math::max(0x104u, strlen(v12) + 1);
        v76[v4] = v15;
      }
      v16 = v76[v4];
      if ( v16 > 0x104 )
        v75 = (vostok::vfs::base_node<1> *)((char *)v75 + v16);
      i = (vostok::resources::queries_result *)((char *)i + 16);
      if ( ++v4 >= params->requests_count )
        break;
    }
  }
  v17 = 720 * params->requests_count;
  allocator = params->allocator;
  v19 = allocator->__vftable;
  v70.m_type = (_DWORD)v73 << 6;
  m_link_target = (vostok::vfs::base_node<1> *)(48 * (_DWORD)p_m_user_data);
  v21 = v17 + 80;
  v70.m_link_target = (vostok::vfs::base_node<1> *)(48 * (_DWORD)p_m_user_data);
  i = (vostok::resources::queries_result *)v19->call_malloc(
                                             allocator,
                                             (unsigned int)v75 + 64 * (_DWORD)v73 + 48 * (_DWORD)p_m_user_data + v21);
  parent = params->parent;
  v23 = parent
     && ((int)parent[1].m_memory_usage_self.vostok::resources::query_result_for_user::vostok::resources::resource_base::vostok::resources::resource_quality::type
       & 0x8000000) != 0;
  v24 = params->query_type == query_type_helper_for_mount;
  if ( v23 || (queries_type = query_type_normal, v24) )
    queries_type = query_type_helper_for_mount;
  v25 = params->parent;
  assert_on_fail = params->assert_on_fail;
  if ( v25 )
  {
    m_parent = v25->m_parent;
    if ( m_parent )
    {
      if ( m_parent->m_assert_on_fail == assert_on_fail_false )
        assert_on_fail = assert_on_fail_false;
    }
  }
  CurrentThreadId = GetCurrentThreadId();
  if ( i )
  {
    autoselect_quality = params->autoselect_quality;
    v68 = assert_on_fail;
    v67 = autoselect_quality;
    quality_indexes = params->quality_indexes;
    v66 = queries_type;
    disable_cache = params->disable_cache;
    v65 = quality_indexes;
    target_satisfactions = params->target_satisfactions;
    v64 = disable_cache;
    v32 = params->parent;
    v63 = target_satisfactions;
    v33 = params->allocator;
    v62 = v32;
    v61 = CurrentThreadId;
    v60 = v33;
    v34 = (vostok::resources::queries_result *)&v59;
    v59.vtable = 0;
    vtable = params->callback.vtable;
    if ( vtable )
    {
      v59.vtable = params->callback.vtable;
      if ( ((unsigned __int8)vtable & 1) != 0 )
        v59.functor = params->callback.functor;
      else
        (*(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, _DWORD))((unsigned int)vtable & 0xFFFFFFFE))(
          &params->callback.functor,
          &v59.functor,
          0);
    }
    vostok::resources::queries_result::queries_result(
      v34,
      params->requests_count,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68);
    m_link_target = v70.m_link_target;
  }
  out_queries_id = params->out_queries_id;
  result = i;
  if ( out_queries_id )
    *out_queries_id = (unsigned int)i;
  _InterlockedExchangeAdd(&result->m_reference_count, 1u);
  v73 = (vostok::variant<32> *)((char *)result + v21);
  v71 = (vostok::variant<32> *)((char *)m_link_target + (_DWORD)result + v21);
  v38 = (char *)result + v70.m_type + (_DWORD)m_link_target + v21;
  v39 = 0;
  queries_type = (vostok::resources::query_type_enum)v38;
  v70.m_link_target = v75;
  assert_on_faila = assert_on_fail_false;
  if ( params->requests_count )
  {
    v75 = 0;
    p_m_user_data = &result->m_queries[0].m_user_data;
    do
    {
      v40 = params->user_data;
      if ( v40 && v40[v39] )
      {
        v41 = v73;
        *p_m_user_data = v73;
        if ( v41 )
        {
          v41->m_helper = 0;
          v41->m_type_id = 0;
        }
        vostok::variant<32>::operator=(*p_m_user_data, params->user_data[v39]);
        ++v73;
      }
      v42 = params->transforms;
      if ( v42 && v42[v39] )
      {
        v43 = (char *)v71;
        *(p_m_user_data - 8) = v71;
        qmemcpy(v43, params->transforms[assert_on_faila], 0x40u);
        v39 = assert_on_faila;
        v71 = (vostok::variant<32> *)(v43 + 64);
      }
      v44 = params->requests_create;
      if ( v44
        && (v45 = *(_DWORD *)((char *)&v75->m_next_overlapped.max_storage + (_DWORD)v44 + 4)) != unknown_data_class )
      {
        v46 = 1;
      }
      else
      {
        v45 = params->requests[v39].id;
        v46 = 0;
      }
      *(p_m_user_data - 50) = (vostok::variant<32> *)v45;
      if ( v46 )
        v47 = *(const char **)((char *)&v75->m_mount_root.pointer + (unsigned int)params->requests_create);
      else
        v47 = params->requests[v39].path;
      v70.m_type = (vostok::vfs::vfs_iterator::type_enum)v47;
      if ( !v47 )
      {
        v47 = (const char *)&buf;
        v70.m_type = (vostok::vfs::vfs_iterator::type_enum)&buf;
      }
      v48 = strlen(v47);
      v49 = p_m_user_data;
      v50 = v48 < 0x104;
      assert_on_fail_3a = v50;
      v51 = (vostok::resources::query_type_enum)(p_m_user_data + 1);
      if ( !v50 )
        v51 = queries_type;
      *(p_m_user_data - 21) = (vostok::variant<32> *)v51;
      if ( v50 )
        v52 = 260;
      else
        v52 = v76[v39];
      v49[66] = (vostok::variant<32> *)v52;
      if ( v46 )
      {
        v53 = params->requests_create;
        v54 = v75;
        v70.m_hashset = *(vostok::vfs::vfs_hashset **)((char *)&v75->m_mount_helper_parent.max_storage + (_DWORD)v53 + 4);
        v70.m_node = *(vostok::vfs::base_node<1> **)((char *)&v53->m_data.m_size + (_DWORD)v75);
        if ( vostok::mutable_buffer::size(&v70) )
        {
          v55 = params->requests_create;
          v56 = p_m_user_data;
          *(p_m_user_data - 31) = *(vostok::variant<32> **)((char *)&v54->m_mount_helper_parent.max_storage
                                                          + (_DWORD)v55
                                                          + 4);
          *(v56 - 30) = *(vostok::variant<32> **)((char *)&v55->m_data.m_size + (_DWORD)v54);
        }
      }
      v57 = v76;
      memcpy((unsigned __int8 *)*(p_m_user_data - 21), (unsigned __int8 *)v70.m_type, v76[v39]);
      if ( !assert_on_fail_3a )
      {
        v58 = v57[v39];
        v70.m_link_target = (vostok::vfs::base_node<1> *)((char *)v70.m_link_target - v58);
        queries_type += v58;
      }
      p_m_user_data += 180;
      v75 = (vostok::vfs::base_node<1> *)((char *)v75 + 16);
      assert_on_faila = ++v39;
    }
    while ( v39 < params->requests_count );
    return i;
  }
  return result;
}
