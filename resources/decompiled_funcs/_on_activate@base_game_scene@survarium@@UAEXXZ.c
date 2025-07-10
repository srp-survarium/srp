void __thiscall survarium::base_game_scene::on_activate(survarium::base_game_scene *this)
{
  survarium::game *m_game; // eax
  vostok::sound::world_user *v3; // eax
  unsigned int v4; // [esp+0h] [ebp-4h]

  m_game = this->m_game;
  this->m_is_active = 1;
  v3 = (vostok::sound::world_user *)((int (__thiscall *)(vostok::sound::world *, vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *))m_game->m_sound_world->get_logic_world_user)(
                                      m_game->m_sound_world,
                                      &this->m_sound_scene);
  vostok::sound::world_user::set_active_sound_scene(v3, 0, 0, v4);
  this->m_camera_director->on_focus(this->m_camera_director, 1);
  this->m_mouse_pos.x = 50;
  this->m_mouse_pos.y = 50;
}
