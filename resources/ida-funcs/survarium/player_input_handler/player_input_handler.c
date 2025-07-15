void __fastcall survarium::player_input_handler::player_input_handler(survarium::player_input_handler *this, int a2)
{
  _DWORD *v2; // eax
  int v3; // edx
  int v4; // ecx
  float v5; // xmm0_4

  survarium::game_camera::game_camera((survarium::game_camera *)this, a2 + 4);
  *v2 = &survarium::player_input_handler::`vftable'{for `survarium::game_camera'};
  *(_DWORD *)v3 = &survarium::player_input_handler::`vftable'{for `vostok::input::handler'};
  *(_DWORD *)(v3 + 672) = 0;
  *(_DWORD *)(v3 + 676) = 0;
  *(_DWORD *)(v3 + 680) = v3 + 692;
  *(_DWORD *)(v3 + 684) = v3 + 692;
  *(_DWORD *)(v3 + 688) = v3 + 820;
  *(_DWORD *)(v3 + 820) = v4;
  *(_DWORD *)(v3 + 824) = 0;
  *(_DWORD *)(v3 + 828) = 0;
  *(_DWORD *)(v3 + 832) = 0;
  *(_DWORD *)(v3 + 836) = 0;
  *(_DWORD *)(v3 + 840) = 0;
  *(_DWORD *)(v3 + 844) = 0;
  *(_DWORD *)(v3 + 848) = 0;
  *(_DWORD *)(v3 + 852) = 0;
  *(_DWORD *)(v3 + 856) = 0;
  v5 = s_bm_current_air_resistance;
  *(_DWORD *)(v3 + 864) = 0;
  *(_BYTE *)(v3 + 869) = 0;
  *(float *)(v3 + 860) = v5;
  *(_BYTE *)(v3 + 868) = 1;
  *(_DWORD *)(v3 + 872) = 1;
}
