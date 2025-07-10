void __userpurge survarium::game_world_ui::add_victory_points(
        survarium::game_world_ui *this@<ecx>,
        int a2@<eax>,
        char team_1_points,
        char team_2_points)
{
  int v5; // ecx
  int v6; // eax
  int v7; // edi
  int v8; // ebp
  survarium::flash_value *v9; // eax
  int i; // ecx
  int v11; // edi
  int v12; // ecx
  char v13; // cl
  int v14; // edi
  int v15; // ecx
  char *v16; // esi
  int j; // edi
  int v18; // eax
  survarium::flash_value args[2]; // [esp+20h] [ebp-34h] BYREF
  char v20; // [esp+50h] [ebp-4h] BYREF

  v5 = *(_DWORD *)(*(_DWORD *)(a2 + 8) + 168);
  v6 = *(_DWORD *)(*(_DWORD *)(v5 + 952) + 15544);
  v7 = 0;
  if ( v6 )
  {
    v7 = *(_DWORD *)(*(_DWORD *)(v5 + 952) + 15544);
    _InterlockedExchangeAdd((volatile signed __int32 *)(v6 + 496), 1u);
  }
  v8 = (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 72))(v7);
  if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(v7 + 496), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(v7 + 496),
      (vostok::resources::unmanaged_resource *)(v7 + 288));
  *(_BYTE *)(a2 + 48) += team_1_points;
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
  v11 = *(unsigned __int8 *)(a2 + 48);
  *(_DWORD *)&args[0].body[4] = 4;
  *(_DWORD *)&args[0].body[8] = v8 != 0;
  if ( (args[1].body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)args[1].body + 8))(
      *(_DWORD *)args[1].body,
      &args[1],
      *(_DWORD *)&args[1].body[8]);
    *(_DWORD *)args[1].body = 0;
  }
  v12 = *(_DWORD *)(a2 + 4);
  *(_DWORD *)&args[1].body[4] = 4;
  *(_DWORD *)&args[1].body[8] = v11;
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(v12 + 264) + 4),
    "root.set_artifacts_progress",
    0,
    (const Scaleform::GFx::Value *)args,
    2u);
  v13 = args[0].body[4];
  *(_BYTE *)(a2 + 49) += team_2_points;
  if ( (v13 & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)args[0].body + 8))(
      *(_DWORD *)args[0].body,
      args,
      *(_DWORD *)&args[0].body[8]);
    *(_DWORD *)args[0].body = 0;
  }
  v14 = *(unsigned __int8 *)(a2 + 49);
  *(_DWORD *)&args[0].body[4] = 4;
  *(_DWORD *)&args[0].body[8] = v8 != 1;
  if ( (args[1].body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)args[1].body + 8))(
      *(_DWORD *)args[1].body,
      &args[1],
      *(_DWORD *)&args[1].body[8]);
    *(_DWORD *)args[1].body = 0;
  }
  v15 = *(_DWORD *)(a2 + 4);
  *(_DWORD *)&args[1].body[4] = 4;
  *(_DWORD *)&args[1].body[8] = v14;
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(v15 + 264) + 4),
    "root.set_artifacts_progress",
    0,
    (const Scaleform::GFx::Value *)args,
    2u);
  v16 = &v20;
  for ( j = 1; j >= 0; --j )
  {
    v18 = *((_DWORD *)v16 - 5);
    v16 -= 24;
    if ( (v18 & 0x40) != 0 )
    {
      (*(void (__stdcall **)(char *, _DWORD))(**(_DWORD **)v16 + 8))(v16, *((_DWORD *)v16 + 2));
      *(_DWORD *)v16 = 0;
    }
    *((_DWORD *)v16 + 1) = 0;
  }
}
