void __userpurge stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::resize(
        stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *this@<eax>,
        unsigned int __new_size@<edx>,
        void *const *__x)
{
  void **M_finish; // eax
  unsigned int v5; // ecx
  void **v6; // ecx
  void **v7; // esi
  const stlp_std::__true_type *v8; // edx
  unsigned int v9; // ecx
  bool v10; // [esp+0h] [ebp-Ch]

  M_finish = this->_M_finish;
  v5 = M_finish - this->_M_start;
  if ( __new_size >= v5 )
  {
    v8 = (const stlp_std::__true_type *)(__new_size - v5);
    if ( v8 )
    {
      v9 = this->_M_end_of_storage._M_data - M_finish;
      if ( v9 < (unsigned int)v8 )
        stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::_M_insert_overflow(
          (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)v9,
          (int)this,
          M_finish,
          __x,
          v8,
          0,
          v10);
      else
        stlp_std::priv::_Impl_vector<void *,vostok::input::std_allocator<void *>>::_M_fill_insert_aux(
          (stlp_std::priv::_Impl_vector<void *,vostok::input::std_allocator<void *> > *)this,
          M_finish,
          (unsigned int)v8,
          __x,
          (const stlp_std::__false_type *)&__x);
    }
  }
  else
  {
    v6 = &this->_M_start[__new_size];
    if ( v6 != M_finish )
    {
      LOBYTE(__x) = 0;
      v7 = stlp_std::priv::__copy_ptrs<void * *,void * *>(M_finish, M_finish, v6);
      stlp_std::_Destroy<vostok::fs_new::virtual_path_string>(v7, this->_M_finish);
      this->_M_finish = v7;
    }
  }
}
