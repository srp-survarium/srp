void __thiscall vostok::engine::engine_world::logic(vostok::engine::engine_world *this)
{
  DWORD CurrentThreadId; // eax
  boost::function0<bool> *m_begin; // ecx
  vostok::tasks *v4; // ecx
  vostok::engine::engine_world *v5; // ecx
  vostok::tasks *v6; // [esp-4h] [ebp-10h]

  CurrentThreadId = GetCurrentThreadId();
  m_begin = (boost::function0<bool> *)g_threads.m_begin;
  g_threads.m_begin[1].m_thread_id = CurrentThreadId;
  vostok::apc::process(logic, m_begin, 1);
  v4 = v6;
  while ( !this->m_destruction_started )
  {
    if ( vostok::core::journal_usage() == replay_journal )
    {
      vostok::engine::engine_world::logic_journal_tick(v5, this);
    }
    else
    {
      vostok::engine::engine_world::logic_tick(v5, this);
      if ( this->m_logic_frame_id <= this->m_render_world->m_engine_renderer->m_render_engine_world->m_frame_id + 1
        || this->m_destruction_started )
      {
        vostok::apc::try_process_single_call(logic);
      }
      else
      {
        do
        {
          vostok::engine::engine_world::logic_dispatch_callbacks(this);
          this->m_engine_user_world->on_waiting_for_render(this->m_engine_user_world, this->m_logic_frame_id);
          if ( !this->m_game_enabled || this->m_last_game_enabled_value )
          {
            if ( !vostok::apc::try_process_single_call(logic) )
              vostok::threading::yield(1u, v4);
          }
          else
          {
            --this->m_logic_frame_id;
          }
        }
        while ( this->m_logic_frame_id > this->m_render_world->m_engine_renderer->m_render_engine_world->m_frame_id + 1
             && !this->m_destruction_started );
      }
    }
  }
  vostok::apc::process(logic, (boost::function0<bool> *)v4, 1);
}
