void __thiscall vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *this)
{
  if ( this->m_object )
  {
    if ( !_InterlockedExchangeAdd(&this->m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::managed_intrusive_base::destroy(
        &this->m_object->vostok::resources::managed_intrusive_base,
        this->m_object);
  }
}
