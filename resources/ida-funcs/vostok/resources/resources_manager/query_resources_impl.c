int __thiscall vostok::resources::resources_manager::query_resources_impl(
        vostok::resources::resources_manager *this,
        const vostok::resources::query_resource_params *params)
{
  DWORD CurrentThreadId; // eax
  unsigned int v3; // ebx
  vostok::resources::resources_manager *v4; // ecx
  vostok::resources::queries_result *queries_result; // esi
  unsigned int m_size; // ecx
  int m_queries; // edi
  unsigned int v8; // ebx
  int v9; // edi
  vostok::resources::query_result **v10; // eax
  vostok::resources::query_result *v11; // ecx
  bool is_translate_query; // al
  int v13; // eax
  const vostok::resources::query_resource_params *v14; // edi
  unsigned int v15; // ebx
  vostok::resources::query_result *v16; // esi
  vostok::resources::query_result *v17; // ecx
  bool v18; // zf
  unsigned int requests_count; // esi
  void *v20; // esp
  vostok::resources::query_result **v21; // ebx
  unsigned int v22; // ebx
  volatile int *p_m_flags; // edi
  int v24; // eax
  int v25; // esi
  int i; // ecx
  vostok::resources::query_result **v27; // edi
  int v28; // edi
  vostok::resources::queries_result *v29; // ecx
  vostok::resources::query_result *v31; // [esp-4h] [ebp-40h]
  vostok::resources::query_result *v32; // [esp-4h] [ebp-40h]
  vostok::resources::resources_manager *v33[4]; // [esp+0h] [ebp-3Ch] BYREF
  vostok::resources::query_result **__first; // [esp+10h] [ebp-2Ch] BYREF
  vostok::resources::query_result **__last; // [esp+14h] [ebp-28h]
  vostok::resources::resources_manager **v36; // [esp+18h] [ebp-24h]
  vostok::resources::query_result *value; // [esp+1Ch] [ebp-20h] BYREF
  unsigned int v38; // [esp+20h] [ebp-1Ch] BYREF
  vostok::resources::queries_result *v39; // [esp+24h] [ebp-18h]
  vostok::resources::thread_local_data *thread_local_data; // [esp+28h] [ebp-14h]
  vostok::resources::sorting_predicate v41[4]; // [esp+2Ch] [ebp-10h] BYREF
  vostok::resources::sorting_predicate __comp[4]; // [esp+30h] [ebp-Ch] BYREF
  vostok::resources::query_result *v43; // [esp+34h] [ebp-8h] BYREF
  char v44; // [esp+38h] [ebp-4h]
  char v45; // [esp+39h] [ebp-3h]
  char v46; // [esp+3Ah] [ebp-2h]
  char v47; // [esp+3Bh] [ebp-1h]

  CurrentThreadId = GetCurrentThreadId();
  v3 = 0;
  thread_local_data = vostok::resources::resources_manager::get_thread_local_data(
                        v4,
                        (unsigned int)&s_resources_manager_buffer,
                        CurrentThreadId,
                        0);
  queries_result = vostok::resources::resources_manager::create_queries_result(params);
  m_size = (unsigned int)v31;
  v39 = queries_result;
  _InterlockedExchange((volatile __int32 *)&v38, (__int32)queries_result);
  if ( queries_result->m_size )
  {
    m_queries = (int)queries_result->m_queries;
    do
    {
      m_size = *(_DWORD *)(m_queries + 212);
      if ( !*(_DWORD *)(m_queries + 208)
        && !m_size
        && !vostok::resources::query_result::is_fs_iterator_query(0, m_queries) )
      {
        vostok::resources::query_result::translate_request_path((vostok::resources::query_result *)m_size, m_queries);
      }
      ++v3;
      m_queries += 736;
    }
    while ( v3 < queries_result->m_size );
  }
  v8 = 0;
  if ( params->requests_count )
  {
    v9 = (int)queries_result->m_queries;
    do
    {
      v10 = (vostok::resources::query_result **)(v9 + 208);
      m_size = *(_DWORD *)(v9 + 704);
      if ( (m_size & 0x10000000) == 0 )
      {
        v11 = *v10;
        if ( !*v10 && !*(_DWORD *)(v9 + 212)
          || (is_translate_query = vostok::resources::query_result::is_translate_query(v11, v9)) )
        {
          is_translate_query = 1;
        }
        v13 = vostok::resources::query_result::consider_with_name_registry(v11, (char *)v9, is_translate_query);
        if ( v13 == 4 )
        {
          vostok::resources::query_result::end_query_might_destroy_this((vostok::resources::query_result *)m_size, v9);
        }
        else if ( v13 != 2
               && vostok::resources::query_result::is_translate_query((vostok::resources::query_result *)m_size, v9) )
        {
          vostok::resources::query_result::translate_query_if_needed((vostok::resources::query_result *)m_size, v9);
        }
      }
      ++v8;
      v9 += 736;
    }
    while ( v8 < params->requests_count );
  }
  if ( s_resources_manager_buffer.m_pending_mount_operations_count
    || s_resources_manager_buffer.m_pending_mount_helper_query_count )
  {
    v14 = params;
  }
  else
  {
    v14 = params;
    v15 = 0;
    if ( params->requests_count )
    {
      v16 = queries_result->m_queries;
      do
      {
        if ( (v16->m_flags & 0x10000000) == 0
          && !vostok::resources::query_result::is_fs_iterator_query((vostok::resources::query_result *)m_size, (int)v16)
          && !vostok::resources::query_result::is_translate_query((vostok::resources::query_result *)m_size, (int)v16)
          && (v16->m_flags & 0x40) == 0
          && (v16->m_flags & 0x200) == 0 )
        {
          m_size = v16->m_creation_data_from_user.m_size;
          if ( !v16->m_creation_data_from_user.m_data
            && !m_size
            && vostok::resources::query_result::process_request_path(0, v16, 1)
            && !vostok::resources::query_result::check_fat_for_resource_reusage(
                  (vostok::resources::query_result *)m_size,
                  (int)v16) )
          {
            vostok::resources::query_result::allocate_raw_unmanaged_resource_if_needed(
              (vostok::resources::query_result *)m_size,
              (int)v16);
            vostok::resources::query_result::try_synchronous_cook_from_inline_data(v17, v16);
          }
        }
        ++v15;
        ++v16;
      }
      while ( v15 < params->requests_count );
    }
  }
  if ( !thread_local_data
    || !thread_local_data->in_transaction
    || (v18 = v14->query_type == query_type_normal, v47 = 1, !v18) )
  {
    v47 = 0;
  }
  requests_count = params->requests_count;
  v20 = alloca(4 * requests_count);
  v38 = 0;
  v21 = (vostok::resources::query_result **)v33;
  __first = (vostok::resources::query_result **)v33;
  __last = (vostok::resources::query_result **)v33;
  v36 = &v33[requests_count];
  v46 = 0;
  v45 = 0;
  v44 = 0;
  if ( requests_count )
  {
    v22 = v38;
    p_m_flags = &v39->m_queries[0].m_flags;
    do
    {
      if ( (*p_m_flags & 0x200) == 0
        && (*p_m_flags & 0x4000) == 0
        && (*p_m_flags & 0x40) == 0
        && (*p_m_flags & 0x80u) == 0 )
      {
        if ( vostok::resources::query_result::is_fs_iterator_query(
               (vostok::resources::query_result *)(p_m_flags - 176),
               (int)(p_m_flags - 176)) )
        {
          v44 = 1;
        }
        else
        {
          if ( *((_DWORD *)p_m_flags - 2) )
            v45 = 1;
          value = (vostok::resources::query_result *)m_size;
          vostok::buffer_vector<vostok::resources::query_result *>::push_back(
            (vostok::buffer_vector<vostok::resources::query_result *> *)m_size,
            (int)&__first,
            &value);
        }
      }
      ++v22;
      p_m_flags += 184;
    }
    while ( v22 < params->requests_count );
    v21 = __first;
    if ( v45 )
    {
      v24 = 0;
      __comp[0] = 0;
      if ( __first == __last )
        goto LABEL_73;
      v25 = __last - __first;
      for ( i = v25; i != 1; i >>= 1 )
        ++v24;
      stlp_std::priv::__introsort_loop<vostok::resources::query_result * *,vostok::resources::query_result *,int,vostok::resources::sorting_predicate>(
        (vostok::resources::sorting_predicate)&__comp[1],
        __first,
        __last,
        0,
        2 * v24,
        *(vostok::resources::query_result ***)__comp);
      v41[0] = __comp[0];
      if ( v25 <= 16 )
      {
        LOBYTE(v43) = __comp[0];
        stlp_std::priv::__insertion_sort<vostok::resources::query_result * *,vostok::resources::query_result *,vostok::resources::sorting_predicate>(
          v21,
          __last,
          &v43);
      }
      else
      {
        v27 = v21 + 16;
        stlp_std::priv::__insertion_sort<vostok::resources::query_result * *,vostok::resources::query_result *,vostok::resources::sorting_predicate>(
          v21,
          v21 + 16,
          (vostok::resources::query_result **)v41);
        while ( v27 != __last )
        {
          v32 = *(vostok::resources::query_result **)v41;
          stlp_std::priv::__unguarded_linear_insert<vostok::resources::query_result * *,vostok::resources::query_result *,vostok::resources::sorting_predicate>(
            v27,
            *v27);
          m_size = (unsigned int)v32;
          ++v27;
        }
      }
    }
  }
  if ( v21 != __last )
  {
    do
    {
      if ( v47 )
      {
        vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
          &thread_local_data->to_init_by_transaction,
          *v21,
          (vostok::threading::mutex *)m_size);
      }
      else
      {
        vostok::resources::resources_manager::push_new_query(*v21, (vostok::threading::mutex *)m_size, v33[0]);
        v46 = 1;
      }
      ++v21;
    }
    while ( v21 != __last );
    if ( v46 && !v47 )
      vostok::resources::resources_manager::wakeup_resources_thread(
        (vostok::resources::resources_manager *)m_size,
        (int)&s_resources_manager_buffer);
  }
LABEL_73:
  v28 = (int)v39;
  if ( !v39->m_size )
    vostok::resources::queries_result::on_query_end((vostok::resources::queries_result *)m_size, 1);
  if ( !v46 && !v47 && v44 )
    vostok::resources::queries_result::query_fs_iterators((vostok::resources::queries_result *)m_size, (_DWORD *)v28);
  if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(v28 + 44), 0xFFFFFFFF) )
  {
    v29 = *(vostok::resources::queries_result **)(v28 + 64);
    if ( v29 == (vostok::resources::queries_result *)-1 )
      v29 = (vostok::resources::queries_result *)_InterlockedExchange((volatile __int32 *)(v28 + 64), 1);
    vostok::resources::queries_result::end_and_delete_self(v29, v28, 0);
  }
  return v28;
}
