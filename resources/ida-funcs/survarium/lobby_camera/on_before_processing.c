void __thiscall survarium::lobby_camera::on_before_processing(
        survarium::lobby_camera *this,
        vostok::input::world *input_world,
        unsigned int current_time_in_ms)
{
  this->m_rotation_delta = 0;
  this->m_z_mouse_axis = 0.0;
}
