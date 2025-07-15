void __thiscall vostok::tasks::task_manager::spawn_task(
        vostok::tasks::task_manager *this,
        vostok::tasks::task *function,
        boost::function<void __cdecl(void)> *type,
        vostok::tasks::task *parent)
{
  unsigned int *v4; // ecx
  vostok::tasks::task_allocator *v5; // ecx
  vostok::tasks::task_type *v6; // esi
  vostok::tasks::thread_tls *v7; // eax
  vostok::tasks::task *current_task; // edi
  vostok::tasks::task *m_push_list; // ecx
  volatile signed __int32 *v10; // edx
  vostok::tasks::thread_pool *v11; // ecx
  char *v12; // [esp+0h] [ebp-24h]
  unsigned int ordinal; // [esp+10h] [ebp-14h]
  volatile __int64 ordinal_4; // [esp+14h] [ebp-10h]
  vostok::tasks::task *v15; // [esp+1Ch] [ebp-8h]
  bool do_debug_break; // [esp+23h] [ebp-1h] BYREF

  v15 = vostok::tasks::task_allocator::allocate(
          (vostok::tasks::task_allocator *)this,
          (int)&s_task_manager.m_task_allocator);
  if ( !v15 )
  {
    vostok::tasks::task_manager::collect_garbage(v4);
    v15 = vostok::tasks::task_allocator::allocate(v5, (int)&s_task_manager.m_task_allocator);
    if ( !v15 && !debug_macro_helper_ignore_always_24 )
    {
      do_debug_break = 0;
      vostok::debug::on_error(
        &do_debug_break,
        process_error_true,
        0,
        "assertion_failed",
        "fatal error",
        ".\\tasks_manager.cpp",
        "vostok::tasks::task_manager::spawn_task",
        (const char *)0xB8,
        "tasks: out of memory",
        v12);
      if ( vostok::debug::is_debugger_present() || do_debug_break )
        __debugbreak();
    }
  }
  do
  {
    v6 = (vostok::tasks::task_type *)(LODWORD(s_task_manager.m_task_ordinal) + 1);
    ordinal_4 = s_task_manager.m_task_ordinal;
    ordinal = (unsigned __int64)(s_task_manager.m_task_ordinal + 1) >> 32;
  }
  while ( _InterlockedCompareExchange64(
            &s_task_manager.m_task_ordinal,
            s_task_manager.m_task_ordinal + 1,
            s_task_manager.m_task_ordinal) != ordinal_4 );
  v7 = vostok::tasks::current_task_thread_tls();
  current_task = parent;
  if ( !parent )
    current_task = v7->current_task;
  if ( v15 )
    vostok::tasks::task::task(
      function,
      (int)v15,
      type,
      v6,
      __PAIR64__((unsigned int)current_task, ordinal),
      (vostok::tasks::task *)v12);
  if ( current_task )
  {
    v15->m_next_task_in_child_queue = 0;
    ++current_task->m_children.m_size;
    if ( current_task->m_children.m_first )
      current_task->m_children.m_last->m_next_task_in_child_queue = v15;
    else
      current_task->m_children.m_first = v15;
    current_task->m_children.m_last = v15;
    _InterlockedExchangeAdd(&current_task->m_child_counter, 1u);
  }
  do
  {
    m_push_list = s_task_manager.m_pending_tasks.m_push_list;
    v15->m_next_task_in_full_queue = s_task_manager.m_pending_tasks.m_push_list;
  }
  while ( (vostok::tasks::task *)_InterlockedCompareExchange(
                                   (volatile signed __int32 *)&s_task_manager.m_pending_tasks.m_push_list,
                                   (signed __int32)v15,
                                   (signed __int32)m_push_list) != m_push_list );
  v10 = (volatile signed __int32 *)&type[2];
  do
  {
    v11 = (vostok::tasks::thread_pool *)*v10;
    v15->m_next_task_in_type_queue = (vostok::tasks::task *)*v10;
  }
  while ( (vostok::tasks::thread_pool *)_InterlockedCompareExchange(v10, (signed __int32)v15, (signed __int32)v11) != v11 );
  vostok::tasks::thread_pool::on_new_task(v11, s_thread_pool.m_variable);
}
