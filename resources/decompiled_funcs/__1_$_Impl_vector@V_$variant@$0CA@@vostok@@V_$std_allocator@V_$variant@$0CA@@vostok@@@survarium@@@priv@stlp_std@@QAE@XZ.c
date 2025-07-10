void __thiscall stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>::~_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>(
        stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32> > > *this)
{
  vostok::variant<32> *v1; // [esp-8h] [ebp-64h] BYREF
  void *current; // [esp-4h] [ebp-60h] BYREF
  stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32> > > *thisa; // [esp+0h] [ebp-5Ch]
  int v4; // [esp+4h] [ebp-58h]
  vostok::variant<32> **v5; // [esp+44h] [ebp-18h]
  stlp_std::reverse_iterator<vostok::variant<32> *> v6; // [esp+48h] [ebp-14h]
  void **v7; // [esp+4Ch] [ebp-10h]
  stlp_std::reverse_iterator<vostok::variant<32> *> v8; // [esp+50h] [ebp-Ch]

  thisa = this;
  current = this;
  v7 = &current;
  v8.current = this->_M_start;
  current = v8.current;
  v1 = v8.current;
  v5 = &v1;
  v6.current = this->_M_finish;
  stlp_std::_Destroy_Range<stlp_std::reverse_iterator<vostok::variant<32> *>>(v6, v8);
  if ( thisa->_M_start )
  {
    v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
      thisa->_M_start);
  }
}
