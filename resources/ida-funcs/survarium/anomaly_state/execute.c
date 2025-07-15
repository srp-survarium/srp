void __userpurge survarium::anomaly_state::execute(
        survarium::anomaly_state *this@<ecx>,
        unsigned int *a2@<edi>,
        unsigned int time_delta_ms,
        unsigned int current_time_ms)
{
  survarium::zone_group *v4; // ecx
  int v5; // esi
  int v6; // ebx
  unsigned int v7; // eax
  unsigned int v8; // eax
  int j; // [esp+0h] [ebp-8h]
  unsigned int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < (int)(a2[8] - a2[7]) >> 2; ++i )
  {
    v4 = (survarium::zone_group *)i;
    v5 = *(_DWORD *)(a2[7] + 4 * i);
    v6 = *(_DWORD *)(v5 + 20);
    for ( j = *(_DWORD *)(v5 + 24); v6 != j; v6 += 4 )
    {
      if ( *(_BYTE *)(*(_DWORD *)v6 + 292) )
        (*(void (__thiscall **)(int, unsigned int, unsigned int))(*(_DWORD *)(*(_DWORD *)v6 + 264) + 20))(
          *(_DWORD *)v6 + 264,
          time_delta_ms,
          current_time_ms);
    }
    if ( !*(_BYTE *)(v5 + 1) )
    {
      v7 = *(_DWORD *)(v5 + 36);
      if ( v7 )
      {
        if ( current_time_ms >= v7 )
          survarium::zone_group::recharge(v4, v5, current_time_ms);
      }
    }
  }
  v8 = a2[11];
  if ( v8 )
  {
    if ( current_time_ms > v8 )
    {
      *(float *)(a2[10] + 332) = (float)a2[5];
      a2[11] = 0;
    }
  }
}
