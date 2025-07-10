unsigned int __cdecl vostok::render::calc_data_crc_vostok::render::custom_config_value_(
        const vostok::render::custom_config_value *value)
{
  unsigned int v1; // esi
  void *v2; // esp
  unsigned __int8 v4[12]; // [esp+0h] [ebp-1Ch] BYREF
  vostok::mutable_buffer buffer; // [esp+Ch] [ebp-10h] BYREF
  boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> v6; // [esp+14h] [ebp-8h] BYREF

  v1 = vostok::render::get_data_crc_buffer_size_vostok::render::custom_config_value_(value);
  v2 = alloca(v1);
  boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
    &buffer,
    v4,
    v1);
  vostok::render::fill_data_crc_buffer_vostok::render::custom_config_value_(value, &buffer);
  v6.rem_ = boost::detail::crc_helper<32,1>::reflect(0xFFFFFFFF);
  boost::detail::crc_table_t<32,79764919,1>::init_table();
  boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>::process_block(&v6, v4, &v4[v1]);
  return ~v6.rem_;
}
