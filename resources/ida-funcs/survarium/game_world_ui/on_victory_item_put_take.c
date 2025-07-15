void __thiscall survarium::game_world_ui::on_victory_item_put_take(
        survarium::game_world_ui *this,
        int player_id,
        bool is_taken,
        bool is_base,
        char a5)
{
  int v5; // ebx
  int v6; // eax
  survarium::game_world_ui *v7; // ecx
  survarium::flash_value *v8; // ecx
  survarium::flash_value *v9; // ecx
  survarium::flash_value *v10; // ecx
  int v11; // eax
  survarium::flash_value *v12; // ecx
  survarium::flash_value *v13; // ecx
  survarium::flash_value *v14; // ecx
  int v15; // eax
  survarium::flash_value *v16; // ecx
  survarium::flash_value *v17; // ecx
  survarium::flash_value *v18; // ecx
  survarium::flash_value *v19; // ecx
  survarium::flash_value *v20; // ecx
  survarium::flash_value *v21; // ecx
  survarium::flash_value *v22; // ecx
  unsigned __int8 v23; // [esp+0h] [ebp-48h]
  unsigned int v24; // [esp+4h] [ebp-44h]
  Scaleform::GFx::Value pargs; // [esp+Ch] [ebp-3Ch] BYREF
  survarium::flash_value value; // [esp+24h] [ebp-24h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v27; // [esp+3Ch] [ebp-Ch] BYREF
  survarium::flash_value *v28; // [esp+40h] [ebp-8h]
  char v29; // [esp+47h] [ebp-1h]
  unsigned __int8 v30; // [esp+5Bh] [ebp+13h]

  survarium::game_world_ui::update_minimap_objects(this, player_id);
  v5 = *(_DWORD *)(player_id + 24) + 1488 * is_taken;
  survarium::base_network_client::get_current_player(
    *(survarium::base_network_client **)(*(_DWORD *)(*(_DWORD *)(player_id + 20) + 160) + 13912),
    &v27);
  if ( v27.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v29 = v27.m_object->m_lods[1].m_emitter_instance_list.gap4;
  }
  else
  {
    v29 = -1;
  }
  if ( v27.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v28 = *(survarium::flash_value **)(v27.m_object[88].m_is_playing + 440);
  }
  else
  {
    v28 = 0;
  }
  if ( *(survarium::flash_value **)(v5 + 440) == v28 )
  {
    v6 = *(_DWORD *)(player_id + 8);
    pargs.pObjectInterface = 0;
    pargs.Type = VT_Undefined;
    survarium::flash_movie::CreateObject(
      (survarium::flash_movie *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr,
      *(survarium::flash_value **)(v6 + 264),
      &pargs);
    *(_DWORD *)value.body = 0;
    *(_DWORD *)&value.body[4] = 0;
    if ( is_base )
    {
      v30 = 3;
      if ( v29 == is_taken )
        survarium::game_world_ui::show_parametrized_message(
          v7,
          (const char *)player_id,
          "st_bring_item_to_base",
          v23,
          v24);
    }
    else
    {
      v30 = (a5 != 0) + 4;
    }
    survarium::flash_value::SetInt((survarium::flash_value *)v7, (int)&value, v30);
    survarium::flash_value::SetMember(v8, &pargs, "action_id", &value);
    survarium::flash_value::SetString(&value, (const char *)(v5 + 8));
    survarium::flash_value::SetMember(v9, &pargs, "who_name", &value);
    if ( v29 == is_taken )
    {
      v11 = 2;
    }
    else
    {
      v10 = v28;
      v11 = *(_DWORD *)(v5 + 440) != (_DWORD)v28;
    }
    survarium::flash_value::SetInt(v10, (int)&value, v11);
    survarium::flash_value::SetMember(v12, &pargs, "who_team", &value);
    survarium::flash_value::SetString(&value, (const char *)(v5 + 8));
    survarium::flash_value::SetMember(v13, &pargs, "victim_name", &value);
    if ( v29 == is_taken )
    {
      v15 = 2;
    }
    else
    {
      v14 = v28;
      v15 = *(_DWORD *)(v5 + 440) != (_DWORD)v28;
    }
    survarium::flash_value::SetInt(v14, (int)&value, v15);
    survarium::flash_value::SetMember(v16, &pargs, "victim_team", &value);
    survarium::flash_value::SetInt(v17, (int)&value, 0);
    survarium::flash_value::SetMember(v18, &pargs, "object_icon", &value);
    survarium::flash_value::SetInt(v19, (int)&value, 0);
    survarium::flash_value::SetMember(v20, &pargs, "extra_icon", &value);
    survarium::flash_value::SetInt(v21, (int)&value, 0);
    survarium::flash_value::SetMember(v22, &pargs, "mastery_icon", &value);
    Scaleform::GFx::Movie::Invoke(
      *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(player_id + 8) + 264) + 4),
      "root.add_log_message",
      0,
      &pargs,
      1u);
    Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&value);
    Scaleform::GFx::Value::~Value(&pargs);
  }
  else if ( is_base && a5 )
  {
    survarium::game_world_ui::show_parametrized_message(
      (survarium::game_world_ui *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr,
      (const char *)player_id,
      "st_on_enemy_theft_item",
      v23,
      v24);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v27);
}
