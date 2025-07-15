void __thiscall boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>(
        boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> *this)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  this->size_ = 0;
  this->values_._M_impl._M_node._M_data._M_next = 0;
  this->values_._M_impl._M_node._M_data._M_prev = 0;
  stlp_std::priv::_List_base<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::allocator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>>>::_M_empty_initialize(&this->values_._M_impl);
  this->spares_._M_impl._M_node._M_data._M_next = 0;
  this->spares_._M_impl._M_node._M_data._M_prev = 0;
  this->spares_._M_impl._M_node._M_data._M_next = &this->spares_._M_impl._M_node._M_data;
  this->spares_._M_impl._M_node._M_data._M_prev = this->spares_._M_impl._M_node._M_data._M_next;
  this->buckets_ = 0;
  this->num_buckets_ = 0;
}
