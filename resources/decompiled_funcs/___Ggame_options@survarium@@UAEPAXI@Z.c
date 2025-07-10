survarium::game_options *__thiscall survarium::game_options::`scalar deleting destructor'(
        survarium::game_options *this,
        char a2)
{
  survarium::game_options::~game_options(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
