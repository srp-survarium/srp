survarium::simple_game_project *__thiscall survarium::simple_game_project::`scalar deleting destructor'(
        survarium::simple_game_project *this,
        char a2)
{
  survarium::simple_game_project::~simple_game_project(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
