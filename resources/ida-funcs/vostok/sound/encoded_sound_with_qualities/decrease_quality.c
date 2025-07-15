void __thiscall vostok::sound::encoded_sound_with_qualities::decrease_quality(
        vostok::sound::encoded_sound_with_qualities *this,
        unsigned int new_best_quality)
{
  unsigned int child_quality; // [esp+34h] [ebp-8h]
  unsigned int i; // [esp+38h] [ebp-4h]

  for ( i = 0; i < 2; ++i )
  {
    child_quality = vostok::resources::resource_quality::child_quality(this, this->m_qualities[i].m_object);
    if ( child_quality != -1 && child_quality < new_best_quality )
      vostok::resources::child_resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base>::set_zero(&this->m_qualities[i]);
  }
}
