survarium::victory_item *__thiscall survarium::victory_item::`vector deleting destructor'(
        survarium::victory_item *this,
        char a2)
{
  vostok::render::static_model_instance *m_object; // eax

  m_object = this->m_model.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_model.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_model.m_object);
  survarium::victory_item_core::~victory_item_core(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
