void __thiscall vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this,
        const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *object)
{
  vostok::configs::binary_config *m_object; // eax
  vostok::configs::binary_config *v4; // eax

  m_object = this->m_object;
  if ( this->m_object != object->m_object )
  {
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &this->m_object->vostok::resources::unmanaged_intrusive_base,
        this->m_object);
    v4 = object->m_object;
    this->m_object = object->m_object;
    if ( v4 )
      _InterlockedExchangeAdd(&v4->m_reference_count, 1u);
  }
}
