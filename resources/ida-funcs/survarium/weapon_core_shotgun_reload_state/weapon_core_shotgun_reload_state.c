void __userpurge survarium::weapon_core_shotgun_reload_state::weapon_core_shotgun_reload_state(
        survarium::weapon_core_shotgun_reload_state *this@<ecx>,
        int a2@<eax>,
        survarium::weapon_core *weapon,
        vostok::ai::fsm *reload_start,
        vostok::ai::fsm *reload_one_round,
        vostok::ai::fsm *reload_finish)
{
  survarium::weapon_core_shotgun_reload_state *v7; // ecx

  survarium::weapon_core_base_state::weapon_core_base_state(this, a2, weapon, weapon_state_reload);
  *(_DWORD *)(a2 + 304) = 0;
  *(_DWORD *)a2 = &survarium::weapon_core_shotgun_reload_state::`vftable'{for `vostok::ai::fsm_state'};
  *(_DWORD *)(a2 + 24) = &survarium::weapon_core_shotgun_reload_state::`vftable'{for `vostok::resources::unmanaged_resource'};
  *(_BYTE *)(a2 + 308) = 1;
  *(_DWORD *)(a2 + 292) = -3;
  survarium::weapon_core_shotgun_reload_state::initialize_logic(
    v7,
    (survarium::weapon_core_shotgun_reload_base_substate *)a2,
    reload_start,
    reload_one_round,
    reload_finish);
}
