void __thiscall survarium::lobby_menu::on_shop_ui_ready(survarium::lobby_menu *this, survarium::lobby_menu *thisa)
{
  unsigned int v2; // esi
  int v3; // edi
  survarium::lobby_client *v4; // eax
  survarium::lobby_client *v5; // ecx

  v2 = 1;
  v3 = 4;
  do
  {
    v4 = thisa->m_game->m_network_client->lobby_client(thisa->m_game->m_network_client);
    survarium::lobby_client::query_prices(v5, v4, v2++);
    --v3;
  }
  while ( v3 );
}
