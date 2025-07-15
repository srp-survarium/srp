vostok::math::float3 *__thiscall survarium::weapon_core::get_dispersed_bullet_dir(
        survarium::weapon_core *this,
        vostok::math::float3 *result)
{
  survarium::game_camera *v2; // ecx
  const vostok::math::float3 *v3; // eax
  const vostok::math::float3 *v4; // ebx
  survarium::game_camera *v5; // ecx
  const vostok::math::float3 *v6; // eax
  vostok::math::float4x4 *rotation; // eax
  survarium::game_camera *v8; // ecx
  const vostok::math::float3 *v9; // eax
  const vostok::math::float3 *v10; // ebx
  float v11; // xmm0_4
  vostok::math::float4x4 *v12; // eax
  unsigned int v14; // [esp+14h] [ebp-E8h]
  vostok::math::float3 v16; // [esp+D4h] [ebp-28h] BYREF
  float dispersion_angle; // [esp+E0h] [ebp-1Ch]
  float dispersion_amount; // [esp+E4h] [ebp-18h]
  const vostok::math::float3 *rot_axis; // [esp+E8h] [ebp-14h]
  float random_k; // [esp+ECh] [ebp-10h]
  vostok::math::float3 bullet_direction; // [esp+F0h] [ebp-Ch] BYREF

  *(float *)&v14 = survarium::normal_random::rand_n(&this->m_normal_random, 1.0);
  random_k = vostok::math::clamp_r<float>((__m128)0xBF800000, v14, 1.0).m128_f32[0];
  dispersion_amount = survarium::dispersion_calculator::get_dispersion(&this->m_dispersion_calculator) * random_k;
  dispersion_angle = vostok::math::random32::random_f(&this->m_random, 6.2831855);
  survarium::weapon_user_dead_state::finalize(v2);
  v4 = v3;
  survarium::weapon_user_dead_state::finalize(v5);
  rotation = vostok::math::create_rotation(v6, dispersion_angle);
  vostok::math::float4x4::transform_direction(v4, &v16, rotation);
  rot_axis = &v16;
  survarium::weapon_user_dead_state::finalize(v8);
  v10 = v9;
  v11 = dispersion_amount;
  vostok::math::deg2rad();
  v12 = vostok::math::create_rotation(rot_axis, v11);
  vostok::math::float4x4::transform_direction(v10, &bullet_direction, v12);
  *result = bullet_direction;
  return result;
}
