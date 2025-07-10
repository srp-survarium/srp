vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *__usercall vostok::render::create_custom_config@<eax>(
        unsigned int *out_data_crc@<eax>,
        unsigned int *a2@<esi>,
        vostok::render::effect_options_descriptor *value)
{
  vostok::render::create_custom_config_impl_vostok::render::effect_options_descriptor__0(value, a2, out_data_crc);
  return (vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)a2;
}
