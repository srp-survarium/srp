void __thiscall stlp_std::priv::_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::~_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>(
        stlp_std::priv::_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *this)
{
  vostok::fixed_vector<unsigned int,32> *v1; // [esp-8h] [ebp-60h] BYREF
  void *current; // [esp-4h] [ebp-5Ch] BYREF
  stlp_std::priv::_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *thisa; // [esp+0h] [ebp-58h]
  int v4; // [esp+4h] [ebp-54h]
  vostok::fixed_vector<unsigned int,32> **v5; // [esp+40h] [ebp-18h]
  stlp_std::reverse_iterator<vostok::fixed_vector<unsigned int,32> *> v6; // [esp+44h] [ebp-14h]
  void **v7; // [esp+48h] [ebp-10h]
  stlp_std::reverse_iterator<vostok::fixed_vector<unsigned int,32> *> v8; // [esp+4Ch] [ebp-Ch]

  thisa = this;
  current = this;
  v7 = &current;
  v8.current = this->_M_start;
  current = v8.current;
  v1 = v8.current;
  v5 = &v1;
  v6.current = this->_M_finish;
  stlp_std::_Destroy_Range<stlp_std::reverse_iterator<vostok::fixed_vector<unsigned int,32> *>>(v6, v8);
  if ( thisa->_M_start )
  {
    v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
    vostok::memory::base_allocator::free_impl(thisa->_M_end_of_storage.m_allocator, thisa->_M_start);
  }
}
