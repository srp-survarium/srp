survarium::game_material_manager *__thiscall survarium::game_material_manager::`vector deleting destructor'(
        survarium::game_material_manager *this,
        char a2)
{
  survarium::game_material_manager::~game_material_manager(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
