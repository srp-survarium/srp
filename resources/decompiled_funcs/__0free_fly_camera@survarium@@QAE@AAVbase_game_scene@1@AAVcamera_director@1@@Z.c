void __userpurge survarium::free_fly_camera::free_fly_camera(
        survarium::free_fly_camera *this@<ecx>,
        int a2@<eax>,
        survarium::camera_director *w,
        survarium::camera_director *cd)
{
  const vostok::math::float4x4 *v4; // xmm0_4

  *(float *)(a2 + 72) = satisfaction_equality_tolerance;
  *(float *)(a2 + 76) = survarium::s_camera_far_plane;
  v4 = clear_value;
  *(_DWORD *)(a2 + 68) = this;
  *(_DWORD *)(a2 + 80) = v4;
  *(_DWORD *)(a2 + 96) = -1082130432;
  *(_DWORD *)a2 = &survarium::free_fly_camera::`vftable'{for `survarium::game_camera'};
  *(_DWORD *)(a2 + 84) = &survarium::free_fly_camera::`vftable'{for `vostok::input::handler'};
  *(_DWORD *)(a2 + 88) = w;
  *(_DWORD *)(a2 + 92) = 0;
  *(_DWORD *)(a2 + 100) = 0;
  *(_DWORD *)(a2 + 104) = 0;
  *(_DWORD *)(a2 + 108) = 0;
  *(_DWORD *)(a2 + 112) = 0;
  *(_DWORD *)(a2 + 116) = 0;
  *(_DWORD *)(a2 + 120) = 0;
  *(_DWORD *)(a2 + 124) = 0;
  *(_DWORD *)(a2 + 128) = 0;
  *(_DWORD *)(a2 + 132) = 0;
}
