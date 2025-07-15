vostok::tasks::task *__thiscall vostok::tasks::task_manager::grab_next_task(vostok::tasks::task_manager *this)
{
  vostok::tasks::thread_tls *v1; // eax
  vostok::tasks::task *p_in_grab_next_task; // ecx
  int last_task_type; // esi
  vostok::tasks::task *v4; // edi
  bool v5; // bl
  volatile __int64 m_oldest_task_ordinal; // rax
  volatile __int64 *p_m_oldest_task_ordinal; // esi
  volatile __int32 *v9; // [esp+1Ch] [ebp-Ch]
  vostok::tasks::thread_tls *v10; // [esp+20h] [ebp-8h]
  char v11; // [esp+27h] [ebp-1h]

  while ( s_task_manager.m_collecting_garbage )
    ;
  v1 = vostok::tasks::current_task_thread_tls();
  p_in_grab_next_task = (vostok::tasks::task *)&v1->in_grab_next_task;
  v10 = v1;
  v9 = &v1->in_grab_next_task;
  _InterlockedExchange(&v1->in_grab_next_task, 1);
  while ( 1 )
  {
    last_task_type = (int)v1->last_task_type;
    v11 = 0;
    if ( !last_task_type
      || (p_in_grab_next_task = (vostok::tasks::task *)(LODWORD(s_task_manager.m_oldest_task_ordinal) + 51200),
          s_task_manager.m_oldest_task_ordinal + 51200 <= *(_QWORD *)(last_task_type + 96))
      || (v4 = (vostok::tasks::task *)vostok::intrusive_queue<vostok::tasks::task,vostok::tasks::task,8,vostok::threading::mutex>::pop_front(
                                        (vostok::intrusive_queue<vostok::tasks::task,vostok::tasks::task,8,vostok::threading::mutex> *)p_in_grab_next_task,
                                        last_task_type),
          v11 = 1,
          !v4) )
    {
      v4 = vostok::intrusive_queue<vostok::tasks::task,vostok::tasks::task,12,vostok::threading::mutex>::pop_front(p_in_grab_next_task);
      if ( !v4 )
      {
        v4 = 0;
        goto LABEL_10;
      }
    }
    v5 = _InterlockedCompareExchange(&v4->m_state, 2, 1) == 1;
    vostok::tasks::task::decrement_reference_count_and_deallocate_when_zero((vostok::tasks::task *)2, (unsigned int)v4);
    if ( v5 )
      break;
    v1 = v10;
  }
  if ( v11 )
  {
    p_m_oldest_task_ordinal = (volatile __int64 *)(last_task_type + 96);
    m_oldest_task_ordinal = *p_m_oldest_task_ordinal;
  }
  else
  {
    m_oldest_task_ordinal = s_task_manager.m_oldest_task_ordinal;
    p_m_oldest_task_ordinal = &s_task_manager.m_oldest_task_ordinal;
  }
  _InterlockedCompareExchange64(p_m_oldest_task_ordinal, v4->m_ordinal, m_oldest_task_ordinal);
  v10->current_task = v4;
  v10->last_task_type = v4->m_type;
LABEL_10:
  _InterlockedExchange(v9, 0);
  return v4;
}
