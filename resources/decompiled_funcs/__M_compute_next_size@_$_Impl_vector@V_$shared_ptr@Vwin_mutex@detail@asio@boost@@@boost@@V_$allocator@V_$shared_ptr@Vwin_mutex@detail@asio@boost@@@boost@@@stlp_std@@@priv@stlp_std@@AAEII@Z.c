unsigned int __thiscall stlp_std::priv::_Impl_vector<boost::shared_ptr<boost::asio::detail::win_mutex>,stlp_std::allocator<boost::shared_ptr<boost::asio::detail::win_mutex>>>::_M_compute_next_size(
        stlp_std::priv::_Impl_vector<boost::shared_ptr<boost::asio::detail::win_mutex>,stlp_std::allocator<boost::shared_ptr<boost::asio::detail::win_mutex> > > *this,
        unsigned int __n)
{
  const unsigned int *v2; // eax
  unsigned int __size; // [esp+2Ch] [ebp-8h] BYREF
  unsigned int __len; // [esp+30h] [ebp-4h]

  __size = this->_M_finish - this->_M_start;
  if ( __n > 0x1FFFFFFF - __size )
    stlp_std::priv::_Vector_base<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info>>::_M_throw_length_error((stlp_std::priv::_Vector_base<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> > *)this);
  v2 = stlp_std::max<unsigned int>(&__n, &__size);
  __len = *v2 + __size;
  if ( __len > 0x1FFFFFFF || __len < __size )
    return 0x1FFFFFFF;
  return __len;
}
