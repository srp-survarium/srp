void __thiscall survarium::dictionary_item::~dictionary_item(survarium::dictionary_item *this)
{
  vostok::configs::binary_config *m_object; // eax

  m_object = this->item_cfg.m_object;
  if ( m_object )
  {
    if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &this->item_cfg.m_object->vostok::resources::unmanaged_intrusive_base,
        this->item_cfg.m_object);
  }
}
