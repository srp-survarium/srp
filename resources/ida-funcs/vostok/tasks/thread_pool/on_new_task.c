void __usercall vostok::tasks::thread_pool::on_new_task(
        vostok::tasks::thread_pool *this@<ecx>,
        vostok::tasks::thread_pool *a2@<edi>)
{
  volatile int *m_begin; // ecx
  volatile int *m_end; // edx
  unsigned int v4; // ebx
  volatile int *v5; // eax
  vostok::tasks::thread_tls *i; // esi
  int v7; // [esp+8h] [ebp-10h]
  int v8; // [esp+Ch] [ebp-Ch]
  int v9; // [esp+10h] [ebp-8h]

  m_begin = a2->m_core_thread_count.m_begin;
  m_end = a2->m_core_thread_count.m_end;
  v4 = -1;
  v8 = -1;
  v5 = m_begin;
  if ( m_begin == m_end )
    goto LABEL_10;
  v9 = 0;
  while ( 1 )
  {
    v7 = *v5;
    if ( v4 == -1 || v7 < v8 )
    {
      v4 = v9 >> 2;
      v8 = *v5;
    }
    if ( !v7 )
      break;
    v9 += 4;
    if ( ++v5 == m_end )
      goto LABEL_10;
  }
  if ( v5 - m_begin == -1 )
  {
LABEL_10:
    if ( a2->m_active_task_thread_count >= a2->m_min_permanent_working_threads )
      return;
  }
  for ( i = a2->m_task_thread_tls.m_begin;
        i != a2->m_task_thread_tls.m_end
     && (i->state != 1 || !vostok::tasks::thread_pool::try_activate_task_thread(a2, i, v4));
        ++i )
  {
    ;
  }
}
