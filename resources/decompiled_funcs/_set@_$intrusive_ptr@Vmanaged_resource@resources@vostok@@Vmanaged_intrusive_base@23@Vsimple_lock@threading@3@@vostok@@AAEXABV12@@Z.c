void __thiscall vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *this,
        const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *object)
{
  vostok::resources::managed_resource *m_object; // eax
  vostok::resources::managed_resource *v4; // eax

  m_object = this->m_object;
  if ( this->m_object != object->m_object )
  {
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::managed_intrusive_base::destroy(
        &this->m_object->vostok::resources::managed_intrusive_base,
        this->m_object);
    v4 = object->m_object;
    this->m_object = object->m_object;
    if ( v4 )
      _InterlockedExchangeAdd(&v4->m_reference_count, 1u);
  }
}
