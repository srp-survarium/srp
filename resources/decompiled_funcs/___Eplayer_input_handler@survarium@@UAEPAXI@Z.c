survarium::player_input_handler *__thiscall survarium::player_input_handler::`vector deleting destructor'(
        survarium::player_input_handler *this,
        char a2)
{
  this->vostok::input::handler::__vftable = (survarium::player_input_handler_vtbl *)&survarium::player_input_handler::`vftable'{for `vostok::input::handler'};
  this->survarium::game_camera::__vftable = (survarium::game_camera_vtbl *)&survarium::player_input_handler::`vftable'{for `survarium::game_camera'};
  this->m_game_actions.m_end = this->m_game_actions.m_begin;
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
