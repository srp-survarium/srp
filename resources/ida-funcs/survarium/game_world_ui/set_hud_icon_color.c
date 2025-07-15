void __thiscall survarium::game_world_ui::set_hud_icon_color(
        survarium::game_world_ui *this,
        int icon_uid,
        unsigned __int8 red,
        unsigned __int8 green,
        unsigned __int8 blue,
        unsigned __int8 a6)
{
  int v6; // edi
  survarium::flash_value *v7; // ecx
  survarium::flash_value *v8; // ecx
  int v9; // edx
  survarium::flash_value *v10; // ecx
  survarium::flash_value *v11; // ecx
  survarium::flash_value *v12; // ecx
  Scaleform::GFx::Value *v13; // esi
  survarium::flash_value v14; // [esp+8h] [ebp-60h] BYREF
  _BYTE v15[24]; // [esp+20h] [ebp-48h] BYREF
  _BYTE v16[24]; // [esp+38h] [ebp-30h] BYREF
  _BYTE v17[24]; // [esp+50h] [ebp-18h] BYREF
  char vars0; // [esp+68h] [ebp+0h] BYREF

  v6 = 3;
  v7 = &v14;
  do
  {
    survarium::flash_value::flash_value(v7);
    v7 = v8 + 1;
  }
  while ( v9 - 1 >= 0 );
  survarium::flash_value::SetUInt(v7, (int)&v14, red);
  survarium::flash_value::SetUInt(v10, (int)v15, green);
  survarium::flash_value::SetUInt(v11, (int)v16, blue);
  survarium::flash_value::SetUInt(v12, (int)v17, a6);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(icon_uid + 16) + 264) + 4),
    "root.set_player_color",
    0,
    (const Scaleform::GFx::Value *)&v14,
    4u);
  v13 = (Scaleform::GFx::Value *)&vars0;
  do
  {
    Scaleform::GFx::Value::~Value(--v13);
    --v6;
  }
  while ( v6 >= 0 );
}
