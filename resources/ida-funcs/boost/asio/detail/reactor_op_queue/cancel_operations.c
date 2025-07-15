char __userpurge boost::asio::detail::reactor_op_queue<unsigned int>::cancel_operations@<al>(
        boost::asio::detail::reactor_op_queue<unsigned int> *this@<ecx>,
        int a2@<eax>,
        unsigned int descriptor,
        boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *ops,
        stlp_std::priv::_List_node_base *ec)
{
  unsigned int v6; // ecx
  unsigned int v7; // edx
  boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> *v8; // ecx
  int v9; // eax
  stlp_std::priv::_List_iterator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::_Nonconst_traits<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > > v10; // edi
  stlp_std::priv::_List_node_base *v11; // eax
  stlp_std::priv::_List_node_base *v13; // ecx
  stlp_std::priv::_List_node_base *v14; // edx
  stlp_std::priv::_List_node_base *M_prev; // eax

  v6 = *(_DWORD *)(a2 + 24);
  if ( !v6 )
  {
LABEL_7:
    v8 = (boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> *)(a2 + 4);
    goto LABEL_8;
  }
  v7 = descriptor % v6;
  v8 = (boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> *)(a2 + 4);
  v9 = *(_DWORD *)(a2 + 20) + 8 * v7;
  v10._M_node = *(stlp_std::priv::_List_node_base **)v9;
  if ( *(_DWORD *)v9 != a2 + 4 )
  {
    v11 = **(stlp_std::priv::_List_node_base ***)(v9 + 4);
    while ( v10._M_node != v11 )
    {
      if ( v10._M_node[1]._M_next == (stlp_std::priv::_List_node_base *)descriptor )
        goto LABEL_9;
      v10._M_node = v10._M_node->_M_next;
    }
    goto LABEL_7;
  }
LABEL_8:
  v10._M_node = (stlp_std::priv::_List_node_base *)v8;
LABEL_9:
  if ( (boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> *)v10._M_node == v8 )
    return 0;
  while ( 1 )
  {
    M_prev = v10._M_node[1]._M_prev;
    if ( !M_prev )
      break;
    M_prev[4] = *ec;
    v13 = v10._M_node[1]._M_prev;
    if ( v13 )
    {
      v14 = v13[2]._M_prev;
      v10._M_node[1]._M_prev = v14;
      if ( !v14 )
        v10._M_node[2]._M_next = 0;
      v13[2]._M_prev = 0;
    }
    boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation>::push(
      ops,
      (boost::asio::detail::win_iocp_operation *)M_prev);
  }
  boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>::erase(
    v8,
    a2,
    v10);
  return 1;
}
