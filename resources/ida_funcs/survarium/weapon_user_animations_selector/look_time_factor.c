double __thiscall survarium::weapon_user_animations_selector::look_time_factor(
        survarium::weapon_user_animations_selector *this)
{
  float v2; // [esp+8h] [ebp-Ch]

  v2 = *(float *)&clear_value - 0.0000099999997;
  ((double (__thiscall *)(survarium::base_player *))this->m_user->get_look_pitch)(this->m_user);
  vostok::math::min();
  return v2;
}
