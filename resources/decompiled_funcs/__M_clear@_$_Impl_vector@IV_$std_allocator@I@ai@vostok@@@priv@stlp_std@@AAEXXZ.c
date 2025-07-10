void __thiscall stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::_M_clear(
        stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int> > *this)
{
  boost::_bi::list1<vostok::network_core::packet_reader &> *v1; // ecx
  survarium::game_camera *v2; // ecx
  boost::_bi::list1<vostok::network_core::packet_reader &> *v3; // [esp-8h] [ebp-40h] BYREF
  stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int> > *v4; // [esp-4h] [ebp-3Ch] BYREF
  stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int> > *thisa; // [esp+0h] [ebp-38h]
  int v6; // [esp+4h] [ebp-34h]
  boost::_bi::list1<vostok::network_core::packet_reader &> **v7; // [esp+20h] [ebp-18h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *M_finish; // [esp+24h] [ebp-14h]
  stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int> > **v9; // [esp+28h] [ebp-10h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *M_start; // [esp+2Ch] [ebp-Ch]

  thisa = this;
  v4 = this;
  v9 = &v4;
  M_start = (boost::_bi::list1<vostok::network_core::packet_reader &> *)this->_M_start;
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    M_start,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&v4);
  v3 = v1;
  v7 = &v3;
  M_finish = (boost::_bi::list1<vostok::network_core::packet_reader &> *)thisa->_M_finish;
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    M_finish,
    &v3);
  survarium::weapon_user_dead_state::finalize(v2);
  v6 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
  vostok::memory::doug_lea_allocator::free_impl(vostok::ai::g_allocator, thisa->_M_start);
}
