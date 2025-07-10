void __thiscall vostok::engine::engine_world::initialize_logic_modules(vostok::engine::engine_world *this)
{
  vostok::engine_user::engine *v2; // eax
  vostok::engine_user::world *v3; // eax
  BOOL m_game_enabled; // ecx

  if ( this )
    v2 = &this->vostok::engine_user::engine;
  else
    v2 = 0;
  v3 = this->m_engine_user_module_proxy->create_world(
         this->m_engine_user_module_proxy,
         v2,
         this->m_render_world,
         this->m_sound_world,
         this->m_network_world);
  m_game_enabled = this->m_game_enabled;
  this->m_engine_user_world = v3;
  v3->enable(v3, m_game_enabled);
}
