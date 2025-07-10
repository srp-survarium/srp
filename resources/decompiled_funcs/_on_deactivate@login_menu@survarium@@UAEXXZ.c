void __thiscall survarium::login_menu::on_deactivate(survarium::login_menu *this)
{
  survarium::camera_director *m_camera_director; // ecx
  vostok::input::world *v3; // eax

  m_camera_director = this->m_camera_director;
  this->m_is_active = 0;
  m_camera_director->on_focus(m_camera_director, 0);
  v3 = this->m_game->input_world(this->m_game);
  v3->remove_handler(v3, &this->vostok::input::handler);
}
