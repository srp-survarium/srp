void __cdecl vostok::network::enqueue_impl(
        vostok::network::match_client_impl **const client,
        vostok::network_core::udp_match_packet *packet)
{
  vostok::network_core::udp_match_client *v2; // ecx
  boost::intrusive::rbtree_node<void *> *p_header; // ebx
  int v4; // esi
  vostok::network_core::udp_match_packet *v5; // eax
  vostok::network_core::udp_match_client *v6; // ecx
  boost::intrusive::rbtree_node<void *> *i; // eax
  void *v8; // esp
  vostok::network_core::udp_match_packet *left; // esi
  unsigned __int8 *v10; // edi
  unsigned int m_size; // ebx
  _BYTE v12[16]; // [esp+0h] [ebp-20h] BYREF
  vostok::network_core::buffer_reader reader; // [esp+10h] [ebp-10h] BYREF
  int v14; // [esp+1Ch] [ebp-4h]

  p_header = &packet->parts.tree_.data_.node_plus_pred_.header_plus_size_.header_;
  v4 = 0;
  if ( packet->parts.tree_.data_.node_plus_pred_.header_plus_size_.header_.parent_ )
  {
    for ( i = packet->parts.tree_.data_.node_plus_pred_.header_plus_size_.header_.left_;
          i != p_header;
          i = boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::next_node(i) )
    {
      v4 = (int)i[83].right_ + v4 - 12;
    }
    v8 = alloca(v4);
    reader.m_buffer_size = v4;
    v14 = v4;
    left = (vostok::network_core::udp_match_packet *)packet->parts.tree_.data_.node_plus_pred_.header_plus_size_.header_.left_;
    v10 = v12;
    reader.m_buffer = v12;
    reader.m_pointer = v12;
    if ( left != (vostok::network_core::udp_match_packet *)p_header )
    {
      do
      {
        memcpy(v10, left->m_buffer.m_buffer + 12, left->m_buffer.m_size - 12);
        m_size = left->m_buffer.m_size;
        v14 += 12 - m_size;
        v10 = &v10[m_size - 12];
        left = (vostok::network_core::udp_match_packet *)boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::next_node(&left->ordered_multipackets_hook.boost::intrusive::rbtree_node<void *>);
      }
      while ( left != (vostok::network_core::udp_match_packet *)&packet->parts.tree_.data_.node_plus_pred_.header_plus_size_.header_ );
    }
    vostok::network_core::udp_match_client::enqueue(
      v2,
      (int)*client + (_DWORD)&loc_5545C + 4,
      (vostok::network_core::buffer_reader *)packet->message_type,
      &reader);
  }
  else
  {
    v5 = vostok::network::match_client_impl::clone_packet(*client, packet);
    vostok::network_core::udp_match_client::enqueue(
      v6,
      (vostok::network_core::udp_match_packet *)((char *)*client + (_DWORD)&loc_5545C + 4),
      v5);
  }
}
