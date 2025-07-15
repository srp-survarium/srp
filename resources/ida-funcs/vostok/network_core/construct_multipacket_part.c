void __usercall vostok::network_core::construct_multipacket_part(
        vostok::network_core::udp_match_packet *packet@<esi>,
        vostok::network_core::buffer_writer *a2@<ecx>,
        vostok::network_core::udp_match_packets_orderer *packets_orderer,
        int message_type,
        vostok::network_core::sequence_number<unsigned short> *order_id,
        unsigned __int8 message_part_id)
{
  vostok::network_core::sequence_number<unsigned short> *v6; // ebx
  vostok::network_core::buffer_writer *v7; // ecx
  vostok::network_core::buffer_writer *v8; // ecx
  vostok::network_core::buffer_writer *v9; // ecx
  _BYTE v10[4]; // [esp+8h] [ebp-4h] BYREF

  v6 = order_id;
  packet->message_type = message_type;
  HIBYTE(order_id) = -1;
  vostok::network_core::buffer_writer::w(
    a2,
    &packet->m_writer.serialization_operations_descriptors.m_size,
    (unsigned __int8 *)&order_id + 3,
    1u);
  vostok::network_core::buffer_writer::w(
    v7,
    &packet->m_writer.serialization_operations_descriptors.m_size,
    (unsigned __int8 *)&message_type,
    1u);
  packets_orderer->get_sending_message_info(
    packets_orderer,
    (vostok::network_core::udp_match_message_type_info *)v10,
    message_type);
  *((_BYTE *)packet + 107) = v10[3];
  packet->order_id = (vostok::network_core::sequence_number<unsigned short>)v6->m_number;
  vostok::network_core::buffer_writer::w(
    v8,
    &packet->m_writer.serialization_operations_descriptors.m_size,
    (unsigned __int8 *)v6,
    2u);
  LOBYTE(v9) = message_part_id;
  packet->message_part_id = message_part_id;
  vostok::network_core::buffer_writer::w(
    v9,
    &packet->m_writer.serialization_operations_descriptors.m_size,
    &packet->message_part_id,
    1u);
}
