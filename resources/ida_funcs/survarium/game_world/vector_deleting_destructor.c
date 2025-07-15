survarium::game_world *__thiscall survarium::game_world::`vector deleting destructor'(
        survarium::game_world *this,
        char a2)
{
  survarium::game_world::~game_world(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


survarium::game_world *__thiscall survarium::game_world::`vector deleting destructor'(char *this, char a2)
{
  return survarium::game_world::`vector deleting destructor'((survarium::game_world *)(this - 464), a2);
}


survarium::game_world *__thiscall survarium::game_world::`vector deleting destructor'(char *this, char a2)
{
  return survarium::game_world::`vector deleting destructor'((survarium::game_world *)(this - 188), a2);
}


survarium::game_world *__thiscall survarium::game_world::`vector deleting destructor'(char *this, char a2)
{
  return survarium::game_world::`vector deleting destructor'((survarium::game_world *)(this - 192), a2);
}


survarium::game_world *__thiscall survarium::game_world::`vector deleting destructor'(char *this, char a2)
{
  return survarium::game_world::`vector deleting destructor'((survarium::game_world *)(this - 200), a2);
}
