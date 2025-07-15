vostok::math::float3 *__thiscall survarium::bullet::compute_parabolic_position(
        survarium::bullet *this,
        vostok::math::float3 *result,
        float time,
        const vostok::math::float3 *gravity)
{
  vostok::math::float3 *v4; // esi
  vostok::math::float3 *v5; // eax
  vostok::math::float3 *v6; // eax
  vostok::math::float3 *v8; // esi
  vostok::math::float3 *v9; // eax
  vostok::math::float3 *v10; // edi
  vostok::math::float3 *v11; // eax
  vostok::math::float3 *v12; // eax
  vostok::math::float3 *v13; // eax
  vostok::math::float3 v15; // [esp+28h] [ebp-88h] BYREF
  vostok::math::float3 v16; // [esp+34h] [ebp-7Ch] BYREF
  vostok::math::float3 v17; // [esp+40h] [ebp-70h] BYREF
  vostok::math::float3 v18; // [esp+4Ch] [ebp-64h] BYREF
  vostok::math::float3 v19; // [esp+58h] [ebp-58h] BYREF
  float v20; // [esp+64h] [ebp-4Ch] BYREF
  vostok::math::float3 v21; // [esp+68h] [ebp-48h] BYREF
  vostok::math::float3 v22; // [esp+74h] [ebp-3Ch] BYREF
  vostok::math::float3 v23; // [esp+80h] [ebp-30h] BYREF
  vostok::math::float3 v24; // [esp+8Ch] [ebp-24h] BYREF
  float v25; // [esp+98h] [ebp-18h] BYREF
  float value; // [esp+9Ch] [ebp-14h] BYREF
  vostok::math::float3 xz_velocity; // [esp+A0h] [ebp-10h] BYREF
  float sqr_t_div_2; // [esp+ACh] [ebp-4h] BYREF

  vostok::math::float3::float3(
    &xz_velocity,
    COERCE_UNSIGNED_INT(this->m_start_velocity.x),
    COERCE_UNSIGNED_INT(0.0),
    this->m_start_velocity.z);
  value = vostok::math::float3_pod::squared_length((SpeedTree::Vec3 *)&xz_velocity);
  if ( vostok::math::is_zero<float>(&value, &epsilon_5_84) )
  {
    v25 = vostok::math::sqr<float>(&time) * 0.5;
    v4 = vostok::math::operator*(gravity, &v24, &v25);
    v5 = vostok::math::operator*(&this->m_start_velocity, &v23, &time);
    v6 = vostok::math::operator+(v5, &this->m_start_position, &v22);
    vostok::math::operator+(v4, v6, result);
  }
  else
  {
    sqr_t_div_2 = vostok::math::sqr<float>(&time) * 0.5;
    v20 = -this->m_current_resistance;
    v8 = vostok::math::operator*(gravity, &v21, &sqr_t_div_2);
    v9 = vostok::math::operator*(&this->m_start_velocity, &v19, &v20);
    v10 = vostok::math::operator*(v9, &v18, &sqr_t_div_2);
    v11 = vostok::math::operator*(&this->m_start_velocity, &v17, &time);
    v12 = vostok::math::operator+(v11, &this->m_start_position, &v16);
    v13 = vostok::math::operator+(v10, v12, &v15);
    vostok::math::operator+(v8, v13, result);
  }
  return result;
}
