void __usercall survarium::game::on_queried_by_network_client_scene_ready(
        survarium::game *this@<ecx>,
        survarium::game *a2@<eax>)
{
  if ( this )
  {
    if ( this != (survarium::game *)1 )
      return;
    a2->m_lobby_scene_ready = 1;
  }
  else
  {
    a2->m_login_scene_ready = 1;
  }
  if ( a2->m_lobby_scene_ready && a2->m_login_scene_ready )
    survarium::game::create_network_client(0, a2, 0);
}
