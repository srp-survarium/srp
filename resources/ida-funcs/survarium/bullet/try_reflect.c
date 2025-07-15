// local variable allocation has failed, the output may be wrong!
int __thiscall survarium::bullet::try_reflect(
        survarium::bullet *this,
        const vostok::math::float3 *collide_point,
        __int128 direction,
        float speed,
        float collision_time,
        vostok::math::float3 *start_position,
        float *start_time,
        float *current_time,
        float cos_alpha)
{
  vostok::math::float3 *v10; // eax
  vostok::math::float3 *v11; // eax
  vostok::math::float3 *v12; // eax
  float value; // [esp+0h] [ebp-58h]
  vostok::math::float3 v15; // [esp+14h] [ebp-44h] BYREF
  vostok::math::float3 v16; // [esp+20h] [ebp-38h] BYREF
  vostok::math::float3 v17; // [esp+2Ch] [ebp-2Ch] BYREF
  vostok::math::float3 v18; // [esp+38h] [ebp-20h] BYREF
  float v19; // [esp+44h] [ebp-14h] BYREF
  float v20; // [esp+48h] [ebp-10h] BYREF
  float fin_ricochet_angle; // [esp+4Ch] [ebp-Ch]
  float angle_alpha; // [esp+50h] [ebp-8h]
  float calculated_koeff; // [esp+54h] [ebp-4h]

  fin_ricochet_angle = this->m_collided_material->m_ricochet_koef * this->m_ricochet_angle;
  angle_alpha = vostok::math::acos(cos_alpha) - 1.5707964;
  calculated_koeff = *(float *)&clear_value - (float)(angle_alpha / fin_ricochet_angle);
  speed = (float)((float)((float)(*(float *)&clear_value - this->m_collided_material->m_bullet_reflection_speed_down)
                        * calculated_koeff)
                + this->m_collided_material->m_bullet_reflection_speed_down)
        * speed;
  if ( speed < 0.0 )
    return 1;
  v20 = -cos_alpha;
  v19 = retry_to_increase_quality_period_sec;
  v10 = vostok::math::operator*((const vostok::math::float3_pod *)HIDWORD(direction), &v18, &v19);
  v11 = vostok::math::operator*(v10, &v17, &v20);
  *(vostok::math::float3 *)&direction = *vostok::math::operator+(
                                           (const vostok::math::float3_pod *)&direction,
                                           v11,
                                           &v16);
  value = collision_time;
  v12 = vostok::math::operator*((const vostok::math::float3_pod *)&direction, &v15, &speed);
  survarium::bullet::change_trajectory(this, collide_point, v12, value);
  *start_position = this->m_start_position;
  *start_time = this->m_life_time;
  *current_time = *current_time - collision_time;
  ++this->m_ricochet_count;
  return 3;
}
