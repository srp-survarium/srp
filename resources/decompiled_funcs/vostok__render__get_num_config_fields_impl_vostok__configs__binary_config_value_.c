int __cdecl vostok::render::get_num_config_fields_impl_vostok::configs::binary_config_value_(
        const vostok::configs::binary_config_value *value)
{
  unsigned __int16 type; // ax
  int v2; // ebx
  const vostok::configs::binary_config_value *i; // esi

  type = value->type;
  v2 = 1;
  if ( type == 3 || type == 4 )
  {
    for ( i = (const vostok::configs::binary_config_value *)value->data.pointer;
          i != (const vostok::configs::binary_config_value *)value->data.pointer + value->count;
          ++i )
    {
      v2 += vostok::render::get_num_config_fields_impl_vostok::configs::binary_config_value_(i);
    }
  }
  return v2;
}
