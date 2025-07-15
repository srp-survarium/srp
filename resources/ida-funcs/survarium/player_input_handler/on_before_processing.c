void __thiscall survarium::player_input_handler::on_before_processing(
        survarium::player_input_handler *this,
        vostok::input::world *input_world)
{
  vostok::circular_buffer<stlp_std::pair<enum survarium::game_action_id,enum survarium::action_state_enum>,64>::clear(&this->m_game_actions);
  this->m_current_input.actions_mask = 0;
  this->m_current_input.rotation_delta.x = 0.0;
  this->m_current_input.rotation_delta.y = 0.0;
  this->m_z_mouse_axis = 0.0;
}
