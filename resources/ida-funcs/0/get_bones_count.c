int __cdecl get_bones_count(const vostok::configs::binary_config_value *value, unsigned int *bones_ids_buffer_length)
{
  const char *pointer; // eax
  const vostok::configs::binary_config_value *v3; // edi
  int v4; // ebx
  const vostok::configs::binary_config_value *v5; // esi

  pointer = value->id.pointer;
  if ( pointer )
    *bones_ids_buffer_length += strlen(pointer) + 1;
  v3 = (const vostok::configs::binary_config_value *)value->data.pointer;
  v4 = 0;
  v5 = (const vostok::configs::binary_config_value *)((char *)value->data.pointer + 24 * value->count);
  while ( v3 != v5 )
  {
    if ( is_table(v3) )
      v4 += get_bones_count(v3, bones_ids_buffer_length) + 1;
    ++v3;
  }
  return v4;
}
