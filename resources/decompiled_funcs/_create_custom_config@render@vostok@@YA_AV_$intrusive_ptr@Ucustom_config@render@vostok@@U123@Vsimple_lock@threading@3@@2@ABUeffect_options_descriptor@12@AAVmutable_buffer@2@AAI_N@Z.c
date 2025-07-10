vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *__usercall vostok::render::create_custom_config@<eax>(
        vostok::render::custom_config_value *value@<ecx>,
        vostok::mutable_buffer *data_buffer@<esi>,
        unsigned int *out_data_crc@<eax>,
        vostok::render::custom_config **a4@<edi>)
{
  vostok::render::custom_config *v4; // eax

  v4 = vostok::render::create_custom_config_impl_vostok::render::effect_options_descriptor_(
         data_buffer,
         value,
         out_data_crc,
         1);
  *a4 = 0;
  if ( v4 )
  {
    *a4 = v4;
    _InterlockedExchangeAdd(&v4->m_reference_count, 1u);
  }
  return (vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)a4;
}
