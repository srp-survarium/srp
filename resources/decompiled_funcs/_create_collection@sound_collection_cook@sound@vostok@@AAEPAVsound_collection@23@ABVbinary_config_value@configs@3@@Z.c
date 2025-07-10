vostok::sound::sound_collection *__thiscall vostok::sound::sound_collection_cook::create_collection(
        vostok::sound::sound_collection_cook *this,
        vostok::configs::binary_config_value *collection)
{
  vostok::configs::binary_config_value *v2; // eax
  const char *v3; // eax
  int v4; // eax
  unsigned int v7; // [esp+4h] [ebp-90h]
  int v8; // [esp+Ch] [ebp-88h]
  vostok::configs::binary_config_value *v10; // [esp+40h] [ebp-54h]
  unsigned __int16 cyclic_repeating_index; // [esp+74h] [ebp-20h]
  vostok::sound::sound_collection *buffer; // [esp+78h] [ebp-1Ch]
  bool can_repeat_successively; // [esp+8Fh] [ebp-5h]

  v8 = strcmp(
         (const char *)vostok::configs::binary_config_value::operator[](collection, "type")->data.pointer,
         "random");
  can_repeat_successively = vostok::configs::binary_config_value::operator[](
                              collection,
                              "dont_repeat_sound_successively")->data.pointer != 0;
  v10 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                  collection,
                                                  "cyclic_repeat_from_sound");
  cyclic_repeating_index = vostok::configs::binary_config_value::cast_number<unsigned short,unsigned __int64,unsigned int>(v10);
  if ( vostok::configs::binary_config_value::value_exists(collection, "sound_items") )
  {
    v2 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                   collection,
                                                   "sound_items");
    v7 = vostok::configs::binary_config_value::size(v2);
  }
  else
  {
    v7 = 0;
  }
  v3 = type_info::name(&char `RTTI Type Descriptor', &__type_info_root_node);
  buffer = (vostok::sound::sound_collection *)vostok::resources::allocate_unmanaged_memory(4 * v7 + 304, v3);
  if ( !buffer )
    return 0;
  vostok::sound::sound_collection::sound_collection(
    buffer,
    (vostok::sound::collection_playback_types)(v8 != 0),
    can_repeat_successively,
    cyclic_repeating_index,
    &buffer[1],
    v7,
    this->m_world->m_last_current_time_in_ms);
  return (vostok::sound::sound_collection *)v4;
}
