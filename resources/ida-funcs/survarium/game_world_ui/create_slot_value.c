void __thiscall survarium::game_world_ui::create_slot_value(
        survarium::game_world_ui *this,
        survarium::profile_slot_enum slot,
        survarium::inventory_item_props *item_props,
        survarium::flash_value *slot_descr_value,
        _DWORD *a5)
{
  survarium::dictionary_item *v6; // eax
  vostok::configs::binary_config_value *v7; // eax
  bool v8; // zf
  survarium::flash_movie *v9; // ecx
  int action_dik; // eax
  survarium::key_binder *v11; // ecx
  int v12; // eax
  survarium::flash_value *v13; // ecx
  survarium::flash_value *v14; // ecx
  survarium::flash_value *v15; // ecx
  survarium::flash_value *v16; // ecx
  survarium::flash_value *v17; // ecx
  survarium::flash_value *v18; // ecx
  survarium::flash_value *v19; // ecx
  survarium::flash_value *v20; // ecx
  survarium::flash_value *v21; // ecx
  survarium::flash_value *v22; // ecx
  survarium::flash_value *v23; // ecx
  survarium::flash_value *v24; // ecx
  survarium::text_translator *v25; // ecx
  survarium::flash_value *v26; // ecx
  int v27; // [esp+0h] [ebp-230h]
  char v28[512]; // [esp+10h] [ebp-220h] BYREF
  bool v29[4]; // [esp+210h] [ebp-20h]
  survarium::flash_value value; // [esp+214h] [ebp-1Ch] BYREF
  char *v31; // [esp+22Ch] [ebp-4h]
  unsigned __int8 pointer; // [esp+243h] [ebp+13h]

  if ( *(_WORD *)slot_descr_value->body )
  {
    v6 = survarium::items_dictionary::item_by_id(
           *(survarium::items_dictionary **)(*(_DWORD *)(*(_DWORD *)(slot + 20) + 160) + 13908),
           (survarium::items_dictionary_vtbl *)*(unsigned __int16 *)slot_descr_value->body);
    v7 = vostok::configs::binary_config_value::operator[](v6->item_cfg.m_object->m_root, "ui_desc");
    pointer = (unsigned __int8)vostok::configs::binary_config_value::operator[](v7, "icon")->data.pointer;
  }
  else
  {
    pointer = 0;
  }
  v8 = *(_WORD *)&slot_descr_value->body[4] == 0;
  v31 = (char *)uri;
  v29[0] = !v8;
  if ( item_props == (survarium::inventory_item_props *)13 )
  {
    action_dik = survarium::key_binder::get_action_dik(
                   kQUICK_USE_1,
                   *(survarium::key_binder **)(*(_DWORD *)(*(_DWORD *)(slot + 20) + 160) + 144),
                   v27);
  }
  else if ( item_props == (survarium::inventory_item_props *)14 )
  {
    action_dik = survarium::key_binder::get_action_dik(
                   kQUICK_USE_2,
                   *(survarium::key_binder **)(*(_DWORD *)(*(_DWORD *)(slot + 20) + 160) + 144),
                   v27);
  }
  else if ( item_props == (survarium::inventory_item_props *)15 )
  {
    action_dik = survarium::key_binder::get_action_dik(
                   kQUICK_USE_3,
                   *(survarium::key_binder **)(*(_DWORD *)(*(_DWORD *)(slot + 20) + 160) + 144),
                   v27);
  }
  else if ( item_props == (survarium::inventory_item_props *)16 )
  {
    action_dik = survarium::key_binder::get_action_dik(
                   kQUICK_USE_4,
                   *(survarium::key_binder **)(*(_DWORD *)(*(_DWORD *)(slot + 20) + 160) + 144),
                   v27);
  }
  else if ( item_props == (survarium::inventory_item_props *)17 )
  {
    action_dik = survarium::key_binder::get_action_dik(
                   kQUICK_USE_5,
                   *(survarium::key_binder **)(*(_DWORD *)(*(_DWORD *)(slot + 20) + 160) + 144),
                   v27);
  }
  else
  {
    v9 = (survarium::flash_movie *)&item_props[-3].6;
    if ( item_props != (survarium::inventory_item_props *)18 )
      goto LABEL_17;
    action_dik = survarium::key_binder::get_action_dik(
                   kQUICK_USE_6,
                   *(survarium::key_binder **)(*(_DWORD *)(*(_DWORD *)(slot + 20) + 160) + 144),
                   v27);
  }
  v31 = (char *)survarium::key_binder::dik_to_keyname(v11, action_dik);
LABEL_17:
  v12 = *(_DWORD *)(slot + 8);
  *(_DWORD *)value.body = 0;
  *(_DWORD *)&value.body[4] = 0;
  survarium::flash_movie::CreateObject(v9, *(survarium::flash_value **)(v12 + 264), (Scaleform::GFx::Value *)&value);
  survarium::flash_value::SetUInt(v13, (int)&value, pointer);
  survarium::flash_value::SetMember(v14, a5, "icon", &value);
  survarium::flash_value::SetUInt(v15, (int)&value, (unsigned int)item_props);
  survarium::flash_value::SetMember(v16, a5, "slot_id", &value);
  survarium::flash_value::SetUInt(v17, (int)&value, *(unsigned __int16 *)&slot_descr_value->body[4]);
  survarium::flash_value::SetMember(v18, a5, "count", &value);
  survarium::flash_value::SetUInt(v19, (int)&value, (unsigned __int8)slot_descr_value->body[6]);
  survarium::flash_value::SetMember(v20, a5, "cooldown", &value);
  survarium::flash_value::SetUInt(v21, (int)&value, *(unsigned __int16 *)&slot_descr_value->body[2]);
  survarium::flash_value::SetMember(v22, a5, "timer", &value);
  survarium::flash_value::SetBoolean(v23, (int)&value, v29[0]);
  survarium::flash_value::SetMember(v24, a5, "enabled", &value);
  if ( v31 )
  {
    survarium::text_translator::translate_text(v25, *(_DWORD *)(*(_DWORD *)(slot + 20) + 160) + 13944, v31, v28);
    survarium::flash_value::SetString(&value, v28);
    survarium::flash_value::SetMember(v26, a5, "hotkey", &value);
  }
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&value);
}
