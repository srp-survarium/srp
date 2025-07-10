void __thiscall survarium::game::load(survarium::game *this, const char *project_resource_name)
{
  this->m_network_client->load(this->m_network_client, project_resource_name, this->m_game_world.m_camera_director);
}
