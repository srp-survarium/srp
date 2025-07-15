void __usercall survarium::lobby_menu::play_button_clicked(survarium::lobby_menu *this@<ecx>, int a2@<esi>)
{
  survarium::lobby_menu *v2; // ecx
  unsigned __int8 v3; // bl
  survarium::lobby_client *v4; // eax
  survarium::lobby_menu *v5; // ecx
  survarium::lobby_client *v6; // eax
  survarium::lobby_client *v7; // ecx
  int v8; // [esp-4h] [ebp-8h]

  if ( survarium::lobby_menu::lobby_client(this, a2)->m_profiles_count )
  {
    v3 = *(_BYTE *)(a2 + 1604);
    v4 = survarium::lobby_menu::lobby_client(v2, a2);
    v5 = (survarium::lobby_menu *)(1512 * v3);
    v8 = *(unsigned int *)((char *)&v4->m_profiles[0].profile_id + (_DWORD)v5);
    v6 = survarium::lobby_menu::lobby_client(v5, a2);
    survarium::lobby_client::set_status_ready_for_match(v7, (const vostok::network_core::tcp_packet *)v6, v8);
  }
}
