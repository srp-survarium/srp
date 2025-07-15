void __userpurge survarium::jump_logic::jump_logic(
        survarium::jump_logic *this@<ecx>,
        int a2@<eax>,
        survarium::weapon_user_animations_selector *owner,
        survarium::player_logic_jump_state *owner_state)
{
  int v5; // esi
  float v6; // xmm0_4
  survarium::jump_logic *v7; // ecx

  v5 = a2 + 56;
  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 24) = 0;
  survarium::jump_logic_base_state::jump_logic_base_state(
    (survarium::jump_logic_base_state *)(a2 + 56),
    (survarium::jump_logic *)a2);
  *(_DWORD *)v5 = &survarium::short_jump_start_state::`vftable';
  *(_BYTE *)(v5 + 44) = 0;
  survarium::jump_logic_base_state::jump_logic_base_state(
    (survarium::jump_logic_base_state *)(a2 + 104),
    (survarium::jump_logic *)a2);
  *(_DWORD *)(a2 + 104) = &survarium::short_jump_landing_state::`vftable';
  survarium::jump_logic_base_state::jump_logic_base_state(
    (survarium::jump_logic_base_state *)(a2 + 148),
    (survarium::jump_logic *)a2);
  *(_DWORD *)(a2 + 148) = &survarium::jump_logic_state_prepare::`vftable';
  survarium::jump_logic_base_state::jump_logic_base_state(
    (survarium::jump_logic_base_state *)(a2 + 200),
    (survarium::jump_logic *)a2);
  *(_DWORD *)(a2 + 200) = &survarium::jump_logic_state_start::`vftable';
  *(_DWORD *)(a2 + 244) = 0;
  *(_DWORD *)(a2 + 248) = 0;
  *(_BYTE *)(a2 + 252) = 0;
  *(_BYTE *)(a2 + 253) = 0;
  survarium::jump_logic_base_state::jump_logic_base_state(
    (survarium::jump_logic_base_state *)(a2 + 256),
    (survarium::jump_logic *)a2);
  v6 = s_bm_current_air_resistance;
  *(_DWORD *)(a2 + 256) = &survarium::jump_logic_state_landing::`vftable';
  *(_DWORD *)(a2 + 300) = 4;
  *(_DWORD *)(a2 + 304) = owner;
  *(_DWORD *)(a2 + 308) = owner_state;
  *(_DWORD *)(a2 + 312) = 0;
  *(_DWORD *)(a2 + 316) = 0;
  *(_DWORD *)(a2 + 320) = 1;
  *(float *)(a2 + 324) = v6;
  *(_BYTE *)(a2 + 328) = 1;
  survarium::jump_logic::initialize_logic(v7, a2);
}
