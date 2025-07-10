void __thiscall stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::~_Impl_vector<void const *,vostok::vectora_allocator<void const *>>(
        vostok::vectora<vostok::resources::request> *this)
{
  if ( this->_M_impl._M_start )
    this->_M_impl._M_end_of_storage.m_allocator->call_free(
      this->_M_impl._M_end_of_storage.m_allocator,
      (void *)this->_M_impl._M_start);
}
