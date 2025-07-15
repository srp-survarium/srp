double __thiscall survarium::weapon_recoil_calculator::get_random_angle(
        survarium::weapon_recoil_calculator *this,
        float range)
{
  survarium::base_player *user; // [esp+10h] [ebp-Ch]
  float v5; // [esp+18h] [ebp-4h]

  if ( !s_recoil_use_pseudo_random_value )
    return vostok::math::random32::random_f(&this->m_random, range);
  user = survarium::weapon_core::get_user((survarium::weapon_core *)this, (int)this->m_weapon);
  v5 = (double)user->local_time(user, this->m_last_time_in_ms) * 0.001;
  this->m_pseudo_random.m_time = v5;
  return survarium::pseudo_random::random_f(&this->m_pseudo_random, range);
}
