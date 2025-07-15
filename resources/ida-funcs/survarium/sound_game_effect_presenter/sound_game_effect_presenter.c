void __userpurge survarium::sound_game_effect_presenter::sound_game_effect_presenter(
        survarium::sound_game_effect_presenter *this@<ecx>,
        int a2@<eax>,
        survarium::base_game_scene *scene,
        const bool first_person)
{
  float v4; // xmm0_4

  v4 = s_bm_current_air_resistance;
  *(_DWORD *)(a2 + 4) = this;
  *(_BYTE *)(a2 + 8) = (_BYTE)scene;
  *(_DWORD *)a2 = &survarium::sound_game_effect_presenter::`vftable';
  *(_DWORD *)(a2 + 12) = 1;
  *(_DWORD *)(a2 + 20) = a2 + 32;
  *(_DWORD *)(a2 + 24) = a2 + 32;
  *(_DWORD *)(a2 + 28) = a2 + 224;
  *(_DWORD *)(a2 + 224) = a2 + 236;
  *(_DWORD *)(a2 + 228) = a2 + 236;
  *(float *)(a2 + 16) = v4;
  *(_DWORD *)(a2 + 232) = a2 + 428;
}
