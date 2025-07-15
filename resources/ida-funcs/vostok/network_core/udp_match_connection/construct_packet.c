void __cdecl vostok::network_core::udp_match_connection::construct_packet(
        vostok::network_core::udp_match_packets_orderer *packets_orderer,
        vostok::network_core::udp_match_packet *packet,
        unsigned __int8 message_type)
{
  unsigned __int8 v3; // [esp+1Bh] [ebp-1h] BYREF

  packet->message_type = message_type;
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(packet, message_type);
  packets_orderer->get_sending_message_info(
    packets_orderer,
    (vostok::network_core::udp_match_message_type_info *)&v3,
    message_type);
  *((_BYTE *)packet + 42) = v3 & 0x3F | *((_BYTE *)packet + 42) & 0xC0;
  *((_BYTE *)packet + 42) = (((v3 & 0x40) != 0) << 6) | *((_BYTE *)packet + 42) & 0xBF;
  *((_BYTE *)packet + 42) = (v3 >> 7 << 7) | *((_BYTE *)packet + 42) & 0x7F;
  if ( *((char *)packet + 42) < 0 )
    vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(packet, 0xFFFFu);
}
