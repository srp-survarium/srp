void __thiscall vostok::network_core::udp_match_connection::instant_disconnect(
        vostok::network_core::udp_match_connection *this,
        boost::function4<void,unsigned int,float,float,char const *> *type)
{
  boost::array<vostok::network_core::udp_match_connection::channel,1> *v2; // ecx
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v3; // ecx
  survarium::game_camera *v4; // ecx
  boost::intrusive::rbtree_node<void *> *v6; // [esp+16Ch] [ebp-88h]
  const char *v7; // [esp+188h] [ebp-6Ch]
  vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy> *v8; // [esp+18Ch] [ebp-68h]
  const char *m_logging_id; // [esp+1A8h] [ebp-4Ch]
  vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy> *m_packets_allocator; // [esp+1ACh] [ebp-48h]
  boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_packet,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,8>,vostok::network_core::udp_match_connection::comparer,unsigned int,1> >,0> v11; // [esp+1C0h] [ebp-34h] BYREF
  remove_all_predicate v12; // [esp+1C4h] [ebp-30h] BYREF
  remove_all_predicate predicate; // [esp+1D0h] [ebp-24h] BYREF
  __int16 v14; // [esp+1DCh] [ebp-18h]
  __int16 v15; // [esp+1DEh] [ebp-16h]
  __int16 v16; // [esp+1E0h] [ebp-14h]
  __int16 v17; // [esp+1E2h] [ebp-12h]
  vostok::network_core::udp_match_packet *packet; // [esp+1E4h] [ebp-10h] BYREF
  vostok::network_core::udp_match_connection::channel *channel; // [esp+1E8h] [ebp-Ch]
  unsigned int i; // [esp+1ECh] [ebp-8h]
  unsigned int n; // [esp+1F0h] [ebp-4h]

  this->m_state = disconnected;
  this->m_last_send_time_in_ms = 0;
  this->m_last_send_attempt_time_in_ms = 0;
  this->m_last_receive_time_in_ms = 0;
  this->m_disconnection_receive_time_in_ms = 0;
  this->m_remote_acknowledgement_bits = 0;
  this->m_received_local_acknowledgement_bits = 0;
  this->m_pending_operations_count = 0;
  v17 = -1;
  this->m_local_sequence_id.m_number = -1;
  v16 = -1;
  this->m_remote_sequence_id.m_number = -1;
  v15 = -1;
  this->m_received_local_sequence_id.m_number = -1;
  v14 = -1;
  this->m_disconnection_local_sequence_id.m_number = -1;
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
  v7 = this->m_logging_id;
  v8 = this->m_packets_allocator;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v12);
  v12.m_packets_allocator = v8;
  v12.m_stats = (vostok::network_core::udp_match_stats *)this;
  v12.m_logging_id = v7;
  vostok::intrusive_list<vostok::network_core::udp_match_packet,vostok::network_core::udp_match_packet *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::remove_if<remove_all_predicate>(
    &this->m_packets_to_send,
    &v12);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&v12);
  i = 0;
  n = 1;
  while ( i < n )
  {
    v2 = &this->m_channels + i;
    channel = (vostok::network_core::udp_match_connection::channel *)v2;
    while ( stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
              (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)v2,
              (int)&channel->packets.tree_.data_.node_plus_pred_.header_plus_size_.header_) )
    {
      v6 = (boost::intrusive::rbtree_node<void *> *)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                                                      v3,
                                                      (int)&channel->packets.tree_.data_.node_plus_pred_.header_plus_size_.header_);
      survarium::weapon_user_dead_state::finalize(v4);
      v11.members_.nodeptr_ = v6;
      packet = (vostok::network_core::udp_match_packet *)boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_packet,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,8>,vostok::network_core::udp_match_connection::comparer,unsigned int,1>>,0>::operator->(&v11);
      boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_packet,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,8>,vostok::network_core::udp_match_connection::comparer,unsigned int,1>>::erase<vostok::network_core::udp_match_packet,vostok::network_core::udp_match_connection::comparer>(
        &channel->packets.tree_,
        packet,
        (vostok::network_core::udp_match_connection::comparer)channel->packets.tree_.data_.node_plus_pred_.header_plus_size_.size_,
        0);
      vostok::network_core::delete_udp_match_packet(
        this->m_packets_allocator,
        (vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::node **)&packet);
    }
    vostok::network_core::udp_match_connection::channel::reset(channel);
    ++i;
  }
  if ( (!vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_on_disconnect)
      ? (unsigned int)boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull
      : 0) != 0 )
    boost::function1<void,enum vostok::network_core::disconnect_event_types_enum>::operator()(
      &this->m_on_disconnect,
      type);
}
