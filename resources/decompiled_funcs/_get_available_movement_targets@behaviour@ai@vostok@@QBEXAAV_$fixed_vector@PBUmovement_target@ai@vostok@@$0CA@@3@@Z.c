void __thiscall vostok::ai::behaviour::get_available_movement_targets(
        vostok::ai::behaviour *this,
        vostok::buffer_vector<void const *> *destination)
{
  const vostok::ai::movement_target *it; // [esp+2Ch] [ebp-Ch] BYREF
  const vostok::ai::movement_target *it_begin; // [esp+30h] [ebp-8h]
  const vostok::ai::movement_target *it_end; // [esp+34h] [ebp-4h]

  it_begin = vostok::ai::behaviour::get_movement_targets(this);
  it_end = &it_begin[this->m_movement_targets_count];
  for ( it = it_begin; it != it_end; ++it )
  {
    if ( (unsigned int)(destination->m_end - destination->m_begin) < 0x20 )
      vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(destination, (const void **)&it);
  }
}
