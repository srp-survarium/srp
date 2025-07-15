void __thiscall vostok::network::enqueue_order::~enqueue_order(vostok::network::enqueue_order *this)
{
  vostok::network_core::udp_match_packet *m_packet; // eax
  boost::intrusive::set<vostok::network_core::udp_match_message_part,boost::intrusive::member_hook<vostok::network_core::udp_match_message_part,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,boost::intrusive::compare<vostok::network_core::udp_match_packet::part_id_comparer>,boost::intrusive::none,boost::intrusive::none> *v3; // ecx
  vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> *v4; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  boost::intrusive::set<vostok::network_core::udp_match_message_part,boost::intrusive::member_hook<vostok::network_core::udp_match_message_part,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,boost::intrusive::compare<vostok::network_core::udp_match_packet::part_id_comparer>,boost::intrusive::none,boost::intrusive::none> *v6; // [esp-4h] [ebp-2Ch] BYREF
  boost::intrusive::set_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_message_part,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::network_core::udp_match_packet::part_id_comparer,unsigned int,1> > v7; // [esp+Ch] [ebp-1Ch] BYREF
  boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_message_part,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::network_core::udp_match_packet::part_id_comparer,unsigned int,1> >,1> i; // [esp+20h] [ebp-8h] BYREF
  boost::intrusive::rbtree_node<void *> *left; // [esp+24h] [ebp-4h] BYREF

  m_packet = this->m_packet;
  this->__vftable = (vostok::network::enqueue_order_vtbl *)&vostok::network::enqueue_order::`vftable';
  if ( m_packet->parts.tree_.data_.node_plus_pred_.header_plus_size_.header_.parent_ )
  {
    v7.tree_.data_.node_plus_pred_.header_plus_size_.header_.parent_ = 0;
    v7.tree_.data_.node_plus_pred_.header_plus_size_.header_.left_ = &v7.tree_.data_.node_plus_pred_.header_plus_size_.header_;
    v7.tree_.data_.node_plus_pred_.header_plus_size_.header_.right_ = &v7.tree_.data_.node_plus_pred_.header_plus_size_.header_;
    v7.tree_.data_.node_plus_pred_.header_plus_size_.header_.color_ = red_t;
    v7.tree_.data_.node_plus_pred_.header_plus_size_.size_ = 0;
    boost::intrusive::set_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_message_part,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::network_core::udp_match_packet::part_id_comparer,unsigned int,1>>::swap(
      &v7,
      &m_packet->parts);
    while ( v7.tree_.data_.node_plus_pred_.header_plus_size_.header_.parent_ )
    {
      left = v7.tree_.data_.node_plus_pred_.header_plus_size_.header_.left_;
      boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_packet,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,20>,vostok::network_core::udp_match_packet::comparer,unsigned int,1>>::erase(
        (boost::intrusive::set_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_message_part,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::network_core::udp_match_packet::part_id_comparer,unsigned int,1> > *)&v6,
        (boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_message_part,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::network_core::udp_match_packet::part_id_comparer,unsigned int,1> >,0> *)&v7,
        (boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_message_part,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::network_core::udp_match_packet::part_id_comparer,unsigned int,1> >,1>)&i,
        v7.tree_.data_.node_plus_pred_.header_plus_size_.header_.left_);
      vostok::network_core::delete_udp_match_packet(
        this->m_allocator.m_object,
        (vostok::memory::single_size_buffer_allocator<140,vostok::threading::simple_lock>::node **)&left);
      v3 = v6;
    }
    boost::intrusive::set<vostok::network_core::udp_match_packet,boost::intrusive::member_hook<vostok::network_core::udp_match_packet,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,20>,boost::intrusive::compare<vostok::network_core::udp_match_packet::comparer>,boost::intrusive::none,boost::intrusive::none>::~set<vostok::network_core::udp_match_packet,boost::intrusive::member_hook<vostok::network_core::udp_match_packet,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,20>,boost::intrusive::compare<vostok::network_core::udp_match_packet::comparer>,boost::intrusive::none,boost::intrusive::none>(
      v3,
      &v7);
  }
  else
  {
    left = (boost::intrusive::rbtree_node<void *> *)m_packet;
    vostok::network_core::delete_udp_match_packet(
      this->m_allocator.m_object,
      (vostok::memory::single_size_buffer_allocator<140,vostok::threading::simple_lock>::node **)&left);
  }
  if ( vostok::network_core::operator>=(&this->m_copied_stats, this->m_target_stats) )
  {
    qmemcpy(this->m_target_stats, &this->m_copied_stats, sizeof(vostok::network_core::udp_match_stats));
    v4 = 0;
  }
  vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>::dec(
    v4,
    (int **)&this->m_allocator);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v5,
    (int *)&this->m_enqueuer);
  this->__vftable = (vostok::network::enqueue_order_vtbl *)&vostok::network::order::`vftable';
}
