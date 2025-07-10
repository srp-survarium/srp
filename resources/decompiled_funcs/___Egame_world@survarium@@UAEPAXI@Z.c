survarium::game_world *__thiscall survarium::game_world::`vector deleting destructor'(
        survarium::game_world *this,
        char a2)
{
  survarium::game_world::~game_world(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
