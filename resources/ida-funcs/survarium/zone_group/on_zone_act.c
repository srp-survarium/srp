void __userpurge survarium::zone_group::on_zone_act(
        survarium::zone_group *this@<ecx>,
        int a2@<esi>,
        survarium::damage_zone_core *zone,
        survarium::hit_receiver *receiver,
        unsigned int current_time_in_ms)
{
  int v5; // edx
  survarium::damage_zone_core **v6; // eax
  survarium::damage_zone_core **i; // ecx

  *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(a2 + 32) + 40) + 392) = 1;
  if ( !*(_BYTE *)(a2 + 1) && !*(_BYTE *)(a2 + 2) )
  {
    v5 = 0;
    if ( (*(_DWORD *)(a2 + 24) - *(_DWORD *)(a2 + 20)) >> 2 )
    {
      v6 = *(survarium::damage_zone_core ***)(a2 + 20);
      for ( i = v6; *i != zone; ++i )
      {
        if ( ++v5 >= (unsigned int)((*(_DWORD *)(a2 + 24) - (int)v6) >> 2) )
          return;
      }
      (*(void (__thiscall **)(_DWORD, survarium::damage_zone_core *, _DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 32) + 40)
                                                                            + 24))(
        *(_DWORD *)(*(_DWORD *)(a2 + 32) + 40),
        v6[v5],
        0);
      if ( !*(_DWORD *)(a2 + 36) )
        *(_DWORD *)(a2 + 36) = &receiver[250 * *(_DWORD *)(a2 + 16)];
    }
  }
}
