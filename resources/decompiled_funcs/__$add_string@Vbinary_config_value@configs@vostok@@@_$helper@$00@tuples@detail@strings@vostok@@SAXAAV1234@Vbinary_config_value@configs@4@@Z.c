void __cdecl vostok::strings::detail::tuples::helper<1>::add_string<vostok::configs::binary_config_value>(
        vostok::strings::detail::tuples *self,
        vostok::configs::binary_config_value p)
{
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v2; // ecx
  survarium::game_camera *v3; // ecx
  const char *v4; // eax
  survarium::game_camera *v5; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v6; // ecx
  const vostok::variant<32> **v7; // eax
  vostok::network_core::packet_reader *v8; // eax
  int v9; // eax
  unsigned int v10; // edx
  vostok::network_core::packet_reader *v11; // [esp+0h] [ebp-24h]
  boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *v12; // [esp+14h] [ebp-10h] BYREF
  char v13; // [esp+1Fh] [ebp-5h]
  const char *cstr; // [esp+20h] [ebp-4h]

  stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v2, (int)&p);
  survarium::weapon_user_dead_state::finalize(v3);
  cstr = v4;
  v13 = 0;
  survarium::weapon_user_dead_state::finalize(v5);
  v7 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v6, (int)&p);
  v8 = (vostok::network_core::packet_reader *)vostok::strings::detail::tuples::helper<1>::length((const char *)v7);
  vostok::resources::memory_usage_type::memory_usage_type(
    (boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *)cstr,
    &v12,
    v8,
    v11);
  v10 = *(_DWORD *)(v9 + 4);
  self->m_strings[1].first = *(const char **)v9;
  self->m_strings[1].second = v10;
}
