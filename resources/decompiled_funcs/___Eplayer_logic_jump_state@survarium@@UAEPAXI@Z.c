survarium::player_logic_jump_state *__thiscall survarium::player_logic_jump_state::`vector deleting destructor'(
        survarium::player_logic_jump_state *this,
        char a2)
{
  survarium::game_camera *v2; // ecx

  survarium::jump_logic::~jump_logic(&this->m_logic);
  survarium::weapon_user_dead_state::finalize(v2);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
