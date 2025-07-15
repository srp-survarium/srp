void __usercall survarium::lobby_menu::query_account_data(survarium::lobby_menu *this@<ecx>, int a2@<esi>)
{
  survarium::lobby_client *v2; // eax
  survarium::lobby_client *v3; // ecx
  survarium::lobby_menu *v4; // ecx
  survarium::lobby_client *v5; // eax
  survarium::lobby_client *v6; // ecx
  survarium::lobby_menu *v7; // ecx
  survarium::lobby_client *v8; // eax
  survarium::lobby_client *v9; // ecx
  survarium::lobby_menu *v10; // ecx
  survarium::lobby_client *v11; // eax
  survarium::lobby_client *v12; // ecx
  survarium::lobby_menu *v13; // ecx
  survarium::lobby_client *v14; // eax
  survarium::lobby_client *v15; // ecx
  survarium::lobby_menu *v16; // ecx
  survarium::lobby_client *v17; // eax
  survarium::lobby_client *v18; // ecx
  survarium::lobby_menu *v19; // ecx
  survarium::lobby_client *v20; // eax
  survarium::lobby_client *v21; // ecx

  v2 = survarium::lobby_menu::lobby_client(this, a2);
  survarium::lobby_client::query_client_status(v3, (const vostok::network_core::tcp_packet *)v2, 3u);
  v5 = survarium::lobby_menu::lobby_client(v4, a2);
  survarium::lobby_client::query_client_status(v6, (const vostok::network_core::tcp_packet *)v5, 5u);
  v8 = survarium::lobby_menu::lobby_client(v7, a2);
  survarium::lobby_client::query_client_status(v9, (const vostok::network_core::tcp_packet *)v8, 0x13u);
  v11 = survarium::lobby_menu::lobby_client(v10, a2);
  survarium::lobby_client::query_client_status(v12, (const vostok::network_core::tcp_packet *)v11, 9u);
  v14 = survarium::lobby_menu::lobby_client(v13, a2);
  survarium::lobby_client::query_client_status(v15, (const vostok::network_core::tcp_packet *)v14, 0xCu);
  v17 = survarium::lobby_menu::lobby_client(v16, a2);
  survarium::lobby_client::query_client_status(v18, (const vostok::network_core::tcp_packet *)v17, 0x10u);
  if ( *(_BYTE *)(a2 + 1657) )
  {
    v20 = survarium::lobby_menu::lobby_client(v19, a2);
    survarium::lobby_client::query_client_status(v21, (const vostok::network_core::tcp_packet *)v20, 0xBu);
  }
}
