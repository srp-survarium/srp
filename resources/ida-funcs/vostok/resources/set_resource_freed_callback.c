void __cdecl vostok::resources::set_resource_freed_callback(
        boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> callback)
{
  boost::function1<void,vostok::physics::contact_point const &> *v1; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx
  boost::function1<void,vostok::physics::contact_point const &> *v3; // edi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  boost::function1<void,vostok::physics::contact_point const &> v6; // [esp+8h] [ebp-40h] BYREF
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+28h] [ebp-20h] BYREF

  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(&callback, &f);
  v3 = v1;
  if ( v1 != (boost::function1<void,vostok::physics::contact_point const &> *)&s_resource_freed_callback )
  {
    v6.vtable = 0;
    boost::function1<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,unsigned char>::move_assign(
      &v6,
      v1);
    boost::function1<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,unsigned char>::move_assign(
      v3,
      (boost::function1<void,vostok::physics::contact_point const &> *)&s_resource_freed_callback);
    boost::function1<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,unsigned char>::move_assign(
      (boost::function1<void,vostok::physics::contact_point const &> *)&s_resource_freed_callback,
      &v6);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v4,
      (int *)&v6);
  }
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v2, (int *)&f);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v5,
    (int *)&callback);
}
