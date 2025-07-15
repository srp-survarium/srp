void __usercall vostok::engine::engine_world::logic_tick(
        vostok::engine::engine_world *this@<ecx>,
        vostok::engine::engine_world *a2@<edi>)
{
  vostok::tasks *v2; // ecx
  bool m_game_enabled; // al

  if ( a2->m_engine_user_world->is_loading(a2->m_engine_user_world) )
    vostok::threading::yield(0xAu, v2);
  vostok::engine::engine_world::logic_dispatch_callbacks(a2);
  m_game_enabled = a2->m_game_enabled;
  a2->m_last_game_enabled_value = m_game_enabled;
  if ( m_game_enabled && a2->is_application_active(&a2->vostok::editor::engine) )
  {
    a2->m_engine_user_world->tick(a2->m_engine_user_world, a2->m_logic_frame_id);
    ++a2->m_logic_frame_id;
  }
  else
  {
    if ( !a2->m_game_enabled )
      ++a2->m_logic_frame_id;
    a2->m_engine_user_world->on_waiting_for_render(a2->m_engine_user_world, a2->m_logic_frame_id);
  }
}
