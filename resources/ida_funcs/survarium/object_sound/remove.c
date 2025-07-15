void __thiscall survarium::object_sound::remove(survarium::object_sound *this)
{
  vostok::sound::sound_instance_proxy *m_object; // eax

  m_object = this->m_sound_instance.m_object;
  this->m_sound_instance.m_object = 0;
  if ( m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      m_object->free_object(m_object);
  }
}
