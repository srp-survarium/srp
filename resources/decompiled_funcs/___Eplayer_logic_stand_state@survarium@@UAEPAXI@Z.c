survarium::player_logic_crouch_state *__thiscall survarium::player_logic_stand_state::`vector deleting destructor'(
        survarium::player_logic_crouch_state *this,
        char a2)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
