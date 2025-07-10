void __userpurge stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short>>::resize(
        stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short> > *this@<eax>,
        unsigned int __new_size@<edx>,
        const unsigned __int16 *__x)
{
  unsigned __int16 *M_finish; // eax
  unsigned int v5; // ecx
  unsigned __int16 *v6; // ecx
  const stlp_std::__true_type *v7; // edx
  unsigned int v8; // ecx
  unsigned int v9; // [esp+0h] [ebp-Ch]
  bool v10; // [esp+4h] [ebp-8h]

  M_finish = this->_M_finish;
  v5 = M_finish - this->_M_start;
  if ( __new_size >= v5 )
  {
    v7 = (const stlp_std::__true_type *)(__new_size - v5);
    if ( v7 )
    {
      v8 = this->_M_end_of_storage._M_data - M_finish;
      if ( v8 < (unsigned int)v7 )
        stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short>>::_M_insert_overflow(
          (stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short> > *)v8,
          M_finish,
          __x,
          v7,
          v9,
          v10);
      else
        stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short>>::_M_fill_insert_aux(
          (stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short> > *)this,
          M_finish,
          (unsigned int)v7,
          __x,
          (const stlp_std::__false_type *)&__x);
    }
  }
  else
  {
    v6 = &this->_M_start[__new_size];
    if ( v6 != M_finish )
      this->_M_finish = v6;
  }
}
