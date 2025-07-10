void __thiscall survarium::game_world::on_activate(survarium::game_world *this)
{
  vostok::input::handler *v2; // edi
  vostok::input::world *v3; // eax
  vostok::sound::world_user *v4; // eax

  survarium::base_game_scene::on_activate(this);
  if ( this )
    v2 = &this->vostok::input::handler;
  else
    v2 = 0;
  v3 = this->m_game->input_world(this->m_game);
  v3->add_handler(v3, v2);
  if ( this->m_sound_scene.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v4 = this->m_game->m_sound_world->get_logic_world_user(this->m_game->m_sound_world);
    vostok::sound::world_user::set_active_sound_scene(v4, &this->m_sound_scene, 0, 0);
  }
  if ( this->m_game->m_network_client->has_bandwidth(this->m_game->m_network_client) )
    survarium::chat_handler::set_mode((survarium::chat_handler *)this->m_game, this->m_game->m_chat_handler, 1);
}
