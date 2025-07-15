survarium::player_input_handler *__thiscall survarium::player_input_handler::`vector deleting destructor'(
        survarium::player_input_handler *this,
        char a2)
{
  survarium::player_input_handler::~player_input_handler(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
