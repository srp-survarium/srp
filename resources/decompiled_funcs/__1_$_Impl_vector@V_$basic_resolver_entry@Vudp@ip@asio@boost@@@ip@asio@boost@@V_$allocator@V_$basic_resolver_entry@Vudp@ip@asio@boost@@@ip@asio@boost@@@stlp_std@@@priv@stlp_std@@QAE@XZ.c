void __thiscall stlp_std::priv::_Impl_vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp>>>::~_Impl_vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp>>>(
        stlp_std::priv::_Impl_vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp> > > *this)
{
  boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp> *v1; // [esp-8h] [ebp-5Ch] BYREF
  void *current; // [esp-4h] [ebp-58h] BYREF
  stlp_std::priv::_Impl_vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp> > > *thisa; // [esp+0h] [ebp-54h]
  int v4; // [esp+4h] [ebp-50h]
  void *__p; // [esp+8h] [ebp-4Ch]
  boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp> **v6; // [esp+3Ch] [ebp-18h]
  stlp_std::reverse_iterator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp> *> v7; // [esp+40h] [ebp-14h]
  void **v8; // [esp+44h] [ebp-10h]
  stlp_std::reverse_iterator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp> *> v9; // [esp+48h] [ebp-Ch]

  thisa = this;
  current = this;
  v8 = &current;
  v9.current = this->_M_start;
  current = v9.current;
  v1 = v9.current;
  v6 = &v1;
  v7.current = this->_M_finish;
  stlp_std::_Destroy_Range<stlp_std::reverse_iterator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp> *>>(
    v7,
    v9);
  if ( thisa->_M_start )
  {
    v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
    __p = thisa->_M_start;
    if ( __p )
      stlp_std::__node_alloc::deallocate(__p, 76 * v4);
  }
}
