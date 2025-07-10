void __thiscall survarium::text_translator::~text_translator(survarium::text_translator *this)
{
  if ( this->m_text_data.m_object )
  {
    if ( !_InterlockedExchangeAdd(&this->m_text_data.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &this->m_text_data.m_object->vostok::resources::unmanaged_intrusive_base,
        this->m_text_data.m_object);
  }
}
