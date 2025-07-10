void __thiscall vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        vostok::intrusive_ptr<vostok::sound::sound_spl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this,
        vostok::sound::sound_spl *object)
{
  if ( this->m_object != object )
  {
    vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this);
    this->m_object = object;
    if ( this->m_object )
      _InterlockedExchangeAdd(&this->m_object->m_reference_count, 1u);
  }
}
