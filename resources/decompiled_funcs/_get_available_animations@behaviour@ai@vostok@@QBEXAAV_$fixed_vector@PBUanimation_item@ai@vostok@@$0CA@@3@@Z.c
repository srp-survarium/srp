void __thiscall vostok::ai::behaviour::get_available_animations(
        vostok::ai::behaviour *this,
        vostok::buffer_vector<void const *> *destination)
{
  const vostok::ai::animation_item *it; // [esp+1Ch] [ebp-Ch] BYREF
  const vostok::ai::animation_item *it_begin; // [esp+20h] [ebp-8h]
  const vostok::ai::animation_item *it_end; // [esp+24h] [ebp-4h]

  it_begin = (const vostok::ai::animation_item *)&this[1];
  it_end = (const vostok::ai::animation_item *)((char *)&this[1] + 280 * this->m_animations_count);
  for ( it = (const vostok::ai::animation_item *)&this[1]; it != it_end; ++it )
  {
    if ( (unsigned int)(destination->m_end - destination->m_begin) < 0x20 )
      vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(destination, (const void **)&it);
  }
}
