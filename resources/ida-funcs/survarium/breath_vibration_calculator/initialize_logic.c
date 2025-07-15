void __usercall survarium::breath_vibration_calculator::initialize_logic(
        survarium::breath_vibration_calculator *this@<ecx>,
        survarium::breath_vibration_calculator *a2@<edi>)
{
  vostok::memory::doug_lea_allocator *v2; // esi
  char *v3; // eax
  vostok::memory::doug_lea_allocator *v4; // ecx
  char *v5; // eax
  vostok::memory::doug_lea_allocator *v6; // esi
  char *v7; // eax
  vostok::memory::doug_lea_allocator *v8; // ecx
  char *v9; // eax
  vostok::memory::doug_lea_allocator *v10; // esi
  char *v11; // eax
  vostok::memory::doug_lea_allocator *v12; // ecx
  char *v13; // eax
  vostok::ai::fsm_state *v14; // ebx
  _DWORD *v15; // eax
  _DWORD *v16; // eax
  boost::function<bool __cdecl(void)> *v17; // ecx
  vostok::ai::fsm *v18; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v19; // ecx
  boost::function<bool __cdecl(void)> *v20; // ecx
  vostok::ai::fsm *v21; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v22; // ecx
  boost::function<bool __cdecl(void)> *v23; // ecx
  vostok::ai::fsm *v24; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v25; // ecx
  boost::function<bool __cdecl(void)> *v26; // ecx
  vostok::ai::fsm *v27; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v28; // ecx
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::breath_vibration_calculator>,boost::_bi::list1<boost::_bi::value<survarium::breath_vibration_calculator *> > > v29; // [esp-8h] [ebp-40h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::breath_vibration_calculator>,boost::_bi::list1<boost::_bi::value<survarium::breath_vibration_calculator *> > > v30; // [esp-8h] [ebp-40h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::breath_vibration_calculator>,boost::_bi::list1<boost::_bi::value<survarium::breath_vibration_calculator *> > > v31; // [esp-8h] [ebp-40h]
  const char *v32; // [esp+0h] [ebp-38h]
  const char *v33; // [esp+0h] [ebp-38h]
  const char *v34; // [esp+0h] [ebp-38h]
  int v35; // [esp+0h] [ebp-38h]
  int v36; // [esp+0h] [ebp-38h]
  int v37; // [esp+0h] [ebp-38h]
  int v38; // [esp+0h] [ebp-38h]
  const char *v39; // [esp+4h] [ebp-34h]
  const char *v40; // [esp+4h] [ebp-34h]
  const char *v41; // [esp+4h] [ebp-34h]
  boost::function<bool __cdecl(void)> transition_predicate; // [esp+8h] [ebp-30h] BYREF
  vostok::ai::fsm *v43; // [esp+2Ch] [ebp-Ch]
  vostok::ai::fsm *v44; // [esp+30h] [ebp-8h]
  vostok::ai::fsm *v45; // [esp+34h] [ebp-4h]

  v2 = survarium::g_allocator;
  v3 = type_info::raw_name(&survarium::breath_state_normal `RTTI Type Descriptor');
  v5 = vostok::memory::doug_lea_allocator::malloc_impl(
         v4,
         (int)v2,
         0x2Cu,
         v3,
         v32,
         v39,
         (const unsigned int)transition_predicate.vtable);
  if ( v5 )
  {
    *((_DWORD *)v5 + 2) = 0;
    *((_DWORD *)v5 + 4) = 0;
    *((_DWORD *)v5 + 5) = 0;
    *((_DWORD *)v5 + 9) = &a2->m_speed_factor;
    *(_DWORD *)v5 = &survarium::breath_state_normal::`vftable';
    *((_DWORD *)v5 + 10) = &a2->m_penalty_factor;
    v45 = (vostok::ai::fsm *)v5;
  }
  else
  {
    v45 = 0;
  }
  v6 = survarium::g_allocator;
  v7 = type_info::raw_name(&survarium::breath_state_holding `RTTI Type Descriptor');
  v9 = vostok::memory::doug_lea_allocator::malloc_impl(
         v8,
         (int)v6,
         0x50u,
         v7,
         v33,
         v40,
         (const unsigned int)transition_predicate.vtable);
  if ( v9 )
  {
    *((_DWORD *)v9 + 2) = 0;
    *((_DWORD *)v9 + 4) = 0;
    *((_DWORD *)v9 + 5) = 0;
    *((_DWORD *)v9 + 9) = &a2->m_breath_holding_reserve;
    *(_DWORD *)v9 = &survarium::breath_state_holding::`vftable';
    *((_DWORD *)v9 + 10) = 0;
    *((_DWORD *)v9 + 18) = &a2->m_speed_factor;
    v43 = (vostok::ai::fsm *)v9;
  }
  else
  {
    v43 = 0;
  }
  v10 = survarium::g_allocator;
  v11 = type_info::raw_name(&survarium::breath_state_shortbreathing `RTTI Type Descriptor');
  v13 = vostok::memory::doug_lea_allocator::malloc_impl(
          v12,
          (int)v10,
          0x2Cu,
          v11,
          v34,
          v41,
          (const unsigned int)transition_predicate.vtable);
  if ( v13 )
  {
    *((_DWORD *)v13 + 2) = 0;
    *((_DWORD *)v13 + 4) = 0;
    *((_DWORD *)v13 + 5) = 0;
    *((_DWORD *)v13 + 9) = &a2->m_speed_factor;
    *(_DWORD *)v13 = &survarium::breath_state_shortbreathing::`vftable';
    *((_DWORD *)v13 + 10) = &a2->m_penalty_factor;
    v44 = (vostok::ai::fsm *)v13;
  }
  else
  {
    v44 = 0;
  }
  vostok::ai::fsm::add_state(v45, a2);
  v14 = (vostok::ai::fsm_state *)v43;
  vostok::ai::fsm::add_state(v43, v15);
  vostok::ai::fsm::add_state(v44, v16);
  v29.l_.a1_.t_ = a2;
  v29.f_.f_ = (bool (__thiscall *)(survarium::breath_vibration_calculator *))survarium::breath_vibration_calculator::can_hold_breath;
  boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
    v17,
    (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::breath_vibration_calculator>,boost::_bi::list1<boost::_bi::value<survarium::breath_vibration_calculator *> > > *)&transition_predicate,
    v29,
    v35);
  vostok::ai::fsm::append_transition(v18, (vostok::ai::fsm_state *)v45, v14, &transition_predicate);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v19,
    (int *)&transition_predicate);
  v30.l_.a1_.t_ = a2;
  v30.f_.f_ = (bool (__thiscall *)(survarium::breath_vibration_calculator *))survarium::breath_vibration_calculator::not_holding_breath;
  boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
    v20,
    (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::breath_vibration_calculator>,boost::_bi::list1<boost::_bi::value<survarium::breath_vibration_calculator *> > > *)&transition_predicate,
    v30,
    v36);
  vostok::ai::fsm::append_transition(v21, v14, (vostok::ai::fsm_state *)v45, &transition_predicate);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v22,
    (int *)&transition_predicate);
  v31.l_.a1_.t_ = a2;
  v31.f_.f_ = (bool (__thiscall *)(survarium::breath_vibration_calculator *))survarium::breath_vibration_calculator::insufficient_breath;
  boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
    v23,
    (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::breath_vibration_calculator>,boost::_bi::list1<boost::_bi::value<survarium::breath_vibration_calculator *> > > *)&transition_predicate,
    v31,
    v37);
  vostok::ai::fsm::append_transition(v24, v14, (vostok::ai::fsm_state *)v44, &transition_predicate);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v25,
    (int *)&transition_predicate);
  boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
    v26,
    &transition_predicate,
    (bool (__cdecl *)())vostok::collision::box_geometry_instance::is_valid,
    v38);
  vostok::ai::fsm::append_transition(
    v27,
    (vostok::ai::fsm_state *)v44,
    (vostok::ai::fsm_state *)v45,
    &transition_predicate);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v28,
    (int *)&transition_predicate);
}
