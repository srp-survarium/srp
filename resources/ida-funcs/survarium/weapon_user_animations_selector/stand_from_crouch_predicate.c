BOOL __thiscall survarium::weapon_user_animations_selector::stand_from_crouch_predicate(
        survarium::weapon_user_animations_selector *this)
{
  vostok::physics::bt_character_controller *v2; // ecx

  return !survarium::weapon_user_animations_selector::crouch_predicate(this)
      && vostok::physics::bt_character_controller::can_stand(
           v2,
           *(int *)((char *)&dword_10E74 + (unsigned int)this->m_user));
}
