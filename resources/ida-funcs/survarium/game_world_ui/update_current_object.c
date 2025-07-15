void __thiscall survarium::game_world_ui::update_current_object(survarium::game_world_ui *this, int a2)
{
  survarium::flash_value *v3; // ecx
  survarium::flash_value *v4; // ecx
  int v5; // edx
  survarium::flash_movie *v6; // ecx
  _WORD *v7; // edi
  int v8; // esi
  survarium::flash_value *v9; // ecx
  survarium::flash_value *v10; // ecx
  const vostok::configs::binary_config_value *v11; // eax
  vostok::configs::binary_config_value *v12; // ecx
  survarium::flash_value *v13; // ecx
  vostok::configs::binary_config_value *v14; // eax
  unsigned __int8 pointer; // al
  survarium::flash_value *v16; // ecx
  survarium::flash_value *v17; // ecx
  survarium::flash_value *v18; // ecx
  survarium::flash_value *v19; // ecx
  survarium::flash_value *v20; // ecx
  survarium::flash_value *v21; // ecx
  survarium::flash_value *v22; // ecx
  Scaleform::GFx::Value *v23; // esi
  int i; // edi
  survarium::flash_value v25; // [esp+14h] [ebp-E4h] BYREF
  _BYTE v26[24]; // [esp+2Ch] [ebp-CCh] BYREF
  _BYTE v27[24]; // [esp+44h] [ebp-B4h] BYREF
  _BYTE v28[24]; // [esp+5Ch] [ebp-9Ch] BYREF
  _BYTE v29[24]; // [esp+74h] [ebp-84h] BYREF
  _BYTE v30[24]; // [esp+8Ch] [ebp-6Ch] BYREF
  _BYTE v31[24]; // [esp+A4h] [ebp-54h] BYREF
  char v32; // [esp+BCh] [ebp-3Ch] BYREF
  survarium::flash_value value; // [esp+C0h] [ebp-38h] BYREF
  survarium::flash_value v34; // [esp+D8h] [ebp-20h] BYREF
  survarium::dictionary_item *v35; // [esp+F0h] [ebp-8h]
  unsigned __int8 v36; // [esp+103h] [ebp+Bh]

  v3 = &v25;
  do
  {
    survarium::flash_value::flash_value(v3);
    v3 = v4 + 1;
  }
  while ( v5 - 1 >= 0 );
  Scaleform::GFx::Movie::CreateArray(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 8) + 264) + 4),
    (Scaleform::GFx::Value *)&v25);
  Scaleform::GFx::Movie::CreateArray(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 8) + 264) + 4),
    (Scaleform::GFx::Value *)&v25);
  v7 = (_WORD *)(a2 + 502);
  *(_DWORD *)value.body = 0;
  *(_DWORD *)&value.body[4] = 0;
  v36 = 0;
  if ( *(_WORD *)(a2 + 502) )
  {
    v8 = 0;
    do
    {
      *(_DWORD *)v34.body = 0;
      *(_DWORD *)&v34.body[4] = 0;
      survarium::flash_movie::CreateObject(
        v6,
        *(survarium::flash_value **)(*(_DWORD *)(a2 + 8) + 264),
        (Scaleform::GFx::Value *)&v34);
      survarium::flash_value::SetUInt(v9, (int)&value, *(unsigned __int16 *)(a2 + 4 * v8 + 500));
      survarium::flash_value::SetMember(v10, &v34, "count", &value);
      v35 = survarium::items_dictionary::item_by_id(
              *(survarium::items_dictionary **)(*(_DWORD *)(*(_DWORD *)(a2 + 20) + 160) + 13908),
              (survarium::items_dictionary_vtbl *)(unsigned __int16)*v7);
      v11 = vostok::configs::binary_config_value::operator[](v35->item_cfg.m_object->m_root, "ui_desc");
      if ( vostok::configs::binary_config_value::value_exists(v12, (int)v11, (unsigned int)"ammo_indicator_icon") )
      {
        v14 = vostok::configs::binary_config_value::operator[](v35->item_cfg.m_object->m_root, "ui_desc");
        pointer = (unsigned __int8)vostok::configs::binary_config_value::operator[](v14, "ammo_indicator_icon")->data.pointer;
      }
      else
      {
        pointer = 0;
      }
      survarium::flash_value::SetUInt(v13, (int)&value, pointer);
      survarium::flash_value::SetMember(v16, &v34, "icon", &value);
      survarium::flash_value::PushBack(v17, &v25, &v34);
      Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v34);
      v8 = ++v36;
      v7 = (_WORD *)(a2 + 4 * v36 + 502);
    }
    while ( *v7 );
  }
  survarium::flash_value::SetUInt((survarium::flash_value *)v6, (int)v26, *(unsigned __int8 *)(a2 + 576));
  survarium::flash_value::SetUInt(v18, (int)v27, *(_DWORD *)(a2 + 564));
  survarium::flash_value::SetBoolean(v19, (int)v28, *(_BYTE *)(a2 + 577));
  survarium::flash_value::SetUInt(v20, (int)v29, *(_DWORD *)(a2 + 568));
  survarium::flash_value::SetBoolean(v21, (int)v30, *(_BYTE *)(a2 + 578));
  survarium::flash_value::SetNumber(v22, (int)v31, *(float *)(a2 + 572));
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 8) + 264) + 4),
    "root.update_current_player_weapon_stats",
    0,
    (const Scaleform::GFx::Value *)&v25,
    7u);
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&value);
  v23 = (Scaleform::GFx::Value *)&v32;
  for ( i = 6; i >= 0; --i )
    Scaleform::GFx::Value::~Value(--v23);
}
