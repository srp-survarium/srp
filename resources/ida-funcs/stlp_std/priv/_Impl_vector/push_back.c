void __thiscall stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::push_back(
        stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *> > *this,
        void **__x)
{
  void **M_finish; // eax

  M_finish = this->_M_finish;
  if ( M_finish == this->_M_end_of_storage._M_data )
  {
    stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::_M_insert_overflow(
      this,
      M_finish,
      __x,
      (const stlp_std::__true_type *)&__x + 3,
      1u,
      1);
  }
  else
  {
    *M_finish = *__x;
    ++this->_M_finish;
  }
}


void __usercall stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::push_back(
        stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *> > *this@<ecx>,
        int a2@<eax>)
{
  void **v3; // eax
  bool v4; // [esp+0h] [ebp-4h]

  v3 = *(void ***)(a2 + 4);
  if ( v3 == *(void ***)(a2 + 8) )
  {
    stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::_M_insert_overflow(
      this,
      a2,
      v3,
      (void **)&this->_M_start,
      (const stlp_std::__true_type *)1,
      1,
      v4);
  }
  else
  {
    *v3 = this->_M_start;
    *(_DWORD *)(a2 + 4) += 4;
  }
}


void __usercall stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::push_back(
        stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *this@<ecx>,
        stlp_std::priv::_STLP_alloc_proxy<void * *,void *,vostok::vectora_allocator<void *> > *a2@<eax>)
{
  void **M_data; // eax
  bool v4; // [esp+0h] [ebp-4h]

  M_data = a2->_M_data;
  if ( M_data == a2[1]._M_data )
  {
    stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::_M_insert_overflow(
      this,
      a2,
      M_data,
      (void **)&this->_M_start,
      (const stlp_std::__true_type *)1,
      1,
      v4);
  }
  else
  {
    *M_data = this->_M_start;
    ++a2->_M_data;
  }
}
