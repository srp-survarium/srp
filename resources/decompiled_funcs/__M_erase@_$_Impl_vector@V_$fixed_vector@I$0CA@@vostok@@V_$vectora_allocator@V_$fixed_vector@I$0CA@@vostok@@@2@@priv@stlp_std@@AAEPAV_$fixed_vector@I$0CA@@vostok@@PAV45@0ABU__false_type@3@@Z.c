vostok::fixed_vector<unsigned int,32> *__thiscall stlp_std::priv::_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::_M_erase(
        stlp_std::priv::_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *this,
        vostok::fixed_vector<unsigned int,32> *__first,
        vostok::fixed_vector<unsigned int,32> *__last,
        const stlp_std::__false_type *__formal)
{
  vostok::fixed_vector<unsigned int,32> *v6; // [esp+18h] [ebp-30h]
  vostok::fixed_vector<unsigned int,32> *v7; // [esp+1Ch] [ebp-2Ch]
  unsigned int *end; // [esp+38h] [ebp-10h] BYREF
  int i; // [esp+3Ch] [ebp-Ch]
  char v10; // [esp+43h] [ebp-5h]
  vostok::fixed_vector<unsigned int,32> *__i; // [esp+44h] [ebp-4h]

  v10 = 0;
  v6 = __first;
  v7 = __last;
  for ( i = this->_M_finish - __last; i > 0; --i )
  {
    end = v7->m_end;
    vostok::buffer_vector<unsigned int>::assign<unsigned int const *>(
      v6,
      v7->m_begin,
      (const unsigned int *const *)&end);
    ++v7;
    ++v6;
  }
  __i = v6;
  stlp_std::__destroy_range<vostok::fixed_vector<unsigned int,32> *,vostok::fixed_vector<unsigned int,32>>(
    v6,
    this->_M_finish,
    0);
  this->_M_finish = __i;
  return __first;
}
