void __thiscall survarium::legs_ik_processor::~legs_ik_processor(survarium::legs_ik_processor *this)
{
  vostok::memory::doug_lea_allocator *v1; // eax
  survarium::game_camera *v2; // ecx

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,survarium::legs_ik_drawer,vostok::memory::detail::call_destructor_predicate>(
    v1,
    &this->m_drawer);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_toe_interpolator);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_heel_interpolator);
  survarium::weapon_user_dead_state::finalize(v2);
}
