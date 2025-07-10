int __usercall survarium::base_network_client::current_player_team@<eax>(
        survarium::base_network_client *this@<ecx>,
        int a2@<eax>)
{
  int v2; // ecx

  v2 = *(_DWORD *)(a2 + 8);
  if ( v2 )
    return (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 72))(v2);
  else
    return 2;
}
