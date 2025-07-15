void __userpurge survarium::anomaly_state::finalize(survarium::anomaly_state *this@<ecx>, int a2@<edi>, int forced)
{
  unsigned int i; // ebx

  for ( i = 0; i < (*(_DWORD *)(a2 + 32) - *(_DWORD *)(a2 + 28)) >> 2; ++i )
    survarium::zone_group::finalize((survarium::zone_group *)this, *(_DWORD *)(*(_DWORD *)(a2 + 28) + 4 * i), forced);
}
