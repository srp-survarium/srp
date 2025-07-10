void __thiscall survarium::ai_sound_player::clear_resources(survarium::ai_sound_player *this)
{
  vostok::sound::sound_instance_proxy *m_object; // eax

  m_object = this->m_active_sound.m_object;
  this->m_active_sound.m_object = 0;
  if ( m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      m_object->free_object(m_object);
  }
}
