void __thiscall boost::asio::detail::reactor_op_queue<unsigned int>::get_all_operations(
        boost::asio::detail::reactor_op_queue<unsigned int> *this,
        boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *ops)
{
  _BYTE v2[8]; // [esp-4h] [ebp-94h] BYREF
  boost::asio::detail::reactor_op_queue<unsigned int> *thisa; // [esp+4h] [ebp-8Ch]
  _BYTE *v4; // [esp+50h] [ebp-40h]
  stlp_std::priv::_List_node_base *v5; // [esp+54h] [ebp-3Ch]
  stlp_std::priv::_List_node_base **p_M_prev; // [esp+58h] [ebp-38h]
  boost::asio::detail::win_iocp_operation *M_prev; // [esp+5Ch] [ebp-34h]
  stlp_std::priv::_List_node_base *M_node; // [esp+60h] [ebp-30h]
  _DWORD v9[4]; // [esp+64h] [ebp-2Ch] BYREF
  stlp_std::priv::_List_node_base *M_next; // [esp+74h] [ebp-1Ch]
  stlp_std::priv::_List_node_base *v11; // [esp+78h] [ebp-18h]
  stlp_std::list<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::allocator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > > *p_values; // [esp+80h] [ebp-10h]
  stlp_std::priv::_List_iterator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::_Nonconst_traits<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > > op_iter; // [esp+88h] [ebp-8h]
  stlp_std::priv::_List_iterator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::_Nonconst_traits<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > > i; // [esp+8Ch] [ebp-4h]

  thisa = this;
  M_next = this->operations_.values_._M_impl._M_node._M_data._M_next;
  v11 = M_next;
  i._M_node = M_next;
  while ( 1 )
  {
    v9[3] = &thisa->operations_.values_;
    p_values = &thisa->operations_.values_;
    v9[1] = v9;
    v9[2] = &thisa->operations_.values_;
    v9[0] = &thisa->operations_.values_;
    v2[7] = i._M_node != &thisa->operations_.values_._M_impl._M_node._M_data;
    if ( (stlp_std::list<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::allocator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > > *)i._M_node == &thisa->operations_.values_ )
      break;
    M_node = i._M_node;
    i._M_node = i._M_node->_M_next;
    op_iter._M_node = M_node;
    p_M_prev = &M_node[1]._M_prev;
    M_prev = (boost::asio::detail::win_iocp_operation *)M_node[1]._M_prev;
    if ( M_prev )
    {
      if ( ops->back_ )
        ops->back_->next_ = M_prev;
      else
        ops->front_ = M_prev;
      ops->back_ = (boost::asio::detail::win_iocp_operation *)p_M_prev[1];
      *p_M_prev = 0;
      p_M_prev[1] = 0;
    }
    v4 = v2;
    v5 = op_iter._M_node;
    boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>::erase(
      &thisa->operations_,
      op_iter);
  }
}
