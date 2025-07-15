void __thiscall boost::asio::detail::reactor_op_queue<unsigned int>::get_descriptors<boost::asio::detail::win_fd_set_adapter>(
        boost::asio::detail::reactor_op_queue<unsigned int> *this,
        boost::asio::detail::win_fd_set_adapter *descriptors,
        boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *ops)
{
  boost::asio::error::detail::misc_category *misc_category; // [esp+4Ch] [ebp-44h]
  _DWORD v5[4]; // [esp+60h] [ebp-30h] BYREF
  stlp_std::priv::_List_node_base *M_next; // [esp+70h] [ebp-20h]
  stlp_std::priv::_List_node_base *v7; // [esp+74h] [ebp-1Ch]
  stlp_std::list<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::allocator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > > *p_values; // [esp+78h] [ebp-18h]
  boost::system::error_code ec; // [esp+80h] [ebp-10h] BYREF
  unsigned int descriptor; // [esp+88h] [ebp-8h]
  stlp_std::priv::_List_iterator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::_Nonconst_traits<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > > i; // [esp+8Ch] [ebp-4h]

  M_next = this->operations_.values_._M_impl._M_node._M_data._M_next;
  v7 = M_next;
  i._M_node = M_next;
  while ( 1 )
  {
    v5[3] = &this->operations_.values_;
    p_values = &this->operations_.values_;
    v5[1] = v5;
    v5[2] = &this->operations_.values_;
    v5[0] = &this->operations_.values_;
    if ( (stlp_std::list<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::allocator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > > *)i._M_node == &this->operations_.values_ )
      break;
    descriptor = (unsigned int)i._M_node[1]._M_next;
    i._M_node = i._M_node->_M_next;
    if ( !boost::asio::detail::win_fd_set_adapter::set(descriptors, descriptor) )
    {
      misc_category = boost::asio::error::get_misc_category();
      ec.m_val = 4;
      ec.m_cat = misc_category;
      boost::asio::detail::reactor_op_queue<unsigned int>::cancel_operations(this, descriptor, ops, &ec);
    }
  }
}
