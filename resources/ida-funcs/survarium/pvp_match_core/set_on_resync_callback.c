void __thiscall survarium::pvp_match_core::set_on_resync_callback(
        survarium::pvp_match_core *this,
        boost::function<void __cdecl(unsigned int)> callback,
        int a3)
{
  boost::function1<void,vostok::physics::contact_point const &> *v3; // esi
  boost::function1<void,vostok::physics::contact_point const &> *v4; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  boost::function1<void,vostok::physics::contact_point const &> *v6; // edi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v10; // [esp+8h] [ebp-64h] BYREF
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+28h] [ebp-44h] BYREF
  boost::function1<void,vostok::physics::contact_point const &> v12; // [esp+48h] [ebp-24h] BYREF

  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
    (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&(&callback.vtable)[1],
    &f);
  v3 = (boost::function1<void,vostok::physics::contact_point const &> *)((char *)callback.vtable[78].manager + 49568);
  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(&f, &v10);
  v6 = v4;
  if ( v3 != v4 )
  {
    v12.vtable = 0;
    boost::function1<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,unsigned char>::move_assign(
      &v12,
      v4);
    boost::function1<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,unsigned char>::move_assign(
      v6,
      v3);
    boost::function1<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,unsigned char>::move_assign(
      v3,
      &v12);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v7,
      (int *)&v12);
  }
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v5,
    (int *)&v10);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v8, (int *)&f);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v9,
    (int *)&(&callback.vtable)[1]);
}
