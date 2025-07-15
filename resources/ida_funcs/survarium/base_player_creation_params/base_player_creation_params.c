void __usercall survarium::base_player_creation_params::base_player_creation_params(
        survarium::base_player_creation_params *this@<ecx>,
        int a2@<esi>)
{
  const vostok::math::float4x4 *v2; // xmm0_4

  *(_DWORD *)a2 = 0;
  *(_BYTE *)(a2 + 4) = -1;
  *(_DWORD *)(a2 + 8) = 0;
  *(_BYTE *)(a2 + 12) = 0;
  survarium::character_recoil_params::character_recoil_params((survarium::character_recoil_params *)(a2 + 16));
  survarium::character_dispersion_params::character_dispersion_params((survarium::character_dispersion_params *)(a2 + 32));
  *(_DWORD *)(a2 + 88) = 1075838976;
  *(_DWORD *)(a2 + 92) = 1086324736;
  *(float *)(a2 + 96) = FLOAT_0_5;
  *(_DWORD *)(a2 + 100) = 1077936128;
  v2 = clear_value;
  *(_DWORD *)(a2 + 104) = clear_value;
  *(_DWORD *)(a2 + 108) = v2;
  *(_DWORD *)(a2 + 112) = v2;
  *(_DWORD *)(a2 + 116) = v2;
  *(_DWORD *)(a2 + 120) = v2;
  *(_DWORD *)(a2 + 124) = v2;
  survarium::player_stamina::player_stamina((survarium::player_stamina *)(a2 + 128));
  survarium::player_stealth::player_stealth((survarium::player_stealth *)(a2 + 232));
  *(_DWORD *)(a2 + 276) = 0;
  *(_DWORD *)(a2 + 280) = 0;
  *(_DWORD *)(a2 + 288) = 0;
}
