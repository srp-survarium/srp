vostok::math::float3 *__userpurge survarium::bullet::compute_trajectory_position@<eax>(
        survarium::bullet *this@<edi>,
        survarium::bullet *a2@<ecx>,
        vostok::math::float3 *a3@<esi>,
        float a4@<xmm0>,
        float time)
{
  const vostok::math::float3 *v5; // edx
  const vostok::math::float3 *v7; // edx
  float *v8; // edx
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  vostok::math::float3 v12; // [esp+4h] [ebp-20h] BYREF
  vostok::math::float3 v13; // [esp+10h] [ebp-14h] BYREF
  float v14; // [esp+1Ch] [ebp-8h]
  float v15; // [esp+20h] [ebp-4h]

  survarium::bullet::get_parabolic_time(a2);
  v15 = a4;
  v14 = time - a4;
  if ( (float)(time - a4) < 0.0 )
    return survarium::bullet::compute_parabolic_position(v5, a3, this, time);
  survarium::bullet::compute_parabolic_position(v5, &v12, this, v15);
  survarium::bullet::compute_parabolic_velocity(v7, &v13, this, v15);
  v9 = (float)(v14 * v14) * 0.5;
  v10 = (float)(v12.y + (float)(v13.y * v14)) + (float)(v8[1] * v9);
  v11 = (float)(v12.z + (float)(v13.z * v14)) + (float)(v8[2] * v9);
  a3->x = (float)(v12.x + (float)(v13.x * v14)) + (float)(*v8 * v9);
  a3->y = v10;
  a3->z = v11;
  return a3;
}
