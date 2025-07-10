void __thiscall vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>(
        vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *this)
{
  if ( this->m_object && !_InterlockedExchangeAdd(&this->m_object->m_reference_count, 0xFFFFFFFF) )
  {
    if ( this->m_object )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &this->m_object->vostok::resources::unmanaged_intrusive_base,
        &this->m_object->vostok::resources::unmanaged_resource);
    else
      vostok::resources::unmanaged_intrusive_base::destroy((vostok::resources::unmanaged_intrusive_base *)0x1F0, 0);
  }
}
