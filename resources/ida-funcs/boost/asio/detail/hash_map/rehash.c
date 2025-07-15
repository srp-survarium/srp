void __usercall boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>::rehash(
        boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> *this@<esi>,
        unsigned int num_buckets@<eax>)
{
  boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>::bucket_type *v3; // eax
  int v4; // edx
  boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>::bucket_type *i; // ecx
  boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>::bucket_type *v6; // edi
  unsigned int v7; // ecx
  boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>::bucket_type *v8; // eax
  stlp_std::list<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::allocator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > > *p_values; // eax
  stlp_std::priv::_List_node_base *M_next; // edi
  unsigned int v11; // ebx
  stlp_std::priv::_List_iterator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::_Nonconst_traits<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > > *p_last; // eax
  stlp_std::priv::_List_node_base *v13; // ecx
  boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>::bucket_type *v14; // eax
  stlp_std::priv::_List_node_base *M_node; // ecx
  stlp_std::priv::_List_node_base *v16; // ecx
  stlp_std::list<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::allocator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > > *v17; // [esp-4h] [ebp-Ch]
  stlp_std::priv::_List_iterator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::_Nonconst_traits<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > > v18; // [esp+0h] [ebp-8h]

  if ( num_buckets != this->num_buckets_ )
  {
    this->num_buckets_ = num_buckets;
    v3 = (boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>::bucket_type *)operator new[](8 * num_buckets);
    if ( v3 )
    {
      v4 = num_buckets - 1;
      for ( i = v3; v4 >= 0; --v4 )
      {
        i->first._M_node = 0;
        i->last._M_node = 0;
        ++i;
      }
      v6 = v3;
    }
    else
    {
      v6 = 0;
    }
    operator delete[](this->buckets_);
    v7 = 0;
    for ( this->buckets_ = v6; v7 < this->num_buckets_; v8->first._M_node = v8->last._M_node )
    {
      this->buckets_[v7].last._M_node = &this->values_._M_impl._M_node._M_data;
      v8 = &this->buckets_[v7++];
    }
    p_values = &this->values_;
    M_next = this->values_._M_impl._M_node._M_data._M_next;
    while ( 1 )
    {
      if ( M_next == (stlp_std::priv::_List_node_base *)p_values )
        return;
      v11 = (unsigned int)M_next[1]._M_next % this->num_buckets_;
      p_last = &this->buckets_[v11].last;
      if ( (stlp_std::list<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::allocator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > > *)p_last->_M_node == &this->values_ )
      {
        v13 = M_next;
        M_next = M_next->_M_next;
        p_last->_M_node = v13;
        v14 = &this->buckets_[v11];
        M_node = v14->last._M_node;
      }
      else
      {
        v16 = p_last->_M_node->_M_next;
        p_last->_M_node = v16;
        if ( v16 == M_next )
        {
          M_next = M_next->_M_next;
          goto LABEL_16;
        }
        v17 = (stlp_std::list<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::allocator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > > *)M_next;
        M_next = M_next->_M_next;
        stlp_std::list<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::allocator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>>>::splice(
          (stlp_std::list<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::allocator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > > *)this->buckets_[v11].last._M_node,
          (stlp_std::list<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::allocator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > > *)this->buckets_[v11].last._M_node,
          v17,
          v18);
        v14 = (boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>::bucket_type *)&this->buckets_[v11].last;
        M_node = v14->first._M_node->_M_prev;
      }
      v14->first._M_node = M_node;
LABEL_16:
      p_values = &this->values_;
    }
  }
}
