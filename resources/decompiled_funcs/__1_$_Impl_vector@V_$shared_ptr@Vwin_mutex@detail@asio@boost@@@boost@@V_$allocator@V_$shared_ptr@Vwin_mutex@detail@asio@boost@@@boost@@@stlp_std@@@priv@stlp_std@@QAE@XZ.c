void __thiscall stlp_std::priv::_Impl_vector<boost::shared_ptr<boost::asio::detail::win_mutex>,stlp_std::allocator<boost::shared_ptr<boost::asio::detail::win_mutex>>>::~_Impl_vector<boost::shared_ptr<boost::asio::detail::win_mutex>,stlp_std::allocator<boost::shared_ptr<boost::asio::detail::win_mutex>>>(
        stlp_std::priv::_Impl_vector<boost::shared_ptr<boost::asio::detail::win_mutex>,stlp_std::allocator<boost::shared_ptr<boost::asio::detail::win_mutex> > > *this)
{
  boost::shared_ptr<boost::asio::detail::win_mutex> *v1; // [esp-8h] [ebp-60h] BYREF
  void *current; // [esp-4h] [ebp-5Ch] BYREF
  stlp_std::priv::_Impl_vector<boost::shared_ptr<boost::asio::detail::win_mutex>,stlp_std::allocator<boost::shared_ptr<boost::asio::detail::win_mutex> > > *thisa; // [esp+0h] [ebp-58h]
  int v4; // [esp+4h] [ebp-54h]
  void *__p; // [esp+8h] [ebp-50h]
  boost::shared_ptr<boost::asio::detail::win_mutex> **v6; // [esp+40h] [ebp-18h]
  stlp_std::reverse_iterator<boost::shared_ptr<boost::asio::detail::win_mutex> *> v7; // [esp+44h] [ebp-14h]
  void **v8; // [esp+48h] [ebp-10h]
  stlp_std::reverse_iterator<boost::shared_ptr<boost::asio::detail::win_mutex> *> v9; // [esp+4Ch] [ebp-Ch]

  thisa = this;
  current = this;
  v8 = &current;
  v9.current = this->_M_start;
  current = v9.current;
  v1 = v9.current;
  v6 = &v1;
  v7.current = this->_M_finish;
  stlp_std::_Destroy_Range<stlp_std::reverse_iterator<boost::shared_ptr<boost::asio::detail::win_mutex> *>>(v7, v9);
  if ( thisa->_M_start )
  {
    v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
    __p = thisa->_M_start;
    if ( __p )
      stlp_std::__node_alloc::deallocate(__p, 8 * v4);
  }
}
