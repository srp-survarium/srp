unsigned int __cdecl vostok::render::get_data_crc_buffer_size_vostok::render::custom_config_value_(
        const vostok::render::custom_config_value *value)
{
  unsigned int v1; // edi
  unsigned __int16 type; // ax
  const vostok::render::custom_config_value *i; // esi

  v1 = 0;
  if ( value->id )
    v1 = strlen(value->id) + 1;
  type = value->type;
  if ( type != 3 && type != 4 )
    return value->count + v1;
  for ( i = (const vostok::render::custom_config_value *)value->data;
        i != (const vostok::render::custom_config_value *)value->data + value->count;
        ++i )
  {
    v1 += vostok::render::get_data_crc_buffer_size_vostok::render::custom_config_value_(i);
  }
  return v1;
}
