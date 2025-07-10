vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *__thiscall vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::operator=(
        vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *this,
        const vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *object)
{
  vostok::sound::sound_instance_proxy *m_object; // eax
  vostok::sound::sound_instance_proxy *v4; // ecx

  m_object = 0;
  if ( object->m_object )
  {
    m_object = object->m_object;
    ++object->m_object->m_reference_count;
  }
  v4 = this->m_object;
  this->m_object = m_object;
  if ( v4 )
  {
    if ( v4->m_reference_count-- == 1 )
      v4->free_object(v4);
  }
  return this;
}
