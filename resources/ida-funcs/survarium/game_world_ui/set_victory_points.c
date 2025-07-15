void __thiscall survarium::game_world_ui::set_victory_points(
        survarium::game_world_ui *this,
        int team_1_points,
        char team_2_points,
        survarium::game_team_id local_player_team,
        int a5)
{
  survarium::flash_value *v5; // ecx
  survarium::flash_value *v6; // ecx
  int v7; // edx
  survarium::flash_value *v8; // ecx
  survarium::flash_value *v9; // ecx
  survarium::flash_value *v10; // ecx
  Scaleform::GFx::Value *v11; // esi
  int i; // edi
  survarium::flash_value v13; // [esp+Ch] [ebp-30h] BYREF
  _BYTE v14[24]; // [esp+24h] [ebp-18h] BYREF
  char vars0; // [esp+3Ch] [ebp+0h] BYREF

  v5 = &v13;
  do
  {
    survarium::flash_value::flash_value(v5);
    v5 = v6 + 1;
  }
  while ( v7 - 1 >= 0 );
  survarium::flash_value::SetUInt(v5, (int)&v13, a5 != 0);
  survarium::flash_value::SetUInt(v8, (int)v14, team_2_points);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(team_1_points + 8) + 264) + 4),
    "root.set_artifacts_progress",
    0,
    (const Scaleform::GFx::Value *)&v13,
    2u);
  survarium::flash_value::SetUInt(v9, (int)&v13, a5 != 1);
  survarium::flash_value::SetUInt(v10, (int)v14, (char)local_player_team);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(team_1_points + 8) + 264) + 4),
    "root.set_artifacts_progress",
    0,
    (const Scaleform::GFx::Value *)&v13,
    2u);
  v11 = (Scaleform::GFx::Value *)&vars0;
  for ( i = 1; i >= 0; --i )
    Scaleform::GFx::Value::~Value(--v11);
}
