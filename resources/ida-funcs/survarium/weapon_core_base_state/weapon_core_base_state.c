void __userpurge survarium::weapon_core_base_state::weapon_core_base_state(
        survarium::weapon_core_base_state *this@<ecx>,
        int a2@<esi>,
        survarium::weapon_core *weapon,
        survarium::weapon_state_id_enum id)
{
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 20) = 0;
  vostok::resources::unmanaged_resource::unmanaged_resource(
    (vostok::resources::unmanaged_resource *)this,
    (_DWORD *)(a2 + 24),
    fs_iterator_class);
  *(_DWORD *)(a2 + 292) = -1;
  *(_DWORD *)(a2 + 288) = weapon;
  *(_DWORD *)(a2 + 24) = &survarium::weapon_core_base_state::`vftable'{for `vostok::resources::unmanaged_resource'};
  *(_DWORD *)(a2 + 296) = id;
  *(_BYTE *)(a2 + 300) = 0;
  *(_BYTE *)(a2 + 301) = 0;
  *(_DWORD *)a2 = &survarium::weapon_core_base_state::`vftable'{for `vostok::ai::fsm_state'};
}
