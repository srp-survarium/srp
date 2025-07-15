void __thiscall survarium::free_fly_camera::build_view_matrix(
        survarium::free_fly_camera *this,
        const vostok::math::float2 *raw_angles,
        float *shift_forward,
        float shift_right,
        float shift_up,
        float a6)
{
  float v6; // xmm1_4
  float v7; // xmm0_4
  vostok::math::float3 *v8; // [esp+0h] [ebp-F8h]
  vostok::math::axis_rotation_order v9; // [esp+4h] [ebp-F4h]
  vostok::math::float3 angles; // [esp+10h] [ebp-E8h] BYREF
  float v11[3]; // [esp+1Ch] [ebp-DCh] BYREF
  vostok::math::float4x4 v12; // [esp+28h] [ebp-D0h] BYREF
  float v13; // [esp+74h] [ebp-84h]
  vostok::math::float4x4 order; // [esp+78h] [ebp-80h] BYREF
  vostok::math::float4x4 v15; // [esp+B8h] [ebp-40h] BYREF

  qmemcpy(&v12, (const void *)(LODWORD(raw_angles[26].x) + 4), sizeof(v12));
  vostok::math::float4x4::get_angles(0, v8, v9);
  v6 = v11[0] - *shift_forward;
  angles.y = v11[1] - shift_forward[1];
  angles.z = v11[2] * 0.0;
  v7 = FLOAT_N1_5707964;
  if ( v6 > -1.5707964 )
  {
    v7 = pi_d2_11;
    if ( v6 <= 1.5707964 )
      v7 = v6;
  }
  angles.x = v7;
  vostok::math::create_rotation(&angles, (int)v11, (const vostok::math::axis_rotation_order)&order);
  v13 = v12.j.z * a6;
  v11[0] = (float)(v12.i.x * shift_up) + v12.c.x;
  angles.x = (float)(v11[0] + (float)(v12.j.x * a6)) + (float)(v12.k.x * shift_right);
  angles.y = (float)((float)(v12.c.y + (float)(v12.i.y * shift_up)) + (float)(v12.j.y * a6))
           + (float)(v12.k.y * shift_right);
  angles.z = (float)((float)(v12.c.z + (float)(v12.i.z * shift_up)) + (float)(v12.j.z * a6))
           + (float)(v12.k.z * shift_right);
  vostok::math::create_translation(&angles, &v12);
  vostok::math::mul4x3(&v12, &order, &v15);
  qmemcpy(&raw_angles[8].elements[1], &v15, 0x40u);
}
