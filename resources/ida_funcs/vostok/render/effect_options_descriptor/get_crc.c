unsigned int __usercall vostok::render::effect_options_descriptor::get_crc@<eax>(
        vostok::render::effect_options_descriptor *this@<ecx>,
        vostok::render::effect_options_descriptor *a2@<eax>)
{
  int num_total_fields; // edi
  unsigned int data_memory_usage; // eax
  unsigned int v5; // edi
  void *v6; // esp
  vostok::render::custom_config *v7; // eax
  vostok::render::custom_config *v8; // edi
  unsigned __int8 v10[16]; // [esp+0h] [ebp-20h] BYREF
  vostok::mutable_buffer mbuffer; // [esp+10h] [ebp-10h] BYREF
  unsigned int last_align_value; // [esp+18h] [ebp-8h] BYREF
  unsigned int crc; // [esp+1Ch] [ebp-4h] BYREF

  num_total_fields = vostok::render::effect_options_descriptor::get_num_total_fields(a2);
  crc = 0;
  last_align_value = 0;
  data_memory_usage = vostok::render::effect_options_descriptor::get_data_memory_usage(a2, &crc, &last_align_value);
  v5 = data_memory_usage + 20 * num_total_fields + 32 + crc;
  v6 = alloca(v5);
  boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
    &mbuffer,
    v10,
    v5);
  v7 = vostok::render::create_custom_config_impl_vostok::render::effect_options_descriptor_(a2, &mbuffer, &crc, 1);
  v8 = 0;
  if ( v7 )
  {
    v8 = v7;
    _InterlockedExchangeAdd(&v7->m_reference_count, 1u);
  }
  v8->own_buffer = 0;
  v8->call_destructors = 0;
  if ( !_InterlockedExchangeAdd(&v8->m_reference_count, 0xFFFFFFFF) )
    vostok::render::custom_config::destroy(v8, v8);
  return crc;
}
