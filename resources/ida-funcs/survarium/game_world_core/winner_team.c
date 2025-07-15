int __usercall survarium::game_world_core::winner_team@<eax>(survarium::game_world_core *this@<ecx>, int a2@<eax>)
{
  _DWORD *v2; // ebp
  _DWORD *v3; // esi
  _DWORD *v4; // ebx
  _DWORD *i; // esi
  int v6; // edi
  int v8; // [esp+8h] [ebp-4h]

  v2 = *(_DWORD **)(a2 + 49508);
  v3 = *(_DWORD **)(a2 + 49504);
  if ( v3 != v2 )
  {
    v4 = *(_DWORD **)(a2 + 49504);
    for ( i = v3 + 1; i != v2; ++i )
    {
      v6 = *i;
      v8 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*v4 + 76))(*v4);
      if ( v8 < (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 76))(v6) )
        v4 = i;
    }
    v3 = v4;
  }
  return (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*v3 + 80))(*v3);
}
