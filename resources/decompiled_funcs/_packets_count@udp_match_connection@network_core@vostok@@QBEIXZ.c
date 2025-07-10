char *__thiscall vostok::network_core::udp_match_connection::packets_count(
        vostok::network_core::udp_match_connection *this)
{
  const vostok::variant<32> **v1; // esi
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v2; // ecx
  char *v3; // esi
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v4; // ecx
  unsigned int i; // [esp+2Ch] [ebp-Ch]
  char *result; // [esp+34h] [ebp-4h]

  v1 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
         (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
         (int)&this->m_packets_to_send);
  v3 = (char *)v1
     + (_DWORD)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                 v2,
                 (int)&this->m_outgoing_packets);
  result = &v3[(_DWORD)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                         v4,
                         (int)&this->m_unacknowledged_packets)];
  for ( i = 0; !i; i = 1 )
    result += this->m_channels.elems[0].packets.tree_.data_.node_plus_pred_.header_plus_size_.size_;
  return result;
}
