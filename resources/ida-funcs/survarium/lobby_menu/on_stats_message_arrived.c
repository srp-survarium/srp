void __usercall survarium::lobby_menu::on_stats_message_arrived(survarium::lobby_menu *this@<ecx>, int a2@<esi>)
{
  survarium::lobby_menu *v2; // ecx
  survarium::lobby_client *v3; // eax
  survarium::lobby_client *v4; // ecx
  survarium::lobby_menu *v5; // ecx
  survarium::lobby_client *v6; // eax
  survarium::lobby_client *v7; // ecx
  survarium::lobby_menu *v8; // ecx
  survarium::lobby_client *v9; // eax
  survarium::lobby_client *v10; // ecx
  survarium::lobby_menu *v11; // ecx
  survarium::lobby_client *v12; // eax
  survarium::lobby_client *v13; // ecx
  survarium::lobby_menu *v14; // ecx
  survarium::lobby_client *v15; // eax
  survarium::lobby_client *v16; // ecx
  survarium::lobby_menu *v17; // ecx
  survarium::lobby_client *v18; // eax
  survarium::lobby_client *v19; // ecx

  if ( survarium::lobby_menu::lobby_client(this, a2)->m_net_client_connected )
  {
    v3 = survarium::lobby_menu::lobby_client(v2, a2);
    survarium::lobby_client::query_client_status(v4, (const vostok::network_core::tcp_packet *)v3, 3u);
    v6 = survarium::lobby_menu::lobby_client(v5, a2);
    survarium::lobby_client::query_client_status(v7, (const vostok::network_core::tcp_packet *)v6, 5u);
    v9 = survarium::lobby_menu::lobby_client(v8, a2);
    survarium::lobby_client::query_client_status(v10, (const vostok::network_core::tcp_packet *)v9, 0xBu);
    v12 = survarium::lobby_menu::lobby_client(v11, a2);
    survarium::lobby_client::query_client_status(v13, (const vostok::network_core::tcp_packet *)v12, 0xCu);
    v15 = survarium::lobby_menu::lobby_client(v14, a2);
    survarium::lobby_client::query_client_status(v16, (const vostok::network_core::tcp_packet *)v15, 0x13u);
    v18 = survarium::lobby_menu::lobby_client(v17, a2);
    survarium::lobby_client::query_client_status(v19, (const vostok::network_core::tcp_packet *)v18, 9u);
  }
  else
  {
    *(_BYTE *)(a2 + 1657) = 1;
  }
}
