void __usercall survarium::game::switch_to_game_world(survarium::game *this@<ecx>, int a2@<edi>)
{
  int v2; // ecx
  void (__thiscall ***v3)(int); // esi

  v2 = *(_DWORD *)(a2 + 940);
  v3 = (void (__thiscall ***)(int))(a2 + 152);
  if ( v2 != a2 + 152 )
  {
    if ( v2 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 4))(v2);
    *(_DWORD *)(a2 + 940) = v3;
    (**v3)(a2 + 152);
  }
}
