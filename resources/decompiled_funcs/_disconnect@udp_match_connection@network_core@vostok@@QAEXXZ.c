void __thiscall vostok::network_core::udp_match_connection::disconnect(
        vostok::network_core::udp_match_connection *this)
{
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v1; // ecx
  survarium::game_camera *v2; // ecx
  boost::intrusive::rbtree_node<void *> *v4; // [esp+38h] [ebp-78h]
  const char *v5; // [esp+54h] [ebp-5Ch]
  vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy> *v6; // [esp+58h] [ebp-58h]
  const char *m_logging_id; // [esp+74h] [ebp-3Ch]
  vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy> *m_packets_allocator; // [esp+78h] [ebp-38h]
  boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_packet,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,8>,vostok::network_core::udp_match_connection::comparer,unsigned int,1> >,0> v9; // [esp+7Ch] [ebp-34h] BYREF
  remove_all_predicate v10; // [esp+80h] [ebp-30h] BYREF
  remove_all_predicate predicate; // [esp+8Ch] [ebp-24h] BYREF
  char v12; // [esp+9Bh] [ebp-15h]
  vostok::network_core::udp_match_packet *packet; // [esp+9Ch] [ebp-14h] BYREF
  vostok::network_core::udp_match_connection::channel *channel; // [esp+A0h] [ebp-10h]
  unsigned int i; // [esp+A4h] [ebp-Ch]
  unsigned int n; // [esp+A8h] [ebp-8h]
  vostok::network_core::sequence_number<unsigned short> test; // [esp+ACh] [ebp-4h] BYREF

  v12 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_state = initiating_disconnection;
  test.m_number = this->m_local_sequence_id.m_number;
  ++test.m_number;
  if ( vostok::network_core::sequence_number<unsigned short>::operator<=(&test, &this->m_received_local_sequence_id) )
  {
    vostok::network_core::udp_match_connection::instant_disconnect(
      this,
      (boost::function4<void,unsigned int,float,float,char const *> *)2);
  }
  else
  {
    m_logging_id = this->m_logging_id;
    m_packets_allocator = this->m_packets_allocator;
    survarium::weapon_core::cast_weapon_core((survarium::game_options *)&predicate);
    predicate.m_packets_allocator = m_packets_allocator;
    predicate.m_stats = (vostok::network_core::udp_match_stats *)this;
    predicate.m_logging_id = m_logging_id;
    vostok::intrusive_list<vostok::network_core::udp_match_packet,vostok::network_core::udp_match_packet *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::remove_if<remove_all_predicate>(
      &this->m_unacknowledged_packets,
      &predicate);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&predicate);
    v5 = this->m_logging_id;
    v6 = this->m_packets_allocator;
    survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v10);
    v10.m_packets_allocator = v6;
    v10.m_stats = (vostok::network_core::udp_match_stats *)this;
    v10.m_logging_id = v5;
    vostok::intrusive_list<vostok::network_core::udp_match_packet,vostok::network_core::udp_match_packet *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::remove_if<remove_all_predicate>(
      &this->m_packets_to_send,
      &v10);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&v10);
    i = 0;
    n = 1;
    while ( i < n )
    {
      v1 = (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)(24 * i);
      channel = &this->m_channels.elems[i];
      while ( stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                v1,
                (int)&channel->packets.tree_.data_.node_plus_pred_.header_plus_size_.header_) )
      {
        v4 = (boost::intrusive::rbtree_node<void *> *)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                                                        0,
                                                        (int)&channel->packets.tree_.data_.node_plus_pred_.header_plus_size_.header_);
        survarium::weapon_user_dead_state::finalize(v2);
        v9.members_.nodeptr_ = v4;
        packet = (vostok::network_core::udp_match_packet *)boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_packet,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,8>,vostok::network_core::udp_match_connection::comparer,unsigned int,1>>,0>::operator->(&v9);
        boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_packet,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,8>,vostok::network_core::udp_match_connection::comparer,unsigned int,1>>::erase<vostok::network_core::udp_match_packet,vostok::network_core::udp_match_connection::comparer>(
          &channel->packets.tree_,
          packet,
          (vostok::network_core::udp_match_connection::comparer)channel->packets.tree_.data_.node_plus_pred_.header_plus_size_.size_,
          0);
        vostok::network_core::delete_udp_match_packet(
          this->m_packets_allocator,
          (vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::node **)&packet);
      }
      ++i;
    }
    this->m_disconnection_local_sequence_id.m_number = this->m_local_sequence_id.m_number;
    ++this->m_disconnection_local_sequence_id.m_number;
  }
}
