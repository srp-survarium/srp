void __thiscall survarium::weapon_user_animations_selector::~weapon_user_animations_selector(
        survarium::weapon_user_animations_selector *this)
{
  survarium::game_camera *v1; // ecx
  vostok::memory::doug_lea_allocator *v2; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v3; // ecx
  survarium::game_camera *v4; // ecx
  vostok::ai::fsm_state *state; // [esp+1Ch] [ebp-4h] BYREF

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
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&this->m_animations);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v3,
    (int *)&this->m_leg_damaged_subscriber);
  survarium::weapon_user_dead_state::finalize(v4);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
