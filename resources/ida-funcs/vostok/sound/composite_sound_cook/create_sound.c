vostok::sound::composite_sound *__thiscall vostok::sound::composite_sound_cook::create_sound(
        vostok::sound::composite_sound_cook *this,
        vostok::configs::binary_config_value *composite)
{
  vostok::configs::binary_config_value *v2; // eax
  const char *v3; // eax
  int v4; // eax
  vostok::sound::composite_sound *buffer; // [esp+2Ch] [ebp-10h]
  int sounds_buffer_size; // [esp+30h] [ebp-Ch]

  sounds_buffer_size = 0;
  if ( vostok::configs::binary_config_value::value_exists(composite, "sound_items") )
  {
    v2 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                   composite,
                                                   "sound_items");
    sounds_buffer_size = 12 * vostok::configs::binary_config_value::size(v2);
  }
  v3 = type_info::name(&char `RTTI Type Descriptor', &__type_info_root_node);
  buffer = (vostok::sound::composite_sound *)vostok::resources::allocate_unmanaged_memory(sounds_buffer_size + 288, v3);
  if ( !buffer )
    return 0;
  vostok::sound::composite_sound::composite_sound(
    buffer,
    &buffer[1],
    sounds_buffer_size,
    this->m_world->m_last_current_time_in_ms);
  return (vostok::sound::composite_sound *)v4;
}
