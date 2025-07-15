survarium::jump_logic_base_state *__thiscall survarium::jump_logic_state_prepare::`vector deleting destructor'(
        survarium::jump_logic_base_state *this,
        char a2)
{
  survarium::jump_logic_base_state::~jump_logic_base_state(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
