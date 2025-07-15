void __thiscall survarium::weapon_user_animations_selector::weapon_user_animations_selector(
        survarium::weapon_user_animations_selector *this,
        survarium::weapon_user_animations_selector *owner)
{
  vostok::memory::doug_lea_allocator *v3; // esi
  char *v4; // eax
  vostok::memory::doug_lea_allocator *v5; // ecx
  char *v6; // eax
  survarium::weapon_user_animations_selector *v7; // eax
  vostok::memory::doug_lea_allocator *v8; // esi
  char *v9; // eax
  vostok::memory::doug_lea_allocator *v10; // ecx
  char *v11; // eax
  vostok::ai::fsm *v12; // eax
  vostok::memory::doug_lea_allocator *v13; // esi
  char *v14; // eax
  vostok::memory::doug_lea_allocator *v15; // ecx
  char *v16; // eax
  char *v17; // esi
  vostok::memory::doug_lea_allocator *v18; // esi
  char *v19; // eax
  vostok::memory::doug_lea_allocator *v20; // ecx
  char *v21; // eax
  survarium::player_logic_jump_state *v22; // esi
  survarium::jump_logic *v23; // ecx
  vostok::memory::doug_lea_allocator *v24; // esi
  char *v25; // eax
  vostok::memory::doug_lea_allocator *v26; // ecx
  char *v27; // eax
  int v28; // eax
  _DWORD *v29; // eax
  _DWORD *v30; // eax
  _DWORD *v31; // eax
  _DWORD *v32; // eax
  boost::function<bool __cdecl(void)> *v33; // ecx
  vostok::ai::fsm *v34; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v35; // ecx
  boost::function<bool __cdecl(void)> *v36; // ecx
  vostok::ai::fsm *v37; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v38; // ecx
  boost::function<bool __cdecl(void)> *v39; // ecx
  vostok::ai::fsm *v40; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v41; // ecx
  boost::function<bool __cdecl(void)> *v42; // ecx
  vostok::ai::fsm *v43; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v44; // ecx
  boost::function<bool __cdecl(void)> *v45; // ecx
  vostok::ai::fsm *v46; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v47; // ecx
  boost::function<bool __cdecl(void)> *v48; // ecx
  vostok::ai::fsm *v49; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v50; // ecx
  boost::function<bool __cdecl(void)> *v51; // ecx
  vostok::ai::fsm *v52; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v53; // ecx
  boost::function<bool __cdecl(void)> *v54; // ecx
  vostok::ai::fsm *v55; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v56; // ecx
  boost::function<bool __cdecl(void)> *v57; // ecx
  vostok::ai::fsm *v58; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v59; // ecx
  boost::function<bool __cdecl(void)> *v60; // ecx
  vostok::ai::fsm *v61; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v62; // ecx
  boost::function<bool __cdecl(void)> *v63; // ecx
  vostok::ai::fsm *v64; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v65; // ecx
  boost::function<bool __cdecl(void)> *v66; // ecx
  vostok::ai::fsm *v67; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v68; // ecx
  boost::function<bool __cdecl(void)> *v69; // ecx
  vostok::ai::fsm *v70; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v71; // ecx
  boost::function<bool __cdecl(void)> *v72; // ecx
  vostok::ai::fsm *v73; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v74; // ecx
  boost::function<bool __cdecl(void)> *v75; // ecx
  vostok::ai::fsm *v76; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v77; // ecx
  boost::function<bool __cdecl(void)> *v78; // ecx
  vostok::ai::fsm *v79; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v80; // ecx
  vostok::ai::fsm *v81; // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::player_logic_sprint_state,bool &>,boost::_bi::list2<boost::_bi::value<survarium::player_logic_sprint_state *>,boost::arg<1> > > v82; // [esp-8h] [ebp-54h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > v83; // [esp-8h] [ebp-54h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > v84; // [esp-8h] [ebp-54h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > v85; // [esp-8h] [ebp-54h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > v86; // [esp-8h] [ebp-54h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > v87; // [esp-8h] [ebp-54h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > v88; // [esp-8h] [ebp-54h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > v89; // [esp-8h] [ebp-54h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > v90; // [esp-8h] [ebp-54h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > v91; // [esp-8h] [ebp-54h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > v92; // [esp-8h] [ebp-54h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > v93; // [esp-8h] [ebp-54h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > v94; // [esp-8h] [ebp-54h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > v95; // [esp-8h] [ebp-54h]
  boost::_bi::bind_t<bool,bool (__cdecl*)(void),boost::_bi::list0> v96; // [esp-8h] [ebp-54h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > v97; // [esp-8h] [ebp-54h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > v98; // [esp-8h] [ebp-54h]
  const char *v99; // [esp+0h] [ebp-4Ch]
  const char *v100; // [esp+0h] [ebp-4Ch]
  const char *v101; // [esp+0h] [ebp-4Ch]
  const char *v102; // [esp+0h] [ebp-4Ch]
  const char *v103; // [esp+0h] [ebp-4Ch]
  int v104; // [esp+0h] [ebp-4Ch]
  int v105; // [esp+0h] [ebp-4Ch]
  int v106; // [esp+0h] [ebp-4Ch]
  int v107; // [esp+0h] [ebp-4Ch]
  int v108; // [esp+0h] [ebp-4Ch]
  int v109; // [esp+0h] [ebp-4Ch]
  int v110; // [esp+0h] [ebp-4Ch]
  int v111; // [esp+0h] [ebp-4Ch]
  int v112; // [esp+0h] [ebp-4Ch]
  int v113; // [esp+0h] [ebp-4Ch]
  int v114; // [esp+0h] [ebp-4Ch]
  int v115; // [esp+0h] [ebp-4Ch]
  int v116; // [esp+0h] [ebp-4Ch]
  int v117; // [esp+0h] [ebp-4Ch]
  int v118; // [esp+0h] [ebp-4Ch]
  int v119; // [esp+0h] [ebp-4Ch]
  const char *v120; // [esp+4h] [ebp-48h]
  const char *v121; // [esp+4h] [ebp-48h]
  const char *v122; // [esp+4h] [ebp-48h]
  const char *v123; // [esp+4h] [ebp-48h]
  const char *v124; // [esp+4h] [ebp-48h]
  unsigned int v125; // [esp+8h] [ebp-44h]
  unsigned int v126; // [esp+8h] [ebp-44h]
  unsigned int v127; // [esp+8h] [ebp-44h]
  unsigned int v128; // [esp+8h] [ebp-44h]
  unsigned int v129; // [esp+8h] [ebp-44h]
  boost::function<bool __cdecl(void)> transition_predicate; // [esp+10h] [ebp-3Ch] BYREF
  vostok::ai::fsm *v131; // [esp+38h] [ebp-14h]
  vostok::ai::fsm *v132; // [esp+3Ch] [ebp-10h]
  vostok::ai::fsm *v133; // [esp+40h] [ebp-Ch]
  vostok::ai::fsm *v134; // [esp+44h] [ebp-8h]
  survarium::weapon_user_animations_selector *ownera; // [esp+54h] [ebp+8h]

  v3 = survarium::g_allocator;
  owner->m_logic.m_states.m_size = 0;
  owner->m_logic.m_states.m_first = 0;
  owner->m_logic.m_states.m_last = 0;
  owner->m_logic.m_current_state = 0;
  owner->m_logic.m_on_transition.vtable = 0;
  owner->m_animations.m_object = 0;
  owner->m_right_leg_is_supporting = 1;
  v4 = type_info::raw_name(&survarium::player_logic_stand_state `RTTI Type Descriptor');
  v6 = vostok::memory::doug_lea_allocator::malloc_impl(v5, (int)v3, 0x2Cu, v4, v99, v120, v125);
  if ( v6 )
  {
    survarium::player_logic_base_state::player_logic_base_state(
      (survarium::player_logic_base_state *)v6,
      owner,
      type_stand);
    v7->m_logic.m_states.m_size = (unsigned int)&survarium::player_logic_stand_state::`vftable';
    ownera = v7;
  }
  else
  {
    ownera = 0;
  }
  v8 = survarium::g_allocator;
  v9 = type_info::raw_name(&survarium::player_logic_crouch_state `RTTI Type Descriptor');
  v11 = vostok::memory::doug_lea_allocator::malloc_impl(v10, (int)v8, 0x2Cu, v9, v100, v121, v126);
  if ( v11 )
  {
    survarium::player_logic_base_state::player_logic_base_state(
      (survarium::player_logic_base_state *)v11,
      owner,
      type_crouch);
    v12->m_states.m_size = (unsigned int)&survarium::player_logic_crouch_state::`vftable';
    v133 = v12;
  }
  else
  {
    v133 = 0;
  }
  v13 = survarium::g_allocator;
  v14 = type_info::raw_name(&survarium::player_logic_sprint_state `RTTI Type Descriptor');
  v16 = vostok::memory::doug_lea_allocator::malloc_impl(v15, (int)v13, 0x98u, v14, v101, v122, v127);
  v17 = v16;
  if ( v16 )
  {
    survarium::player_logic_base_state::player_logic_base_state(
      (survarium::player_logic_base_state *)v16,
      owner,
      type_sprint);
    *(_DWORD *)v17 = &survarium::player_logic_sprint_state::`vftable';
    *((_DWORD *)v17 + 12) = 0;
    *((_DWORD *)v17 + 20) = 0;
    v82.l_.a1_.t_ = (survarium::player_logic_sprint_state *)v17;
    *((_DWORD *)v17 + 28) = 0;
    *((_DWORD *)v17 + 36) = 0;
    v82.f_.f_ = (void (__thiscall *)(survarium::player_logic_sprint_state *, bool *))survarium::weapon_core_show_state_base::on_animation_end_impl;
    boost::function<void __cdecl (bool &)>::operator=<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::player_logic_sprint_state,bool &>,boost::_bi::list2<boost::_bi::value<survarium::player_logic_sprint_state *>,boost::arg<1>>>>(
      (boost::function<void __cdecl(bool &)> *)survarium::weapon_core_show_state_base::on_animation_end_impl,
      (boost::function1<void,vostok::physics::contact_point const &> *)(v17 + 112),
      v82);
    v17[40] = 1;
    v134 = (vostok::ai::fsm *)v17;
  }
  else
  {
    v134 = 0;
  }
  v18 = survarium::g_allocator;
  v19 = type_info::raw_name(&survarium::player_logic_jump_state `RTTI Type Descriptor');
  v21 = vostok::memory::doug_lea_allocator::malloc_impl(v20, (int)v18, 0x1C0u, v19, v102, v123, v128);
  v22 = (survarium::player_logic_jump_state *)v21;
  if ( v21 )
  {
    survarium::player_logic_base_state::player_logic_base_state(
      (survarium::player_logic_base_state *)v21,
      owner,
      type_jump);
    v22->__vftable = (survarium::player_logic_jump_state_vtbl *)&survarium::player_logic_jump_state::`vftable';
    survarium::jump_logic::jump_logic(v23, (int)&v22->m_logic, owner, v22);
    v22->m_sprint_initialize_callback.vtable = 0;
    v22->m_sprint_finalize_callback.vtable = 0;
    v132 = (vostok::ai::fsm *)v22;
  }
  else
  {
    v132 = 0;
  }
  v24 = survarium::g_allocator;
  v25 = type_info::raw_name(&survarium::player_logic_dead_state `RTTI Type Descriptor');
  v27 = vostok::memory::doug_lea_allocator::malloc_impl(v26, (int)v24, 0x34u, v25, v103, v124, v129);
  if ( v27 )
  {
    survarium::player_logic_base_state::player_logic_base_state(
      (survarium::player_logic_base_state *)v27,
      owner,
      type_dead);
    *(_DWORD *)v28 = &survarium::player_logic_dead_state::`vftable';
    *(_DWORD *)(v28 + 44) = 0;
    *(_DWORD *)(v28 + 48) = 0;
    *(_BYTE *)(v28 + 39) = 0;
    v131 = (vostok::ai::fsm *)v28;
  }
  else
  {
    v131 = 0;
  }
  vostok::ai::fsm::add_state(&ownera->m_logic, owner);
  vostok::ai::fsm::add_state(v133, v29);
  vostok::ai::fsm::add_state(v134, v30);
  vostok::ai::fsm::add_state(v132, v31);
  vostok::ai::fsm::add_state(v131, v32);
  v83.l_.a1_.t_ = owner;
  v83.f_.f_ = survarium::weapon_user_animations_selector::dead_predicate;
  boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
    v33,
    (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > *)&transition_predicate,
    v83,
    v104);
  vostok::ai::fsm::append_transition(
    v34,
    (vostok::ai::fsm_state *)ownera,
    (vostok::ai::fsm_state *)v131,
    &transition_predicate);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v35,
    (int *)&transition_predicate);
  v84.l_.a1_.t_ = owner;
  v84.f_.f_ = survarium::weapon_user_animations_selector::crouch_predicate;
  boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
    v36,
    (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > *)&transition_predicate,
    v84,
    v105);
  vostok::ai::fsm::append_transition(
    v37,
    (vostok::ai::fsm_state *)ownera,
    (vostok::ai::fsm_state *)v133,
    &transition_predicate);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v38,
    (int *)&transition_predicate);
  v85.l_.a1_.t_ = owner;
  v85.f_.f_ = (bool (__thiscall *)(survarium::weapon_user_animations_selector *))survarium::weapon_user_animations_selector::sprint_predicate;
  boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
    v39,
    (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > *)&transition_predicate,
    v85,
    v106);
  vostok::ai::fsm::append_transition(
    v40,
    (vostok::ai::fsm_state *)ownera,
    (vostok::ai::fsm_state *)v134,
    &transition_predicate);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v41,
    (int *)&transition_predicate);
  v86.l_.a1_.t_ = owner;
  v86.f_.f_ = (bool (__thiscall *)(survarium::weapon_user_animations_selector *))survarium::weapon_user_animations_selector::jump_predicate;
  boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
    v42,
    (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > *)&transition_predicate,
    v86,
    v107);
  vostok::ai::fsm::append_transition(
    v43,
    (vostok::ai::fsm_state *)ownera,
    (vostok::ai::fsm_state *)v132,
    &transition_predicate);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v44,
    (int *)&transition_predicate);
  v87.l_.a1_.t_ = owner;
  v87.f_.f_ = survarium::weapon_user_animations_selector::dead_predicate;
  boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
    v45,
    (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > *)&transition_predicate,
    v87,
    v108);
  vostok::ai::fsm::append_transition(
    v46,
    (vostok::ai::fsm_state *)v133,
    (vostok::ai::fsm_state *)v131,
    &transition_predicate);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v47,
    (int *)&transition_predicate);
  v88.l_.a1_.t_ = owner;
  v88.f_.f_ = (bool (__thiscall *)(survarium::weapon_user_animations_selector *))survarium::weapon_user_animations_selector::stand_from_crouch_predicate;
  boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
    v48,
    (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > *)&transition_predicate,
    v88,
    v109);
  vostok::ai::fsm::append_transition(
    v49,
    (vostok::ai::fsm_state *)v133,
    (vostok::ai::fsm_state *)ownera,
    &transition_predicate);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v50,
    (int *)&transition_predicate);
  v89.l_.a1_.t_ = owner;
  v89.f_.f_ = (bool (__thiscall *)(survarium::weapon_user_animations_selector *))survarium::weapon_user_animations_selector::sprint_predicate;
  boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
    v51,
    (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > *)&transition_predicate,
    v89,
    v110);
  vostok::ai::fsm::append_transition(
    v52,
    (vostok::ai::fsm_state *)v133,
    (vostok::ai::fsm_state *)v134,
    &transition_predicate);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v53,
    (int *)&transition_predicate);
  v90.l_.a1_.t_ = owner;
  v90.f_.f_ = survarium::weapon_user_animations_selector::dead_predicate;
  boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
    v54,
    (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > *)&transition_predicate,
    v90,
    v111);
  vostok::ai::fsm::append_transition(
    v55,
    (vostok::ai::fsm_state *)v134,
    (vostok::ai::fsm_state *)v131,
    &transition_predicate);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v56,
    (int *)&transition_predicate);
  v91.l_.a1_.t_ = owner;
  v91.f_.f_ = survarium::weapon_user_animations_selector::crouch_predicate;
  boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
    v57,
    (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > *)&transition_predicate,
    v91,
    v112);
  vostok::ai::fsm::append_transition(
    v58,
    (vostok::ai::fsm_state *)v134,
    (vostok::ai::fsm_state *)v133,
    &transition_predicate);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v59,
    (int *)&transition_predicate);
  v92.l_.a1_.t_ = owner;
  v92.f_.f_ = (bool (__thiscall *)(survarium::weapon_user_animations_selector *))survarium::weapon_user_animations_selector::not_sprint_predicate;
  boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
    v60,
    (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > *)&transition_predicate,
    v92,
    v113);
  vostok::ai::fsm::append_transition(
    v61,
    (vostok::ai::fsm_state *)v134,
    (vostok::ai::fsm_state *)ownera,
    &transition_predicate);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v62,
    (int *)&transition_predicate);
  v93.l_.a1_.t_ = owner;
  v93.f_.f_ = (bool (__thiscall *)(survarium::weapon_user_animations_selector *))survarium::weapon_user_animations_selector::jump_predicate;
  boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
    v63,
    (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > *)&transition_predicate,
    v93,
    v114);
  vostok::ai::fsm::append_transition(
    v64,
    (vostok::ai::fsm_state *)v134,
    (vostok::ai::fsm_state *)v132,
    &transition_predicate);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v65,
    (int *)&transition_predicate);
  v94.l_.a1_.t_ = owner;
  v94.f_.f_ = survarium::weapon_user_animations_selector::dead_predicate;
  boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
    v66,
    (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > *)&transition_predicate,
    v94,
    v115);
  vostok::ai::fsm::append_transition(
    v67,
    (vostok::ai::fsm_state *)v132,
    (vostok::ai::fsm_state *)v131,
    &transition_predicate);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v68,
    (int *)&transition_predicate);
  v95.l_.a1_.t_ = owner;
  v95.f_.f_ = survarium::weapon_user_animations_selector::broken_legs_predicate;
  boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
    v69,
    (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > *)&transition_predicate,
    v95,
    v116);
  vostok::ai::fsm::append_transition(
    v70,
    (vostok::ai::fsm_state *)v132,
    (vostok::ai::fsm_state *)v133,
    &transition_predicate);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v71,
    (int *)&transition_predicate);
  *(_DWORD *)&v96.l_ = v131;
  v96.f_ = (bool (__cdecl *)())vostok::collision::box_geometry_instance::is_valid;
  boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
    v72,
    (boost::_bi::bind_t<bool,bool (__cdecl*)(void),boost::_bi::list0> *)&transition_predicate,
    v96,
    v117);
  vostok::ai::fsm::append_transition(
    v73,
    (vostok::ai::fsm_state *)v132,
    (vostok::ai::fsm_state *)ownera,
    &transition_predicate);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v74,
    (int *)&transition_predicate);
  v97.l_.a1_.t_ = owner;
  v97.f_.f_ = (bool (__thiscall *)(survarium::weapon_user_animations_selector *))survarium::weapon_user_animations_selector::sprint_predicate;
  boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
    v75,
    (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > *)&transition_predicate,
    v97,
    v118);
  vostok::ai::fsm::append_transition(
    v76,
    (vostok::ai::fsm_state *)v132,
    (vostok::ai::fsm_state *)v134,
    &transition_predicate);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v77,
    (int *)&transition_predicate);
  v98.l_.a1_.t_ = owner;
  v98.f_.f_ = survarium::weapon_user_animations_selector::alive_predicate;
  boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
    v78,
    (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > *)&transition_predicate,
    v98,
    v119);
  vostok::ai::fsm::append_transition(
    v79,
    (vostok::ai::fsm_state *)v131,
    (vostok::ai::fsm_state *)ownera,
    &transition_predicate);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v80,
    (int *)&transition_predicate);
  v81 = v133;
  owner->m_stand_state = (survarium::player_logic_base_state *)ownera;
  owner->m_crouch_state = (survarium::player_logic_base_state *)v81;
}
