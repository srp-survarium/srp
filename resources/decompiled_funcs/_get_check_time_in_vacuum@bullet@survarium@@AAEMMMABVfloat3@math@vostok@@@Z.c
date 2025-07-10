double __thiscall survarium::bullet::get_check_time_in_vacuum(
        survarium::bullet *this,
        float start_low,
        float high,
        const vostok::math::float3 *gravity)
{
  vostok::math::float3 *v4; // esi
  vostok::math::float3 *v5; // eax
  vostok::math::float3 *v6; // eax
  vostok::math::float3_pod *v7; // ecx
  vostok::math::float3 *v9; // eax
  vostok::math::float3_pod *v10; // ecx
  float v11; // xmm0_4
  long double v12; // st7
  survarium::game_camera *v13; // ecx
  survarium::game_camera *v14; // ecx
  survarium::game_camera *v15; // ecx
  vostok::math::float3 v17; // [esp+18h] [ebp-50h] BYREF
  vostok::math::float3 v18; // [esp+24h] [ebp-44h] BYREF
  vostok::math::float3 v19; // [esp+30h] [ebp-38h] BYREF
  vostok::math::float3 v20; // [esp+3Ch] [ebp-2Ch] BYREF
  float value; // [esp+48h] [ebp-20h] BYREF
  float max_test_distance; // [esp+4Ch] [ebp-1Ch]
  float result; // [esp+50h] [ebp-18h] BYREF
  float fall_down_velocity_magnitude; // [esp+54h] [ebp-14h] BYREF
  float time; // [esp+58h] [ebp-10h]
  float time_delta; // [esp+5Ch] [ebp-Ch] BYREF
  float positive_gravity; // [esp+60h] [ebp-8h]
  float time_to_fly; // [esp+64h] [ebp-4h]

  max_test_distance = this->m_max_distance - this->m_flown_distance;
  time_delta = high - start_low;
  value = vostok::math::sqr<float>(&time_delta) * 0.5;
  v4 = vostok::math::operator*(gravity, &v20, &value);
  v5 = vostok::math::operator*(&this->m_start_velocity, &v19, &time_delta);
  v6 = vostok::math::operator+(v4, v5, &v18);
  time_to_fly = vostok::math::float3_pod::length(v7, &v6->x);
  if ( max_test_distance >= time_to_fly )
    return high;
  v9 = survarium::bullet::compute_trajectory_velocity(this, &v17, start_low, gravity);
  fall_down_velocity_magnitude = vostok::math::float3_pod::length(v10, &v9->x);
  positive_gravity = -gravity->y;
  v11 = vostok::math::sqr<float>(&fall_down_velocity_magnitude);
  v12 = vostok::math::sqrt(v11 + (float)((float)(2.0 * max_test_distance) * positive_gravity));
  time = (v12 - fall_down_velocity_magnitude) / positive_gravity;
  survarium::weapon_user_dead_state::finalize(v13);
  survarium::weapon_user_dead_state::finalize(v14);
  result = start_low + time;
  vostok::math::clamp<float>(&result, start_low, high);
  survarium::weapon_user_dead_state::finalize(v15);
  return result;
}
