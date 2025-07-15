void __userpurge stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::resize(
        stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *> > *this@<eax>,
        unsigned int __new_size@<edx>,
        void **__x)
{
  stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *> > *M_finish; // ecx
  void **M_start; // esi
  unsigned int v6; // eax
  unsigned int v7; // edx
  bool v8; // [esp+0h] [ebp-Ch]

  M_finish = (stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *> > *)this->_M_finish;
  M_start = this->_M_start;
  v6 = ((char *)M_finish - (char *)this->_M_start) >> 2;
  if ( __new_size >= v6 )
  {
    v7 = __new_size - v6;
    if ( v7 )
    {
      if ( ((char *)this->_M_end_of_storage._M_data - (char *)M_finish) >> 2 < v7 )
        stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::_M_insert_overflow(
          M_finish,
          (int)this,
          (void **)&M_finish->_M_start,
          __x,
          (const stlp_std::__true_type *)v7,
          0,
          v8);
      else
        stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::_M_fill_insert_aux(
          (stlp_std::priv::_Impl_vector<void *,vostok::input::std_allocator<void *> > *)this,
          (void **)&M_finish->_M_start,
          v7,
          __x,
          (const stlp_std::__false_type *)&__x + 3);
    }
  }
  else if ( &M_start[__new_size] != (void **)M_finish )
  {
    this->_M_finish = (void **)stlp_std::priv::__copy_trivial(
                                 (unsigned __int8 *)M_finish,
                                 (unsigned __int8 *)M_finish,
                                 (unsigned __int8 *)&M_start[__new_size]);
  }
}


void __userpurge stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::resize(
        stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *this@<ecx>,
        unsigned int __new_size@<eax>,
        void **__x)
{
  void **M_start; // ecx
  void **M_finish; // edi
  const stlp_std::__true_type *v6; // eax
  unsigned int v7; // ecx
  bool v8; // [esp+0h] [ebp-8h]

  M_start = this->_M_start;
  M_finish = this->_M_finish;
  if ( __new_size >= M_finish - M_start )
  {
    v6 = (const stlp_std::__true_type *)(__new_size - (M_finish - M_start));
    if ( v6 )
    {
      v7 = this->_M_end_of_storage._M_data - M_finish;
      if ( v7 < (unsigned int)v6 )
        stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::_M_insert_overflow(
          (stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *)v7,
          (stlp_std::priv::_STLP_alloc_proxy<void * *,void *,vostok::vectora_allocator<void *> > *)this,
          M_finish,
          __x,
          v6,
          0,
          v8);
      else
        stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::_M_fill_insert_aux(
          (stlp_std::priv::_Impl_vector<void *,vostok::input::std_allocator<void *> > *)this,
          M_finish,
          (unsigned int)v6,
          __x,
          (const stlp_std::__false_type *)&__x + 3);
    }
  }
  else
  {
    stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::erase(
      this,
      &M_start[__new_size],
      this->_M_finish);
  }
}
