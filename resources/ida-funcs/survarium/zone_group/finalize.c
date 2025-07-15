void __userpurge survarium::zone_group::finalize(survarium::zone_group *this@<ecx>, int a2@<esi>, int forced)
{
  _DWORD *v3; // edi
  _DWORD *v4; // ebx
  unsigned int i; // edi
  int v6; // eax

  if ( *(_BYTE *)(a2 + 1) )
  {
    v3 = *(_DWORD **)(a2 + 20);
    v4 = *(_DWORD **)(a2 + 24);
    while ( v3 != v4 )
      (*(void (__thiscall **)(_DWORD, _DWORD, int))(**(_DWORD **)(*(_DWORD *)(a2 + 32) + 40) + 24))(
        *(_DWORD *)(*(_DWORD *)(a2 + 32) + 40),
        *v3++,
        forced);
  }
  else
  {
    for ( i = 0; i < (*(_DWORD *)(a2 + 24) - *(_DWORD *)(a2 + 20)) >> 2; ++i )
    {
      v6 = *(_DWORD *)(*(_DWORD *)(a2 + 20) + 4 * i);
      if ( *(_BYTE *)(v6 + 292) )
        (*(void (__thiscall **)(_DWORD, int, int))(**(_DWORD **)(*(_DWORD *)(a2 + 32) + 40) + 24))(
          *(_DWORD *)(*(_DWORD *)(a2 + 32) + 40),
          v6,
          forced);
    }
  }
}
