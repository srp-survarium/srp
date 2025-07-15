void __usercall survarium::player_input_handler::player_input_handler(
        survarium::player_input_handler *this@<ecx>,
        int a2@<esi>)
{
  const vostok::math::float4x4 *v2; // xmm0_4
  const vostok::math::float4x4 *v3; // xmm0_4

  *(float *)(a2 + 76) = satisfaction_equality_tolerance;
  *(float *)(a2 + 80) = survarium::s_camera_far_plane;
  v2 = clear_value;
  *(_DWORD *)(a2 + 72) = this;
  *(_DWORD *)(a2 + 4) = &survarium::game_camera::`vftable';
  *(_DWORD *)(a2 + 84) = v2;
  *(_DWORD *)a2 = &survarium::player_input_handler::`vftable'{for `vostok::input::handler'};
  *(_DWORD *)(a2 + 4) = &survarium::player_input_handler::`vftable'{for `survarium::game_camera'};
  *(_DWORD *)(a2 + 88) = a2 + 96;
  *(_DWORD *)(a2 + 92) = a2 + 96;
  *(_DWORD *)(a2 + 352) = this;
  survarium::player_input::player_input((survarium::player_input *)(a2 + 356));
  *(_DWORD *)(a2 + 380) = 0;
  *(_DWORD *)(a2 + 384) = 0;
  *(_DWORD *)(a2 + 392) = 0;
  *(_DWORD *)(a2 + 408) = 0;
  *(_DWORD *)(a2 + 388) = 0;
  *(_DWORD *)(a2 + 396) = 0;
  *(_DWORD *)(a2 + 400) = 0;
  v3 = clear_value;
  *(_BYTE *)(a2 + 412) = 1;
  *(_DWORD *)(a2 + 416) = 1;
  *(_DWORD *)(a2 + 404) = v3;
}
