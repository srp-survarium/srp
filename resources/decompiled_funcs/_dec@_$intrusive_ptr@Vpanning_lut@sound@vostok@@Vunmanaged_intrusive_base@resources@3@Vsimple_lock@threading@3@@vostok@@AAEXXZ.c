void __thiscall vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(
        vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this)
{
  if ( this->m_object )
  {
    if ( !_InterlockedDecrement(&this->m_object->m_reference_count) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &this->m_object->vostok::resources::unmanaged_intrusive_base,
        this->m_object);
  }
}
