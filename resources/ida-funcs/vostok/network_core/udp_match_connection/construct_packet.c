void __usercall vostok::network_core::udp_match_connection::construct_packet(
        vostok::network_core::udp_match_packet *packet@<esi>,
        vostok::network_core::buffer_writer *a2@<ecx>,
        vostok::network_core::udp_match_packets_orderer *packets_orderer,
        int message_type)
{
  vostok::network_core::udp_match_packets_orderer *v4; // ebx
  vostok::network_core::buffer_writer *v5; // ecx
  char v6; // al

  v4 = packets_orderer;
  packet->message_type = message_type;
  vostok::network_core::buffer_writer::w(
    a2,
    &packet->m_writer.serialization_operations_descriptors.m_size,
    (unsigned __int8 *)&message_type,
    1u);
  v4->get_sending_message_info(v4, (vostok::network_core::udp_match_message_type_info *)&packets_orderer, message_type);
  v6 = HIBYTE(packets_orderer);
  *((_BYTE *)packet + 107) = HIBYTE(packets_orderer);
  if ( v6 < 0 )
  {
    HIWORD(message_type) = -1;
    vostok::network_core::buffer_writer::w(
      v5,
      &packet->m_writer.serialization_operations_descriptors.m_size,
      (unsigned __int8 *)&message_type + 2,
      2u);
  }
}
