void __usercall vostok::strings::detail::tuples::helper<1>::add_string<char const *>(
        vostok::strings::detail::tuples *self@<edi>,
        const char *p@<edx>)
{
  if ( p )
  {
    self->m_strings[1].first = p;
    self->m_strings[1].second = strlen(p);
  }
  else
  {
    self->m_strings[1].first = 0;
    self->m_strings[1].second = 0;
  }
}


void __usercall vostok::strings::detail::tuples::helper<2>::add_string<char const *>(
        vostok::strings::detail::tuples *self@<edi>,
        const char *p@<edx>)
{
  if ( p )
  {
    self->m_strings[2].first = p;
    self->m_strings[2].second = strlen(p);
  }
  else
  {
    self->m_strings[2].first = 0;
    self->m_strings[2].second = 0;
  }
}


void __cdecl vostok::strings::detail::tuples::helper<3>::add_string<char const *>(
        vostok::strings::detail::tuples *self,
        const char *p)
{
  survarium::game_camera *v2; // ecx
  int v3; // eax
  unsigned int v4; // edx
  unsigned __int8 *a1; // [esp+0h] [ebp-18h]
  boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *v6[2]; // [esp+8h] [ebp-10h] BYREF
  char v7; // [esp+13h] [ebp-5h]
  const char *cstr; // [esp+14h] [ebp-4h]

  cstr = p;
  v7 = 0;
  survarium::weapon_user_dead_state::finalize(v2);
  if ( p )
  {
    a1 = (unsigned __int8 *)vostok::strings::length(p);
    vostok::resources::memory_usage_type::memory_usage_type(
      (boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *)cstr,
      v6,
      (vostok::network_core::packet_reader *)a1,
      (vostok::network_core::packet_reader *)a1);
  }
  else
  {
    vostok::resources::memory_usage_type::memory_usage_type(0, v6, 0, 0);
  }
  v4 = *(_DWORD *)(v3 + 4);
  self->m_strings[3].first = *(const char **)v3;
  self->m_strings[3].second = v4;
}


void __cdecl vostok::strings::detail::tuples::helper<4>::add_string<char const *>(
        vostok::strings::detail::tuples *self,
        const char *p)
{
  survarium::game_camera *v2; // ecx
  int v3; // eax
  unsigned int v4; // edx
  unsigned __int8 *a1; // [esp+0h] [ebp-18h]
  boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *v6[2]; // [esp+8h] [ebp-10h] BYREF
  char v7; // [esp+13h] [ebp-5h]
  const char *cstr; // [esp+14h] [ebp-4h]

  cstr = p;
  v7 = 0;
  survarium::weapon_user_dead_state::finalize(v2);
  if ( p )
  {
    a1 = (unsigned __int8 *)vostok::strings::length(p);
    vostok::resources::memory_usage_type::memory_usage_type(
      (boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *)cstr,
      v6,
      (vostok::network_core::packet_reader *)a1,
      (vostok::network_core::packet_reader *)a1);
  }
  else
  {
    vostok::resources::memory_usage_type::memory_usage_type(0, v6, 0, 0);
  }
  v4 = *(_DWORD *)(v3 + 4);
  self->m_strings[4].first = *(const char **)v3;
  self->m_strings[4].second = v4;
}


void __usercall vostok::strings::detail::tuples::helper<0>::add_string<char const *>(
        vostok::strings::detail::tuples *self@<edi>,
        const char *p@<edx>)
{
  if ( p )
  {
    self->m_strings[0].first = p;
    self->m_strings[0].second = strlen(p);
  }
  else
  {
    self->m_strings[0].first = 0;
    self->m_strings[0].second = 0;
  }
}


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
