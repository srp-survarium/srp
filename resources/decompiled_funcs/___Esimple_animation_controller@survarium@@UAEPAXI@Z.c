survarium::simple_animation_controller *__thiscall survarium::simple_animation_controller::`vector deleting destructor'(
        survarium::simple_animation_controller *this,
        char a2)
{
  survarium::simple_animation_controller::~simple_animation_controller(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
