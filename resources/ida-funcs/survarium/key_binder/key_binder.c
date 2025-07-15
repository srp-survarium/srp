void __userpurge survarium::key_binder::key_binder(survarium::game *g@<eax>, survarium::key_binder *this)
{
  survarium::game_action_descr *v2; // eax
  survarium::console_command_bind *v3; // ecx
  vostok::console_commands::cc_delegate *v4; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  vostok::console_commands::cc_delegate *v6; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::key_binder,char const *,int>,boost::_bi::list3<boost::_bi::value<survarium::key_binder *>,boost::arg<1>,boost::_bi::value<int> > > v8; // [esp-10h] [ebp-54h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::key_binder,char const *,int>,boost::_bi::list3<boost::_bi::value<survarium::key_binder *>,boost::arg<1>,boost::_bi::value<int> > > v9; // [esp-10h] [ebp-54h]
  survarium::console_command_bind *v10; // [esp-4h] [ebp-48h]
  survarium::console_command_bind *v11; // [esp-4h] [ebp-48h]
  survarium::console_command_bind *v12; // [esp-4h] [ebp-48h]
  survarium::console_command_bind *v13; // [esp-4h] [ebp-48h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+10h] [ebp-34h] BYREF
  void (__thiscall *v15)(survarium::key_binder *, char *, int); // [esp+34h] [ebp-10h]
  survarium::key_binder *v16; // [esp+38h] [ebp-Ch]
  int v17; // [esp+3Ch] [ebp-8h]

  this->m_game = g;
  memset((int)this, 0, 0x360u);
  v2 = actions_;
  do
  {
    v3 = (survarium::console_command_bind *)(12 * v2->id);
    *(survarium::game_action_descr **)((char *)&this->m_key_bindings[0].m_action + (_DWORD)v3) = v2++;
  }
  while ( v2 != (survarium::game_action_descr *)survarium::keyboards );
  if ( (_S9_5 & 1) == 0 )
  {
    _S9_5 |= 1u;
    survarium::console_command_bind::console_command_bind(
      v3,
      (survarium::key_binder *)&s_bind_key_command,
      (survarium::keyboard_key_descr *)this,
      0);
    atexit((int (__cdecl *)())survarium::key_binder::key_binder_::_8_::_dynamic_atexit_destructor_for__s_bind_key_command__);
    v3 = v10;
  }
  if ( (_S9_5 & 2) == 0 )
  {
    _S9_5 |= 2u;
    survarium::console_command_bind::console_command_bind(
      v3,
      (survarium::key_binder *)&s_bind_sec_key_command,
      (survarium::keyboard_key_descr *)this,
      (survarium::game_action_descr *)1);
    atexit((int (__cdecl *)())survarium::key_binder::key_binder_::_8_::_dynamic_atexit_destructor_for__s_bind_sec_key_command__);
    v3 = v11;
  }
  if ( (_S9_5 & 4) == 0 )
  {
    _S9_5 |= 4u;
    v17 = 0;
    v15 = survarium::key_binder::unbind_key;
    v16 = this;
    v8.l_.a1_.t_ = (survarium::key_binder *)survarium::key_binder::unbind_key;
    v8.l_.a3_.t_ = (int)this;
    v8.f_.f_ = (void (__thiscall *)(survarium::key_binder *, const char *, int))&f;
    boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(
      (boost::function<void __cdecl(char const *)> *)v3,
      v8,
      0);
    vostok::console_commands::cc_delegate::cc_delegate(
      v4,
      (int)&s_unbind_key_command,
      "unbind",
      &f,
      1,
      command_type_user_specific);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v5,
      (int *)&f);
    atexit((int (__cdecl *)())survarium::key_binder::key_binder_::_8_::_dynamic_atexit_destructor_for__s_unbind_key_command__);
    v3 = v12;
  }
  if ( (_S9_5 & 8) == 0 )
  {
    _S9_5 |= 8u;
    v17 = 1;
    v15 = survarium::key_binder::unbind_key;
    v16 = this;
    v9.l_.a1_.t_ = (survarium::key_binder *)survarium::key_binder::unbind_key;
    v9.l_.a3_.t_ = (int)this;
    v9.f_.f_ = (void (__thiscall *)(survarium::key_binder *, const char *, int))&f;
    boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(
      (boost::function<void __cdecl(char const *)> *)v3,
      v9,
      1);
    vostok::console_commands::cc_delegate::cc_delegate(
      v6,
      (int)&s_unbind_second_key_command,
      "unbind_sec",
      &f,
      1,
      command_type_user_specific);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v7,
      (int *)&f);
    atexit((int (__cdecl *)())survarium::key_binder::key_binder_::_8_::_dynamic_atexit_destructor_for__s_unbind_second_key_command__);
    v3 = v13;
  }
  survarium::key_binder::set_default_controls((survarium::key_binder *)v3, this);
}
