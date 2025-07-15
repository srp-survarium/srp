void __usercall survarium::jump_logic::initialize_logic(survarium::jump_logic *this@<ecx>, int a2@<edi>)
{
  _DWORD *v2; // eax
  _DWORD *v3; // eax
  boost::function<bool __cdecl(void)> *v4; // ecx
  vostok::ai::fsm *v5; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  boost::function<bool __cdecl(void)> *v7; // ecx
  vostok::ai::fsm *v8; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  _DWORD *v10; // eax
  boost::function<bool __cdecl(void)> *v11; // ecx
  vostok::ai::fsm *v12; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v13; // ecx
  boost::_bi::bind_t<bool,bool (__cdecl*)(void),boost::_bi::list0> v14; // [esp-8h] [ebp-40h]
  boost::_bi::bind_t<bool,bool (__cdecl*)(void),boost::_bi::list0> v15; // [esp-8h] [ebp-40h]
  boost::_bi::bind_t<bool,bool (__cdecl*)(void),boost::_bi::list0> v16; // [esp-8h] [ebp-40h]
  int v17; // [esp+0h] [ebp-38h]
  int v18; // [esp+0h] [ebp-38h]
  int v19; // [esp+0h] [ebp-38h]
  boost::function<bool __cdecl(void)> transition_predicate; // [esp+8h] [ebp-30h] BYREF
  vostok::ai::fsm_state *from; // [esp+30h] [ebp-8h]
  vostok::ai::fsm_state *to; // [esp+34h] [ebp-4h]

  vostok::ai::fsm::add_state((vostok::ai::fsm *)(a2 + 148), (_DWORD *)a2);
  vostok::ai::fsm::add_state((vostok::ai::fsm *)(a2 + 200), v2);
  vostok::ai::fsm::add_state((vostok::ai::fsm *)(a2 + 256), v3);
  *(_DWORD *)&v14.l_ = from;
  v14.f_ = (bool (__cdecl *)())vostok::collision::box_geometry_instance::is_valid;
  boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
    v4,
    (boost::_bi::bind_t<bool,bool (__cdecl*)(void),boost::_bi::list0> *)&transition_predicate,
    v14,
    v17);
  vostok::ai::fsm::append_transition(
    v5,
    (vostok::ai::fsm_state *)(a2 + 148),
    (vostok::ai::fsm_state *)(a2 + 200),
    &transition_predicate);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v6,
    (int *)&transition_predicate);
  *(_DWORD *)&v15.l_ = from;
  v15.f_ = (bool (__cdecl *)())vostok::collision::box_geometry_instance::is_valid;
  boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
    v7,
    (boost::_bi::bind_t<bool,bool (__cdecl*)(void),boost::_bi::list0> *)&transition_predicate,
    v15,
    v18);
  vostok::ai::fsm::append_transition(
    v8,
    (vostok::ai::fsm_state *)(a2 + 200),
    (vostok::ai::fsm_state *)(a2 + 256),
    &transition_predicate);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v9,
    (int *)&transition_predicate);
  from = (vostok::ai::fsm_state *)(a2 + 56);
  vostok::ai::fsm::add_state((vostok::ai::fsm *)(a2 + 56), (_DWORD *)a2);
  to = (vostok::ai::fsm_state *)(a2 + 104);
  vostok::ai::fsm::add_state((vostok::ai::fsm *)(a2 + 104), v10);
  *(_DWORD *)&v16.l_ = from;
  v16.f_ = (bool (__cdecl *)())vostok::collision::box_geometry_instance::is_valid;
  boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
    v11,
    (boost::_bi::bind_t<bool,bool (__cdecl*)(void),boost::_bi::list0> *)&transition_predicate,
    v16,
    v19);
  vostok::ai::fsm::append_transition(v12, from, to, &transition_predicate);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v13,
    (int *)&transition_predicate);
}
