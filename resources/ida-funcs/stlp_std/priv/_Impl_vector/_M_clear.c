void __thiscall stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::_M_clear(
        stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *> > *this)
{
  stlp_std::allocator<void *>::deallocate(
    &this->_M_end_of_storage,
    (_STLP_atomic_freelist::item *)this->_M_start,
    this->_M_end_of_storage._M_data - this->_M_start);
}
