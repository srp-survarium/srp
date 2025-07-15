void __userpurge survarium::anomaly_state::post_deserialize_resolve(
        survarium::anomaly_state *this@<ecx>,
        int a2@<esi>,
        survarium::game_world_core *game_world_core)
{
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  unsigned int i; // [esp+0h] [ebp-4h]

  for ( i = 0; i < (*(_DWORD *)(a2 + 32) - *(_DWORD *)(a2 + 28)) >> 2; ++i )
  {
    v3 = *(_DWORD *)(*(_DWORD *)(a2 + 28) + 4 * i);
    v4 = *(_DWORD *)(v3 + 20);
    v5 = *(_DWORD *)(v3 + 24);
    while ( v4 != v5 )
    {
      if ( *(_BYTE *)(*(_DWORD *)v4 + 292) )
        (*(void (__thiscall **)(int, survarium::game_world_core *))(*(_DWORD *)(*(_DWORD *)v4 + 328) + 8))(
          *(_DWORD *)v4 + 328,
          game_world_core);
      v4 += 4;
    }
  }
}
