void __thiscall survarium::jump_logic::~jump_logic(survarium::jump_logic *this)
{
  survarium::game_camera *v1; // ecx
  vostok::memory::doug_lea_allocator *v2; // eax
  vostok::memory::doug_lea_allocator *v3; // eax
  survarium::game_camera *v4; // ecx
  vostok::ai::fsm_state *state; // [esp+28h] [ebp-4h] BYREF

  vostok::ai::fsm::clear_transitions(this->m_logic);
  while ( 1 )
  {
    state = vostok::ai::fsm::pop_state(this->m_logic);
    if ( !state )
      break;
    survarium::weapon_user_dead_state::finalize(v1);
    vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,survarium::inventory,vostok::memory::detail::call_destructor_predicate>(
      v2,
      (vostok::sound::sound_scene **)&state);
  }
  survarium::weapon_user_dead_state::finalize(v1);
  vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,vostok::ai::fsm,vostok::memory::detail::call_destructor_predicate>(
    v3,
    &this->m_logic);
  survarium::weapon_user_dead_state::finalize(v4);
}
