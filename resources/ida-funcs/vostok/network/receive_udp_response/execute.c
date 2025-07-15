void __thiscall vostok::network::receive_udp_response::execute(vostok::network::receive_udp_response *this)
{
  vostok::network::receive_udp_response *v1; // ebx
  vostok::network_core::udp_match_packet *m_packet; // eax
  int v3; // esi
  boost::intrusive::rbtree_node<void *> *left; // eax
  boost::intrusive::rbtree_node<void *> *p_header; // edi
  void *v6; // esp
  vostok::network_core::udp_match_packet *v7; // eax
  boost::intrusive::rbtree_node<void *> *node; // esi
  boost::intrusive::rbtree_node<void *> *right; // edi
  _BYTE v10[12]; // [esp+0h] [ebp-24h] BYREF
  _BYTE *v11; // [esp+Ch] [ebp-18h] BYREF
  _BYTE *v12; // [esp+10h] [ebp-14h]
  vostok::network::receive_udp_response *v13; // [esp+14h] [ebp-10h]
  boost::intrusive::rbtree_node<void *> *i; // [esp+18h] [ebp-Ch]
  int v15; // [esp+1Ch] [ebp-8h]
  unsigned __int8 *dst; // [esp+20h] [ebp-4h]

  v1 = this;
  m_packet = this->m_packet;
  v3 = 0;
  if ( m_packet->parts.tree_.data_.node_plus_pred_.header_plus_size_.header_.parent_ )
  {
    left = m_packet->parts.tree_.data_.node_plus_pred_.header_plus_size_.header_.left_;
    p_header = &this->m_packet->parts.tree_.data_.node_plus_pred_.header_plus_size_.header_;
    while ( left != p_header )
    {
      v3 = (int)left[83].right_ + v3 - 12;
      left = boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::next_node(left);
    }
    v6 = alloca(v3);
    v11 = v10;
    v12 = v10;
    v7 = v1->m_packet;
    v13 = (vostok::network::receive_udp_response *)v3;
    v15 = v3;
    node = v7->parts.tree_.data_.node_plus_pred_.header_plus_size_.header_.left_;
    dst = v10;
    for ( i = &v7->parts.tree_.data_.node_plus_pred_.header_plus_size_.header_;
          node != i;
          node = boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::next_node(node) )
    {
      memcpy(dst, (unsigned __int8 *)&node[83].parent_->color_, (unsigned int)&node[83].right_[-1].left_);
      right = node[83].right_;
      v15 += 12 - (_DWORD)right;
      dst = (unsigned __int8 *)right + (_DWORD)dst - 12;
    }
  }
  else
  {
    this = (vostok::network::receive_udp_response *)(m_packet->m_buffer.m_size - 12);
    v11 = m_packet->m_buffer.m_buffer + 12;
    v12 = v11;
    v13 = this;
  }
  boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
    (boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *)this,
    &v1->m_receiver.vtable,
    (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)&v11);
  if ( vostok::network_core::operator>=(&v1->m_copied_stats, v1->m_target_stats) )
    qmemcpy(v1->m_target_stats, &v1->m_copied_stats, sizeof(vostok::network_core::udp_match_stats));
}
