survarium::game_statistics_handler *__thiscall survarium::game_statistics_handler::`scalar deleting destructor'(
        survarium::game_statistics_handler *this,
        char a2)
{
  survarium::game_statistics_handler::~game_statistics_handler(this, (int)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
