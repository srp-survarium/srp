void __usercall survarium::game::toggle_pause(survarium::game *this@<ecx>, survarium::game *a2@<esi>)
{
  bool v2; // cl

  if ( !((unsigned __int8 (__thiscall *)(survarium::base_network_client *, survarium::game *))a2->m_network_client->has_bandwidth)(
          a2->m_network_client,
          this) )
  {
    v2 = !a2->m_is_paused;
    a2->m_is_paused = v2;
    if ( v2 )
      survarium::game::pause(a2);
    else
      survarium::game::resume(a2);
  }
}
