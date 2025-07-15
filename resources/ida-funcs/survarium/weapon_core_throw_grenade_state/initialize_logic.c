void __thiscall survarium::weapon_core_throw_grenade_state::initialize_logic(
        survarium::weapon_core_throw_grenade_state *this,
        survarium::weapon_core_throw_grenade_state::substates_collection *substates,
        vostok::ai::fsm **a3)
{
  _DWORD *v4; // eax
  _DWORD *v5; // eax
  vostok::ai::fsm *v6; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  vostok::ai::fsm *v8; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  vostok::ai::fsm *v10; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v11; // ecx
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core_throw_grenade_state,bool>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_throw_grenade_state *>,boost::_bi::value<bool> > > v12; // [esp-14h] [ebp-4Ch]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core_throw_grenade_state,bool>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_throw_grenade_state *>,boost::_bi::value<bool> > > v13; // [esp-14h] [ebp-4Ch]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core_throw_grenade_state,bool>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_throw_grenade_state *>,boost::_bi::value<bool> > > v14; // [esp-14h] [ebp-4Ch]
  void *v15; // [esp+14h] [ebp-24h]
  boost::function<bool __cdecl(void)> f; // [esp+18h] [ebp-20h] BYREF

  vostok::ai::fsm::add_state(*a3, &substates[25].idle_state);
  vostok::ai::fsm::add_state(a3[1], v4);
  vostok::ai::fsm::add_state(a3[2], v5);
  f.functor.obj_ptr = substates;
  f.vtable = (boost::detail::function::vtable_base *)survarium::weapon_core_throw_grenade_state::test_input_throw_action;
  (&f.vtable)[1] = 0;
  LOBYTE(v15) = 1;
  f.functor.vostok_pointer_size_alignment[1] = v15;
  HIDWORD(v12.f_.f_) = survarium::weapon_core_throw_grenade_state::test_input_throw_action;
  v12.l_.a1_.t_ = 0;
  *(_DWORD *)&v12.l_.a2_.t_ = substates;
  LODWORD(v12.f_.f_) = &f;
  boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(0, v12, (int)v15);
  vostok::ai::fsm::append_transition(v6, (vostok::ai::fsm_state *)*a3, (vostok::ai::fsm_state *)a3[1], &f);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v7, (int *)&f);
  f.vtable = (boost::detail::function::vtable_base *)survarium::weapon_core_throw_grenade_state::test_input_throw_action;
  f.functor.obj_ptr = substates;
  LOBYTE(v15) = 0;
  f.functor.vostok_pointer_size_alignment[1] = v15;
  (&f.vtable)[1] = 0;
  HIDWORD(v13.f_.f_) = survarium::weapon_core_throw_grenade_state::test_input_throw_action;
  v13.l_.a1_.t_ = 0;
  *(_DWORD *)&v13.l_.a2_.t_ = substates;
  LODWORD(v13.f_.f_) = &f;
  boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(0, v13, (int)v15);
  vostok::ai::fsm::append_transition(v8, (vostok::ai::fsm_state *)*a3, (vostok::ai::fsm_state *)a3[2], &f);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v9, (int *)&f);
  f.vtable = (boost::detail::function::vtable_base *)survarium::weapon_core_throw_grenade_state::test_input_throw_action;
  f.functor.obj_ptr = substates;
  LOBYTE(v15) = 0;
  f.functor.vostok_pointer_size_alignment[1] = v15;
  (&f.vtable)[1] = 0;
  HIDWORD(v14.f_.f_) = survarium::weapon_core_throw_grenade_state::test_input_throw_action;
  v14.l_.a1_.t_ = 0;
  *(_DWORD *)&v14.l_.a2_.t_ = substates;
  LODWORD(v14.f_.f_) = &f;
  boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(0, v14, (int)v15);
  vostok::ai::fsm::append_transition(v10, (vostok::ai::fsm_state *)a3[1], (vostok::ai::fsm_state *)a3[2], &f);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v11,
    (int *)&f);
}
