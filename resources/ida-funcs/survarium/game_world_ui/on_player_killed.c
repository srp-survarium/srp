void __thiscall survarium::game_world_ui::on_player_killed(
        survarium::game_world_ui *this,
        _DWORD *victim_id,
        unsigned __int8 killer_id,
        unsigned __int8 is_headshot,
        unsigned __int16 item_dict_id,
        unsigned __int16 a6)
{
  survarium::flash_movie *v6; // ecx
  char *v7; // ebx
  int v8; // eax
  int v9; // eax
  survarium::flash_movie *v10; // ecx
  survarium::flash_value *v11; // ecx
  survarium::flash_value *v12; // ecx
  survarium::flash_value *v13; // ecx
  survarium::flash_value *v14; // ecx
  unsigned int v15; // eax
  survarium::flash_value *v16; // ecx
  survarium::flash_value *v17; // ecx
  survarium::flash_value *v18; // ecx
  unsigned int v19; // eax
  survarium::flash_value *v20; // ecx
  survarium::flash_value *v21; // ecx
  survarium::flash_value *v22; // ecx
  survarium::flash_value *v23; // ecx
  unsigned __int8 v24; // al
  survarium::flash_value *v25; // ecx
  survarium::flash_value *v26; // ecx
  survarium::flash_value *v27; // ecx
  Scaleform::GFx::Value pargs; // [esp+10h] [ebp-44h] BYREF
  survarium::flash_value value; // [esp+28h] [ebp-2Ch] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v30; // [esp+40h] [ebp-14h] BYREF
  char *v31; // [esp+44h] [ebp-10h]
  survarium::flash_value *v32; // [esp+48h] [ebp-Ch]
  char v33; // [esp+4Fh] [ebp-5h]
  unsigned __int8 combat_log_icon; // [esp+6Fh] [ebp+1Bh]

  if ( is_headshot == 0xFF )
    is_headshot = killer_id;
  survarium::base_network_client::get_current_player(
    *(survarium::base_network_client **)(*(_DWORD *)(victim_id[5] + 160) + 13912),
    &v30);
  if ( v30.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v33 = v30.m_object->m_lods[1].m_emitter_instance_list.gap4;
  }
  else
  {
    v33 = -1;
  }
  if ( v30.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v32 = *(survarium::flash_value **)(v30.m_object[88].m_is_playing + 440);
  }
  else
  {
    v32 = 0;
  }
  if ( v33 == killer_id )
    Scaleform::GFx::Movie::Invoke(
      *(Scaleform::GFx::Movie **)(*(_DWORD *)(victim_id[2] + 264) + 4),
      "root.reset_damage_indicator",
      0,
      0,
      0);
  v6 = (survarium::flash_movie *)victim_id[6];
  v7 = (char *)v6 + 1488 * is_headshot;
  v31 = (char *)v6 + 1488 * killer_id;
  if ( a6 )
    combat_log_icon = survarium::items_dictionary::item_by_id(
                        *(survarium::items_dictionary **)(*(_DWORD *)(victim_id[5] + 160) + 13908),
                        (survarium::items_dictionary_vtbl *)a6)->combat_log_icon;
  else
    combat_log_icon = 0;
  v8 = victim_id[2];
  pargs.pObjectInterface = 0;
  pargs.Type = VT_Undefined;
  survarium::flash_movie::CreateObject(v6, *(survarium::flash_value **)(v8 + 264), &pargs);
  v9 = victim_id[2];
  *(_DWORD *)value.body = 0;
  *(_DWORD *)&value.body[4] = 0;
  survarium::flash_movie::CreateObject(v10, *(survarium::flash_value **)(v9 + 264), (Scaleform::GFx::Value *)&value);
  LOBYTE(v11) = is_headshot;
  survarium::flash_value::SetUInt(v11, (int)&value, (killer_id == is_headshot) + 1);
  survarium::flash_value::SetMember(v12, &pargs, "action_id", &value);
  survarium::flash_value::SetString(&value, v7 + 8);
  survarium::flash_value::SetMember(v13, &pargs, "who_name", &value);
  if ( v33 == is_headshot )
  {
    v15 = 2;
  }
  else
  {
    v14 = v32;
    v15 = *((_DWORD *)v7 + 110) != (_DWORD)v32;
  }
  survarium::flash_value::SetUInt(v14, (int)&value, v15);
  survarium::flash_value::SetMember(v16, &pargs, "who_team", &value);
  survarium::flash_value::SetString(&value, v31 + 8);
  survarium::flash_value::SetMember(v17, &pargs, "victim_name", &value);
  if ( v33 == killer_id )
  {
    v19 = 2;
  }
  else
  {
    v18 = v32;
    v19 = *((_DWORD *)v31 + 110) != (_DWORD)v32;
  }
  survarium::flash_value::SetUInt(v18, (int)&value, v19);
  survarium::flash_value::SetMember(v20, &pargs, "victim_team", &value);
  survarium::flash_value::SetUInt(v21, (int)&value, combat_log_icon);
  survarium::flash_value::SetMember(v22, &pargs, "object_icon", &value);
  if ( killer_id == is_headshot )
    v24 = 4;
  else
    v24 = (_BYTE)item_dict_id != 0;
  survarium::flash_value::SetInt(v23, (int)&value, v24);
  survarium::flash_value::SetMember(v25, &pargs, "extra_icon", &value);
  survarium::flash_value::SetInt(v26, (int)&value, 0);
  survarium::flash_value::SetMember(v27, &pargs, "mastery_icon", &value);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(victim_id[2] + 264) + 4),
    "root.add_log_message",
    0,
    &pargs,
    1u);
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&value);
  Scaleform::GFx::Value::~Value(&pargs);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v30);
}
