void __thiscall survarium::weapon_core_shotgun_reload_state::initialize_logic(
        survarium::weapon_core_shotgun_reload_state *this,
        survarium::weapon_core_shotgun_reload_base_substate *reload_start,
        vostok::ai::fsm *reload_one_round,
        vostok::ai::fsm *reload_finish,
        vostok::ai::fsm *a5)
{
  vostok::memory::doug_lea_allocator *v5; // esi
  char *v6; // eax
  vostok::memory::doug_lea_allocator *v7; // ecx
  char *v8; // eax
  int v9; // ecx
  vostok::ai::fsm *v10; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v11; // ecx
  boost::function<bool __cdecl(void)> *v12; // ecx
  vostok::ai::fsm *v13; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v14; // ecx
  vostok::ai::fsm *v15; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v16; // ecx
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core_shotgun_reload_state>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core_shotgun_reload_state *> > > v17; // [esp-14h] [ebp-44h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core_shotgun_reload_state>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core_shotgun_reload_state *> > > v18; // [esp-14h] [ebp-44h]
  boost::_bi::bind_t<bool,bool (__cdecl*)(void),boost::_bi::list0> v19; // [esp-8h] [ebp-38h]
  const char *v20; // [esp+0h] [ebp-30h]
  int v21; // [esp+0h] [ebp-30h]
  const char *v22; // [esp+4h] [ebp-2Ch]
  unsigned int v23; // [esp+8h] [ebp-28h]
  boost::function<bool __cdecl(void)> f; // [esp+10h] [ebp-20h] BYREF

  v5 = survarium::g_allocator;
  v6 = type_info::raw_name(&vostok::ai::fsm `RTTI Type Descriptor');
  v8 = vostok::memory::doug_lea_allocator::malloc_impl(v7, (int)v5, 0x38u, v6, v20, v22, v23);
  if ( v8 )
  {
    *(_DWORD *)v8 = 0;
    *((_DWORD *)v8 + 2) = 0;
    *((_DWORD *)v8 + 3) = 0;
    *((_DWORD *)v8 + 4) = 0;
    *((_DWORD *)v8 + 6) = 0;
  }
  else
  {
    v8 = 0;
  }
  reload_start->m_user_animations[1][1].m_object = (vostok::resources::managed_resource *)v8;
  vostok::ai::fsm::add_state(reload_one_round, v8);
  vostok::ai::fsm::add_state(reload_finish, &reload_start->m_user_animations[1][1].m_object->__vftable);
  vostok::ai::fsm::add_state(a5, &reload_start->m_user_animations[1][1].m_object->__vftable);
  *(_DWORD *)(v9 + 344) = (char *)&reload_start->m_user_animations[1][0].m_object + 1;
  f.functor.obj_ptr = reload_start;
  f.vtable = (boost::detail::function::vtable_base *)survarium::weapon_core_shotgun_reload_state::player_wants_to_fire_predicate;
  (&f.vtable)[1] = 0;
  HIDWORD(v17.f_.f_) = survarium::weapon_core_shotgun_reload_state::player_wants_to_fire_predicate;
  *(_QWORD *)&v17.l_.a1_.t_ = __PAIR64__((unsigned int)reload_start, 0);
  LODWORD(v17.f_.f_) = &f;
  boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
    0,
    v17,
    (int)f.functor.vostok_pointer_size_alignment[1]);
  vostok::ai::fsm::append_transition(v10, (vostok::ai::fsm_state *)reload_one_round, (vostok::ai::fsm_state *)a5, &f);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v11,
    (int *)&f);
  *(_DWORD *)&v19.l_ = (&f.vtable)[1];
  v19.f_ = (bool (__cdecl *)())vostok::collision::box_geometry_instance::is_valid;
  boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
    v12,
    (boost::_bi::bind_t<bool,bool (__cdecl*)(void),boost::_bi::list0> *)&f,
    v19,
    v21);
  vostok::ai::fsm::append_transition(
    v13,
    (vostok::ai::fsm_state *)reload_one_round,
    (vostok::ai::fsm_state *)reload_finish,
    &f);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v14,
    (int *)&f);
  f.functor.obj_ptr = reload_start;
  f.vtable = (boost::detail::function::vtable_base *)survarium::weapon_core_shotgun_reload_state::finish_reload_predicate;
  (&f.vtable)[1] = 0;
  HIDWORD(v18.f_.f_) = survarium::weapon_core_shotgun_reload_state::finish_reload_predicate;
  *(_QWORD *)&v18.l_.a1_.t_ = __PAIR64__((unsigned int)reload_start, 0);
  LODWORD(v18.f_.f_) = &f;
  boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
    0,
    v18,
    (int)f.functor.vostok_pointer_size_alignment[1]);
  vostok::ai::fsm::append_transition(v15, (vostok::ai::fsm_state *)reload_finish, (vostok::ai::fsm_state *)a5, &f);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v16,
    (int *)&f);
}
