void __usercall survarium::game::query_base_resources(survarium::game *this@<ecx>, unsigned int a2@<eax>)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::game,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::game *>,boost::arg<1> > > v4; // [esp-14h] [ebp-4Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::game,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::game *>,boost::arg<1> > > f; // [esp+8h] [ebp-30h] BYREF
  void (__thiscall *v6)(survarium::game *, vostok::resources::queries_result *); // [esp+18h] [ebp-20h]
  int v7; // [esp+1Ch] [ebp-1Ch]
  unsigned int v8; // [esp+20h] [ebp-18h]
  int v9; // [esp+24h] [ebp-14h]
  vostok::resources::request v10; // [esp+28h] [ebp-10h] BYREF
  const char *v11; // [esp+30h] [ebp-8h]
  int v12; // [esp+34h] [ebp-4h]

  survarium::game::register_console_commands(this, a2);
  v8 = a2;
  v10.id = raw_data_class;
  v12 = 3;
  v6 = survarium::game::on_configs_loaded;
  v7 = 0;
  HIDWORD(v4.f_.f_) = survarium::game::on_configs_loaded;
  v4.l_.a1_.t_ = 0;
  *((_DWORD *)&v4.l_ + 1) = a2;
  LODWORD(v4.f_.f_) = &f;
  v10.path = "resources/startup.cfg";
  v11 = "user_data/user.cfg";
  boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
    0,
    v4,
    v9);
  vostok::resources::query_resources(&v10, 2u, survarium::g_allocator, 0, 0, assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v3, (int *)&f);
}
