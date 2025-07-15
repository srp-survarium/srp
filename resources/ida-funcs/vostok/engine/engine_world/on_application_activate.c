void __thiscall vostok::engine::engine_world::on_application_activate(vostok::engine::engine_world *this)
{
  bool v2; // zf
  vostok::sound::world *volatile m_sound_world; // ecx

  v2 = BYTE2(this->m_render_has_been_created) == 0;
  BYTE1(this->m_render_has_been_created) = 1;
  if ( v2 )
  {
    m_sound_world = this->m_sound_world;
    BYTE2(this->m_render_has_been_created) = 1;
    if ( m_sound_world )
      m_sound_world->__vftable[1].get_logic_world_user(m_sound_world);
    else
      BYTE2(this->m_render_has_been_created) = 0;
  }
}
