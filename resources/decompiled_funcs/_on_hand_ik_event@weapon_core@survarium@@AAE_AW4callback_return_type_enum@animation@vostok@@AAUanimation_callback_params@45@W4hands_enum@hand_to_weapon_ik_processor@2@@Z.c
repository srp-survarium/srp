vostok::animation::callback_return_type_enum __thiscall survarium::weapon_core::on_hand_ik_event(
        survarium::weapon_core *this,
        vostok::animation::animation_callback_params *params,
        survarium::hand_to_weapon_ik_processor::hands_enum hand)
{
  survarium::game_camera *v3; // ecx

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v3);
  survarium::hand_to_weapon_ik_processor::activate_hand(
    &this->m_hand_ik_processor,
    hand,
    params->domain_data == 9,
    params->callback_time_in_ms);
  return 0;
}
