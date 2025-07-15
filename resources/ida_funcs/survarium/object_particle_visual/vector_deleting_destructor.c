survarium::object_particle_visual *__thiscall survarium::object_particle_visual::`vector deleting destructor'(
        survarium::object_particle_visual *this,
        char a2)
{
  vostok::resources::unmanaged_resource *m_object; // eax

  m_object = this->m_particle_system_instance_ptr.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_particle_system_instance_ptr.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_particle_system_instance_ptr.m_object);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
