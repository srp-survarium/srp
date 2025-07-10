void __thiscall survarium::base_game_scene::on_after_tick(survarium::base_game_scene *this)
{
  survarium::camera_director::apply((survarium::camera_director *)this, this->m_camera_director);
}
