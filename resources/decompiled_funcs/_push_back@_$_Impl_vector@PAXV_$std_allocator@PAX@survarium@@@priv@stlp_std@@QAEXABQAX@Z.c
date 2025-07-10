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
      v3,
      (void *const *)&this->_M_start,
      (const stlp_std::__true_type *)1,
      1u,
      v4);
  }
  else
  {
    *v3 = this->_M_start;
    *(_DWORD *)(a2 + 4) += 4;
  }
}
