void __thiscall stlp_std::priv::_Impl_vector<vostok::fixed_string<16>,survarium::std_allocator<vostok::fixed_string<16>>>::~_Impl_vector<vostok::fixed_string<16>,survarium::std_allocator<vostok::fixed_string<16>>>(
        stlp_std::priv::_Impl_vector<vostok::fixed_string<16>,survarium::std_allocator<vostok::fixed_string<16> > > *this)
{
  vostok::fixed_string<16> *v1; // [esp-8h] [ebp-60h] BYREF
  stlp_std::priv::_Impl_vector<vostok::fixed_string<16>,survarium::std_allocator<vostok::fixed_string<16> > > *v2; // [esp-4h] [ebp-5Ch] BYREF
  stlp_std::priv::_Impl_vector<vostok::fixed_string<16>,survarium::std_allocator<vostok::fixed_string<16> > > *thisa; // [esp+0h] [ebp-58h]
  int v4; // [esp+4h] [ebp-54h]
  vostok::fixed_string<16> **v5; // [esp+40h] [ebp-18h]
  vostok::fixed_string<16> *M_finish; // [esp+44h] [ebp-14h]
  stlp_std::priv::_Impl_vector<vostok::fixed_string<16>,survarium::std_allocator<vostok::fixed_string<16> > > **v7; // [esp+48h] [ebp-10h]
  vostok::fixed_string<16> *M_start; // [esp+4Ch] [ebp-Ch]

  thisa = this;
  v2 = this;
  v7 = &v2;
  M_start = this->_M_start;
  v2 = (stlp_std::priv::_Impl_vector<vostok::fixed_string<16>,survarium::std_allocator<vostok::fixed_string<16> > > *)M_start;
  v1 = M_start;
  v5 = &v1;
  M_finish = this->_M_finish;
  v1 = M_finish;
  stlp_std::_Destroy_Range<stlp_std::reverse_iterator<vostok::logging::initiator_filter *>>();
  if ( thisa->_M_start )
  {
    v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
      (void *)thisa->_M_start);
  }
}
