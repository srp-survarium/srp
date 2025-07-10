void __thiscall stlp_std::priv::_Impl_vector<survarium::hit_receiver_info,survarium::std_allocator<survarium::hit_receiver_info>>::~_Impl_vector<survarium::hit_receiver_info,survarium::std_allocator<survarium::hit_receiver_info>>(
        stlp_std::priv::_Impl_vector<survarium::hit_receiver_info,survarium::std_allocator<survarium::hit_receiver_info> > *this)
{
  survarium::hit_receiver_info *v1; // [esp-8h] [ebp-60h] BYREF
  stlp_std::priv::_Impl_vector<survarium::hit_receiver_info,survarium::std_allocator<survarium::hit_receiver_info> > *v2; // [esp-4h] [ebp-5Ch] BYREF
  stlp_std::priv::_Impl_vector<survarium::hit_receiver_info,survarium::std_allocator<survarium::hit_receiver_info> > *thisa; // [esp+0h] [ebp-58h]
  int v4; // [esp+4h] [ebp-54h]
  survarium::hit_receiver_info **v5; // [esp+40h] [ebp-18h]
  survarium::hit_receiver_info *M_finish; // [esp+44h] [ebp-14h]
  stlp_std::priv::_Impl_vector<survarium::hit_receiver_info,survarium::std_allocator<survarium::hit_receiver_info> > **v7; // [esp+48h] [ebp-10h]
  survarium::hit_receiver_info *M_start; // [esp+4Ch] [ebp-Ch]

  thisa = this;
  v2 = this;
  v7 = &v2;
  M_start = this->_M_start;
  v2 = (stlp_std::priv::_Impl_vector<survarium::hit_receiver_info,survarium::std_allocator<survarium::hit_receiver_info> > *)M_start;
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
      thisa->_M_start);
  }
}
