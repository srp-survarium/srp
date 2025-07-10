void __thiscall stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>(
        stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *this,
        const vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > *__a)
{
  this->_M_start = 0;
  this->_M_finish = 0;
  this->_M_end_of_storage.m_allocator = __a->m_allocator;
  this->_M_end_of_storage._M_data = 0;
}
