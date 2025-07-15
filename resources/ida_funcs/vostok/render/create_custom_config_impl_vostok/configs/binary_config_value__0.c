vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *__usercall vostok::render::create_custom_config_impl_vostok::configs::binary_config_value__0@<eax>(
        const vostok::configs::binary_config_value *value@<eax>,
        vostok::render::custom_config **a2@<edi>,
        unsigned int *out_data_crc)
{
  int v4; // ebx
  unsigned __int8 *v5; // eax
  vostok::render::custom_config *v6; // eax
  unsigned int v8; // [esp-4h] [ebp-1Ch]
  unsigned int last_align_value; // [esp+Ch] [ebp-Ch] BYREF
  vostok::mutable_buffer b; // [esp+10h] [ebp-8h] BYREF

  last_align_value = 0;
  v4 = 20 * vostok::render::get_num_config_fields_vostok::configs::binary_config_value_(value) + 32;
  v8 = 2
     * (v4 + vostok::render::get_config_data_memory_usage_vostok::configs::binary_config_value_(
               value,
               &last_align_value));
  v5 = (unsigned __int8 *)vostok::memory::doug_lea_allocator::malloc_impl(
                            (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                            v8);
  boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
    &b,
    v5,
    v8);
  v6 = vostok::render::create_custom_config_impl_vostok::configs::binary_config_value_(&b, value, out_data_crc);
  v6->own_buffer = 1;
  *a2 = v6;
  _InterlockedExchangeAdd(&v6->m_reference_count, 1u);
  return (vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)a2;
}
