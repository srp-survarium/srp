void __usercall stlp_std::vector<vostok::resources::request,survarium::std_allocator<vostok::resources::request>>::push_back(
        stlp_std::vector<vostok::resources::request,survarium::std_allocator<vostok::resources::request> > *this@<ecx>,
        int a2@<eax>)
{
  int v3; // eax
  bool v4; // [esp+0h] [ebp-4h]

  v3 = *(_DWORD *)(a2 + 4);
  if ( v3 == *(_DWORD *)(a2 + 8) )
  {
    stlp_std::priv::_Impl_vector<vostok::resources::request,survarium::std_allocator<vostok::resources::request>>::_M_insert_overflow(
      &this->_M_impl,
      (vostok::resources::request *)v3,
      (const vostok::resources::request *)this,
      (const stlp_std::__true_type *)1,
      1u,
      v4);
  }
  else
  {
    *(_DWORD *)v3 = this->_M_impl._M_start;
    *(_DWORD *)(v3 + 4) = this->_M_impl._M_finish;
    *(_DWORD *)(a2 + 4) += 8;
  }
}
