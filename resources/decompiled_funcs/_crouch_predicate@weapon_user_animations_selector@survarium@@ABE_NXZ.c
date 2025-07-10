bool __thiscall survarium::weapon_user_animations_selector::crouch_predicate(
        survarium::weapon_user_animations_selector *this)
{
  vostok::physics::bt_character_controller *v1; // ecx
  bool v3; // [esp+0h] [ebp-Ch]

  v3 = 1;
  if ( !survarium::weapon_user_animations_selector::broken_legs_predicate(this) )
  {
    if ( (this->m_user->input(this->m_user)->actions_mask & 0x100) == 0 )
      return 0;
    this->m_user->physics_controller(this->m_user);
    if ( !vostok::physics::bt_character_controller::can_crouch(v1) )
      return 0;
  }
  return v3;
}
