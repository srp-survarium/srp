void __thiscall survarium::free_fly_camera::build_view_matrix(
        survarium::free_fly_camera *this,
        survarium::free_fly_camera *raw_angles,
        float *shift_forward,
        float shift_right,
        float shift_up,
        float shift_upa)
{
  float v6; // xmm1_4
  float v7; // xmm0_4
  vostok::math::float3 *v8; // [esp+0h] [ebp-F8h]
  vostok::math::axis_rotation_order v9; // [esp+4h] [ebp-F4h]
  vostok::math::float3 position; // [esp+10h] [ebp-E8h] BYREF
  vostok::math::float3 angles_zxy; // [esp+1Ch] [ebp-DCh]
  vostok::math::float4x4 view_inverted; // [esp+28h] [ebp-D0h] BYREF
  float v13; // [esp+74h] [ebp-84h]
  vostok::math::float4x4 rotation; // [esp+78h] [ebp-80h] BYREF
  vostok::math::float4x4 result; // [esp+B8h] [ebp-40h] BYREF

  qmemcpy((void *)&view_inverted, &raw_angles->m_camera_director->m_inverted_view, sizeof(view_inverted));
  vostok::math::float4x4::get_angles(0, v8, v9);
  v6 = angles_zxy.x - *shift_forward;
  position.y = angles_zxy.y - shift_forward[1];
  position.z = angles_zxy.z * 0.0;
  v7 = -1.5707964;
  if ( v6 > -1.5707964 )
  {
    v7 = pi_d2_8;
    if ( v6 <= 1.5707964 )
      v7 = v6;
  }
  position.x = v7;
  vostok::math::create_rotation(&position, &rotation);
  v13 = view_inverted.j.z * shift_upa;
  angles_zxy.x = (float)(view_inverted.i.x * shift_up) + view_inverted.c.x;
  position.x = (float)(angles_zxy.x + (float)(view_inverted.j.x * shift_upa)) + (float)(view_inverted.k.x * shift_right);
  position.y = (float)((float)(view_inverted.c.y + (float)(view_inverted.i.y * shift_up))
                     + (float)(view_inverted.j.y * shift_upa))
             + (float)(view_inverted.k.y * shift_right);
  position.z = (float)((float)(view_inverted.c.z + (float)(view_inverted.i.z * shift_up))
                     + (float)(view_inverted.j.z * shift_upa))
             + (float)(view_inverted.k.z * shift_right);
  vostok::math::create_translation(&view_inverted, &position);
  vostok::math::mul4x3(&result, &rotation, &view_inverted);
  qmemcpy((void *)&raw_angles->m_inverted_view_matrix, &result, sizeof(raw_angles->m_inverted_view_matrix));
}
