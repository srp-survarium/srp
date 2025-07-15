survarium::server_game_project *__thiscall survarium::server_game_project::`vector deleting destructor'(
        survarium::server_game_project *this,
        char a2)
{
  survarium::server_game_project::~server_game_project(this, (int)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


survarium::server_game_project *__thiscall survarium::server_game_project::`vector deleting destructor'(
        char *this,
        char a2)
{
  return survarium::server_game_project::`vector deleting destructor'((survarium::server_game_project *)(this - 48), a2);
}
