void __thiscall vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::set(
        vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *this,
        vostok::sound::sound_instance_proxy *object)
{
  vostok::sound::sound_instance_proxy *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object != object )
  {
    if ( m_object )
    {
      if ( m_object->m_reference_count-- == 1 )
        ((void (*)(void))this->m_object->free_object)();
    }
    this->m_object = object;
    if ( object )
      ++object->m_reference_count;
  }
}
