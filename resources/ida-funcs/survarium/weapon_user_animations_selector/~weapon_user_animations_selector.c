void __usercall survarium::weapon_user_animations_selector::~weapon_user_animations_selector(
        survarium::weapon_user_animations_selector *this@<ecx>,
        int a2@<eax>)
{
  vostok::ai::fsm *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  vostok::ai::fsm *v5; // [esp-4h] [ebp-14h]
  const char *v6; // [esp+0h] [ebp-10h]
  const char *v7; // [esp+4h] [ebp-Ch]
  unsigned int v8; // [esp+8h] [ebp-8h]
  vostok::ai::fsm_state *pointer; // [esp+Ch] [ebp-4h] BYREF

  vostok::ai::fsm::clear_transitions(&this->m_logic, a2);
  while ( 1 )
  {
    pointer = vostok::ai::fsm::pop_state(v3, (_DWORD *)a2);
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
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a2 + 56));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v4,
    (int *)(a2 + 24));
}
