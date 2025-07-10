void __usercall stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::_Impl_vector<void *,vostok::vectora_allocator<void *>>(
        stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *this@<eax>,
        const vostok::vectora_allocator<void *> *__a@<edx>)
{
  this->_M_start = 0;
  this->_M_finish = 0;
  this->_M_end_of_storage.m_allocator = __a->m_allocator;
  this->_M_end_of_storage._M_data = 0;
}
