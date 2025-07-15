int __usercall vostok::render::get_num_config_fields_vostok::configs::binary_config_value_@<eax>(
        const vostok::configs::binary_config_value *value@<eax>)
{
  unsigned __int16 type; // cx
  int v2; // edi
  const vostok::configs::binary_config_value *pointer; // esi
  const vostok::configs::binary_config_value *v4; // ebx

  type = value->type;
  v2 = 0;
  if ( type == 3 || type == 4 )
  {
    pointer = (const vostok::configs::binary_config_value *)value->data.pointer;
    v4 = (const vostok::configs::binary_config_value *)((char *)value->data.pointer + 24 * value->count);
    while ( pointer != v4 )
      v2 += vostok::render::get_num_config_fields_impl_vostok::configs::binary_config_value_(pointer++);
  }
  return v2;
}
