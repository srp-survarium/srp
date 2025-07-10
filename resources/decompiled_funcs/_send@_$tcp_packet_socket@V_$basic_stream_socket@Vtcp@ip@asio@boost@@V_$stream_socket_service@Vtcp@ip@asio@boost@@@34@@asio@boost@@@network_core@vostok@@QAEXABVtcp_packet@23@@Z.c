void __thiscall vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>>::send(
        vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > > *this,
        const vostok::network_core::tcp_packet *packet)
{
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v2; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  unsigned __int8 *v4; // eax
  vostok::network_core::packet<vostok::network_core::tcp_packet> *v5; // ecx
  survarium::base_project::resolve_link_object *v6; // [esp-4h] [ebp-2CCh]
  boost::system::error_code error_code; // [esp+2B4h] [ebp-14h] BYREF
  boost::asio::const_buffers_1 result; // [esp+2BCh] [ebp-Ch] BYREF
  vostok::network_core::tcp_packet *cloned_packet; // [esp+2C4h] [ebp-4h]

  cloned_packet = vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>>::new_packet(this);
  cloned_packet->m_buffer_size = 0;
  v6 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
         v2,
         (int)packet);
  v4 = (unsigned __int8 *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                            v3,
                            (int)packet);
  vostok::network_core::packet<vostok::network_core::tcp_packet>::append(v5, (int)cloned_packet, v4, (unsigned int)v6);
  vostok::network_core::buffer_to_send(&result, cloned_packet);
  error_code.m_val = 0;
  error_code.m_cat = boost::system::system_category();
  boost::asio::write<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>,boost::asio::const_buffers_1,boost::asio::detail::transfer_all_t>(
    this->m_socket,
    &result,
    0,
    &error_code);
  vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>>::on_packet_has_been_sent(
    this,
    cloned_packet,
    &error_code,
    result.size_);
}
