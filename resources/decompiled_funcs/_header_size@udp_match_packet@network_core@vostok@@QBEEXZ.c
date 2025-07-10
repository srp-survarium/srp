int __thiscall vostok::network_core::udp_match_packet::header_size(vostok::network_core::udp_match_packet *this)
{
  return this->vostok::network_core::packet<vostok::network_core::udp_match_packet>::vostok::network_core::base_packet::m_buffer
       - (unsigned __int8 *)this
       - 43;
}
