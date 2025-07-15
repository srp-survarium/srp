void __usercall survarium::game::on_queried_by_network_client_scene_ready(
        survarium::game *this@<ecx>,
        survarium::scene_ready_type scene_ready@<eax>)
{
  if ( scene_ready )
  {
    if ( scene_ready != lobby_scene_ready )
      return;
    this->m_lobby_scene_ready = 1;
  }
  else
  {
    this->m_login_scene_ready = 1;
  }
  if ( this->m_lobby_scene_ready && this->m_login_scene_ready )
    survarium::game::create_network_client(this, this, 0);
}
