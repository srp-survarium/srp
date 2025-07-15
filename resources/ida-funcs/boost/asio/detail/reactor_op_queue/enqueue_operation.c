bool __usercall boost::asio::detail::reactor_op_queue<unsigned int>::enqueue_operation@<al>(
        boost::asio::detail::reactor_op_queue<unsigned int> *this@<ecx>,
        unsigned int descriptor@<eax>,
        stlp_std::priv::_List_node_base *op@<esi>)
{
  boost::asio::detail::op_queue<boost::asio::detail::timer_op> *v3; // ecx
  boost::asio::detail::op_queue<boost::asio::detail::timer_op> *v4; // ecx
  stlp_std::priv::_List_node_base *M_node; // eax
  stlp_std::priv::_List_node_base *M_next; // ecx
  stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> v8; // [esp+Ch] [ebp-1Ch] BYREF
  stlp_std::pair<stlp_std::priv::_List_iterator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::_Nonconst_traits<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > >,bool> v9; // [esp+18h] [ebp-10h] BYREF
  int v10[2]; // [esp+20h] [ebp-8h] BYREF

  v8.first = descriptor;
  v10[0] = 0;
  v10[1] = 0;
  v8.second.op_queue_.front_ = 0;
  v8.second.op_queue_.back_ = 0;
  boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>::insert(
    &this->operations_,
    &this->operations_,
    &v9,
    &v8);
  boost::asio::detail::op_queue<boost::asio::detail::timer_op>::~op_queue<boost::asio::detail::timer_op>(
    v3,
    (int *)&v8.second);
  boost::asio::detail::op_queue<boost::asio::detail::timer_op>::~op_queue<boost::asio::detail::timer_op>(v4, v10);
  M_node = v9.first._M_node;
  op[2]._M_prev = 0;
  M_next = M_node[2]._M_next;
  if ( M_next )
    M_next[2]._M_prev = op;
  else
    M_node[1]._M_prev = op;
  M_node[2]._M_next = op;
  return v9.second;
}
