void __thiscall stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>(
        stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *> > *this,
        const vostok::vectora_allocator<void const *> *__a)
{
  this->_M_start = 0;
  this->_M_finish = 0;
  this->_M_end_of_storage.m_allocator = __a->m_allocator;
  this->_M_end_of_storage._M_data = 0;
}
