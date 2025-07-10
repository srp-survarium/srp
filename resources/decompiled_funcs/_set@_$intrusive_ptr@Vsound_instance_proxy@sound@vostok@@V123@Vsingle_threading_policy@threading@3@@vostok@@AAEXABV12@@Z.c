void __thiscall vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::set(
        vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *this,
        const vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *object)
{
  vostok::sound::sound_instance_proxy *m_object; // eax
  vostok::sound::sound_instance_proxy *v5; // eax

  m_object = this->m_object;
  if ( this->m_object != object->m_object )
  {
    if ( m_object )
    {
      if ( m_object->m_reference_count-- == 1 )
        ((void (*)(void))this->m_object->free_object)();
    }
    v5 = object->m_object;
    this->m_object = object->m_object;
    if ( v5 )
      ++v5->m_reference_count;
  }
}
