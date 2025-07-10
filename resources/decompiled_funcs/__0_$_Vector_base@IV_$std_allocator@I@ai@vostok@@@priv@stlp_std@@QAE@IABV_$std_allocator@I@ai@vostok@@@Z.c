void __thiscall stlp_std::priv::_Vector_base<unsigned int,vostok::ai::std_allocator<unsigned int>>::_Vector_base<unsigned int,vostok::ai::std_allocator<unsigned int>>(
        stlp_std::priv::_Vector_base<unsigned int,vostok::ai::std_allocator<unsigned int> > *this,
        unsigned int __n,
        const vostok::ai::std_allocator<unsigned int> *__a)
{
  const unsigned int *v3; // eax
  unsigned int v5; // [esp+8h] [ebp-14h] BYREF
  unsigned int __b; // [esp+10h] [ebp-Ch] BYREF
  char v7; // [esp+17h] [ebp-5h]
  stlp_std::priv::_STLP_alloc_proxy<unsigned int *,unsigned int,vostok::ai::std_allocator<unsigned int> > *p_M_end_of_storage; // [esp+18h] [ebp-4h]

  this->_M_start = 0;
  this->_M_finish = 0;
  p_M_end_of_storage = &this->_M_end_of_storage;
  this->_M_end_of_storage._M_data = 0;
  v7 = 0;
  v5 = __n;
  __b = 1;
  v3 = stlp_std::max<unsigned int>(&v5, &__b);
  this->_M_start = (unsigned int *)vostok::memory::doug_lea_allocator::realloc_impl(vostok::ai::g_allocator, 0, 4 * *v3);
  this->_M_finish = this->_M_start;
  this->_M_end_of_storage._M_data = &this->_M_start[__n];
}
