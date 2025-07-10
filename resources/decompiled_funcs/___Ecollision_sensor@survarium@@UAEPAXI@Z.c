survarium::collision_sensor *__thiscall survarium::collision_sensor::`vector deleting destructor'(
        survarium::collision_sensor *this,
        char a2)
{
  survarium::collision_sensor::~collision_sensor(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
