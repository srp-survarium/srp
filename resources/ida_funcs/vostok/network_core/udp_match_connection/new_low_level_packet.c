vostok::network_core::udp_match_packet *__thiscall vostok::network_core::udp_match_connection::new_low_level_packet(
        vostok::network_core::udp_match_connection *this,
        unsigned __int8 message_type)
{
  survarium::base_project::resolve_link_object *v2; // esi
  survarium::base_project::resolve_link_object *v3; // esi
  vostok::network_core::udp_match_packet *packet; // [esp+38h] [ebp-8h]

  packet = vostok::network_core::new_udp_match_packet(this->m_packets_allocator);
  packet->m_buffer.elems[0] = 1;
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(packet, 1u);
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(packet, message_type);
  ++this->m_stats.sent_low_level.packets.count;
  v2 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
         (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)this,
         (int)packet);
  this->m_stats.sent_low_level.packets.bytes += (unsigned int)&v2[1].config.id.max_storage
                                              + (unsigned __int8)vostok::network_core::udp_match_packet::header_size(packet)
                                              + 6;
  ++this->m_stats.sent_low_level.messages.count;
  v3 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
         (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)this,
         (int)packet);
  this->m_stats.sent_low_level.messages.bytes += (unsigned int)v3
                                               + (unsigned __int8)vostok::network_core::udp_match_packet::header_size(packet);
  ++this->m_stats.sent_low_level.data_bytes;
  return packet;
}
