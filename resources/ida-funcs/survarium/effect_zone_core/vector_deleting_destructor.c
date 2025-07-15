survarium::effect_zone_core *__thiscall survarium::effect_zone_core::`vector deleting destructor'(
        survarium::effect_zone_core *this,
        char a2)
{
  survarium::effect_zone_core::~effect_zone_core(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
