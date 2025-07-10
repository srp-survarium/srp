vostok::network_core::udp_match_packet *__thiscall vostok::network::match_client::new_packet(
        vostok::network::match_client *this,
        unsigned __int8 message_type)
{
  const vostok::variant<32> **v2; // eax
  vostok::network_core::udp_match_packet *result; // [esp+58h] [ebp-4h]

  v2 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
         (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
         (int)this);
  result = vostok::network_core::new_udp_match_packet((vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy> *)v2);
  vostok::network_core::udp_match_connection::construct_packet(this->m_packets_orderer, result, message_type);
  return result;
}
