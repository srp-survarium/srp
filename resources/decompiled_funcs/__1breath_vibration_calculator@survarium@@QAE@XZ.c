void __thiscall survarium::breath_vibration_calculator::~breath_vibration_calculator(
        survarium::breath_vibration_calculator *this)
{
  survarium::game_camera *v1; // ecx
  vostok::memory::doug_lea_allocator *v2; // eax
  vostok::ai::fsm_state *state; // [esp+14h] [ebp-4h] BYREF

  while ( 1 )
  {
    state = vostok::ai::fsm::pop_state(&this->m_logic);
    if ( !state )
      break;
    survarium::weapon_user_dead_state::finalize(v1);
    vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,survarium::inventory,vostok::memory::detail::call_destructor_predicate>(
      v2,
      (vostok::sound::sound_scene **)&state);
  }
  survarium::weapon_user_dead_state::finalize(v1);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
