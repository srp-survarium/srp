void __thiscall survarium::game_world_ui::set_hud_icon_name_visible(
        survarium::game_world_ui *this,
        int icon_uid,
        bool visible,
        bool value)
{
  int v4; // edi
  survarium::flash_value *v5; // ecx
  survarium::flash_value *v6; // ecx
  int v7; // edx
  survarium::flash_value *v8; // ecx
  Scaleform::GFx::Value *v9; // esi
  survarium::flash_value v10; // [esp+8h] [ebp-30h] BYREF
  _BYTE v11[24]; // [esp+20h] [ebp-18h] BYREF
  char vars0; // [esp+38h] [ebp+0h] BYREF

  v4 = 1;
  v5 = &v10;
  do
  {
    survarium::flash_value::flash_value(v5);
    v5 = v6 + 1;
  }
  while ( v7 - 1 >= 0 );
  survarium::flash_value::SetUInt(v5, (int)&v10, visible);
  survarium::flash_value::SetBoolean(v8, (int)v11, value);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(icon_uid + 16) + 264) + 4),
    "root.set_player_name_visible",
    0,
    (const Scaleform::GFx::Value *)&v10,
    2u);
  v9 = (Scaleform::GFx::Value *)&vars0;
  do
  {
    Scaleform::GFx::Value::~Value(--v9);
    --v4;
  }
  while ( v4 >= 0 );
}
