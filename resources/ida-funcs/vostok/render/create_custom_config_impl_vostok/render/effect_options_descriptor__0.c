vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *__usercall vostok::render::create_custom_config_impl_vostok::render::effect_options_descriptor__0@<eax>(
        vostok::render::effect_options_descriptor *value@<eax>,
        unsigned int *out_data_crc,
        unsigned int *is_calc_data_crc)
{
  unsigned int *v3; // ebx
  int num_total_fields; // edi
  unsigned int data_memory_usage; // eax
  unsigned __int8 *v7; // eax
  vostok::render::custom_config *v8; // eax
  unsigned int v10; // [esp-4h] [ebp-20h]
  unsigned int last_align_value; // [esp+Ch] [ebp-10h] BYREF
  vostok::mutable_buffer b; // [esp+10h] [ebp-Ch] BYREF

  v3 = out_data_crc;
  num_total_fields = vostok::render::effect_options_descriptor::get_num_total_fields(value);
  out_data_crc = 0;
  last_align_value = 0;
  data_memory_usage = vostok::render::effect_options_descriptor::get_data_memory_usage(
                        value,
                        (unsigned int *)&out_data_crc,
                        &last_align_value);
  v10 = 2 * ((_DWORD)&out_data_crc[5 * num_total_fields + 8] + data_memory_usage);
  v7 = (unsigned __int8 *)vostok::memory::doug_lea_allocator::malloc_impl(
                            (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                            v10);
  boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
    &b,
    v7,
    v10);
  v8 = vostok::render::create_custom_config_impl_vostok::render::effect_options_descriptor_(
         &b,
         (vostok::render::custom_config_value *)value,
         is_calc_data_crc,
         0);
  v8->own_buffer = 1;
  *v3 = (unsigned int)v8;
  _InterlockedExchangeAdd(&v8->m_reference_count, 1u);
  return (vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)v3;
}
