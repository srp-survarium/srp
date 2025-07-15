void __thiscall survarium::object_sky::~object_sky(survarium::object_sky *this)
{
  vostok::resources::unmanaged_resource *m_object; // eax

  this->__vftable = (survarium::object_sky_vtbl *)&survarium::object_sky::`vftable';
  m_object = this->m_sky_material.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_sky_material.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_sky_material.m_object);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
