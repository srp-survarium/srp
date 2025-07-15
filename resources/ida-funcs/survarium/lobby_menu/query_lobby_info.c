void __usercall survarium::lobby_menu::query_lobby_info(
        survarium::lobby_menu *this@<ecx>,
        survarium::lobby_menu *a2@<esi>)
{
  survarium::lobby_client *v2; // eax
  survarium::lobby_client *v3; // ecx
  survarium::lobby_menu *v4; // ecx
  survarium::lobby_client *v5; // eax
  survarium::lobby_client *v6; // ecx
  survarium::lobby_menu *v7; // ecx
  survarium::lobby_client *v8; // eax
  survarium::lobby_client *v9; // ecx
  int v10; // edi
  int v11; // ebx
  survarium::lobby_client *v12; // eax
  survarium::lobby_client *v13; // ecx
  survarium::lobby_client *v14; // eax
  survarium::lobby_client *v15; // ecx
  survarium::lobby_menu *v16; // ecx

  if ( !a2->m_ui_static_info_initialized )
  {
    v2 = survarium::lobby_menu::lobby_client(this, (int)a2);
    survarium::lobby_client::query_client_status(v3, (const vostok::network_core::tcp_packet *)v2, 8u);
    v5 = survarium::lobby_menu::lobby_client(v4, (int)a2);
    survarium::lobby_client::query_client_status(v6, (const vostok::network_core::tcp_packet *)v5, 0xAu);
    v8 = survarium::lobby_menu::lobby_client(v7, (int)a2);
    survarium::lobby_client::query_client_status(v9, (const vostok::network_core::tcp_packet *)v8, 0x12u);
    v10 = 1;
    v11 = 4;
    do
    {
      v12 = survarium::lobby_menu::lobby_client(this, (int)a2);
      survarium::lobby_client::query_prices(v13, (const vostok::network_core::tcp_packet *)v12, v10++);
      --v11;
    }
    while ( v11 );
    a2->m_ui_static_info_initialized = 1;
  }
  v14 = survarium::lobby_menu::lobby_client(this, (int)a2);
  survarium::lobby_client::query_client_status(v15, (const vostok::network_core::tcp_packet *)v14, 0xEu);
  survarium::lobby_menu::request_status_from_server(v16, a2, 0);
  survarium::lobby_menu::request_squad_status_from_server(a2, 0x3E8u);
}
