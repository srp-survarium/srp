void __thiscall vostok::network_core::tcp_packet_client::on_error(
        vostok::network_core::tcp_packet_client *this,
        vostok::resources::query_result *client_error_code,
        boost::system::error_code error_code)
{
  boost::function<void __cdecl(enum vostok::network_core::client_error_codes_enum,boost::system::error_code)> *p_m_on_error; // eax
  int v4; // ecx

  this->m_async_connector.m_connection_state = host_name_is_unresolved;
  p_m_on_error = &this->m_on_error;
  v4 = -(this->m_on_error.vtable != 0);
  if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v4) != 0 )
    boost::function2<void,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>::operator()(
      (boost::function3<void,vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum> *)v4,
      p_m_on_error,
      client_error_code,
      (const vostok::resources::memory_usage_type *)error_code.m_val,
      (vostok::resources::class_id_enum)error_code.m_cat);
}
