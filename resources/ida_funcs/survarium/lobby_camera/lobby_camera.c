void __usercall survarium::lobby_camera::lobby_camera(survarium::lobby_camera *this@<ecx>, int a2@<eax>)
{
  *(float *)(a2 + 76) = satisfaction_equality_tolerance;
  *(float *)(a2 + 80) = survarium::s_camera_far_plane;
  *(_DWORD *)(a2 + 84) = clear_value;
  *(_DWORD *)(a2 + 72) = this;
  *(_DWORD *)(a2 + 4) = &survarium::game_camera::`vftable';
  *(_DWORD *)a2 = &survarium::lobby_camera::`vftable'{for `vostok::input::handler'};
  *(_DWORD *)(a2 + 4) = &survarium::lobby_camera::`vftable'{for `survarium::game_camera'};
  *(_DWORD *)(a2 + 88) = 0;
  *(_DWORD *)(a2 + 92) = 1069547520;
  *(_DWORD *)(a2 + 96) = 0;
  *(_BYTE *)(a2 + 100) = 0;
  *(_DWORD *)(a2 + 104) = 0;
  *(_DWORD *)(a2 + 108) = 0;
  *(_DWORD *)(a2 + 112) = 1069547520;
  *(_DWORD *)(a2 + 116) = 1069547520;
  *(_DWORD *)(a2 + 120) = 0;
  *(_DWORD *)(a2 + 124) = 0;
  *(_DWORD *)(a2 + 128) = 0;
}
