void __thiscall vostok::engine::engine_world::tick(vostok::engine::engine_world *this)
{
  vostok::command_line::key *v2; // ecx
  vostok::command_line::key *v3; // ecx
  vostok::command_line::key *v4; // ecx
  vostok::engine::engine_world *v5; // ecx
  vostok::render::world *m_render_world; // edi

  if ( vostok::command_line::key::is_set(
         (vostok::command_line::key *)this,
         (int)&vostok::threading::g_debug_single_thread) )
  {
    vostok::resources::tick(v2);
  }
  vostok::resources::dispatch_callbacks(v2);
  if ( vostok::command_line::key::is_set(v3, (int)&vostok::threading::g_debug_single_thread) )
  {
    vostok::resources::dispatch_callbacks(v4);
    this->m_sound_world->tick(this->m_sound_world);
    vostok::engine::engine_world::network_tick(this);
  }
  if ( vostok::threading::core_count(v4) == 1 )
    vostok::engine::engine_world::logic_tick(v5, this);
  m_render_world = this->m_render_world;
  if ( !m_render_world->m_is_logic_frame_ended )
    vostok::render::one_way_render_channel::render_process_commands(
      (vostok::render::one_way_render_channel *)v5,
      (int)m_render_world,
      1);
  if ( !m_render_world->m_is_editor_frame_ended )
    vostok::render::one_way_render_channel::render_process_commands(
      (vostok::render::one_way_render_channel *)v5,
      (int)&m_render_world->m_editor_channel,
      1);
}
