void __thiscall survarium::pvp_match_core::clear_resources(survarium::pvp_match_core *this, int a2)
{
  int v2; // edi
  unsigned int v3; // ebp
  unsigned int v4; // esi
  int v5; // ecx
  _DWORD *v6; // esi
  _DWORD *v7; // edi

  v2 = *(_DWORD *)(a2 + 312);
  v3 = 0;
  v4 = (*(_DWORD *)(v2 + 49324) - *(_DWORD *)(v2 + 49320)) >> 2;
  if ( v4 )
  {
    do
    {
      v5 = *(_DWORD *)(*(_DWORD *)(v2 + 49320) + 4 * v3);
      (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 40))(v5);
      ++v3;
    }
    while ( v3 < v4 );
  }
  survarium::game_world_core::clear((survarium::game_world_core *)this, *(_DWORD *)(a2 + 312));
  v6 = *(_DWORD **)(a2 + 264);
  v7 = *(_DWORD **)(a2 + 268);
  while ( v6 != v7 )
  {
    (*(void (__thiscall **)(_DWORD))(*(_DWORD *)*v6 + 56))(*v6);
    ++v6;
  }
  (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)(a2 + 296) + 16))(
    *(_DWORD *)(a2 + 296),
    *(_DWORD *)(a2 + 304),
    *(_DWORD *)(a2 + 312));
}
