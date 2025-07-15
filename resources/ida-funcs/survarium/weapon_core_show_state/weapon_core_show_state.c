void __userpurge survarium::weapon_core_show_state::weapon_core_show_state(
        survarium::weapon_core_show_state *this@<ecx>,
        int a2@<esi>,
        survarium::weapon_core *weapon,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *animation_timescale,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *animations,
        const unsigned int animations_count)
{
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v6; // edi
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v7; // ebx
  int v8; // [esp+8h] [ebp-4h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v10; // [esp+18h] [ebp+Ch]
  int v11; // [esp+1Ch] [ebp+10h]

  survarium::weapon_core_animation_end_aware_state::weapon_core_animation_end_aware_state(
    this,
    (_DWORD *)a2,
    weapon,
    weapon_state_show,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(a2 + 316));
  *(_DWORD *)(a2 + 292) = -3;
  *(_DWORD *)a2 = &survarium::weapon_core_show_state::`vftable'{for `vostok::ai::fsm_state'};
  *(_DWORD *)(a2 + 24) = &survarium::weapon_core_show_state::`vftable'{for `vostok::resources::unmanaged_resource'};
  *(_DWORD *)(a2 + 316) = 0;
  *(_DWORD *)(a2 + 320) = 0;
  *(_DWORD *)(a2 + 324) = 0;
  *(_DWORD *)(a2 + 328) = 0;
  *(_QWORD *)(a2 + 332) = (unsigned int)animation_timescale;
  v10 = (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(a2 + 316);
  v8 = 2;
  do
  {
    v6 = animations;
    v7 = v10;
    animations += 2;
    v11 = 2;
    do
    {
      vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
        v6++,
        v7);
      v7 += 2;
      --v11;
    }
    while ( v11 );
    ++v10;
    --v8;
  }
  while ( v8 );
}
