vostok::tasks::task_type *__cdecl vostok::tasks::create_new_task_type(
        const char *description,
        vostok::enum_flags<enum vostok::tasks::task_type_flags_enum> flags)
{
  vostok::memory::fixed_size_allocator<vostok::tasks::task_type,vostok::threading::mutex_tasks_unaware> *v2; // esi
  char *v3; // eax
  vostok::threading::mutex_tasks_unaware *v4; // ecx
  int v5; // esi
  _RTL_CRITICAL_SECTION *v6; // ebx
  vostok::intrusive_list<vostok::tasks::task_type,vostok::tasks::task_type *,104,vostok::threading::mutex_tasks_unaware,vostok::size_policy,vostok::no_debug_policy> *v7; // edi

  if ( !s_task_types_allocator )
  {
    if ( _InterlockedExchange(&s_task_types_creation_flag, 1) )
    {
      while ( !s_task_types_allocator )
        ;
    }
    else
    {
      vostok::tasks::inplace_constructor::operator()((vostok::tasks::inplace_constructor *)&s_task_types_creation_flag);
      _InterlockedExchange((volatile __int32 *)&s_task_types_allocator, (__int32)s_task_types_allocator_buffer);
    }
  }
  if ( !s_task_type_list )
    vostok::bind_pointer_to_buffer_mt_safe<vostok::intrusive_list<vostok::tasks::task_type,vostok::tasks::task_type *,104,vostok::threading::mutex_tasks_unaware,vostok::size_policy,vostok::no_debug_policy>,vostok::bind_pointer_to_buffer_mt_safe_placement_new_predicate>();
  v2 = s_task_types_allocator;
  v3 = type_info::raw_name(&vostok::tasks::task_type `RTTI Type Descriptor');
  v5 = (int)v2->call_malloc(v2, 120u, v3, &stru_807510.m_buffer[156], &stru_807510.m_buffer[136], 77u);
  if ( v5 )
  {
    vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(v4, (_RTL_CRITICAL_SECTION *)(v5 + 72));
    *(_DWORD *)v5 = 0;
    *(_DWORD *)(v5 + 64) = 0;
    *(_DWORD *)(v5 + 96) = 0;
    *(_DWORD *)(v5 + 100) = 0;
    *(_DWORD *)(v5 + 104) = 0;
    *(_DWORD *)(v5 + 108) = description;
    *(_BYTE *)(v5 + 112) = flags.m_flags;
  }
  else
  {
    v5 = 0;
  }
  v6 = 0;
  if ( v5 )
  {
    v7 = s_task_type_list;
    *(_DWORD *)(v5 + 104) = 0;
    if ( v7 )
      v6 = (_RTL_CRITICAL_SECTION *)&v7->vostok::threading::mutex_tasks_unaware;
    EnterCriticalSection(v6);
    ++v7->m_size;
    if ( v7->m_first )
      v7->m_last->m_next_task_type = (vostok::tasks::task_type *)v5;
    else
      v7->m_first = (vostok::tasks::task_type *)v5;
    v7->m_last = (vostok::tasks::task_type *)v5;
    LeaveCriticalSection(v6);
  }
  return (vostok::tasks::task_type *)v5;
}
