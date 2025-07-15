void __thiscall survarium::game_world_ui::set_hud_icon_name(
        survarium::game_world_ui *this,
        int icon_uid,
        const char *player_name,
        char *value)
{
  survarium::flash_value *v4; // ecx
  survarium::flash_value *v5; // ecx
  int v6; // edx
  Scaleform::GFx::Value *v7; // esi
  int i; // edi
  survarium::flash_value v9; // [esp+8h] [ebp-34h] BYREF
  survarium::flash_value v10; // [esp+20h] [ebp-1Ch] BYREF
  char v11; // [esp+38h] [ebp-4h] BYREF

  v4 = &v9;
  do
  {
    survarium::flash_value::flash_value(v4);
    v4 = v5 + 1;
  }
  while ( v6 - 1 >= 0 );
  survarium::flash_value::SetUInt(v4, (int)&v9, (unsigned __int8)player_name);
  survarium::flash_value::SetString(&v10, value);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(icon_uid + 16) + 264) + 4),
    "root.set_player_icon_name",
    0,
    (const Scaleform::GFx::Value *)&v9,
    2u);
  v7 = (Scaleform::GFx::Value *)&v11;
  for ( i = 1; i >= 0; --i )
    Scaleform::GFx::Value::~Value(--v7);
}
