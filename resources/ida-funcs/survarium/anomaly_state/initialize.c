void __userpurge survarium::anomaly_state::initialize(
        survarium::anomaly_state *this@<ecx>,
        _DWORD *a2@<edi>,
        unsigned int current_time_in_ms,
        bool forced)
{
  int v4; // esi
  _DWORD *v5; // ebx
  int v6; // eax
  _DWORD *j; // [esp+0h] [ebp-8h]
  survarium::zone_group *i; // [esp+4h] [ebp-4h]

  for ( i = 0; (unsigned int)i < (a2[8] - a2[7]) >> 2; i = (survarium::zone_group *)((char *)i + 1) )
  {
    v4 = *(_DWORD *)(a2[7] + 4 * (_DWORD)i);
    if ( *(_BYTE *)(v4 + 1) )
    {
      v5 = *(_DWORD **)(v4 + 20);
      for ( j = *(_DWORD **)(v4 + 24); v5 != j; ++v5 )
        (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)(*(_DWORD *)(v4 + 32) + 40) + 20))(
          *(_DWORD *)(*(_DWORD *)(v4 + 32) + 40),
          *v5,
          0);
    }
    else
    {
      survarium::zone_group::recharge(i, v4, 0);
    }
  }
  v6 = a2[4];
  if ( v6 )
    a2[11] = current_time_in_ms + 1000 * v6;
  else
    a2[11] = 0;
}
