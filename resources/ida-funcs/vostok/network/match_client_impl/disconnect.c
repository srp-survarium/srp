void __thiscall vostok::network::match_client_impl::disconnect(vostok::network::match_client_impl *this)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx
  vostok::network_core::udp_match_connection *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  boost::function<void __cdecl(void)> v5; // [esp+8h] [ebp-20h] BYREF

  v5.vtable = 0;
  *(_DWORD *)((char *)&loc_6EF80 + (_DWORD)this) = 0;
  boost::function<void __cdecl (void)>::operator=(
    &v5,
    (boost::function1<void,vostok::physics::contact_point const &> *)((char *)&loc_55F88 + (_DWORD)this));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v2,
    (int *)&v5);
  vostok::network_core::udp_match_connection::disconnect(v3, (int)this + (_DWORD)&loc_5545C + 4);
  v5.vtable = 0;
  boost::function<void __cdecl (enum vostok::network_core::disconnect_event_types_enum)>::operator=(
    (boost::function<void __cdecl(unsigned char,short)> *)&v5,
    (boost::function1<void,vostok::physics::contact_point const &> *)((char *)this + (_DWORD)&loc_55FA7 + 1));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v4,
    (int *)&v5);
}
