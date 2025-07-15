void __thiscall survarium::player_input_handler::~player_input_handler(survarium::player_input_handler *this)
{
  this->vostok::input::handler::__vftable = (survarium::player_input_handler_vtbl *)&survarium::player_input_handler::`vftable'{for `vostok::input::handler'};
  this->survarium::game_camera::__vftable = (survarium::game_camera_vtbl *)&survarium::player_input_handler::`vftable'{for `survarium::game_camera'};
  this->m_game_toggle_actions.m_end = this->m_game_toggle_actions.m_begin;
  vostok::circular_buffer<stlp_std::pair<enum survarium::game_action_id,enum survarium::action_state_enum>,64>::clear(&this->m_game_actions);
}
