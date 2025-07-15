void __userpurge survarium::grenade::grenade(
        survarium::grenade *this@<ecx>,
        int a2@<eax>,
        survarium::base_game_scene *w)
{
  float v4; // xmm0_4
  float v5; // xmm1_4

  survarium::grenade_core::grenade_core(this, a2);
  v4 = float_min_18;
  v5 = s_bm_current_air_resistance;
  *(_DWORD *)a2 = &survarium::grenade::`vftable'{for `survarium::tickable_object'};
  *(_DWORD *)(a2 + 12) = &survarium::grenade::`vftable'{for `survarium::serializable_object'};
  *(_DWORD *)(a2 + 24) = &survarium::grenade::`vftable'{for `vostok::collision::game_object'};
  *(_DWORD *)(a2 + 32) = &survarium::grenade::`vftable'{for `vostok::resources::unmanaged_resource'};
  *(_DWORD *)(a2 + 456) = 0;
  *(_DWORD *)(a2 + 460) = 0;
  *(_DWORD *)(a2 + 464) = 0;
  *(_DWORD *)(a2 + 476) = 0;
  *(_BYTE *)(a2 + 484) = 0;
  *(_DWORD *)(a2 + 480) = 500;
  *(_WORD *)(a2 + 468) = -1;
  *(_DWORD *)(a2 + 472) = w;
  *(_WORD *)(a2 + 488) = -1;
  *(float *)(a2 + 492) = v4;
  *(float *)(a2 + 496) = v4;
  *(float *)(a2 + 500) = v4;
  *(_DWORD *)(a2 + 504) = 0;
  *(float *)(a2 + 508) = v5;
  *(_DWORD *)(a2 + 512) = 0;
  *(_DWORD *)(a2 + 516) = 0;
  *(_DWORD *)(a2 + 520) = 0;
}
