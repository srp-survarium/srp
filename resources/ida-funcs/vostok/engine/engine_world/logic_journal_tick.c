void __usercall vostok::engine::engine_world::logic_journal_tick(
        vostok::engine::engine_world *this@<ecx>,
        vostok::engine::engine_world *a2@<edi>)
{
  vostok::tasks *v2; // ecx
  vostok::tasks *v3; // ecx

  if ( a2->m_engine_user_world->is_loading(a2->m_engine_user_world) )
    vostok::threading::yield(0xAu, v2);
  do
  {
    vostok::engine::engine_world::logic_dispatch_callbacks(a2);
    a2->m_engine_user_world->on_waiting_for_render(a2->m_engine_user_world, a2->m_logic_frame_id);
  }
  while ( !a2->m_engine_user_world->tick(a2->m_engine_user_world, a2->m_logic_frame_id) );
  if ( ++a2->m_logic_frame_id <= a2->m_render_world->m_engine_renderer->m_render_engine_world->m_frame_id + 1
    || a2->m_destruction_started )
  {
    vostok::apc::try_process_single_call(logic);
  }
  else
  {
    while ( a2->m_logic_frame_id > a2->m_render_world->m_engine_renderer->m_render_engine_world->m_frame_id + 1
         && !a2->m_destruction_started )
    {
      vostok::engine::engine_world::logic_dispatch_callbacks(a2);
      vostok::threading::yield(1u, v3);
    }
  }
}
