double __thiscall survarium::weapon_recoil_calculator::get_random_amount(
        survarium::weapon_recoil_calculator *this,
        float range)
{
  float angle; // [esp+4h] [ebp-28h]
  survarium::base_player *user; // [esp+18h] [ebp-14h]

  if ( s_recoil_use_pseudo_random_value )
  {
    user = survarium::weapon_core::get_user((survarium::weapon_core *)this, (int)this->m_weapon);
    angle = (double)user->local_time(user, this->m_last_time_in_ms) * 0.0099999998;
    vostok::math::sin(angle);
  }
  else
  {
    vostok::math::random32::random_f(&this->m_random, 1.0);
  }
  vostok::math::max();
  return 0.25 * range;
}
