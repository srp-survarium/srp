void __userpurge survarium::game_world_core::atomic_tick(
        survarium::game_world_core *this@<ecx>,
        int a2@<esi>,
        survarium::base_player *tick_time_in_ms,
        unsigned int time_delta_in_ms)
{
  _DWORD *v5; // edi
  _DWORD *v6; // edi
  survarium::game_world_core *v7; // ecx
  survarium::bullet_manager *v8; // ecx
  int v9; // ecx
  int *v10; // edi
  unsigned __int64 v11; // kr00_8
  int v12; // eax
  _DWORD *i; // [esp+10h] [ebp+8h]
  _DWORD *j; // [esp+10h] [ebp+8h]

  v5 = *(_DWORD **)(a2 + 49504);
  for ( i = *(_DWORD **)(a2 + 49508); v5 != i; ++v5 )
    (*(void (__thiscall **)(_DWORD, unsigned int, survarium::base_player *))(*(_DWORD *)*v5 + 28))(
      *v5,
      time_delta_in_ms,
      tick_time_in_ms);
  v6 = *(_DWORD **)(a2 + 49412);
  for ( j = *(_DWORD **)(a2 + 49416); v6 != j; ++v6 )
  {
    if ( *(survarium::base_player **)(*v6 + 740) != tick_time_in_ms )
      (*(void (__thiscall **)(_DWORD, survarium::base_player *))(*(_DWORD *)*v6 + 48))(*v6, tick_time_in_ms);
  }
  (*(void (__thiscall **)(_DWORD, unsigned int, survarium::base_player *))(**(_DWORD **)(a2 + 51164) + 4))(
    *(_DWORD *)(a2 + 51164),
    time_delta_in_ms,
    tick_time_in_ms);
  survarium::game_world_core::assign_physics_transforms(v7, a2, tick_time_in_ms);
  survarium::bullet_manager::tick(
    v8,
    *(survarium::redundant_bullet_predicate *)(a2 + 51160),
    (unsigned int)tick_time_in_ms);
  v9 = *(_DWORD *)(a2 + 49536);
  if ( v9 )
  {
    v10 = (int *)(a2 + 51176);
    do
    {
      *v10 = *(_DWORD *)(v9 + 8);
      (**(void (__thiscall ***)(int, unsigned int, survarium::base_player *))v9)(v9, time_delta_in_ms, tick_time_in_ms);
      v9 = *v10;
    }
    while ( *v10 );
  }
  v11 = *(unsigned int *)(a2 + 51192) - (unsigned __int64)(unsigned int)tick_time_in_ms;
  v12 = *(_DWORD *)(a2 + 51192) - (v11 & HIDWORD(v11));
  *(_DWORD *)(a2 + 51188) = tick_time_in_ms;
  *(_DWORD *)(a2 + 51176) = 1;
  *(_DWORD *)(a2 + 51192) = v12;
}
