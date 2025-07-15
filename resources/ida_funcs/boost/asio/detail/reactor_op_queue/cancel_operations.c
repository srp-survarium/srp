char __thiscall boost::asio::detail::reactor_op_queue<unsigned int>::cancel_operations(
        boost::asio::detail::reactor_op_queue<unsigned int> *this,
        unsigned int descriptor,
        boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *ops,
        const boost::system::error_code *ec)
{
  const boost::system::error_category *m_cat; // ecx
  boost::asio::detail::reactor_op *v5; // edx
  _BYTE v7[8]; // [esp-4h] [ebp-B8h] BYREF
  boost::asio::detail::reactor_op_queue<unsigned int> *thisa; // [esp+4h] [ebp-B0h]
  _BYTE *v9; // [esp+50h] [ebp-64h]
  stlp_std::priv::_List_node_base *M_node; // [esp+54h] [ebp-60h]
  boost::asio::detail::reactor_op *v11; // [esp+58h] [ebp-5Ch]
  boost::asio::detail::reactor_op *v12; // [esp+5Ch] [ebp-58h]
  stlp_std::priv::_List_node_base **p_M_prev; // [esp+60h] [ebp-54h]
  stlp_std::priv::_List_node_base *M_prev; // [esp+64h] [ebp-50h]
  stlp_std::priv::_List_node_base *v15; // [esp+68h] [ebp-4Ch]
  stlp_std::priv::_List_node_base *v16; // [esp+6Ch] [ebp-48h]
  _DWORD v17[15]; // [esp+70h] [ebp-44h] BYREF
  boost::asio::detail::reactor_op *op; // [esp+ACh] [ebp-8h]
  stlp_std::priv::_List_iterator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::_Nonconst_traits<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > > i; // [esp+B0h] [ebp-4h] BYREF

  thisa = this;
  boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>::find(
    &this->operations_,
    &i,
    &descriptor);
  v17[3] = &thisa->operations_.values_;
  v17[13] = &thisa->operations_.values_;
  v17[1] = v17;
  v17[2] = &thisa->operations_.values_;
  v17[0] = &thisa->operations_.values_;
  v7[7] = i._M_node != &thisa->operations_.values_._M_impl._M_node._M_data;
  if ( (stlp_std::list<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::allocator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > > *)i._M_node == &thisa->operations_.values_ )
    return 0;
  while ( 1 )
  {
    v16 = i._M_node + 1;
    op = (boost::asio::detail::reactor_op *)i._M_node[1]._M_prev;
    if ( !op )
      break;
    m_cat = ec->m_cat;
    v5 = op;
    op->ec_.m_val = ec->m_val;
    v5->ec_.m_cat = m_cat;
    p_M_prev = &i._M_node[1]._M_prev;
    if ( i._M_node[1]._M_prev )
    {
      v15 = *p_M_prev;
      M_prev = (*p_M_prev)[2]._M_prev;
      *p_M_prev = M_prev;
      if ( !*p_M_prev )
        p_M_prev[1] = 0;
      v15[2]._M_prev = 0;
    }
    v11 = op;
    op->next_ = 0;
    if ( ops->back_ )
    {
      v12 = v11;
      ops->back_->next_ = v11;
      ops->back_ = v11;
    }
    else
    {
      ops->back_ = v11;
      ops->front_ = v11;
    }
  }
  v9 = v7;
  M_node = i._M_node;
  boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>::erase(
    &thisa->operations_,
    i);
  return 1;
}
