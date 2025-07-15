survarium::game_world_ui *__thiscall survarium::game_world_ui::`scalar deleting destructor'(
        survarium::game_world_ui *this,
        char a2)
{
  survarium::game_world_ui::~game_world_ui(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
