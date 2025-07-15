void __thiscall vostok::network::receive_response::execute(vostok::network::receive_response *this)
{
  vostok::network_core::packet_reader reader; // [esp+134h] [ebp-8h] BYREF

  reader.m_packet = this->m_packet;
  reader.m_pointer = (const unsigned __int8 *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)reader.m_packet,
                                                (int)reader.m_packet);
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum>::operator()(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)&this->m_receiver,
    (boost::function4<void,unsigned int,float,float,char const *> *)&reader);
}
