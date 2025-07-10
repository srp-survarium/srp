void __thiscall vostok::engine::engine_world::tick(vostok::engine::engine_world *this)
{
  vostok::resources::resources_manager *v2; // ecx
  vostok::resources::resources_manager *v3; // ecx
  vostok::resources::resources_manager *v4; // ecx
  vostok::render::world *m_render_world; // esi
  vostok::render::one_way_render_channel *m_is_logic_frame_ended; // ecx
  vostok::threading *v7; // [esp+0h] [ebp-10h]

  if ( vostok::threading::g_debug_single_thread.m_type == type_unset )
  {
    vostok::threading::g_debug_single_thread.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  if ( vostok::threading::g_debug_single_thread.m_type != type_recursive )
    vostok::resources::tick((vostok::resources::resources_manager *)this);
  vostok::resources::dispatch_callbacks((vostok::resources::resources_manager *)this);
  if ( vostok::threading::g_debug_single_thread.m_type == type_unset )
  {
    vostok::threading::g_debug_single_thread.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  if ( vostok::threading::g_debug_single_thread.m_type != type_recursive )
  {
    vostok::resources::dispatch_callbacks(v2);
    this->m_sound_world->tick(this->m_sound_world);
    vostok::resources::dispatch_callbacks(v3);
    this->m_network_world->tick(this->m_network_world, 0);
  }
  if ( !s_logical_core_count )
    vostok::threading::initialize_core_count(v7);
  if ( s_logical_core_count == 1 )
  {
    vostok::engine::engine_world::logic_tick((vostok::engine::engine_world *)v2, (int)this);
    vostok::resources::dispatch_callbacks(v4);
  }
  m_render_world = this->m_render_world;
  m_is_logic_frame_ended = (vostok::render::one_way_render_channel *)m_render_world->m_is_logic_frame_ended;
  if ( !m_is_logic_frame_ended )
    vostok::render::one_way_render_channel::render_process_commands(0, 1);
  if ( !m_render_world->m_is_editor_frame_ended )
    vostok::render::one_way_render_channel::render_process_commands(m_is_logic_frame_ended, 1);
}
