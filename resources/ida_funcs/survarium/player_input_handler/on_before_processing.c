void __thiscall survarium::player_input_handler::on_before_processing(
        survarium::player_input_handler *this,
        vostok::input::world *input_world,
        unsigned int current_time_in_ms)
{
  unsigned int v3; // edx

  this->m_game_actions.m_end = this->m_game_actions.m_begin;
  this->m_rotation_delta = 0;
  v3 = current_time_in_ms - this->m_current_time_in_ms;
  this->m_z_mouse_axis = 0.0;
  this->m_input.actions_mask = 0;
  this->m_time_delta_in_ms = v3;
  this->m_current_time_in_ms = current_time_in_ms;
}
