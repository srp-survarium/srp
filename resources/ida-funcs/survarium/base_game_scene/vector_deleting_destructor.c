survarium::base_game_scene *__thiscall survarium::base_game_scene::`vector deleting destructor'(
        survarium::base_game_scene *this,
        char a2)
{
  survarium::base_game_scene::~base_game_scene(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
