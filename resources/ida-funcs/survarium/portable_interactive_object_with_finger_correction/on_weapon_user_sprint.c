void __thiscall survarium::portable_interactive_object_with_finger_correction::on_weapon_user_sprint(
        survarium::portable_interactive_object_with_finger_correction *this,
        bool is_double_handed,
        bool user_is_sprinting)
{
  char v4; // dl
  unsigned int v5; // [esp+0h] [ebp-4h]

  survarium::portable_interactive_object::on_weapon_user_sprint(
    this,
    (unsigned int)this,
    is_double_handed,
    user_is_sprinting);
  v4 = is_double_handed || !user_is_sprinting;
  vostok::animation::fingers_to_weapon_corrector::activate_hand(
    left,
    v4,
    &this->m_fingers_corrector,
    idle_locator_set,
    this->m_user->m_current_time_in_ms,
    v5);
}
