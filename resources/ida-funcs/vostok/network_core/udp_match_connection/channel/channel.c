void __thiscall vostok::network_core::udp_match_connection::channel::channel(
        vostok::network_core::udp_match_connection::channel *this)
{
  boost::intrusive::rbtree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::init_header(&this->packets.tree_.data_.node_plus_pred_.header_plus_size_.header_);
  this->packets.tree_.data_.node_plus_pred_.header_plus_size_.size_ = 0;
  this->received_order_id.m_number = -1;
  this->sent_order_id.m_number = 0;
}
