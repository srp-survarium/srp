double __thiscall survarium::pseudo_random::random_f(survarium::pseudo_random *this, float range)
{
  survarium::game_camera *v2; // ecx
  float _Y; // [esp+4h] [ebp-40h]
  float v5; // [esp+8h] [ebp-3Ch]
  float v6; // [esp+18h] [ebp-2Ch]
  float v7; // [esp+1Ch] [ebp-28h]
  float t; // [esp+34h] [ebp-10h]
  float k; // [esp+3Ch] [ebp-8h]

  t = fmod(this->m_time, 3.1415927 * 24.0);
  v7 = vostok::math::sin((float)(t - 1.5707964) / 12.0);
  survarium::weapon_user_dead_state::finalize(v2);
  v6 = vostok::math::pow_impl(5u, v7);
  _Y = vostok::math::sin(t);
  v5 = vostok::math::pow(2.73, _Y);
  k = v5 - vostok::math::cos(4.0 * t) * 2.0 + v6;
  fmod(k, 1.0);
  vostok::math::abs();
  return (float)((float)(4.0 * t) * range);
}
