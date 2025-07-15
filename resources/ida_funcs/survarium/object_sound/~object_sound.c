void __thiscall survarium::object_sound::~object_sound(survarium::object_sound *this)
{
  vostok::sound::sound_instance_proxy *m_object; // eax
  vostok::sound::sound_emitter *v4; // eax

  this->__vftable = (survarium::object_sound_vtbl *)&survarium::object_sound::`vftable';
  m_object = this->m_sound_instance.m_object;
  if ( m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      this->m_sound_instance.m_object->free_object(this->m_sound_instance.m_object);
  }
  v4 = this->m_sound_emitter.m_object;
  if ( v4 && !_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_sound_emitter.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_sound_emitter.m_object);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
