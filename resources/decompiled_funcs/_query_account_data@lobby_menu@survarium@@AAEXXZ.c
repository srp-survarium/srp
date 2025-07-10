void __usercall survarium::lobby_menu::query_account_data(survarium::lobby_menu *this@<ecx>, int a2@<esi>)
{
  survarium::lobby_client *v2; // eax
  survarium::lobby_client *v3; // ecx
  survarium::lobby_client *v4; // eax
  survarium::lobby_client *v5; // ecx
  survarium::lobby_client *v6; // eax
  survarium::lobby_client *v7; // ecx
  survarium::lobby_client *v8; // eax
  survarium::lobby_client *v9; // ecx

  v2 = (survarium::lobby_client *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 168) + 952) + 60))(*(_DWORD *)(*(_DWORD *)(a2 + 168) + 952));
  survarium::lobby_client::query_client_status(v3, v2, q_enumerate_inventory);
  v4 = (survarium::lobby_client *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 168) + 952) + 60))(*(_DWORD *)(*(_DWORD *)(a2 + 168) + 952));
  survarium::lobby_client::query_client_status(v5, v4, q_account_money);
  v6 = (survarium::lobby_client *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 168) + 952) + 60))(*(_DWORD *)(*(_DWORD *)(a2 + 168) + 952));
  survarium::lobby_client::query_client_status(v7, v6, q_player_skills);
  v8 = (survarium::lobby_client *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 168) + 952) + 60))(*(_DWORD *)(*(_DWORD *)(a2 + 168) + 952));
  survarium::lobby_client::query_client_status(v9, v8, q_player_reputations);
}
