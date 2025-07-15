void __thiscall survarium::weapon_core::update_recoil(
        survarium::weapon_core *this,
        unsigned int current_time_in_ms,
        float time_scale)
{
  survarium::weapon_user_state_enum current_state_id; // eax
  bool is_aimed; // [esp-8h] [ebp-10h]

  is_aimed = survarium::weapon_core::is_aimed(this, (int)this);
  current_state_id = survarium::weapon_user_animations_selector::get_current_state_id(&this->m_user_animations_selector);
  survarium::recoil_calculator::tick(
    &this->m_recoil_calculator,
    current_state_id,
    is_aimed,
    current_time_in_ms,
    time_scale);
}
