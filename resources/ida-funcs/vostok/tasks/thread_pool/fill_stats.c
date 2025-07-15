void __userpurge vostok::tasks::thread_pool::fill_stats(
        vostok::tasks::thread_pool *this@<ecx>,
        vostok::tasks::thread_pool *a2@<eax>,
        vostok::strings::text_tree_item *stats)
{
  void *v5; // esp
  int v6; // edx
  unsigned int v7; // eax
  vostok::memory::stack_allocator *m_allocator; // eax
  vostok::strings::text_tree_item *m_arena_current_position; // esi
  vostok::strings::text_tree_item *v10; // eax
  vostok::memory::stack_allocator *v11; // eax
  vostok::strings::text_tree_item *v12; // esi
  vostok::strings::text_tree_item *v13; // ecx
  vostok::strings::text_tree_item *v14; // eax
  const char *i; // ebx
  vostok::fixed_string<512> *v16; // eax
  bool *v17[4]; // [esp+0h] [ebp-224h] BYREF
  _BYTE v18[524]; // [esp+10h] [ebp-214h] BYREF
  vostok::tasks::thread_tls::type_enum __formal; // [esp+21Ch] [ebp-8h]
  unsigned int threads_count; // [esp+220h] [ebp-4h]
  vostok::strings::text_tree_item *statsa; // [esp+22Ch] [ebp+8h]
  vostok::strings::text_tree_item *statsb; // [esp+22Ch] [ebp+8h]

  v5 = alloca(4 * (a2->m_core_thread_count.m_end - a2->m_core_thread_count.m_begin));
  v6 = a2->m_core_thread_count.m_end - a2->m_core_thread_count.m_begin;
  v7 = 0;
  __formal = (vostok::tasks::thread_tls::type_enum)v17;
  if ( v6 )
  {
    do
      v17[v7++] = 0;
    while ( v7 < a2->m_core_thread_count.m_end - a2->m_core_thread_count.m_begin );
  }
  m_allocator = stats->m_allocator;
  m_arena_current_position = (vostok::strings::text_tree_item *)m_allocator->m_arena_current_position;
  m_allocator->m_arena_current_position = &m_arena_current_position[1];
  if ( m_arena_current_position )
  {
    vostok::strings::text_tree_item::text_tree_item(m_arena_current_position + 1, stats->m_allocator, "threads", 0);
    statsa = v10;
  }
  else
  {
    statsa = 0;
  }
  threads_count = (unsigned int)&stats->m_sub_items;
  vostok::intrusive_list<vostok::strings::text_tree_column_item,vostok::strings::text_tree_column_item *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    (vostok::intrusive_list<vostok::strings::text_tree_item_base,vostok::strings::text_tree_item *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)statsa,
    (int)&stats->m_sub_items,
    statsa,
    v17[0]);
  vostok::tasks::thread_pool::fill_stats(
    a2,
    &a2->m_user_thread_tls,
    statsa,
    (unsigned int *)__formal,
    (unsigned int *)v17[0]);
  v11 = stats->m_allocator;
  v12 = (vostok::strings::text_tree_item *)v11->m_arena_current_position;
  v13 = v12 + 1;
  v11->m_arena_current_position = &v12[1];
  if ( v12 )
  {
    vostok::strings::text_tree_item::text_tree_item(v13, stats->m_allocator, "CORES", 0);
    statsb = v14;
  }
  else
  {
    statsb = 0;
  }
  vostok::intrusive_list<vostok::strings::text_tree_column_item,vostok::strings::text_tree_column_item *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    (vostok::intrusive_list<vostok::strings::text_tree_item_base,vostok::strings::text_tree_item *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)v13,
    threads_count,
    statsb,
    v17[0]);
  for ( i = 0; (unsigned int)i < a2->m_core_thread_count.m_end - a2->m_core_thread_count.m_begin; ++i )
  {
    threads_count = a2->m_core_thread_count.m_begin[(_DWORD)i];
    v16 = vostok::fixed_string<512>::createf((int)v18, (vostok::fixed_string<512> *)&stru_95DC74, i);
    vostok::strings::text_tree_item::new_childf(
      statsb,
      v16->m_begin,
      "(%d user + %d task)",
      threads_count - *(_DWORD *)(__formal + 4 * (_DWORD)i),
      *(_DWORD *)(__formal + 4 * (_DWORD)i));
  }
}


void __userpurge vostok::tasks::thread_pool::fill_stats(
        vostok::tasks::thread_pool *this@<edi>,
        vostok::buffer_vector<vostok::tasks::thread_tls> *tls_array@<eax>,
        vostok::strings::text_tree_item *stats,
        unsigned int *__formal,
        unsigned int *task_threads_per_core)
{
  vostok::tasks::thread_tls *m_begin; // esi
  vostok::tasks::thread_tls *m_end; // eax
  unsigned __int64 v7; // rax
  vostok::tasks::task *current_task; // ecx
  char v9; // cl
  char *m_buffer; // ecx
  const char *v11; // eax
  volatile int state; // eax
  const char *v13; // eax
  bool v14; // zf
  const char *v15; // eax
  const char *v16; // eax
  const char *v17; // eax
  const vostok::tasks::thread_tls *it_end; // [esp+10h] [ebp-114h]
  vostok::fixed_string<256> state_string; // [esp+14h] [ebp-110h] BYREF
  char v20; // [esp+120h] [ebp-4h] BYREF

  m_begin = tls_array->m_begin;
  m_end = tls_array->m_end;
  for ( it_end = m_end; m_begin != m_end; ++m_begin )
  {
    if ( m_begin->thread_name.m_end != m_begin->thread_name.m_begin )
    {
      if ( m_begin->last_task_end_tick )
        v7 = 1000
           * (vostok::timing::timer::get_elapsed_ticks(&this->m_timer) - m_begin->last_task_end_tick)
           / vostok::timing::g_qpc_per_second.QuadPart;
      else
        v7 = 0;
      current_task = m_begin->current_task;
      if ( current_task && current_task != &m_begin->user_thread_root_task || v7 < 0x64 )
      {
        ++__formal[m_begin->hardware_thread];
        v9 = 1;
      }
      else
      {
        v9 = 0;
      }
      if ( m_begin->state == 2 )
      {
        m_buffer = state_string.m_buffer;
        state_string.m_end = state_string.m_buffer;
        state_string.m_buffer[0] = 0;
        v11 = "SLEEP";
        do
        {
          if ( m_buffer >= &v20 )
            break;
          *m_buffer = *v11;
          m_buffer = state_string.m_end + 1;
          ++v11;
          ++state_string.m_end;
        }
        while ( *v11 );
      }
      else
      {
        state = m_begin->state;
        state_string.m_buffer[0] = 0;
        if ( state == 1 )
        {
          m_buffer = state_string.m_buffer;
          state_string.m_end = state_string.m_buffer;
          v13 = "IDLE ";
          do
          {
            if ( m_buffer >= &v20 )
              break;
            *m_buffer = *v13;
            m_buffer = state_string.m_end + 1;
            ++v13;
            ++state_string.m_end;
          }
          while ( *v13 );
        }
        else
        {
          v14 = v9 == 0;
          m_buffer = state_string.m_buffer;
          state_string.m_end = state_string.m_buffer;
          if ( v14 )
          {
            if ( m_begin->thread_type )
            {
              v17 = "USER ";
              do
              {
                if ( m_buffer >= &v20 )
                  break;
                *m_buffer = *v17;
                m_buffer = state_string.m_end + 1;
                ++v17;
                ++state_string.m_end;
              }
              while ( *v17 );
            }
            else
            {
              v16 = "TASK ";
              do
              {
                if ( m_buffer >= &v20 )
                  break;
                *m_buffer = *v16;
                m_buffer = state_string.m_end + 1;
                ++v16;
                ++state_string.m_end;
              }
              while ( *v16 );
            }
          }
          else
          {
            v15 = "TASK ";
            do
            {
              if ( m_buffer >= &v20 )
                break;
              *m_buffer = *v15;
              m_buffer = state_string.m_end + 1;
              ++v15;
              ++state_string.m_end;
            }
            while ( *v15 );
          }
        }
      }
      *m_buffer = 0;
      vostok::strings::text_tree_item::new_childf(
        stats,
        m_begin->thread_name.m_begin,
        "state(%s), hardware core(%d), executed(%d)",
        state_string.m_buffer,
        m_begin->hardware_thread,
        m_begin->executed_tasks_count);
      m_end = (vostok::tasks::thread_tls *)it_end;
    }
  }
}
