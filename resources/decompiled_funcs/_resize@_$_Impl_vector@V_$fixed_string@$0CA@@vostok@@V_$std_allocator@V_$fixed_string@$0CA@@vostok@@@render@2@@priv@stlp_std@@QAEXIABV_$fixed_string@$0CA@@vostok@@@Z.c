void __userpurge stlp_std::priv::_Impl_vector<vostok::fixed_string<32>,vostok::render::std_allocator<vostok::fixed_string<32>>>::resize(
        unsigned int __new_size@<eax>,
        stlp_std::priv::_Impl_vector<vostok::fixed_string<32>,vostok::render::std_allocator<vostok::fixed_string<32> > > *this,
        const vostok::fixed_string<32> *__x)
{
  vostok::fixed_string<32> *M_finish; // edi
  int v4; // ecx
  vostok::fixed_string<32> *v5; // ecx
  const stlp_std::random_access_iterator_tag *v6; // [esp+0h] [ebp-10h]
  int *v7; // [esp+4h] [ebp-Ch]

  M_finish = this->_M_finish;
  v4 = (char *)M_finish - (char *)this->_M_start;
  if ( __new_size >= v4 / 44 )
  {
    stlp_std::priv::_Impl_vector<vostok::fixed_string<32>,vostok::render::std_allocator<vostok::fixed_string<32>>>::insert(
      this,
      this->_M_finish,
      __new_size - v4 / 44,
      __x);
  }
  else
  {
    v5 = &this->_M_start[__new_size];
    if ( v5 != M_finish )
      this->_M_finish = stlp_std::priv::__copy<vostok::fixed_string<32> *,vostok::fixed_string<32> *,int>(
                          this->_M_finish,
                          M_finish,
                          v5,
                          v6,
                          v7);
  }
}
