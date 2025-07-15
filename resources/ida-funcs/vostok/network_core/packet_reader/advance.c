void __thiscall vostok::network_core::packet_reader::advance(
        vostok::network_core::packet_reader *this,
        unsigned int offset)
{
  survarium::game_camera *v2; // ecx
  _BYTE *v3; // eax
  survarium::game_camera *v4; // ecx
  _BYTE *v5; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v6; // ecx
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v7; // ecx
  _BYTE *v8; // eax
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v9; // ecx

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v3 )
  {
    stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
      (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
      (int)this->m_packet);
    survarium::weapon_user_dead_state::finalize(v4);
  }
  survarium::weapon_user_dead_state::finalize(v2);
  v6 = (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)(unsigned __int8)*v5;
  if ( *v5 )
  {
    stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v6, (int)this->m_packet);
    stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
      v7,
      (int)this->m_packet);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  }
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v6);
  if ( *v8 )
  {
    stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
      (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
      (int)this->m_packet);
    stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
      v9,
      (int)this->m_packet);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_pointer[offset]);
  }
  this->m_pointer += offset;
}
