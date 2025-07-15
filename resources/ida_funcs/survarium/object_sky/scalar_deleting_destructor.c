survarium::object_sky *__thiscall survarium::object_sky::`scalar deleting destructor'(
        survarium::object_sky *this,
        char a2)
{
  vostok::resources::unmanaged_resource *m_object; // eax

  this->__vftable = (survarium::object_sky_vtbl *)&survarium::object_sky::`vftable';
  m_object = this->m_sky_material.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_sky_material.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_sky_material.m_object);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
