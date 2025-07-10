char __thiscall vostok::sound::encoded_sound_with_qualities::add_quality(
        vostok::sound::encoded_sound_with_qualities *this,
        vostok::resources::resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base> child,
        unsigned int quality)
{
  unsigned int i; // [esp+38h] [ebp-4h]

  for ( i = 0; i < 2; ++i )
  {
    if ( !this->m_qualities[i].m_object )
    {
      vostok::resources::child_resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base>::initialize_as_quality<vostok::sound::encoded_sound_with_qualities>(
        &this->m_qualities[i],
        this,
        child.m_object,
        quality);
      vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&child);
      return 1;
    }
  }
  vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&child);
  return 0;
}
