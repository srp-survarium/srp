unsigned int __cdecl vostok::render::get_config_data_memory_usage_vostok::render::custom_config_value_(
        const vostok::render::custom_config_value *value,
        unsigned int *last_align_value)
{
  unsigned int v2; // edi
  unsigned __int16 type; // ax
  int v4; // eax
  const vostok::render::custom_config_value *i; // esi

  v2 = 0;
  if ( value->id )
    v2 = strlen(value->id) + 1;
  type = value->type;
  if ( type == 3 || type == 4 )
  {
    for ( i = (const vostok::render::custom_config_value *)value->data;
          i != (const vostok::render::custom_config_value *)value->data + value->count;
          ++i )
    {
      v2 += vostok::render::get_config_data_memory_usage_vostok::render::custom_config_value_(i, last_align_value);
    }
  }
  else
  {
    if ( value->count > 4u || value->type == vostok::render::static_type::get_type_id<char const *>() )
      v2 += value->count;
    if ( (v2 & 3) != 0 )
    {
      v4 = 4 - (v2 & 3);
      *last_align_value = v4;
      return v4 + v2;
    }
  }
  return v2;
}
