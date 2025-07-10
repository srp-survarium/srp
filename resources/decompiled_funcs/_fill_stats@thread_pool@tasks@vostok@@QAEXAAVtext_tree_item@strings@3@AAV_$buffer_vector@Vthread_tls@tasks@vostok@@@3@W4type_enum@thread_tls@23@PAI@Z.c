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
