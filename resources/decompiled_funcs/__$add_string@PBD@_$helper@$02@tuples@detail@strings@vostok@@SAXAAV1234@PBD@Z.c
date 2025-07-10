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
