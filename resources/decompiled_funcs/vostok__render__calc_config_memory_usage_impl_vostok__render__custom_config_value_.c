unsigned int __usercall vostok::render::calc_config_memory_usage_impl_vostok::render::custom_config_value_@<eax>(
        const vostok::render::custom_config_value *value@<esi>)
{
  int v1; // edi
  unsigned int last_align_value; // [esp+4h] [ebp-4h] BYREF

  last_align_value = 0;
  v1 = 20 * vostok::render::get_num_config_fields_vostok::render::custom_config_value_(value) + 32;
  return v1
       + vostok::render::get_config_data_memory_usage_vostok::render::custom_config_value_(value, &last_align_value);
}
