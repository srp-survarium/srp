survarium::breath_state_normal *__thiscall survarium::breath_state_holding::`vector deleting destructor'(
        survarium::breath_state_normal *this,
        char a2)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
