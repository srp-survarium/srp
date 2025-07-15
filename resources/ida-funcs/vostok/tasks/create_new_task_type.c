vostok::tasks::task_type *__cdecl vostok::tasks::create_new_task_type(
        const char *description,
        vostok::enum_flags<enum vostok::tasks::task_type_flags_enum> flags)
{
  _RTL_CRITICAL_SECTION *v2; // eax
  vostok::tasks::task_type *v3; // esi
  vostok::tasks::task_type *v4; // ecx
  char *v6; // [esp+0h] [ebp-14h]
  volatile int *v7; // [esp+4h] [ebp-10h]
  vostok::bind_pointer_to_buffer_mt_safe_placement_new_predicate pointer; // [esp+8h] [ebp-Ch]
  vostok::intrusive_list<vostok::tasks::task_type,vostok::tasks::task_type *,104,vostok::threading::mutex_tasks_unaware,vostok::size_policy,vostok::no_debug_policy> **v9; // [esp+Ch] [ebp-8h]

  if ( !s_task_types_allocator )
  {
    pointer = 0;
    vostok::bind_pointer_to_buffer_mt_safe<vostok::memory::fixed_size_allocator<vostok::tasks::task_type,vostok::threading::mutex_tasks_unaware>,vostok::tasks::inplace_constructor>();
  }
  if ( !s_task_type_list )
  {
    LOBYTE(v9) = 0;
    vostok::bind_pointer_to_buffer_mt_safe<vostok::intrusive_list<vostok::tasks::task_type,vostok::tasks::task_type *,104,vostok::threading::mutex_tasks_unaware,vostok::size_policy,vostok::no_debug_policy>,vostok::bind_pointer_to_buffer_mt_safe_placement_new_predicate>(
      v9,
      (char (*)[48])v6,
      v7,
      pointer);
  }
  v2 = (_RTL_CRITICAL_SECTION *)s_task_types_allocator->call_malloc(s_task_types_allocator, 120);
  v3 = (vostok::tasks::task_type *)v2;
  if ( !v2 )
    return 0;
  InitializeCriticalSectionAndSpinCount(v2 + 3, 0x2710u);
  LOBYTE(v4) = flags.m_flags;
  v3->m_tasks.m_pop_list = 0;
  v3->m_tasks.m_push_list = 0;
  LODWORD(v3->m_min_task_ordinal) = 0;
  HIDWORD(v3->m_min_task_ordinal) = 0;
  v3->m_next_task_type = 0;
  v3->m_description = description;
  v3->m_flags = flags.m_flags;
  vostok::intrusive_list<vostok::tasks::task_type,vostok::tasks::task_type *,104,vostok::threading::mutex_tasks_unaware,vostok::size_policy,vostok::no_debug_policy>::push_back(
    v4,
    v3);
  return v3;
}
