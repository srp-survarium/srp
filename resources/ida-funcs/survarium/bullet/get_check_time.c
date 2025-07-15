int __userpurge survarium::bullet::get_check_time@<xmm0>(
        survarium::bullet *this@<eax>,
        survarium::bullet *a2@<ecx>,
        float start_low,
        float high)
{
  survarium::bullet *v5; // ecx
  float i; // xmm0_4
  float v7; // xmm0_4
  survarium::bullet *v8; // ecx
  vostok::math::float3 v10; // [esp+Ch] [ebp-38h] BYREF
  vostok::math::float3 v11; // [esp+18h] [ebp-2Ch] BYREF
  vostok::math::float3 v12; // [esp+24h] [ebp-20h] BYREF
  float v13; // [esp+30h] [ebp-14h]
  float v14; // [esp+34h] [ebp-10h]
  float v15; // [esp+38h] [ebp-Ch]
  float v16; // [esp+3Ch] [ebp-8h]
  float v17; // [esp+40h] [ebp-4h]

  v13 = this->m_weapon_ammunition->m_distance - this->m_flown_distance;
  survarium::bullet::compute_trajectory_position(this, a2, &v11, v13, start_low);
  v16 = start_low;
  for ( i = high; ; i = (float)(v16 + high) * 0.5 )
  {
    v15 = v16 - high;
    v14 = fabs(v16 - high);
    v17 = i;
    if ( v14 < 0.0000099999997 )
      break;
    v7 = (float)(i + start_low) * 0.5;
    survarium::bullet::compute_trajectory_position(this, v5, &v12, v7, v7);
    survarium::bullet::compute_trajectory_position(this, v8, &v10, v7, v17);
    if ( v13 <= (float)(fsqrt(
                          (float)((float)((float)(v12.z - v11.z) * (float)(v12.z - v11.z))
                                + (float)((float)(v12.y - v11.y) * (float)(v12.y - v11.y)))
                        + (float)((float)(v12.x - v11.x) * (float)(v12.x - v11.x)))
                      + fsqrt(
                          (float)((float)((float)(v12.z - v10.z) * (float)(v12.z - v10.z))
                                + (float)((float)(v12.y - v10.y) * (float)(v12.y - v10.y)))
                        + (float)((float)(v12.x - v10.x) * (float)(v12.x - v10.x)))) )
      high = v17;
    else
      v16 = v17;
  }
  return LODWORD(v16);
}
