bool __cdecl vostok::network_core::udp_match_connection::is_low_level_packet(
        const vostok::network_core::base_packet *packet)
{
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v1; // ecx
  vostok::network_core::packet_reader *v2; // ecx
  vostok::network_core::packet_reader *v3; // ecx
  vostok::network_core::packet_reader *v4; // ecx
  vostok::network_core::packet_reader *v5; // ecx
  unsigned __int8 v7; // al
  vostok::network_core::packet_reader reader; // [esp+24h] [ebp-Ch] BYREF
  unsigned __int16 bits; // [esp+2Ch] [ebp-4h]

  reader.m_packet = packet;
  reader.m_pointer = (const unsigned __int8 *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                v1,
                                                (int)packet);
  LOWORD(v3) = vostok::network_core::packet_reader::r<unsigned short>(v2, (int)&reader);
  vostok::network_core::packet_reader::r<unsigned short>(v3, (int)&reader);
  bits = vostok::network_core::packet_reader::r<unsigned short>(v4, (int)&reader);
  if ( (bits & 1) == 0 )
    return 0;
  v7 = vostok::network_core::packet_reader::r<unsigned char>(v5, (int)&reader);
  vostok::network_core::packet_reader::advance(&reader, v7);
  return vostok::network_core::packet_reader::eof(&reader);
}
