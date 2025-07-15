void __thiscall vostok::engine::engine_world::enable_game_in_logic_thread(
        vostok::engine::engine_world *this,
        BOOL value)
{
  volatile __int32 *p_m_is_logic_enabled; // ecx

  p_m_is_logic_enabled = &this->m_render_world->m_is_logic_enabled;
  _InterlockedExchange(p_m_is_logic_enabled, value);
  if ( !value )
    vostok::render::game::renderer::end_frame(
      (vostok::render::game::renderer *)p_m_is_logic_enabled,
      (int)this->m_render_world->m_game_renderer);
  if ( this->m_engine_user_world )
    this->m_engine_user_world->enable(this->m_engine_user_world, value);
}
