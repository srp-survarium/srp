survarium::jump_logic_state_start *__thiscall survarium::jump_logic_state_start::`scalar deleting destructor'(
        survarium::jump_logic_state_start *this,
        char a2)
{
  survarium::jump_logic_state_start::~jump_logic_state_start(this, (int)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
