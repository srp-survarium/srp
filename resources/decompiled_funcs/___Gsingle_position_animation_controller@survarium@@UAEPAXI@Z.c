survarium::single_position_animation_controller *__thiscall survarium::single_position_animation_controller::`scalar deleting destructor'(
        survarium::single_position_animation_controller *this,
        char a2)
{
  survarium::single_position_animation_controller::~single_position_animation_controller(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
