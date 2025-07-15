void __thiscall survarium::game_world_ui::create_hud_icon(
        survarium::game_world_ui *this,
        int icon_uid,
        unsigned __int8 icon_type,
        float icon_size,
        float value)
{
  int v5; // edi
  survarium::flash_value *v6; // ecx
  survarium::flash_value *v7; // ecx
  int v8; // edx
  survarium::flash_value *v9; // ecx
  survarium::flash_value *v10; // ecx
  Scaleform::GFx::Value *v11; // esi
  survarium::flash_value v12; // [esp+Ch] [ebp-48h] BYREF
  _BYTE v13[24]; // [esp+24h] [ebp-30h] BYREF
  _BYTE v14[24]; // [esp+3Ch] [ebp-18h] BYREF
  char vars0; // [esp+54h] [ebp+0h] BYREF

  v5 = 2;
  v6 = &v12;
  do
  {
    survarium::flash_value::flash_value(v6);
    v6 = v7 + 1;
  }
  while ( v8 - 1 >= 0 );
  survarium::flash_value::SetUInt(v6, (int)&v12, icon_type);
  survarium::flash_value::SetUInt(v9, (int)v13, LOBYTE(icon_size));
  survarium::flash_value::SetNumber(v10, (int)v14, value);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(icon_uid + 16) + 264) + 4),
    "root.create_player_icon",
    0,
    (const Scaleform::GFx::Value *)&v12,
    3u);
  v11 = (Scaleform::GFx::Value *)&vars0;
  do
  {
    Scaleform::GFx::Value::~Value(--v11);
    --v5;
  }
  while ( v5 >= 0 );
}
