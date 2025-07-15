void __thiscall survarium::lobby_menu::tick(
        survarium::lobby_menu *this,
        survarium::lobby_menu *frame_delta_in_ms,
        vostok::animation::subscribed_channel **current_time_in_ms,
        bool is_game_paused)
{
  survarium::camera_director *m_camera_director; // eax
  vostok::physics::world *m_physics_world; // ecx
  survarium::camera_director *v7; // ecx
  survarium::lobby_client *v8; // eax
  survarium::lobby_client *v9; // ecx
  survarium::player *v10; // ecx
  survarium::player *m_object; // eax
  unsigned int v12; // [esp+0h] [ebp-10h]

  m_camera_director = this->m_camera_director;
  if ( m_camera_director->m_active_camera )
    m_camera_director->m_active_camera->tick(m_camera_director->m_active_camera);
  if ( !is_game_paused )
  {
    m_physics_world = this->m_physics_world;
    if ( m_physics_world )
      m_physics_world->tick(m_physics_world, (const unsigned int)current_time_in_ms);
  }
  v7 = (survarium::camera_director *)((char *)current_time_in_ms - this->m_last_ping_time_in_ms);
  if ( (unsigned int)v7 >= 0x3E8 )
  {
    v8 = this->m_game->m_network_client->lobby_client(this->m_game->m_network_client);
    survarium::lobby_client::ping_server(v9, (int)v8);
    this->m_last_ping_time_in_ms = (unsigned int)current_time_in_ms;
  }
  survarium::camera_director::apply(v7, this->m_camera_director);
  if ( this->m_is_ui_shown )
    survarium::lobby_menu::update_ui(frame_delta_in_ms, this, (const unsigned int)frame_delta_in_ms, v12);
  m_object = this->m_character->m_player.m_object;
  if ( m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      survarium::player::tick(v10, *(float *)&m_object, current_time_in_ms);
  }
}
