void __thiscall survarium::game_world_ui::create_slot_value(
        survarium::game_world_ui *this,
        survarium::game_world_ui *slot,
        survarium::inventory_item_props *item_props,
        survarium::flash_value *slot_descr_value,
        _DWORD *item_icon)
{
  stlp_std::less<unsigned int> *v6; // eax
  vostok::configs::binary_config_value *v7; // eax
  const vostok::configs::binary_config_value *v8; // eax
  int v9; // ebx
  const char *key_name; // edi
  survarium::game_action_id v11; // eax
  int action_dik; // eax
  survarium::keyboard_key_descr *v13; // eax
  survarium::flash_movie_resource *m_object; // ecx
  int v15; // ecx
  int v16; // eax
  int v17; // ecx
  int v18; // edx
  int v19; // ecx
  int v20; // edx
  int v21; // ecx
  int v22; // eax
  BOOL v23; // [esp+54h] [ebp-30h]
  BOOL v24; // [esp+54h] [ebp-30h]
  BOOL v25; // [esp+54h] [ebp-30h]
  BOOL v26; // [esp+54h] [ebp-30h]
  int v27; // [esp+58h] [ebp-2Ch]
  survarium::key_binder *v28; // [esp+58h] [ebp-2Ch]
  bool v29; // [esp+5Ch] [ebp-28h]
  survarium::flash_value slot_descr_valuec_property; // [esp+68h] [ebp-1Ch] BYREF
  unsigned __int8 item_icona; // [esp+94h] [ebp+10h]

  v6 = survarium::items_dictionary::item_by_id(
         slot->m_game_world->m_game->m_items_dictionary.m_object,
         *(unsigned __int16 *)slot_descr_value->body);
  v7 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                 *(vostok::configs::binary_config_value **)(*(_DWORD *)&v6[4].gap0 + 264),
                                                 "ui_desc");
  v8 = vostok::configs::binary_config_value::operator[](v7, "icon");
  v9 = *(unsigned __int16 *)&slot_descr_value->body[4];
  item_icona = (unsigned __int8)v8->data.pointer;
  key_name = (const char *)&buf;
  switch ( (unsigned int)item_props )
  {
    case 0xDu:
      v11 = kQUICK_USE_1;
      goto LABEL_8;
    case 0xEu:
      v11 = kQUICK_USE_2;
      goto LABEL_8;
    case 0xFu:
      v11 = kQUICK_USE_3;
      goto LABEL_8;
    case 0x10u:
      v11 = kQUICK_USE_4;
      goto LABEL_8;
    case 0x11u:
      v11 = kQUICK_USE_5;
      goto LABEL_8;
    case 0x12u:
      v11 = kQUICK_USE_6;
LABEL_8:
      action_dik = survarium::key_binder::get_action_dik(slot->m_game_world->m_game->m_key_binder, v11, v27);
      v13 = survarium::key_binder::dik_to_ptr(v28, action_dik, v29);
      if ( v13 )
        key_name = v13->key_name;
      else
        key_name = 0;
      break;
    default:
      break;
  }
  m_object = slot->m_game_hud_ui.m_object;
  *(_DWORD *)slot_descr_valuec_property.body = 0;
  *(_DWORD *)&slot_descr_valuec_property.body[4] = 0;
  Scaleform::GFx::Movie::CreateObject(
    m_object->movie->m_movie,
    (Scaleform::GFx::Value *)&slot_descr_valuec_property,
    0,
    0,
    0);
  if ( (slot_descr_valuec_property.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)slot_descr_valuec_property.body + 8))(
      *(_DWORD *)slot_descr_valuec_property.body,
      &slot_descr_valuec_property,
      *(_DWORD *)&slot_descr_valuec_property.body[8]);
    *(_DWORD *)slot_descr_valuec_property.body = 0;
  }
  v15 = *item_icon;
  *(_DWORD *)&slot_descr_valuec_property.body[8] = item_icona;
  v23 = (item_icon[1] & 0x8F) == 10;
  v16 = item_icon[2];
  *(_DWORD *)&slot_descr_valuec_property.body[4] = 4;
  (*(void (__thiscall **)(int, int, const char *, survarium::flash_value *, BOOL))(*(_DWORD *)v15 + 20))(
    v15,
    v16,
    "icon",
    &slot_descr_valuec_property,
    v23);
  if ( (slot_descr_valuec_property.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)slot_descr_valuec_property.body + 8))(
      *(_DWORD *)slot_descr_valuec_property.body,
      &slot_descr_valuec_property,
      *(_DWORD *)&slot_descr_valuec_property.body[8]);
    *(_DWORD *)slot_descr_valuec_property.body = 0;
  }
  v17 = *item_icon;
  v24 = (item_icon[1] & 0x8F) == 10;
  v18 = item_icon[2];
  *(_DWORD *)&slot_descr_valuec_property.body[4] = 4;
  *(_DWORD *)&slot_descr_valuec_property.body[8] = v9;
  (*(void (__thiscall **)(int, int, const char *, survarium::flash_value *, BOOL))(*(_DWORD *)v17 + 20))(
    v17,
    v18,
    "count",
    &slot_descr_valuec_property,
    v24);
  if ( (slot_descr_valuec_property.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)slot_descr_valuec_property.body + 8))(
      *(_DWORD *)slot_descr_valuec_property.body,
      &slot_descr_valuec_property,
      *(_DWORD *)&slot_descr_valuec_property.body[8]);
    *(_DWORD *)slot_descr_valuec_property.body = 0;
  }
  v19 = *item_icon;
  v25 = (item_icon[1] & 0x8F) == 10;
  v20 = item_icon[2];
  *(_DWORD *)&slot_descr_valuec_property.body[4] = 4;
  *(_DWORD *)&slot_descr_valuec_property.body[8] = 0;
  (*(void (__thiscall **)(int, int, const char *, survarium::flash_value *, BOOL))(*(_DWORD *)v19 + 20))(
    v19,
    v20,
    "cooldown",
    &slot_descr_valuec_property,
    v25);
  if ( (slot_descr_valuec_property.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)slot_descr_valuec_property.body + 8))(
      *(_DWORD *)slot_descr_valuec_property.body,
      &slot_descr_valuec_property,
      *(_DWORD *)&slot_descr_valuec_property.body[8]);
    *(_DWORD *)slot_descr_valuec_property.body = 0;
  }
  v21 = *item_icon;
  slot_descr_valuec_property.body[8] = v9 != 0;
  v26 = (item_icon[1] & 0x8F) == 10;
  v22 = item_icon[2];
  *(_DWORD *)&slot_descr_valuec_property.body[4] = 2;
  (*(void (__thiscall **)(int, int, const char *, survarium::flash_value *, BOOL))(*(_DWORD *)v21 + 20))(
    v21,
    v22,
    "enabled",
    &slot_descr_valuec_property,
    v26);
  survarium::flash_value::SetString(&slot_descr_valuec_property, key_name);
  (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(*(_DWORD *)*item_icon + 20))(
    *item_icon,
    item_icon[2],
    "hotkey",
    &slot_descr_valuec_property,
    (item_icon[1] & 0x8F) == 10);
  if ( (slot_descr_valuec_property.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)slot_descr_valuec_property.body + 8))(
      *(_DWORD *)slot_descr_valuec_property.body,
      &slot_descr_valuec_property,
      *(_DWORD *)&slot_descr_valuec_property.body[8]);
}
