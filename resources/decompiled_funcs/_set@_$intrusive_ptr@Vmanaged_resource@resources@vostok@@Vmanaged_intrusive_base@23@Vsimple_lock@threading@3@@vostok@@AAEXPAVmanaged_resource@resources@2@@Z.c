void __thiscall vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *this,
        vostok::resources::managed_resource *object)
{
  vostok::resources::managed_resource *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object != object )
  {
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::managed_intrusive_base::destroy(
        &this->m_object->vostok::resources::managed_intrusive_base,
        this->m_object);
    this->m_object = object;
    if ( object )
      _InterlockedExchangeAdd(&object->m_reference_count, 1u);
  }
}
