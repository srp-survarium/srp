void __thiscall boost::asio::detail::reactor_op_queue<unsigned int>::reactor_op_queue<unsigned int>(
        boost::asio::detail::reactor_op_queue<unsigned int> *this)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>(&this->operations_);
}
