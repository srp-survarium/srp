void __thiscall boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>::rehash(
        boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> *this,
        unsigned int num_buckets)
{
  stlp_std::priv::_List_node_base *M_node; // eax
  BOOL v3; // ecx
  boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>::bucket_type *buckets; // ecx
  _DWORD v5[2]; // [esp-Ch] [ebp-C0h] BYREF
  stlp_std::priv::_List_node_base *v6; // [esp-4h] [ebp-B8h] BYREF
  bool v8; // [esp+2h] [ebp-B2h]
  bool v9; // [esp+3h] [ebp-B1h]
  boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>::bucket_type *v10; // [esp+4h] [ebp-B0h]
  boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> *thisa; // [esp+8h] [ebp-ACh]
  stlp_std::priv::_List_iterator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::_Nonconst_traits<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > > *v12; // [esp+Ch] [ebp-A8h]
  stlp_std::priv::_List_node_base **p_M_node; // [esp+20h] [ebp-94h]
  _DWORD *v14; // [esp+24h] [ebp-90h]
  stlp_std::priv::_List_iterator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::_Nonconst_traits<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > > v15; // [esp+28h] [ebp-8Ch]
  stlp_std::priv::_List_node_base **v16; // [esp+2Ch] [ebp-88h]
  stlp_std::priv::_List_node_base *v17; // [esp+30h] [ebp-84h]
  stlp_std::priv::_List_iterator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::_Nonconst_traits<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > > v18; // [esp+34h] [ebp-80h]
  stlp_std::priv::_List_node_base *v19; // [esp+38h] [ebp-7Ch] BYREF
  stlp_std::priv::_List_iterator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::_Nonconst_traits<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > > *p_last; // [esp+3Ch] [ebp-78h]
  stlp_std::priv::_List_node_base **v21; // [esp+40h] [ebp-74h]
  stlp_std::priv::_List_node_base *v22; // [esp+44h] [ebp-70h]
  stlp_std::priv::_List_iterator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::_Nonconst_traits<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > > __x; // [esp+48h] [ebp-6Ch] BYREF
  _DWORD v24[3]; // [esp+4Ch] [ebp-68h] BYREF
  stlp_std::priv::_List_node_base *v25; // [esp+58h] [ebp-5Ch]
  stlp_std::priv::_List_node_base *v26; // [esp+5Ch] [ebp-58h]
  _DWORD v27[3]; // [esp+60h] [ebp-54h] BYREF
  stlp_std::priv::_List_node_base *M_next; // [esp+6Ch] [ebp-48h]
  stlp_std::priv::_List_node_base *v29; // [esp+70h] [ebp-44h]
  stlp_std::list<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::allocator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > > *p_values; // [esp+78h] [ebp-3Ch]
  stlp_std::priv::_List_iterator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::_Nonconst_traits<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > > v31; // [esp+88h] [ebp-2Ch] BYREF
  void *p; // [esp+94h] [ebp-20h]
  void *__t; // [esp+98h] [ebp-1Ch]
  int __n; // [esp+9Ch] [ebp-18h]
  unsigned int bucket; // [esp+A0h] [ebp-14h]
  unsigned int i; // [esp+A4h] [ebp-10h]
  stlp_std::priv::_List_iterator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::_Nonconst_traits<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > > end_iter; // [esp+A8h] [ebp-Ch]
  boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>::bucket_type *tmp; // [esp+ACh] [ebp-8h]
  stlp_std::priv::_List_iterator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::_Nonconst_traits<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > > iter; // [esp+B0h] [ebp-4h]

  thisa = this;
  if ( num_buckets != this->num_buckets_ )
  {
    thisa->num_buckets_ = num_buckets;
    p_values = &thisa->values_;
    end_iter._M_node = &thisa->values_._M_impl._M_node._M_data;
    __n = thisa->num_buckets_;
    __t = operator new[](8 * __n);
    if ( __t )
    {
      `vector constructor iterator'(
        (char *)__t,
        8u,
        __n,
        (void *(__thiscall *)(void *))boost::shared_ptr<stlp_std::vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>>>>::shared_ptr<stlp_std::vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>>>>);
      v10 = (boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>::bucket_type *)__t;
    }
    else
    {
      v10 = 0;
    }
    tmp = v10;
    p = thisa->buckets_;
    operator delete[](p);
    thisa->buckets_ = v10;
    for ( i = 0; i < thisa->num_buckets_; ++i )
    {
      thisa->buckets_[i].last = end_iter;
      thisa->buckets_[i].first._M_node = thisa->buckets_[i].last._M_node;
    }
    M_next = thisa->values_._M_impl._M_node._M_data._M_next;
    v29 = M_next;
    iter._M_node = M_next;
    while ( 1 )
    {
      v27[1] = v27;
      v27[2] = end_iter._M_node;
      v27[0] = end_iter._M_node;
      v9 = iter._M_node != end_iter._M_node;
      if ( iter._M_node == end_iter._M_node )
        break;
      v26 = iter._M_node + 1;
      v25 = iter._M_node[1]._M_next;
      bucket = (unsigned int)v25 % thisa->num_buckets_;
      v24[1] = v24;
      v24[2] = end_iter._M_node;
      v24[0] = end_iter._M_node;
      M_node = thisa->buckets_[bucket].last._M_node;
      v8 = M_node == end_iter._M_node;
      if ( M_node == end_iter._M_node )
      {
        __x._M_node = iter._M_node;
        iter._M_node = iter._M_node->_M_next;
        stlp_std::priv::_List_iterator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::_Const_traits<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>>>::_List_iterator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::_Const_traits<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>>>(
          &v31,
          &__x);
        thisa->buckets_[bucket].last = v31;
        thisa->buckets_[bucket].first._M_node = thisa->buckets_[bucket].last._M_node;
      }
      else
      {
        v21 = &v19;
        v22 = iter._M_node;
        v19 = iter._M_node;
        p_last = &thisa->buckets_[bucket].last;
        p_last->_M_node = p_last->_M_node->_M_next;
        v3 = p_last->_M_node == v19;
        if ( p_last->_M_node == v19 )
        {
          iter._M_node = iter._M_node->_M_next;
        }
        else
        {
          v6 = (stlp_std::priv::_List_node_base *)v3;
          v16 = &v6;
          v18._M_node = iter._M_node;
          iter._M_node = iter._M_node->_M_next;
          v17 = v18._M_node;
          v6 = v18._M_node;
          v5[1] = &thisa->values_;
          buckets = thisa->buckets_;
          p_M_node = &buckets[bucket].last._M_node;
          v5[0] = buckets;
          v14 = v5;
          v15._M_node = *p_M_node;
          stlp_std::list<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::allocator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>>>::splice(
            &thisa->values_,
            v15,
            &thisa->values_,
            v18);
          v12 = &thisa->buckets_[bucket].last;
          v12->_M_node = v12->_M_node->_M_prev;
        }
      }
    }
  }
}
