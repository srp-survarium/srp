void __thiscall stlp_std::priv::_Impl_vector<vostok::ai::planning::specified_action,vostok::ai::std_allocator<vostok::ai::planning::specified_action>>::_M_clear_after_move(
        stlp_std::priv::_Impl_vector<vostok::ai::planning::specified_action,vostok::ai::std_allocator<vostok::ai::planning::specified_action> > *this)
{
  vostok::ai::planning::specified_action *v1; // [esp-8h] [ebp-A4h] BYREF
  void *current; // [esp-4h] [ebp-A0h] BYREF
  stlp_std::priv::_Impl_vector<vostok::ai::planning::specified_action,vostok::ai::std_allocator<vostok::ai::planning::specified_action> > *thisa; // [esp+0h] [ebp-9Ch]
  int v4; // [esp+4h] [ebp-98h]
  vostok::ai::planning::specified_action **v5; // [esp+84h] [ebp-18h]
  stlp_std::reverse_iterator<vostok::ai::planning::specified_action *> v6; // [esp+88h] [ebp-14h]
  void **v7; // [esp+8Ch] [ebp-10h]
  stlp_std::reverse_iterator<vostok::ai::planning::specified_action *> v8; // [esp+90h] [ebp-Ch]

  thisa = this;
  current = this;
  v7 = &current;
  v8.current = this->_M_start;
  current = v8.current;
  v1 = v8.current;
  v5 = &v1;
  v6.current = this->_M_finish;
  stlp_std::_Destroy_Range<stlp_std::reverse_iterator<vostok::ai::planning::specified_action *>>(v6, v8);
  v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
  vostok::memory::doug_lea_allocator::free_impl(vostok::ai::g_allocator, thisa->_M_start);
}
