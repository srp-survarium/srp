int __usercall vostok::render::get_num_config_fields_vostok::render::custom_config_value_@<eax>(
        const vostok::render::custom_config_value *value@<eax>)
{
  unsigned __int16 type; // cx
  int v2; // edi
  const vostok::render::custom_config_value *data; // esi
  const vostok::render::custom_config_value *v4; // ebx

  type = value->type;
  v2 = 0;
  if ( type == 3 || type == 4 )
  {
    data = (const vostok::render::custom_config_value *)value->data;
    v4 = &data[value->count];
    while ( data != v4 )
      v2 += vostok::render::get_num_config_fields_impl_vostok::render::custom_config_value_(data++);
  }
  return v2;
}
