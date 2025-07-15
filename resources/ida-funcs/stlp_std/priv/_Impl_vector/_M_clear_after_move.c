void __thiscall stlp_std::priv::_Impl_vector<vostok::logging::initiator_filter,vostok::vectora_allocator<vostok::logging::initiator_filter>>::_M_clear_after_move(
        stlp_std::priv::_Impl_vector<vostok::logging::initiator_filter,vostok::vectora_allocator<vostok::logging::initiator_filter> > *this)
{
  stlp_std::pair<vostok::fixed_string<64>,XAUDIO2FX_REVERB_I3DL2_PARAMETERS *> *v1; // [esp-8h] [ebp-60h] BYREF
  void *current; // [esp-4h] [ebp-5Ch] BYREF
  stlp_std::priv::_Impl_vector<vostok::logging::initiator_filter,vostok::vectora_allocator<vostok::logging::initiator_filter> > *thisa; // [esp+0h] [ebp-58h]
  int v4; // [esp+4h] [ebp-54h]
  stlp_std::pair<vostok::fixed_string<64>,XAUDIO2FX_REVERB_I3DL2_PARAMETERS *> **v5; // [esp+40h] [ebp-18h]
  stlp_std::reverse_iterator<stlp_std::pair<vostok::fixed_string<64>,XAUDIO2FX_REVERB_I3DL2_PARAMETERS *> *> v6; // [esp+44h] [ebp-14h]
  void **v7; // [esp+48h] [ebp-10h]
  stlp_std::reverse_iterator<stlp_std::pair<vostok::fixed_string<64>,XAUDIO2FX_REVERB_I3DL2_PARAMETERS *> *> v8; // [esp+4Ch] [ebp-Ch]

  thisa = this;
  current = this;
  v7 = &current;
  v8.current = (stlp_std::pair<vostok::fixed_string<64>,XAUDIO2FX_REVERB_I3DL2_PARAMETERS *> *)this->_M_start;
  current = v8.current;
  v1 = v8.current;
  v5 = &v1;
  v6.current = (stlp_std::pair<vostok::fixed_string<64>,XAUDIO2FX_REVERB_I3DL2_PARAMETERS *> *)this->_M_finish;
  stlp_std::_Destroy_Range<stlp_std::reverse_iterator<vostok::logging::initiator_filter *>>(v6, v8);
  v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
  vostok::memory::base_allocator::free_impl(thisa->_M_end_of_storage.m_allocator, thisa->_M_start);
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info>>::_M_clear_after_move(
        stlp_std::priv::_Impl_vector<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info> > *this)
{
  vostok::sound::unique_propagator_info *v1; // [esp-8h] [ebp-B0h] BYREF
  void *current; // [esp-4h] [ebp-ACh] BYREF
  stlp_std::priv::_Impl_vector<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info> > *thisa; // [esp+0h] [ebp-A8h]
  int v4; // [esp+4h] [ebp-A4h]
  vostok::sound::unique_propagator_info **v5; // [esp+90h] [ebp-18h]
  stlp_std::reverse_iterator<vostok::sound::unique_propagator_info *> v6; // [esp+94h] [ebp-14h]
  void **v7; // [esp+98h] [ebp-10h]
  stlp_std::reverse_iterator<vostok::sound::unique_propagator_info *> v8; // [esp+9Ch] [ebp-Ch]

  thisa = this;
  current = this;
  v7 = &current;
  v8.current = this->_M_start;
  current = v8.current;
  v1 = v8.current;
  v5 = &v1;
  v6.current = this->_M_finish;
  stlp_std::_Destroy_Moved_Range<stlp_std::reverse_iterator<vostok::sound::unique_propagator_info *>>(v6, v8);
  v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
  vostok::memory::base_allocator::free_impl(thisa->_M_end_of_storage.m_allocator, thisa->_M_start);
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::_M_clear_after_move(
        stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl> > *this)
{
  vostok::ai::planning::pddl_world_state_property_impl *v1; // [esp-8h] [ebp-5Ch] BYREF
  void *current; // [esp-4h] [ebp-58h] BYREF
  stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl> > *thisa; // [esp+0h] [ebp-54h]
  int v4; // [esp+4h] [ebp-50h]
  vostok::ai::planning::pddl_world_state_property_impl **v5; // [esp+3Ch] [ebp-18h]
  stlp_std::reverse_iterator<vostok::ai::planning::pddl_world_state_property_impl *> v6; // [esp+40h] [ebp-14h]
  void **v7; // [esp+44h] [ebp-10h]
  stlp_std::reverse_iterator<vostok::ai::planning::pddl_world_state_property_impl *> v8; // [esp+48h] [ebp-Ch]

  thisa = this;
  current = this;
  v7 = &current;
  v8.current = this->_M_start;
  current = v8.current;
  v1 = v8.current;
  v5 = &v1;
  v6.current = this->_M_finish;
  stlp_std::_Destroy_Range<stlp_std::reverse_iterator<vostok::ai::planning::pddl_world_state_property_impl *>>(v6, v8);
  v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
  vostok::memory::doug_lea_allocator::free_impl(vostok::ai::g_allocator, thisa->_M_start);
}


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


void __thiscall stlp_std::priv::_Impl_vector<vostok::fixed_string<16>,survarium::std_allocator<vostok::fixed_string<16>>>::_M_clear_after_move(
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
  v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
  vostok::memory::doug_lea_allocator::free_impl(
    (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
    (void *)thisa->_M_start);
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::_M_clear_after_move(
        stlp_std::priv::_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *this)
{
  vostok::fixed_vector<unsigned int,32> *v1; // [esp-8h] [ebp-60h] BYREF
  void *current; // [esp-4h] [ebp-5Ch] BYREF
  stlp_std::priv::_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *thisa; // [esp+0h] [ebp-58h]
  int v4; // [esp+4h] [ebp-54h]
  vostok::fixed_vector<unsigned int,32> **v5; // [esp+40h] [ebp-18h]
  stlp_std::reverse_iterator<vostok::fixed_vector<unsigned int,32> *> v6; // [esp+44h] [ebp-14h]
  void **v7; // [esp+48h] [ebp-10h]
  stlp_std::reverse_iterator<vostok::fixed_vector<unsigned int,32> *> v8; // [esp+4Ch] [ebp-Ch]

  thisa = this;
  current = this;
  v7 = &current;
  v8.current = this->_M_start;
  current = v8.current;
  v1 = v8.current;
  v5 = &v1;
  v6.current = this->_M_finish;
  stlp_std::_Destroy_Range<stlp_std::reverse_iterator<vostok::fixed_vector<unsigned int,32> *>>(v6, v8);
  v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
  vostok::memory::base_allocator::free_impl(thisa->_M_end_of_storage.m_allocator, thisa->_M_start);
}


void __thiscall stlp_std::priv::_Impl_vector<boost::shared_ptr<boost::asio::detail::win_mutex>,stlp_std::allocator<boost::shared_ptr<boost::asio::detail::win_mutex>>>::_M_clear_after_move(
        stlp_std::priv::_Impl_vector<boost::shared_ptr<boost::asio::detail::win_mutex>,stlp_std::allocator<boost::shared_ptr<boost::asio::detail::win_mutex> > > *this)
{
  boost::shared_ptr<boost::asio::detail::win_mutex> *v1; // [esp-8h] [ebp-60h] BYREF
  void *current; // [esp-4h] [ebp-5Ch] BYREF
  stlp_std::priv::_Impl_vector<boost::shared_ptr<boost::asio::detail::win_mutex>,stlp_std::allocator<boost::shared_ptr<boost::asio::detail::win_mutex> > > *thisa; // [esp+0h] [ebp-58h]
  int v4; // [esp+4h] [ebp-54h]
  void *__p; // [esp+8h] [ebp-50h]
  boost::shared_ptr<boost::asio::detail::win_mutex> **v6; // [esp+40h] [ebp-18h]
  stlp_std::reverse_iterator<boost::shared_ptr<boost::asio::detail::win_mutex> *> v7; // [esp+44h] [ebp-14h]
  void **v8; // [esp+48h] [ebp-10h]
  stlp_std::reverse_iterator<boost::shared_ptr<boost::asio::detail::win_mutex> *> v9; // [esp+4Ch] [ebp-Ch]

  thisa = this;
  current = this;
  v8 = &current;
  v9.current = this->_M_start;
  current = v9.current;
  v1 = v9.current;
  v6 = &v1;
  v7.current = this->_M_finish;
  stlp_std::_Destroy_Range<stlp_std::reverse_iterator<boost::shared_ptr<boost::asio::detail::win_mutex> *>>(v7, v9);
  v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
  __p = thisa->_M_start;
  if ( __p )
    stlp_std::__node_alloc::deallocate(__p, 8 * v4);
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>::_M_clear_after_move(
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
  v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
  vostok::memory::doug_lea_allocator::free_impl(
    (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
    thisa->_M_start);
}
