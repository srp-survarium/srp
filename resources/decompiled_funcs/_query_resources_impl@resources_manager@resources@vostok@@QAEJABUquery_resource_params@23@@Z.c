vostok::resources::queries_result *__userpurge vostok::resources::resources_manager::query_resources_impl@<eax>(
        vostok::resources::resources_manager *this@<ecx>,
        vostok::resources::resources_manager *params,
        vostok::resources::query_result **it,
        vostok::resources::query_result *a4)
{
  char CurrentThreadId; // al
  vostok::resources::resources_manager *v5; // ecx
  vostok::resources::queries_result *queries_result; // eax
  unsigned int v7; // edi
  vostok::const_buffer *p_m_creation_data_from_user; // esi
  vostok::resources::query_result *m_size; // ecx
  vostok::resources::query_result::consider_with_name_registry_result_enum v10; // eax
  vostok::resources::cook_base *cook; // eax
  vostok::resources::query_result *v12; // ecx
  vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *p_m_reference_count; // ecx
  unsigned int v14; // edi
  volatile int *p_m_flags; // esi
  vostok::resources::class_id_enum v16; // edx
  vostok::resources::cook_base *v17; // eax
  vostok::resources::query_result *v18; // ecx
  vostok::resources::query_result *v19; // ecx
  vostok::resources::query_result *v20; // ecx
  bool v21; // zf
  vostok::resources::query_result *v22; // esi
  void *v23; // esp
  vostok::resources::query_result **v24; // edi
  vostok::resources::query_result **v25; // ebx
  unsigned int v26; // edx
  volatile int *v27; // eax
  int v28; // esi
  int v29; // eax
  int i; // ecx
  vostok::resources::query_result **m_end; // ebx
  vostok::resources::queries_result *v32; // esi
  vostok::resources::queries_result *m_result; // ecx
  vostok::resources::queries_result *v34; // edi
  vostok::resources::queries_result *v35; // ecx
  vostok::resources::query_result *v37[3]; // [esp+0h] [ebp-30h] BYREF
  vostok::buffer_vector<vostok::resources::query_result *> queries_array; // [esp+Ch] [ebp-24h]
  __int32 v39; // [esp+14h] [ebp-1Ch] BYREF
  vostok::resources::thread_local_data *local_data; // [esp+18h] [ebp-18h]
  vostok::resources::query_result **__formal; // [esp+1Ch] [ebp-14h]
  vostok::resources::sorting_predicate __comp[4]; // [esp+20h] [ebp-10h]
  vostok::resources::queries_result *queries; // [esp+24h] [ebp-Ch]
  vostok::resources::query_result *v44; // [esp+28h] [ebp-8h]
  bool has_fs_iterator_queries; // [esp+2Ch] [ebp-4h]
  bool need_sorting; // [esp+2Dh] [ebp-3h]
  bool pushed_something; // [esp+2Eh] [ebp-2h]
  bool in_transaction; // [esp+2Fh] [ebp-1h]
  vostok::resources::query_result **ita; // [esp+3Ch] [ebp+Ch]

  CurrentThreadId = GetCurrentThreadId();
  local_data = vostok::resources::resources_manager::get_thread_local_data(v5, (unsigned int)params, CurrentThreadId);
  queries_result = vostok::resources::resources_manager::create_queries_result((const vostok::resources::query_resource_params *)it);
  queries = queries_result;
  _InterlockedExchange(&v39, (__int32)queries_result);
  vostok::resources::queries_result::translate_request_paths(queries_result);
  v7 = 0;
  if ( it[2] )
  {
    p_m_creation_data_from_user = &queries->m_queries[0].m_creation_data_from_user;
    do
    {
      if ( ((int)p_m_creation_data_from_user[60].m_data & 0x10000000) == 0 )
      {
        m_size = (vostok::resources::query_result *)p_m_creation_data_from_user->m_size;
        if ( p_m_creation_data_from_user->m_data || m_size )
          vostok::resources::resources_manager::find_cook((vostok::resources::class_id_enum)p_m_creation_data_from_user[-10].m_size);
        v10 = vostok::resources::query_result::consider_with_name_registry(
                m_size,
                (vostok::resources::query_result::only_try_to_get_associated_resource_bool)&p_m_creation_data_from_user[-26]);
        if ( v10 == consider_with_name_registry_result_got_associated_resource )
        {
          if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&p_m_creation_data_from_user[59].m_size, 0xFFFFFFFF) )
            vostok::resources::query_result::end_query_might_destroy_this_impl(0);
        }
        else if ( v10 != consider_with_name_registry_result_added_as_referer )
        {
          cook = vostok::resources::resources_manager::find_cook((vostok::resources::class_id_enum)p_m_creation_data_from_user[-10].m_size);
          if ( cook )
          {
            if ( (cook->m_flags.m_flags & 8) != 0 )
              vostok::resources::query_result::translate_query_if_needed(v12);
          }
        }
      }
      ++v7;
      p_m_creation_data_from_user += 90;
    }
    while ( v7 < (unsigned int)it[2] );
  }
  p_m_reference_count = *(vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> **)((char *)&loc_201B0 + (unsigned int)vostok::resources::g_resources_manager.m_variable);
  if ( !p_m_reference_count
    && !*(_DWORD *)((char *)&loc_201B0 + (unsigned int)vostok::resources::g_resources_manager.m_variable + 4) )
  {
    v14 = 0;
    if ( it[2] )
    {
      p_m_flags = &queries->m_queries[0].m_flags;
      do
      {
        if ( (*p_m_flags & 0x10000000) == 0 )
        {
          v16 = *((_DWORD *)p_m_flags - 139);
          if ( v16 != fs_iterator_class && v16 != fs_iterator_recursive_class )
          {
            v17 = vostok::resources::resources_manager::find_cook(v16);
            if ( (!v17 || (v17->m_flags.m_flags & 8) == 0)
              && (*p_m_flags & 0x40) == 0
              && (*p_m_flags & 0x200) == 0
              && !*((_DWORD *)p_m_flags - 120)
              && !*((_DWORD *)p_m_flags - 119)
              && vostok::resources::query_result::process_request_path(
                   0,
                   (vostok::resources::query_result *)(p_m_flags - 172),
                   (vostok::vfs::vfs_iterator *)1)
              && !vostok::resources::query_result::check_fat_for_resource_reusage(v18) )
            {
              vostok::resources::query_result::allocate_raw_unmanaged_resource_if_needed(v19, (int)(p_m_flags - 172));
              vostok::resources::query_result::try_synchronous_cook_from_inline_data(
                v20,
                (vostok::resources::query_result *)(p_m_flags - 172));
            }
          }
        }
        p_m_reference_count = (vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)it;
        ++v14;
        p_m_flags += 180;
      }
      while ( v14 < (unsigned int)it[2] );
    }
  }
  if ( !local_data || !local_data->in_transaction || (v21 = it[17] == 0, in_transaction = 1, !v21) )
    in_transaction = 0;
  v22 = it[2];
  v23 = alloca(4 * (_DWORD)v22);
  v24 = v37;
  v25 = v37;
  v26 = 0;
  queries_array.m_end = v37;
  pushed_something = 0;
  need_sorting = 0;
  has_fs_iterator_queries = 0;
  if ( v22 )
  {
    v27 = &queries->m_queries[0].m_flags;
    while ( 1 )
    {
      p_m_reference_count = (vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)*v27;
      if ( (*v27 & 0x200) == 0 )
      {
        p_m_reference_count = (vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)*v27;
        if ( (*v27 & 0x4000) == 0 )
        {
          p_m_reference_count = (vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)*v27;
          if ( (*v27 & 0x40) == 0 )
          {
            p_m_reference_count = (vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)*v27;
            if ( (*v27 & 0x80u) == 0 )
            {
              p_m_reference_count = (vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)*((_DWORD *)v27 - 139);
              if ( p_m_reference_count != (vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)1
                && p_m_reference_count != (vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)2 )
              {
                if ( *((_DWORD *)v27 - 2) )
                  need_sorting = 1;
                m_end = queries_array.m_end;
                if ( queries_array.m_end )
                {
                  p_m_reference_count = (vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)(v27 - 172);
                  *queries_array.m_end = (vostok::resources::query_result *)(v27 - 172);
                }
                v25 = m_end + 1;
                queries_array.m_end = v25;
                goto LABEL_46;
              }
              has_fs_iterator_queries = 1;
            }
          }
        }
      }
      v25 = queries_array.m_end;
LABEL_46:
      ++v26;
      v27 += 180;
      if ( v26 >= (unsigned int)it[2] )
      {
        if ( need_sorting )
        {
          __comp[0] = 0;
          if ( v37 != v25 )
          {
            v28 = v25 - v37;
            v29 = v28;
            for ( i = 0; v29 != 1; ++i )
              v29 >>= 1;
            stlp_std::priv::__introsort_loop<vostok::resources::query_result * *,vostok::resources::query_result *,int,vostok::resources::sorting_predicate>(
              (vostok::resources::sorting_predicate)v28,
              v37,
              v25,
              0,
              2 * i,
              *(vostok::resources::query_result ***)__comp);
            LOBYTE(__formal) = __comp[0];
            if ( v28 <= 16 )
            {
              LOBYTE(v44) = __comp[0];
              stlp_std::priv::__insertion_sort<vostok::resources::query_result * *,vostok::resources::query_result *,vostok::resources::sorting_predicate>(
                v37,
                v25);
            }
            else
            {
              stlp_std::priv::__insertion_sort<vostok::resources::query_result * *,vostok::resources::query_result *,vostok::resources::sorting_predicate>(
                v37,
                &a4);
              stlp_std::priv::__unguarded_insertion_sort_aux<vostok::resources::query_result * *,vostok::resources::query_result *,vostok::resources::sorting_predicate>(
                &a4,
                v25);
            }
          }
        }
        break;
      }
    }
  }
  ita = v37;
  if ( v37 == v25 )
  {
    v32 = queries;
  }
  else
  {
    do
    {
      if ( in_transaction )
      {
        vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
          p_m_reference_count,
          &local_data->to_init_by_transaction.m_size,
          *v24,
          (bool *)v37[0]);
      }
      else
      {
        vostok::resources::resources_manager::push_new_query(params, *v24);
        v24 = ita;
        pushed_something = 1;
      }
      v32 = queries;
      ita = ++v24;
    }
    while ( v24 != v25 );
    if ( pushed_something && !in_transaction )
      SetEvent(*(HANDLE *)((char *)&dword_203D0 + (_DWORD)params));
  }
  if ( !v32->m_size )
  {
    _InterlockedExchange(&v32->m_result, 1);
    p_m_reference_count = (vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)&v32->m_reference_count;
    if ( !_InterlockedExchangeAdd(&v32->m_reference_count, 0xFFFFFFFF) )
    {
      vostok::resources::resources_manager::on_query_finished(
        (vostok::resources::resources_manager *)p_m_reference_count,
        queries);
      v32 = queries;
    }
  }
  if ( !pushed_something && !in_transaction && has_fs_iterator_queries )
    vostok::resources::queries_result::query_fs_iterators((vostok::resources::queries_result *)p_m_reference_count);
  if ( !_InterlockedExchangeAdd(&v32->m_reference_count, 0xFFFFFFFF) )
  {
    m_result = (vostok::resources::queries_result *)v32->m_result;
    if ( m_result == (vostok::resources::queries_result *)-1 )
      _InterlockedExchange(&v32->m_result, 1);
    if ( v32->m_is_queries_for_quality )
    {
      v32 = queries;
      vostok::resources::queries_result::mark_inconsistent_qualities_as_failed(m_result);
    }
    if ( !v32->is_cancelled )
    {
      v34 = queries;
      vostok::resources::queries_result::call_user_callback(m_result);
      vostok::resources::queries_result::push_to_grm_cache(v35);
      v32 = v34;
    }
    vostok::resources::queries_result::~queries_result(m_result);
    v32->m_allocator->call_free(v32->m_allocator, v32);
  }
  return v32;
}
