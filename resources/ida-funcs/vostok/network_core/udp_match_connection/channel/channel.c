void __thiscall vostok::network_core::udp_match_connection::channel::channel(
        vostok::network_core::udp_match_connection::channel *this)
{
  boost::intrusive::rbtree_node<void *> *p_header; // ecx

  p_header = &this->packets.tree_.data_.node_plus_pred_.header_plus_size_.header_;
  p_header->parent_ = 0;
  p_header->left_ = p_header;
  p_header->right_ = p_header;
  p_header->color_ = red_t;
  this->packets.tree_.data_.node_plus_pred_.header_plus_size_.size_ = 0;
  this->multipackets.tree_.data_.node_plus_pred_.header_plus_size_.header_.parent_ = 0;
  this->multipackets.tree_.data_.node_plus_pred_.header_plus_size_.header_.left_ = &this->multipackets.tree_.data_.node_plus_pred_.header_plus_size_.header_;
  this->multipackets.tree_.data_.node_plus_pred_.header_plus_size_.header_.right_ = &this->multipackets.tree_.data_.node_plus_pred_.header_plus_size_.header_;
  this->multipackets.tree_.data_.node_plus_pred_.header_plus_size_.header_.color_ = red_t;
  this->multipackets.tree_.data_.node_plus_pred_.header_plus_size_.size_ = 0;
  this->received_order_id.m_number = -1;
  this->sent_order_id.m_number = 0;
}
