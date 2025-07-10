survarium::damage_zone_core *__thiscall survarium::damage_zone_core::`scalar deleting destructor'(
        survarium::damage_zone_core *this,
        char a2)
{
  survarium::damage_zone_core::~damage_zone_core(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
