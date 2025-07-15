void __thiscall survarium::game::register_console_commands(survarium::game *this, unsigned int a2)
{
  vostok::console_commands::cc_delegate *v2; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  vostok::console_commands::cc_delegate *v4; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  _BYTE v6[28]; // [esp-1Ch] [ebp-60h] BYREF
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+10h] [ebp-34h] BYREF
  void (__thiscall *v8)(survarium::game *, const char *); // [esp+30h] [ebp-14h]
  unsigned int v9; // [esp+34h] [ebp-10h]
  unsigned int v10; // [esp+38h] [ebp-Ch]
  int v11; // [esp+3Ch] [ebp-8h]

  if ( (_S13 & 1) == 0 )
  {
    _S13 |= 1u;
    v8 = survarium::game::exit;
    v10 = a2;
    v9 = 0;
    *(_DWORD *)&v6[12] = survarium::game::exit;
    *(_DWORD *)&v6[16] = 0;
    *(_DWORD *)&v6[20] = a2;
    *(_DWORD *)&v6[8] = &f;
    boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(
      0,
      *(boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::game,char const *>,boost::_bi::list2<boost::_bi::value<survarium::game *>,boost::arg<1> > > *)&v6[8],
      v11);
    vostok::console_commands::cc_delegate::cc_delegate(
      v2,
      (int)&game_exit_cc,
      "quit",
      &f,
      0,
      command_type_user_specific);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v3,
      (int *)&f);
    atexit((int (__cdecl *)())survarium::game::register_console_commands_::_2_::_dynamic_atexit_destructor_for__game_exit_cc__);
  }
  if ( (_S13 & 2) == 0 )
  {
    _S13 |= 2u;
    LOBYTE(v10) = 0;
    f.functor.vostok_pointer_size_alignment[1] = 0;
    f.functor.obj_ptr = survarium::game::load_config_query;
    v9 = a2;
    v11 = 1;
    *((_QWORD *)&f.functor.data + 1) = __PAIR64__(v10, a2);
    f.functor.bound_memfunc_ptr.obj_ptr = (void *)1;
    *(_DWORD *)v6 = &f;
    qmemcpy(&v6[4], &f.functor, 0x18u);
    boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(
      0,
      *(boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::game,char const *,bool,unsigned int>,boost::_bi::list4<boost::_bi::value<survarium::game *>,boost::arg<1>,boost::_bi::value<bool>,boost::_bi::value<enum vostok::console_commands::command_type> > > *)v6,
      *(int *)&v6[24]);
    vostok::console_commands::cc_delegate::cc_delegate(
      v4,
      (int)&cfg_load_cc,
      "cfg_load",
      &f,
      1,
      command_type_engine_internal);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v5,
      (int *)&f);
    atexit((int (__cdecl *)())survarium::game::register_console_commands_::_2_::_dynamic_atexit_destructor_for__cfg_load_cc__);
  }
}
