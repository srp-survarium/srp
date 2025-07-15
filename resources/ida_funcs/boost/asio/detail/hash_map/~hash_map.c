void __thiscall boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>::~hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>(
        boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> *this)
{
  operator delete[](this->buckets_);
  stlp_std::priv::_List_base<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::allocator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>>>::clear(&this->spares_._M_impl);
  stlp_std::priv::_List_base<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::allocator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>>>::clear(&this->values_._M_impl);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
