void __thiscall survarium::portable_interactive_object_core::deserialize(
        survarium::portable_interactive_object_core *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *client_reader,
        unsigned int time_offset)
{
  survarium::hit_animations_selector *v5; // ecx

  if ( s_ik_enable_on_legs_value )
    vostok::animation::legs_ik_solver::deserialize(
      (vostok::animation::legs_ik_solver *)this,
      (vostok::network_core::buffer_reader *)&this->m_legs_ik_solver,
      reader,
      time_offset);
  this->m_user_animations_selector.m_right_leg_is_supporting = vostok::network_core::buffer_reader::r<bool>(reader);
  vostok::ai::fsm::deserialize(&this->m_user_animations_selector.m_logic, reader, client_reader);
  survarium::hit_animations_selector::deserialize(v5, (int)&this->m_user_hit_animations_selector, reader, time_offset);
}
