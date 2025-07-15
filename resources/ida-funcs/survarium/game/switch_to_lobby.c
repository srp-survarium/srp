void __usercall survarium::game::switch_to_lobby(survarium::game *this@<ecx>, survarium::game *a2@<esi>)
{
  if ( a2->m_network_client->has_bandwidth(a2->m_network_client) )
    survarium::game::switch_to_scene(a2, a2->m_lobby_menu);
}
