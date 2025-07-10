survarium::player_logic_sprint_state *__thiscall survarium::player_logic_sprint_state::`vector deleting destructor'(
        survarium::player_logic_sprint_state *this,
        char a2)
{
  survarium::player_logic_sprint_state::~player_logic_sprint_state(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
