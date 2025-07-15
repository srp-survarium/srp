void __thiscall vostok::tasks::task_manager::spawn_task(
        vostok::tasks::task_manager *this,
        vostok::tasks::task *function,
        vostok::tasks::task_type *type,
        vostok::tasks::task *parent)
{
  vostok::tasks::task_manager *v4; // ecx
  vostok::tasks::task_allocator *v5; // ecx
  volatile __int64 m_task_ordinal; // kr00_8
  LPVOID Value; // eax
  vostok::tasks::task *v8; // edi
  vostok::tasks::task *m_push_list; // edi
  void *volatile *p_m_push_list; // ebx
  void *v11; // edi
  vostok::tasks::thread_pool *v12; // ecx
  vostok::tasks::task *v13; // [esp-4h] [ebp-24h]
  vostok::tasks::task *new_task; // [esp+Ch] [ebp-14h]
  unsigned __int64 next_ordinal; // [esp+10h] [ebp-10h]

  new_task = vostok::tasks::task_allocator::allocate(
               (vostok::tasks::task_allocator *)this,
               (int)&s_task_manager.m_task_allocator);
  if ( !new_task )
  {
    vostok::tasks::task_manager::collect_garbage(v4);
    new_task = vostok::tasks::task_allocator::allocate(v5, (int)&s_task_manager.m_task_allocator);
  }
  do
  {
    m_task_ordinal = s_task_manager.m_task_ordinal;
    next_ordinal = s_task_manager.m_task_ordinal + 1;
  }
  while ( _InterlockedCompareExchange64(
            &s_task_manager.m_task_ordinal,
            s_task_manager.m_task_ordinal + 1,
            s_task_manager.m_task_ordinal) != m_task_ordinal );
  Value = TlsGetValue(s_thread_pool.m_variable->m_thread_tls_key);
  v8 = parent;
  if ( !parent )
    v8 = (vostok::tasks::task *)*((_DWORD *)Value + 67);
  if ( new_task )
    vostok::tasks::task::task(function, (const boost::function<void __cdecl(void)> *)function, type, next_ordinal, v8);
  if ( v8 )
  {
    new_task->m_next_task_in_child_queue = 0;
    ++v8->m_children.m_size;
    if ( v8->m_children.m_first )
      v8->m_children.m_last->m_next_task_in_child_queue = new_task;
    else
      v8->m_children.m_first = new_task;
    v8->m_children.m_last = new_task;
    _InterlockedExchangeAdd(&v8->m_child_counter, 1u);
  }
  do
  {
    m_push_list = s_task_manager.m_pending_tasks.m_push_list;
    v13 = s_task_manager.m_pending_tasks.m_push_list;
    new_task->m_next_task_in_full_queue = s_task_manager.m_pending_tasks.m_push_list;
  }
  while ( (vostok::tasks::task *)vostok::threading::interlocked_compare_exchange_pointer(
                                   (void *volatile *)&s_task_manager.m_pending_tasks.m_push_list,
                                   new_task,
                                   v13) != m_push_list );
  p_m_push_list = (void *volatile *)&type->m_tasks.m_push_list;
  do
  {
    v11 = *p_m_push_list;
    new_task->m_next_task_in_type_queue = (vostok::tasks::task *)*p_m_push_list;
  }
  while ( (void *)vostok::threading::interlocked_compare_exchange_pointer(p_m_push_list, new_task, v11) != v11 );
  vostok::tasks::thread_pool::on_new_task(v12);
}
