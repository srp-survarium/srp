void __userpurge survarium::lobby_camera::lobby_camera(
        survarium::lobby_camera *this@<ecx>,
        int a2@<edx>,
        survarium::lobby_menu *w,
        vostok::physics::world *physics_world)
{
  float v4; // xmm1_4
  _DWORD *v5; // eax
  int v6; // edx
  int v7; // ecx

  survarium::game_camera::game_camera((survarium::game_camera *)this, a2 + 4);
  v4 = vostok::sound::s_lpf_param;
  *v5 = &survarium::lobby_camera::`vftable'{for `survarium::game_camera'};
  *(_DWORD *)v6 = &survarium::lobby_camera::`vftable'{for `vostok::input::handler'};
  *(_DWORD *)(v6 + 152) = 0;
  *(float *)(v6 + 156) = v4;
  *(_DWORD *)(v6 + 160) = 0;
  *(_DWORD *)(v6 + 164) = w;
  *(_DWORD *)(v6 + 168) = v7;
  *(_DWORD *)(v6 + 172) = 0;
  *(_DWORD *)(v6 + 176) = 0;
  *(float *)(v6 + 180) = v4;
  *(float *)(v6 + 184) = v4;
  *(_DWORD *)(v6 + 188) = 0;
  *(_BYTE *)(v6 + 200) = 0;
  *(_DWORD *)(v6 + 204) = 0;
  *(_DWORD *)(v6 + 208) = 0;
  *(_DWORD *)(v6 + 192) = 0;
  *(_DWORD *)(v6 + 196) = 0;
}
