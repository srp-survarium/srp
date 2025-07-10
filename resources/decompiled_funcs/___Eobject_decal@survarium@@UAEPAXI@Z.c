survarium::object_decal *__thiscall survarium::object_decal::`vector deleting destructor'(
        survarium::object_decal *this,
        char a2)
{
  vostok::resources::unmanaged_resource *m_object; // eax

  this->__vftable = (survarium::object_decal_vtbl *)&survarium::object_decal::`vftable';
  m_object = this->m_material.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_material.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_material.m_object);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
