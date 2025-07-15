BOOL __usercall survarium::base_player::has_grenade@<eax>(survarium::base_player *this@<ecx>, int a2@<eax>)
{
  int v2; // eax
  int v3; // ecx
  _WORD *v4; // ecx
  int v5; // eax
  survarium::grenade_set_core *v6; // ecx
  BOOL result; // eax

  v2 = *(_DWORD *)(a2 + 268);
  v3 = *(_DWORD *)(v2 + 384);
  result = 0;
  if ( v3 != 23 )
  {
    v4 = *(_WORD **)(v2 + 4 * v3 + 272);
    if ( v4[140] )
    {
      v5 = (*(int (__thiscall **)(_WORD *, survarium::base_player *))(*(_DWORD *)v4 + 80))(v4, this);
      if ( survarium::grenade_set_core::ready_to_throw(v6, v5) )
        return 1;
    }
  }
  return result;
}
