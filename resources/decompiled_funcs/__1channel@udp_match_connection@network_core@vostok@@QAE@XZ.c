void __thiscall vostok::network_core::udp_match_connection::channel::~channel(
        vostok::network_core::udp_match_connection::channel *this)
{
  boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_packet,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,8>,vostok::network_core::udp_match_connection::comparer,unsigned int,1>>::clear(&this->packets.tree_);
}
