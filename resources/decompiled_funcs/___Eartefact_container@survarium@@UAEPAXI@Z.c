survarium::artefact_container *__thiscall survarium::artefact_container::`vector deleting destructor'(
        survarium::artefact_container *this,
        char a2)
{
  survarium::artefact_base *m_object; // eax

  m_object = this->m_artefact.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_artefact.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_artefact.m_object);
  survarium::usable_object::~usable_object(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
