void __thiscall vostok::network::receive_udp_response::execute(vostok::network::receive_udp_response *this)
{
  vostok::network_core::packet_reader reader; // [esp+16Ch] [ebp-8h] BYREF

  reader.m_packet = this->m_packet;
  reader.m_pointer = (const unsigned __int8 *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)reader.m_packet,
                                                (int)reader.m_packet);
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum>::operator()(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)&this->m_receiver,
    (vostok::network_core::disconnect_event_types_enum)&reader);
  if ( vostok::network_core::operator>=(&this->m_copied_stats, this->m_target_stats) )
    qmemcpy(this->m_target_stats, &this->m_copied_stats, sizeof(vostok::network_core::udp_match_stats));
}
