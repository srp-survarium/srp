void __thiscall vostok::engine::engine_world::on_application_deactivate(vostok::engine::engine_world *this)
{
  bool v2; // zf

  v2 = BYTE2(this->m_resources_cooker_destruction_started) == 0;
  BYTE1(this->m_resources_cooker_destruction_started) = 0;
  if ( !v2 )
  {
    this->m_sound_world->~vostok::sound::world(this->m_sound_world);
    BYTE2(this->m_resources_cooker_destruction_started) = 0;
  }
}
