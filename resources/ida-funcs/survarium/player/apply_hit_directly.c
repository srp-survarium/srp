void __thiscall survarium::player::apply_hit_directly(
        survarium::player *this,
        survarium::player *info,
        unsigned int current_time_in_ms,
        unsigned int current_time_in_msa)
{
  survarium::player *v4; // ebx
  const vostok::resources::resource_ptr<survarium::damage_model,vostok::resources::unmanaged_intrusive_base> *(__thiscall *damage_model)(struct survarium::base_player *); // edx
  unsigned int v6; // ebp
  const char *v7; // esi
  const char *v8; // edi
  survarium::damage_model **v9; // eax
  survarium::profile_player_character *v10; // ecx
  int v11; // esi
  int v12; // eax
  int v13; // esi
  int v14; // eax
  const vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *v15; // eax
  survarium::profile_player_character *v16; // ecx
  int v17; // ecx
  int (__thiscall *v18)(int, unsigned int *, int); // edx
  vostok::math::float3 *v19; // edi
  int v20; // eax
  void (__stdcall ****v21)(_DWORD, int, _DWORD); // esi
  void (__stdcall ****v22)(_DWORD, int, _DWORD); // edi
  survarium::hit_receiver *v23; // ebx
  __int128 amount; // [esp+0h] [ebp-28h]
  vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> v25; // [esp+24h] [ebp-4h] BYREF

  v4 = info;
  damage_model = info->damage_model;
  v6 = current_time_in_ms;
  v7 = *(const char **)(current_time_in_ms + 28);
  v8 = *(const char **)current_time_in_ms;
  current_time_in_ms = 0;
  v9 = (survarium::damage_model **)damage_model(info);
  if ( survarium::damage_model::hit_body_part(
         *v9,
         *(_BYTE *)(v6 + 68),
         v8,
         v7,
         *(float *)(v6 + 60),
         *(float *)(v6 + 64),
         current_time_in_msa,
         *(survarium::bullet *const *)(v6 + 56)) )
  {
    v11 = *(int *)((char *)&dword_10F04 + (_DWORD)v4);
    v12 = *(_DWORD *)(*(_DWORD *)(v11 + 952) + 8);
    if ( v12
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
      && *(_BYTE *)(v12 + 52) == *(_BYTE *)(v6 + 68) )
    {
      Scaleform::GFx::Movie::Invoke(
        *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(v11 + 624) + 264) + 4),
        "root.crosshair_enemy_hit",
        0,
        0,
        0);
    }
    if ( *(int *)((char *)&dword_10F7C + (_DWORD)v4) )
    {
      v13 = *(int *)((char *)&dword_10F04 + (_DWORD)v4);
      v14 = *(_DWORD *)(*(_DWORD *)(v13 + 952) + 8);
      LOBYTE(v10) = v4->id;
      if ( v14 )
      {
        if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
        {
          if ( *(_BYTE *)(v14 + 52) == (_BYTE)v10 && *(_BYTE *)(v6 + 69) == (_BYTE)v10 )
          {
            LOBYTE(v14) = *(_BYTE *)(v6 + 68);
            if ( (_BYTE)v14 != 0xFF )
            {
              if ( (_BYTE)v14 == (_BYTE)v10 )
              {
                current_time_in_ms = 1;
                vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>(
                  &v25,
                  v4,
                  v10);
              }
              else
              {
                v17 = *(_DWORD *)(v13 + 952);
                v18 = *(int (__thiscall **)(int, unsigned int *, int))(*(_DWORD *)v17 + 72);
                current_time_in_ms = 2;
                v15 = (const vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *)v18(v17, &current_time_in_msa, v14);
              }
              v19 = (vostok::math::float3 *)v15;
              vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>(
                (vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *)&info,
                v15,
                v16);
              if ( (current_time_in_ms & 2) != 0 )
              {
                current_time_in_ms &= ~2u;
                vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *)&current_time_in_msa);
              }
              if ( (current_time_in_ms & 1) != 0 )
                vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>(&v25);
              v20 = (int)info->get_transform(&info->survarium::collision_user);
              *(_QWORD *)((char *)&amount + 4) = *(_QWORD *)(v20 + 48);
              HIDWORD(amount) = *(_DWORD *)(v20 + 56);
              LODWORD(amount) = *(int *)((char *)&dword_10F7C + (_DWORD)v4);
              survarium::game_world_ui::on_hit_from_pos(
                (survarium::game_world_ui *)amount,
                v19,
                (vostok::math::axis_rotation_order)&info,
                amount);
              vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *)&info);
            }
          }
        }
      }
    }
    v21 = *(void (__stdcall *****)(_DWORD, int, _DWORD))((char *)&dword_10E10 + (_DWORD)v4);
    v22 = *(void (__stdcall *****)(_DWORD, int, _DWORD))((char *)&dword_10E14 + (_DWORD)v4);
    if ( v21 != v22 )
    {
      v23 = &v4->survarium::hit_receiver;
      do
        (***v21++)(v23, 4, *(float *)(v6 + 60));
      while ( v21 != v22 );
    }
  }
}
