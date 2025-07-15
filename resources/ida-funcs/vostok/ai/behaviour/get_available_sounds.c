void __thiscall vostok::ai::behaviour::get_available_sounds(
        vostok::ai::behaviour *this,
        vostok::buffer_vector<void const *> *destination)
{
  const vostok::ai::sound_item *it; // [esp+24h] [ebp-Ch] BYREF
  const vostok::ai::sound_item *it_begin; // [esp+28h] [ebp-8h]
  const vostok::ai::sound_item *it_end; // [esp+2Ch] [ebp-4h]

  it_begin = (const vostok::ai::sound_item *)((char *)&this[1] + 280 * this->m_animations_count);
  it_end = &it_begin[this->m_sounds_count];
  for ( it = it_begin; it != it_end; ++it )
  {
    if ( (unsigned int)(destination->m_end - destination->m_begin) < 0x20 )
      vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(destination, (const void **)&it);
  }
}
