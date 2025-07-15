void __userpurge vostok::tasks::thread_pool::fill_stats(
        vostok::tasks::thread_pool *this@<ecx>,
        vostok::tasks::thread_pool *a2@<esi>,
        vostok::strings::text_tree_item *stats)
{
  void *v3; // esp
  int v4; // eax
  const char *v5; // ebx
  unsigned int v6; // ecx
  unsigned int v7; // eax
  vostok::strings::text_tree_item *v8; // eax
  vostok::strings::text_tree_item *v9; // ecx
  volatile int v10; // edi
  vostok::fixed_string<512> *v11; // eax
  vostok::timing::timer *v12; // [esp-8h] [ebp-224h]
  unsigned int *v13[3]; // [esp+0h] [ebp-21Ch] BYREF
  _DWORD v14[131]; // [esp+Ch] [ebp-210h] BYREF
  unsigned int **v15; // [esp+218h] [ebp-4h]
  vostok::strings::text_tree_item *s; // [esp+224h] [ebp+8h]

  v3 = alloca(4 * (a2->m_core_thread_count.m_end - a2->m_core_thread_count.m_begin));
  v4 = a2->m_core_thread_count.m_end - a2->m_core_thread_count.m_begin;
  v5 = 0;
  v6 = 0;
  v15 = v13;
  if ( v4 )
  {
    v7 = a2->m_core_thread_count.m_end - a2->m_core_thread_count.m_begin;
    do
      v13[v6++] = 0;
    while ( v6 < v7 );
  }
  v12 = (vostok::timing::timer *)v6;
  v8 = vostok::strings::text_tree_item::new_child((vostok::strings::text_tree_item *)v6, (const char *)stats, "threads");
  vostok::tasks::thread_pool::fill_stats(
    &a2->m_user_thread_tls,
    v12,
    a2,
    v8,
    (vostok::tasks::thread_tls::type_enum)v13,
    v13[0]);
  s = vostok::strings::text_tree_item::new_child(v9, (const char *)stats, "CORES");
  if ( a2->m_core_thread_count.m_end - a2->m_core_thread_count.m_begin )
  {
    do
    {
      v10 = a2->m_core_thread_count.m_begin[(_DWORD)v5];
      v11 = vostok::fixed_string<512>::createf(v14, (vostok::fixed_string<512> *)&stru_807510, v5);
      vostok::strings::text_tree_item::new_childf(
        s,
        v11->m_begin,
        "(%d user + %d task)",
        v10 - (_DWORD)v15[(_DWORD)v5],
        v15[(_DWORD)v5]);
      ++v5;
    }
    while ( (unsigned int)v5 < a2->m_core_thread_count.m_end - a2->m_core_thread_count.m_begin );
  }
}


void __userpurge vostok::tasks::thread_pool::fill_stats(
        vostok::buffer_vector<vostok::tasks::thread_tls> *tls_array@<eax>,
        vostok::timing::timer *a2@<ecx>,
        vostok::tasks::thread_pool *this,
        vostok::strings::text_tree_item *stats,
        vostok::tasks::thread_tls::type_enum __formal,
        unsigned int *task_threads_per_core)
{
  vostok::tasks::thread_tls *m_begin; // edi
  unsigned __int64 v7; // rax
  vostok::tasks::task *current_task; // ecx
  char v9; // cl
  char *v10; // edx
  vostok::buffer_string v11; // [esp+Ch] [ebp-118h] BYREF
  _BYTE v12[256]; // [esp+18h] [ebp-10Ch] BYREF
  char v13; // [esp+118h] [ebp-Ch] BYREF
  vostok::tasks::thread_tls *i; // [esp+120h] [ebp-4h]

  m_begin = tls_array->m_begin;
  for ( i = tls_array->m_end; m_begin != i; ++m_begin )
  {
    if ( m_begin->thread_name.m_end != m_begin->thread_name.m_begin )
    {
      if ( m_begin->last_task_end_tick )
        v7 = 1000
           * (vostok::timing::timer::get_elapsed_ticks(a2, (int)&this->m_timer) - m_begin->last_task_end_tick)
           / *(_QWORD *)(*(_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + 8);
      else
        v7 = 0;
      current_task = m_begin->current_task;
      if ( current_task && current_task != &m_begin->user_thread_root_task || v7 < 0x64 )
      {
        ++*(_DWORD *)(__formal + 4 * m_begin->hardware_thread);
        v9 = 1;
      }
      else
      {
        v9 = 0;
      }
      v11.m_begin = v12;
      v11.m_max_end = &v13;
      if ( m_begin->state == 2 )
      {
        v10 = "SLEEP";
      }
      else if ( m_begin->state == 1 )
      {
        v10 = "IDLE ";
      }
      else
      {
        v10 = "TASK ";
        if ( !v9 )
        {
          if ( m_begin->thread_type )
            v10 = "USER ";
        }
      }
      v11.m_end = v12;
      v12[0] = 0;
      vostok::buffer_string::operator+=(&v11, v10);
      vostok::strings::text_tree_item::new_childf(
        stats,
        m_begin->thread_name.m_begin,
        "state(%s), hardware core(%d), executed(%d)",
        v11.m_begin,
        m_begin->hardware_thread,
        m_begin->executed_tasks_count);
    }
  }
}
