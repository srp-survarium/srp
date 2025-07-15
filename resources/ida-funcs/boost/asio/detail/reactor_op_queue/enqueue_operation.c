bool __thiscall boost::asio::detail::reactor_op_queue<unsigned int>::enqueue_operation(
        boost::asio::detail::reactor_op_queue<unsigned int> *this,
        unsigned int descriptor,
        stlp_std::priv::_List_node_base *op)
{
  stlp_std::priv::_List_node_base **p_M_prev; // [esp+8h] [ebp-88h]
  boost::asio::detail::op_queue<boost::asio::detail::timer_op> v6; // [esp+74h] [ebp-1Ch] BYREF
  stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> v; // [esp+7Ch] [ebp-14h] BYREF
  stlp_std::pair<stlp_std::priv::_List_iterator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::_Nonconst_traits<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > >,bool> entry; // [esp+88h] [ebp-8h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v6);
  v6.front_ = 0;
  v6.back_ = 0;
  v.first = descriptor;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v.second);
  v.second.op_queue_.front_ = 0;
  v.second.op_queue_.back_ = 0;
  boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>::insert(
    &this->operations_,
    &entry,
    &v);
  boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation>::~op_queue<boost::asio::detail::win_iocp_operation>((boost::asio::detail::op_queue<boost::asio::detail::timer_op> *)&v.second);
  boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation>::~op_queue<boost::asio::detail::win_iocp_operation>(&v6);
  p_M_prev = &entry.first._M_node[1]._M_prev;
  op[2]._M_prev = 0;
  if ( p_M_prev[1] )
  {
    p_M_prev[1][2]._M_prev = op;
    p_M_prev[1] = op;
  }
  else
  {
    p_M_prev[1] = op;
    *p_M_prev = op;
  }
  return entry.second;
}
