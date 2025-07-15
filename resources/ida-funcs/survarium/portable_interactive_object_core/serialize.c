void __thiscall survarium::portable_interactive_object_core::serialize(
        survarium::portable_interactive_object_core *this,
        vostok::network_core::buffer_writer *writer,
        const vostok::network_core::buffer_writer *client_writer,
        vostok::animation::legs_ik_solver *time_offset)
{
  vostok::ai::fsm *v5; // ecx
  survarium::hit_animations_selector *v6; // ecx

  if ( s_ik_enable_on_legs_value )
    vostok::animation::legs_ik_solver::serialize(
      (vostok::animation::legs_ik_solver *)this,
      (int)&this->m_legs_ik_solver,
      writer,
      time_offset);
  vostok::network_core::buffer_writer::w<bool>(
    &this->m_user_animations_selector.m_right_leg_is_supporting,
    (vostok::network_core::buffer_writer *)this,
    writer,
    ".\\weapon_user_animations_selector.cpp",
    (const char *)0xBA,
    "survarium::weapon_user_animations_selector::serialize",
    "m_right_leg_is_supporting");
  vostok::ai::fsm::serialize(v5, (int)&this->m_user_animations_selector, writer, client_writer);
  survarium::hit_animations_selector::serialize(
    v6,
    (int)&this->m_user_hit_animations_selector,
    writer,
    (const unsigned int)time_offset);
}
