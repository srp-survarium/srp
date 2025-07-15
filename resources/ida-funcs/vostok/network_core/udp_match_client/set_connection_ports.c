void __userpurge vostok::network_core::udp_match_client::set_connection_ports(
        vostok::network_core::udp_match_client *this@<edi>,
        vostok::network_core::udp_match_client *first_port_in_range@<ecx>,
        int ping_message_type,
        unsigned int session_id,
        unsigned __int16 last_port_in_range)
{
  unsigned __int16 v5; // si
  int v6; // ebx
  unsigned __int16 v7; // bx
  vostok::network_core::udp_match_packet *matched; // esi
  vostok::network_core::buffer_writer *v9; // ecx
  vostok::network_core::udp_match_connection *v10; // ecx
  vostok::network_core::buffer_writer *v11; // [esp-4h] [ebp-Ch]

  v5 = last_port_in_range;
  v6 = last_port_in_range;
  this->m_first_port_in_range = (unsigned __int16)first_port_in_range;
  this->m_last_port_in_range = v5;
  this->m_distribution._max = v6;
  this->m_distribution._min = (unsigned __int16)first_port_in_range;
  v7 = (unsigned __int16)first_port_in_range;
  if ( (unsigned __int16)first_port_in_range <= v5 )
  {
    do
    {
      matched = (vostok::network_core::udp_match_packet *)vostok::network_core::new_udp_match_packet(this->m_connection.m_packets_allocator);
      vostok::network_core::udp_match_connection::construct_packet(
        matched,
        v9,
        this->m_connection.m_packets_orderer,
        ping_message_type);
      vostok::network_core::buffer_writer::w(
        v11,
        &matched->m_writer.serialization_operations_descriptors.m_size,
        (unsigned __int8 *)&session_id,
        4u);
      matched->specific_port = v7;
      vostok::network_core::udp_match_connection::enqueue(
        v10,
        (int)this,
        (vostok::network_core::udp_match_connection *)matched);
      ++v7;
    }
    while ( v7 <= last_port_in_range );
  }
  vostok::network_core::udp_match_client::send_queued_packets_impl(
    first_port_in_range,
    (int)this,
    (boost::function<void __cdecl(vostok::network_core::udp_match_packet &,boost::function<void __cdecl(vostok::network_core::udp_match_packet &,boost::system::error_code const &,unsigned int)> const &)> *)this->m_time_in_ms);
}
