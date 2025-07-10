int __cdecl get_bones_count(const vostok::configs::binary_config_value *value, unsigned int *bones_ids_buffer_length)
{
  const vostok::configs::binary_config_value *pointer; // esi
  char *v3; // ebx
  int v4; // edi
  unsigned __int16 type; // ax

  if ( vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&value->id) )
    *bones_ids_buffer_length += strlen((const char *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&value->id))
                              + 1;
  pointer = (const vostok::configs::binary_config_value *)value->data.pointer;
  v3 = (char *)value->data.pointer + 24 * value->count;
  v4 = 0;
  if ( value->data.pointer != v3 )
  {
    do
    {
      type = pointer->type;
      if ( type == 3 || type == 4 )
        v4 += get_bones_count(pointer, bones_ids_buffer_length) + 1;
      ++pointer;
    }
    while ( pointer != (const vostok::configs::binary_config_value *)v3 );
  }
  return v4;
}
