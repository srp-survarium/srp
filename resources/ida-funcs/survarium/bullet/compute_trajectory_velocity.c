vostok::math::float3 *__userpurge survarium::bullet::compute_trajectory_velocity@<eax>(
        survarium::bullet *this@<eax>,
        survarium::bullet *a2@<ecx>,
        vostok::math::float3 *a3@<esi>,
        float a4@<xmm0>,
        float time)
{
  survarium::bullet *v5; // eax
  const vostok::math::float3 *v6; // edx
  float v7; // xmm7_4
  float *v9; // edx
  float v10; // xmm1_4
  float v11; // xmm2_4
  vostok::math::float3 v12; // [esp+4h] [ebp-10h] BYREF
  float v13; // [esp+10h] [ebp-4h]

  survarium::bullet::get_parabolic_time(a2);
  v7 = time - a4;
  v13 = a4;
  if ( (float)(time - a4) < 0.0 )
    return survarium::bullet::compute_parabolic_velocity(v6, a3, v5, time);
  survarium::bullet::compute_parabolic_velocity(v6, &v12, v5, v13);
  v10 = v9[1];
  v11 = v9[2];
  a3->x = (float)(*v9 * v7) + v12.x;
  a3->y = v12.y + (float)(v10 * v7);
  a3->z = v12.z + (float)(v11 * v7);
  return a3;
}
