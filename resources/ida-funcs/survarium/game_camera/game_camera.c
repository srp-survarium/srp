void __usercall survarium::game_camera::game_camera(survarium::game_camera *this@<ecx>, int a2@<eax>)
{
  float v2; // xmm0_4

  *(float *)(a2 + 136) = satisfaction_equality_tolerance;
  *(float *)(a2 + 140) = survarium::s_camera_far_plane;
  v2 = s_bm_current_air_resistance;
  *(_DWORD *)a2 = &survarium::game_camera::`vftable';
  *(_DWORD *)(a2 + 132) = this;
  *(float *)(a2 + 144) = v2;
}
