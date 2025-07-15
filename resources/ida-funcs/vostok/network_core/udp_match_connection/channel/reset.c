void __thiscall vostok::network_core::udp_match_connection::channel::reset(
        vostok::network_core::udp_match_connection::channel *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_packet,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,8>,vostok::network_core::udp_match_connection::comparer,unsigned int,1>>::clear(&this->packets.tree_);
  this->received_order_id.m_number = -1;
  this->sent_order_id.m_number = 0;
}
