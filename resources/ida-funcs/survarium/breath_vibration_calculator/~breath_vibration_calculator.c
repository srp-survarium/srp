void __usercall survarium::breath_vibration_calculator::~breath_vibration_calculator(
        survarium::breath_vibration_calculator *this@<ecx>,
        _DWORD *a2@<eax>)
{
  vostok::ai::fsm *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  vostok::ai::fsm *v5; // [esp-4h] [ebp-14h]
  const char *v6; // [esp+0h] [ebp-10h]
  const char *v7; // [esp+4h] [ebp-Ch]
  unsigned int v8; // [esp+8h] [ebp-8h]
  vostok::ai::fsm_state *pointer; // [esp+Ch] [ebp-4h] BYREF

  vostok::ai::fsm::clear_transitions(&this->m_logic, (int)a2);
  while ( 1 )
  {
    pointer = vostok::ai::fsm::pop_state(v3, a2);
    if ( !pointer )
      break;
    vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::scene_view>(
      survarium::g_allocator,
      &pointer,
      v6,
      v7,
      v8);
    v3 = v5;
  }
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v4, a2 + 6);
}
