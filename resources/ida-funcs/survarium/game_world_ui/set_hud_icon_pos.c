void __thiscall survarium::game_world_ui::set_hud_icon_pos(
        survarium::game_world_ui *this,
        int icon_uid,
        vostok::math::float3 pos_scale,
        float value)
{
  int v4; // edi
  survarium::flash_value *v5; // ecx
  survarium::flash_value *v6; // ecx
  int v7; // edx
  survarium::flash_value *v8; // ecx
  survarium::flash_value *v9; // ecx
  survarium::flash_value *v10; // ecx
  Scaleform::GFx::Value *v11; // esi
  survarium::flash_value v12; // [esp+Ch] [ebp-64h] BYREF
  _BYTE v13[24]; // [esp+24h] [ebp-4Ch] BYREF
  _BYTE v14[24]; // [esp+3Ch] [ebp-34h] BYREF
  _BYTE v15[24]; // [esp+54h] [ebp-1Ch] BYREF
  char v16; // [esp+6Ch] [ebp-4h] BYREF

  v4 = 3;
  v5 = &v12;
  do
  {
    survarium::flash_value::flash_value(v5);
    v5 = v6 + 1;
  }
  while ( v7 - 1 >= 0 );
  survarium::flash_value::SetUInt(v5, (int)&v12, LOBYTE(pos_scale.x));
  survarium::flash_value::SetNumber(v8, (int)v13, pos_scale.y);
  survarium::flash_value::SetNumber(v9, (int)v14, pos_scale.z);
  survarium::flash_value::SetNumber(v10, (int)v15, value);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(icon_uid + 16) + 264) + 4),
    "root.set_player_icon_pos",
    0,
    (const Scaleform::GFx::Value *)&v12,
    4u);
  v11 = (Scaleform::GFx::Value *)&v16;
  do
  {
    Scaleform::GFx::Value::~Value(--v11);
    --v4;
  }
  while ( v4 >= 0 );
}
