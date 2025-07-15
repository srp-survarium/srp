void __userpurge survarium::base_player::process_quick_slots(
        survarium::base_player *this@<ecx>,
        int a2@<eax>,
        survarium::inventory *previous_input,
        const survarium::player_input *new_input,
        int current_time_in_ms)
{
  int v6; // eax
  int v7; // eax
  unsigned int actions_mask; // eax
  survarium::hit_type_enum v9; // edi
  const survarium::profile_slot_enum *v10; // edx
  char v11; // bl
  _DWORD *v12; // eax
  const survarium::base_player *v13; // eax
  survarium::inventory *v14; // ecx
  int *v15; // edi
  int v16; // eax
  survarium::inventory *v17; // ecx
  survarium::inventory *v18; // ecx
  int v19; // esi
  unsigned int v20; // eax
  int v21; // [esp+Ch] [ebp-90h]
  _BYTE v22[116]; // [esp+1Ch] [ebp-80h] BYREF
  int v23; // [esp+90h] [ebp-Ch]
  int v24; // [esp+94h] [ebp-8h]
  unsigned __int8 v25; // [esp+9Ah] [ebp-2h]
  unsigned __int8 v26; // [esp+9Bh] [ebp-1h]

  if ( (new_input->actions_mask & 0x4000000) != 0 )
  {
    vostok::collision::bone_collision_data::bone_collision_data(
      (vostok::collision::bone_collision_data *)this,
      (int)v22,
      (char *)uri,
      "brain");
    v6 = a2 ? a2 + 300 : 0;
    (*(void (__stdcall **)(int, int, _BYTE *, _DWORD, _DWORD, _DWORD, _DWORD, int))(*(_DWORD *)(a2 + 308) + 20))(
      current_time_in_ms,
      v6,
      v22,
      0,
      1.0,
      1.0,
      0,
      16);
    if ( *(_BYTE *)(a2 + 765) )
      return;
  }
  v7 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 320) + 96))(*(_DWORD *)(a2 + 320));
  v24 = 0;
  v23 = v7;
  actions_mask = new_input->actions_mask;
  v26 = -1;
  v9 = shock_damage|0x10;
  v25 = 0;
  v10 = weapon_slots_1;
  do
  {
    if ( v23 && *(_DWORD *)(v23 + 292) == *v10 )
      v26 = v25;
    if ( ((0x2000 << v24) & actions_mask) != 0 )
      v9 = *v10;
    ++v25;
    ++v24;
    ++v10;
  }
  while ( v25 < 2u );
  v11 = 0;
  if ( !v23 )
    goto LABEL_23;
  if ( (actions_mask & 0x8000000) == 0 )
  {
    if ( (actions_mask & 0x10000000) != 0 )
    {
      if ( !v26 )
      {
        v21 = 10;
        goto LABEL_17;
      }
      v9 = anomaly_damage_types_93[v26 + 3];
    }
LABEL_23:
    if ( v9 == (shock_damage|0x10) )
      goto LABEL_27;
    goto LABEL_24;
  }
  if ( !v26 )
  {
    v9 = weapon_slots_1[1];
    goto LABEL_23;
  }
  v21 = 7;
LABEL_17:
  v9 = v21;
LABEL_24:
  v12 = (_DWORD *)(*(_DWORD *)(a2 + 268) + 4 * v9 + 272);
  if ( *v12
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v13 = (const survarium::base_player *)(*(int (__thiscall **)(_DWORD))(*(_DWORD *)*v12 + 60))(*v12);
    goto LABEL_28;
  }
LABEL_27:
  v13 = 0;
LABEL_28:
  if ( v13
    && (const survarium::base_player *)v23 != v13
    && (unsigned __int8)survarium::weapon_core::could_be_used((survarium::weapon_core *)a2, v13) )
  {
    survarium::inventory::action(v14, *(_DWORD **)(a2 + 268), v9, 1u, current_time_in_ms);
  }
  if ( *(_BYTE *)(*(_DWORD *)(a2 + 320) + 14) )
  {
    v15 = (int *)quick_slots;
    v23 = 6;
    do
    {
      v16 = 0x8000 << v11;
      v17 = (survarium::inventory *)((0x8000 << v11) & new_input->actions_mask);
      if ( !v17
        || (v16
          & previous_input->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags) != 0 )
      {
        if ( !v17
          && (v16
            & previous_input->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags) != 0 )
        {
          survarium::inventory::action(previous_input, *(_DWORD **)(a2 + 268), *v15, 0, current_time_in_ms);
        }
      }
      else
      {
        survarium::inventory::action(v17, *(_DWORD **)(a2 + 268), *v15, 1u, current_time_in_ms);
      }
      ++v11;
      ++v15;
      --v23;
    }
    while ( v23 );
  }
  v18 = (survarium::inventory *)((unsigned int)&loc_200000 & new_input->actions_mask);
  if ( !v18
    || ((unsigned int)&loc_200000
      & previous_input->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags) != 0 )
  {
    if ( !v18
      && ((unsigned int)&loc_200000
        & previous_input->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags) != 0 )
    {
      survarium::inventory::action(0, *(_DWORD **)(a2 + 268), 3, 0, current_time_in_ms);
    }
  }
  else
  {
    survarium::inventory::action(v18, *(_DWORD **)(a2 + 268), 3, 1u, current_time_in_ms);
  }
  v19 = *(_DWORD *)(a2 + 268);
  if ( *(_DWORD *)(v19 + 380) )
  {
    v20 = new_input->actions_mask;
    if ( (v20 & 0x1000000) != 0
      || (v20 & 0x20) != 0
      && (previous_input->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
        & 0x20) == 0 )
    {
      survarium::inventory::drop_carried_item(v18, v19);
    }
  }
}
