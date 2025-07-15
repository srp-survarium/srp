void __usercall survarium::lobby_menu::query_lobby_info(survarium::lobby_menu *this@<ecx>, int a2@<esi>)
{
  survarium::lobby_client *v2; // eax
  survarium::lobby_client *v3; // ecx
  survarium::lobby_client *v4; // eax
  survarium::lobby_client *v5; // ecx
  survarium::lobby_client *v6; // eax
  survarium::lobby_client *v7; // ecx
  survarium::lobby_client *v8; // eax
  survarium::lobby_client *v9; // ecx
  unsigned int v10; // edi
  int v11; // ebx
  survarium::lobby_client *v12; // eax
  survarium::lobby_client *v13; // ecx
  survarium::lobby_client *v14; // eax
  survarium::lobby_client *v15; // ecx

  if ( !*(_BYTE *)(a2 + 244) )
  {
    v2 = (survarium::lobby_client *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 168) + 952) + 60))(*(_DWORD *)(*(_DWORD *)(a2 + 168) + 952));
    survarium::lobby_client::query_client_status(v3, v2, q_profile_slots_restrictions);
    v4 = (survarium::lobby_client *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 168) + 952) + 60))(*(_DWORD *)(*(_DWORD *)(a2 + 168) + 952));
    survarium::lobby_client::query_client_status(v5, v4, q_items_compatibility);
    v6 = (survarium::lobby_client *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 168) + 952) + 60))(*(_DWORD *)(*(_DWORD *)(a2 + 168) + 952));
    survarium::lobby_client::query_client_status(v7, v6, q_player_skills_tree);
    v8 = (survarium::lobby_client *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 168) + 952) + 60))(*(_DWORD *)(*(_DWORD *)(a2 + 168) + 952));
    survarium::lobby_client::query_client_status(v9, v8, q_service_prices);
    v10 = 1;
    v11 = 4;
    do
    {
      v12 = (survarium::lobby_client *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 168) + 952) + 60))(*(_DWORD *)(*(_DWORD *)(a2 + 168) + 952));
      survarium::lobby_client::query_prices(v13, v12, v10++);
      --v11;
    }
    while ( v11 );
    *(_BYTE *)(a2 + 244) = 1;
  }
  v14 = (survarium::lobby_client *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 168) + 952) + 60))(*(_DWORD *)(*(_DWORD *)(a2 + 168) + 952));
  survarium::lobby_client::query_client_status(v15, v14, q_client_state);
}
