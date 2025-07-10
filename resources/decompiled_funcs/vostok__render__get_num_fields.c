int __cdecl vostok::render::get_num_fields(const vostok::render::custom_config_value *value)
{
  unsigned __int16 type; // ax
  int v2; // ebx
  const vostok::render::custom_config_value *i; // esi

  type = value->type;
  v2 = 1;
  if ( type == 3 || type == 4 )
  {
    for ( i = (const vostok::render::custom_config_value *)value->data;
          i != (const vostok::render::custom_config_value *)value->data + value->count;
          ++i )
    {
      v2 += vostok::render::get_num_fields(i);
    }
  }
  return v2;
}
