vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *__usercall vostok::render::create_custom_config@<eax>(
        unsigned int *out_data_crc@<eax>,
        vostok::render::custom_config **a2@<ecx>,
        const vostok::configs::binary_config_value *value)
{
  vostok::render::create_custom_config_impl_vostok::configs::binary_config_value__0(value, a2, out_data_crc);
  return (vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)a2;
}
