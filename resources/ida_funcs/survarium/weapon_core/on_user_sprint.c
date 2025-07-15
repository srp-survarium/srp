void __thiscall survarium::weapon_core::on_user_sprint(survarium::weapon_core *this, bool user_is_sprinting)
{
  bool v2; // [esp+3h] [ebp-9h]

  v2 = survarium::weapon_core::is_double_handed(this, (int)this) || !user_is_sprinting;
  survarium::hand_to_weapon_ik_processor::activate_hand(
    &this->m_hand_ik_processor,
    left,
    v2,
    this->m_last_tick_time_in_ms);
}
