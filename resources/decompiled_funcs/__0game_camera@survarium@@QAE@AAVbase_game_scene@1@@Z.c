void __usercall survarium::game_camera::game_camera(survarium::game_camera *this@<ecx>, int a2@<eax>)
{
  const vostok::math::float4x4 *v2; // xmm0_4

  *(float *)(a2 + 72) = satisfaction_equality_tolerance;
  *(float *)(a2 + 76) = survarium::s_camera_far_plane;
  v2 = clear_value;
  *(_DWORD *)a2 = &survarium::game_camera::`vftable';
  *(_DWORD *)(a2 + 68) = this;
  *(_DWORD *)(a2 + 80) = v2;
}
