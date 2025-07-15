void __cdecl vostok::resources::set_query_finished_callback(
        boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> callback)
{
  boost::function1<void,vostok::physics::contact_point const &> *v1; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx
  boost::function1<void,vostok::physics::contact_point const &> *v3; // edi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  boost::function1<void,vostok::physics::contact_point const &> v7; // [esp+8h] [ebp-60h] BYREF
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+28h] [ebp-40h] BYREF
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v9; // [esp+48h] [ebp-20h] BYREF

  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(&callback, &f);
  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(&f, &v9);
  v3 = v1;
  if ( v1 != (boost::function1<void,vostok::physics::contact_point const &> *)&s_resources_manager_buffer.m_query_finished_callback )
  {
    v7.vtable = 0;
    boost::function1<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,unsigned char>::move_assign(
      &v7,
      v1);
    boost::function1<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,unsigned char>::move_assign(
      v3,
      (boost::function1<void,vostok::physics::contact_point const &> *)&s_resources_manager_buffer.m_query_finished_callback);
    boost::function1<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,unsigned char>::move_assign(
      (boost::function1<void,vostok::physics::contact_point const &> *)&s_resources_manager_buffer.m_query_finished_callback,
      &v7);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v4,
      (int *)&v7);
  }
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v2,
    (int *)&v9);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v5, (int *)&f);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v6,
    (int *)&callback);
}
