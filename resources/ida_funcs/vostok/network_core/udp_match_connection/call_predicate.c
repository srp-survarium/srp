void __thiscall vostok::network_core::udp_match_connection::call_predicate<vostok::network_core::process_packet_predicate>(
        vostok::network_core::udp_match_connection *this,
        const vostok::network_core::process_packet_predicate *predicate,
        boost::function4<void,unsigned int,float,float,char const *> *reader)
{
  vostok::network_core::packet_reader *v3; // ecx
  unsigned int v4; // esi
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v5; // ecx
  unsigned __int8 *v6; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v7; // ecx
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v8; // ecx
  survarium::game_camera *v9; // ecx
  survarium::game_camera *v10; // ecx
  unsigned __int8 v12; // [esp+23h] [ebp-1E5h]
  boost::intrusive::rbtree_node<void *> *v13; // [esp+17Ch] [ebp-8Ch]
  vostok::network_core::sequence_number<unsigned short> *p_order_id; // [esp+180h] [ebp-88h]
  boost::intrusive::rbtree_node<void *> *v15; // [esp+198h] [ebp-70h]
  boost::intrusive::rbtree_node<void *> *n_ptr; // [esp+1B4h] [ebp-54h] BYREF
  unsigned __int16 v17; // [esp+1BAh] [ebp-4Eh]
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *p_m_on_packet_received; // [esp+1C0h] [ebp-48h]
  boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_packet,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,8>,vostok::network_core::udp_match_connection::comparer,unsigned int,1> >,0> v19; // [esp+1C8h] [ebp-40h] BYREF
  boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_packet,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,8>,vostok::network_core::udp_match_connection::comparer,unsigned int,1> >,0> v20; // [esp+1CCh] [ebp-3Ch] BYREF
  stlp_std::pair<boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_packet,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,8>,vostok::network_core::udp_match_connection::comparer,unsigned int,1> >,0>,bool> v21; // [esp+1D0h] [ebp-38h] BYREF
  boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_packet,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,8>,vostok::network_core::udp_match_connection::comparer,unsigned int,1> >,0> result; // [esp+1D8h] [ebp-30h] BYREF
  vostok::network_core::udp_match_connection::comparer v23; // [esp+1DFh] [ebp-29h]
  boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_packet,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,8>,vostok::network_core::udp_match_connection::comparer,unsigned int,1> >,0>::members v24; // [esp+1E0h] [ebp-28h] BYREF
  vostok::network_core::udp_match_packet *v25; // [esp+1E4h] [ebp-24h] BYREF
  vostok::network_core::packet_reader a1; // [esp+1E8h] [ebp-20h] BYREF
  vostok::network_core::udp_match_packet *packet; // [esp+1F0h] [ebp-18h]
  const vostok::network_core::udp_match_message_type_info *info; // [esp+1F4h] [ebp-14h]
  vostok::network_core::sequence_number<unsigned short> next_order_id; // [esp+1F8h] [ebp-10h]
  unsigned __int8 message_type; // [esp+1FEh] [ebp-Ah]
  char v31; // [esp+1FFh] [ebp-9h] BYREF
  vostok::network_core::udp_match_connection::channel *channel; // [esp+200h] [ebp-8h]
  vostok::network_core::sequence_number<unsigned short> order_id; // [esp+204h] [ebp-4h] BYREF

  message_type = vostok::network_core::packet_reader::r<unsigned char>(
                   (vostok::network_core::packet_reader *)this,
                   (int)reader);
  this->m_packets_orderer->get_received_message_info(
    this->m_packets_orderer,
    (vostok::network_core::udp_match_message_type_info *)&v31,
    message_type);
  info = (const vostok::network_core::udp_match_message_type_info *)&v31;
  if ( v31 < 0 )
  {
    v17 = vostok::network_core::packet_reader::r<unsigned short>(
            (vostok::network_core::packet_reader *)((unsigned __int8)v31 >> 7),
            (int)reader);
    order_id.m_number = v17;
    channel = &this->m_channels.elems[*(_BYTE *)info & 0x3F];
    if ( !vostok::network_core::sequence_number<unsigned short>::operator<=(&order_id, &channel->received_order_id) )
    {
      v23 = 0;
      n_ptr = &channel->packets.tree_.data_.node_plus_pred_.header_plus_size_.header_;
      boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_packet,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,8>,vostok::network_core::udp_match_connection::comparer,unsigned int,1>>,0>::members::members(
        &v24,
        &n_ptr,
        channel);
      boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_packet,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,8>,vostok::network_core::udp_match_connection::comparer,unsigned int,1>>::find<vostok::network_core::sequence_number<unsigned short>,vostok::network_core::udp_match_connection::comparer>(
        &channel->packets.tree_,
        &result,
        &order_id,
        v23);
      if ( result.members_.nodeptr_ == v24.nodeptr_ )
      {
        packet = vostok::network_core::new_udp_match_packet(this->m_packets_allocator);
        packet->message_type = message_type;
        LOWORD(v3) = order_id;
        packet->order_id = order_id;
        v4 = vostok::network_core::packet_reader::size_to_eof(v3, reader);
        v6 = (unsigned __int8 *)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                                  v5,
                                  (int)reader);
        vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(v4, packet, v6);
        boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_packet,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,8>,vostok::network_core::udp_match_connection::comparer,unsigned int,1>>::insert_unique(
          &channel->packets.tree_,
          &v21,
          packet);
        next_order_id.m_number = channel->received_order_id.m_number;
        LOWORD(v7) = ++next_order_id.m_number;
        while ( stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                  v7,
                  (int)&channel->packets.tree_.data_.node_plus_pred_.header_plus_size_.header_) )
        {
          v15 = (boost::intrusive::rbtree_node<void *> *)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                                                           v8,
                                                           (int)&channel->packets.tree_.data_.node_plus_pred_.header_plus_size_.header_);
          survarium::weapon_user_dead_state::finalize(v9);
          v20.members_.nodeptr_ = v15;
          p_order_id = &boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_packet,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,8>,vostok::network_core::udp_match_connection::comparer,unsigned int,1>>,0>::operator->(&v20)->order_id;
          if ( p_order_id->m_number != next_order_id.m_number )
            break;
          v13 = (boost::intrusive::rbtree_node<void *> *)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                                                           (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)next_order_id.m_number,
                                                           (int)&channel->packets.tree_.data_.node_plus_pred_.header_plus_size_.header_);
          survarium::weapon_user_dead_state::finalize(v10);
          v19.members_.nodeptr_ = v13;
          v25 = boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_packet,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,8>,vostok::network_core::udp_match_connection::comparer,unsigned int,1>>,0>::operator->(&v19);
          boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_packet,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,8>,vostok::network_core::udp_match_connection::comparer,unsigned int,1>>::erase<vostok::network_core::udp_match_packet,vostok::network_core::udp_match_connection::comparer>(
            &channel->packets.tree_,
            v25,
            (vostok::network_core::udp_match_connection::comparer)channel->packets.tree_.data_.node_plus_pred_.header_plus_size_.size_,
            0);
          a1.m_packet = v25;
          a1.m_pointer = (const unsigned __int8 *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                    (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)v25,
                                                    (int)v25);
          v12 = v25->message_type;
          if ( (!vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&predicate->m_client->m_on_packet_received)
              ? (unsigned int)boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull
              : 0) != 0 )
            boost::function2<void,unsigned char,vostok::network_core::packet_reader &>::operator()(
              &predicate->m_client->m_on_packet_received,
              v12,
              (boost::function4<void,unsigned int,float,float,char const *> *)&a1);
          ++channel->received_order_id.m_number;
          ++next_order_id.m_number;
          vostok::network_core::delete_udp_match_packet(
            this->m_packets_allocator,
            (vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::node **)&v25);
        }
      }
    }
  }
  else
  {
    p_m_on_packet_received = (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&predicate->m_client->m_on_packet_received;
    if ( (!vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!(p_m_on_packet_received)
        ? (unsigned int)boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull
        : 0) != 0 )
      boost::function2<void,unsigned char,vostok::network_core::packet_reader &>::operator()(
        &predicate->m_client->m_on_packet_received,
        message_type,
        reader);
  }
}
