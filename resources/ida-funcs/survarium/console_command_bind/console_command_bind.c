void __thiscall survarium::console_command_bind::console_command_bind(
        survarium::console_command_bind *this,
        survarium::key_binder *binder,
        survarium::keyboard_key_descr *type,
        survarium::game_action_descr *a4)
{
  const char *v4; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::key_binder,char const *,int>,boost::_bi::list3<boost::_bi::value<survarium::key_binder *>,boost::arg<1>,boost::_bi::value<int> > > v6; // [esp-10h] [ebp-54h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+10h] [ebp-34h] BYREF
  void (__thiscall *v8)(survarium::key_binder *, char *, int); // [esp+34h] [ebp-10h]
  survarium::keyboard_key_descr *v9; // [esp+38h] [ebp-Ch]
  survarium::game_action_descr *v10; // [esp+3Ch] [ebp-8h]

  v9 = type;
  v10 = a4;
  v8 = survarium::key_binder::bind_key;
  v6.l_.a1_.t_ = (survarium::key_binder *)survarium::key_binder::bind_key;
  v6.l_.a3_.t_ = (int)type;
  v6.f_.f_ = (void (__thiscall *)(survarium::key_binder *, const char *, int))&f;
  boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(
    (boost::function<void __cdecl(char const *)> *)this,
    v6,
    (int)a4);
  v4 = "bind";
  if ( a4 )
    v4 = "bind_sec";
  vostok::console_commands::cc_delegate::cc_delegate(
    (vostok::console_commands::cc_delegate *)&f,
    (int)binder,
    v4,
    &f,
    1,
    command_type_user_specific);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v5, (int *)&f);
  binder->m_key_bindings[8].m_action = a4;
  binder->m_key_bindings[8].m_keyboard[0] = type;
  binder->m_key_bindings[0].m_action = (survarium::game_action_descr *)&survarium::console_command_bind::`vftable';
}
