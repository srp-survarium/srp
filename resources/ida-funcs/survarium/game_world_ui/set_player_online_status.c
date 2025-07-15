void __thiscall survarium::game_world_ui::set_player_online_status(
        survarium::game_world_ui *this,
        unsigned int __formal,
        const char (*player_name)[64],
        bool is_online)
{
  survarium::flash_value *v4; // ecx
  survarium::flash_value *v5; // ecx
  int v6; // edx
  survarium::flash_value *v7; // ecx
  Scaleform::GFx::Value *v8; // esi
  int i; // edi
  survarium::flash_value v10; // [esp+8h] [ebp-34h] BYREF
  _BYTE v11[24]; // [esp+20h] [ebp-1Ch] BYREF
  char v12; // [esp+38h] [ebp-4h] BYREF

  v4 = &v10;
  do
  {
    survarium::flash_value::flash_value(v4);
    v4 = v5 + 1;
  }
  while ( v6 - 1 >= 0 );
  survarium::flash_value::SetString(&v10, (const char *)player_name);
  survarium::flash_value::SetBoolean(v7, (int)v11, is_online);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(__formal + 8) + 264) + 4),
    "root.set_online_player",
    0,
    (const Scaleform::GFx::Value *)&v10,
    2u);
  v8 = (Scaleform::GFx::Value *)&v12;
  for ( i = 1; i >= 0; --i )
    Scaleform::GFx::Value::~Value(--v8);
}
