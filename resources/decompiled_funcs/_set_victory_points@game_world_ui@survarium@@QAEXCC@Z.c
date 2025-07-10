void __userpurge survarium::game_world_ui::set_victory_points(
        survarium::game_world_ui *this@<ecx>,
        int a2@<eax>,
        char team_1_points,
        char team_2_points)
{
  int v6; // ecx
  int v7; // eax
  int v8; // esi
  survarium::flash_value *v9; // eax
  int i; // ecx
  int v11; // edx
  int v12; // ecx
  int v13; // edx
  int *v14; // esi
  int j; // edi
  int v16; // ecx
  survarium::flash_value args[2]; // [esp+20h] [ebp-34h] BYREF
  int v18; // [esp+50h] [ebp-4h] BYREF
  survarium::game_team_id local_player_team; // [esp+58h] [ebp+4h]

  v6 = *(_DWORD *)(*(_DWORD *)(a2 + 8) + 168);
  v7 = *(_DWORD *)(*(_DWORD *)(v6 + 952) + 15544);
  v8 = 0;
  if ( v7 )
  {
    v8 = *(_DWORD *)(*(_DWORD *)(v6 + 952) + 15544);
    _InterlockedExchangeAdd((volatile signed __int32 *)(v7 + 496), 1u);
  }
  local_player_team = (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 72))(v8);
  if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(v8 + 496), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(v8 + 496),
      (vostok::resources::unmanaged_resource *)(v8 + 288));
  *(_BYTE *)(a2 + 48) = team_1_points;
  v9 = args;
  for ( i = 1; i >= 0; --i )
  {
    if ( v9 )
    {
      *(_DWORD *)v9->body = 0;
      *(_DWORD *)&v9->body[4] = 0;
    }
    ++v9;
  }
  if ( (args[0].body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)args[0].body + 8))(
      *(_DWORD *)args[0].body,
      args,
      *(_DWORD *)&args[0].body[8]);
    *(_DWORD *)args[0].body = 0;
  }
  *(_DWORD *)&args[0].body[4] = 4;
  *(_DWORD *)&args[0].body[8] = local_player_team != team_1;
  if ( (args[1].body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)args[1].body + 8))(
      *(_DWORD *)args[1].body,
      &args[1],
      *(_DWORD *)&args[1].body[8]);
    *(_DWORD *)args[1].body = 0;
  }
  v11 = *(_DWORD *)(a2 + 4);
  *(_DWORD *)&args[1].body[4] = 4;
  *(_DWORD *)&args[1].body[8] = team_1_points;
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(v11 + 264) + 4),
    "root.set_artifacts_progress",
    0,
    (const Scaleform::GFx::Value *)args,
    2u);
  v12 = *(_DWORD *)&args[0].body[4] >> 6;
  *(_BYTE *)(a2 + 49) = team_2_points;
  if ( (v12 & 1) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)args[0].body + 8))(
      *(_DWORD *)args[0].body,
      args,
      *(_DWORD *)&args[0].body[8]);
    *(_DWORD *)args[0].body = 0;
  }
  *(_DWORD *)&args[0].body[4] = 4;
  *(_DWORD *)&args[0].body[8] = local_player_team != team_2;
  if ( (args[1].body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)args[1].body + 8))(
      *(_DWORD *)args[1].body,
      &args[1],
      *(_DWORD *)&args[1].body[8]);
    *(_DWORD *)args[1].body = 0;
  }
  v13 = *(_DWORD *)(a2 + 4);
  *(_DWORD *)&args[1].body[4] = 4;
  *(_DWORD *)&args[1].body[8] = team_2_points;
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(v13 + 264) + 4),
    "root.set_artifacts_progress",
    0,
    (const Scaleform::GFx::Value *)args,
    2u);
  v14 = &v18;
  for ( j = 1; j >= 0; --j )
  {
    v16 = *(v14 - 5);
    v14 -= 6;
    if ( (v16 & 0x40) != 0 )
    {
      (*(void (__stdcall **)(int *, int))(*(_DWORD *)*v14 + 8))(v14, v14[2]);
      *v14 = 0;
    }
    v14[1] = 0;
  }
}
