void __usercall vostok::render::renderer::execute_stages(
        vostok::render::renderer *this@<ecx>,
        vostok::timing::timer *a2@<esi>)
{
  vostok::render::stage **m_current_time; // eax
  unsigned int *dips; // edi
  vostok::render::stage *v4; // ebx
  LARGE_INTEGER v5; // rax
  double elapsed_sec; // st7
  survarium::game *m_game; // eax
  vostok::render::stage **it; // [esp+10h] [ebp-10h]
  unsigned int prev_draw_calls; // [esp+14h] [ebp-Ch]
  LARGE_INTEGER PerformanceCount; // [esp+18h] [ebp-8h] BYREF

  if ( s_execute_stages )
  {
    if ( s_do_stages_profiling )
    {
      (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                         + 112))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        *(_DWORD *)LODWORD(a2[4].m_current_time));
      vostok::render::event_query::wait((vostok::render::event_query *)a2[4].m_current_time, a2[4].m_current_time);
    }
    m_current_time = (vostok::render::stage **)a2[9].m_current_time;
    it = m_current_time;
    if ( m_current_time != (vostok::render::stage **)HIDWORD(a2[9].m_current_time) )
    {
      dips = s_render_stages[0].dips;
      do
      {
        v4 = *m_current_time;
        dips[1] = (unsigned int)*m_current_time;
        if ( v4 )
        {
          prev_draw_calls = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                            + 25);
          if ( s_do_stages_profiling )
          {
            if ( vostok::timing::g_cpu_supports_time_stamp )
            {
              v5.QuadPart = __rdtsc();
            }
            else
            {
              QueryPerformanceCounter(&PerformanceCount);
              v5 = PerformanceCount;
            }
            a2[3].m_start_time = v5.QuadPart;
            LODWORD(a2[3].m_current_time) = 0;
            HIDWORD(a2[3].m_current_time) = 0;
          }
          v4->execute(v4);
          if ( s_do_stages_profiling )
          {
            *dips = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                    + 25)
                  - prev_draw_calls;
            elapsed_sec = vostok::timing::timer::get_elapsed_sec(a2 + 3);
            m_game = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game;
            *((double *)dips - 1) = elapsed_sec * 1000.0;
            (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)m_game->m_game_world.m_mouse_pos.y + 112))(
              m_game->m_game_world.m_mouse_pos.y,
              *(_DWORD *)LODWORD(a2[4].m_current_time));
            vostok::render::event_query::wait((vostok::render::event_query *)a2[4].m_current_time, a2[4].m_current_time);
            *((double *)dips - 2) = vostok::timing::timer::get_elapsed_sec(a2 + 3) * 1000.0;
          }
          m_current_time = it;
        }
        ++m_current_time;
        dips += 6;
        it = m_current_time;
      }
      while ( m_current_time != (vostok::render::stage **)HIDWORD(a2[9].m_current_time) );
    }
  }
}
