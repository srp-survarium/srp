void __thiscall vostok::engine::engine_world::on_application_activate(vostok::engine::engine_world *this)
{
  bool v2; // zf
  vostok::sound::world *volatile m_sound_world; // ecx

  v2 = BYTE2(this->m_resources_cooker_destruction_started) == 0;
  BYTE1(this->m_resources_cooker_destruction_started) = 1;
  if ( v2 )
  {
    BYTE2(this->m_resources_cooker_destruction_started) = 1;
    m_sound_world = this->m_sound_world;
    if ( m_sound_world )
      m_sound_world->get_calculation_type(m_sound_world);
    else
      BYTE2(this->m_resources_cooker_destruction_started) = 0;
  }
}
