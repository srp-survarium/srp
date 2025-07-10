vostok::math::float3 *__thiscall survarium::bullet::compute_parabolic_velocity(
        survarium::bullet *this,
        vostok::math::float3 *result,
        float time,
        const vostok::math::float3 *gravity)
{
  vostok::math::float3 *v4; // eax
  vostok::math::float3 *v6; // esi
  vostok::math::float3 *v7; // eax
  vostok::math::float3 v9; // [esp+24h] [ebp-38h] BYREF
  float v10; // [esp+30h] [ebp-2Ch] BYREF
  vostok::math::float3 v11; // [esp+34h] [ebp-28h] BYREF
  vostok::math::float3 v12; // [esp+40h] [ebp-1Ch] BYREF
  float value; // [esp+4Ch] [ebp-10h] BYREF
  vostok::math::float3 xz_velocity; // [esp+50h] [ebp-Ch] BYREF

  vostok::math::float3::float3(
    &xz_velocity,
    COERCE_UNSIGNED_INT(this->m_start_velocity.x),
    COERCE_UNSIGNED_INT(0.0),
    this->m_start_velocity.z);
  value = vostok::math::float3_pod::squared_length((SpeedTree::Vec3 *)&xz_velocity);
  if ( vostok::math::is_zero<float>(&value, &epsilon_5_84) )
  {
    v4 = vostok::math::operator*(gravity, &v12, &time);
    vostok::math::operator+(v4, &this->m_start_velocity, result);
  }
  else
  {
    vostok::math::max();
    v10 = *(float *)&FLOAT_0_0;
    v6 = vostok::math::operator*(gravity, &v11, &time);
    v7 = vostok::math::operator*(&this->m_start_velocity, &v9, &v10);
    vostok::math::operator+(v6, v7, result);
  }
  return result;
}
