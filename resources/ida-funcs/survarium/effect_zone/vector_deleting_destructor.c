survarium::effect_zone *__thiscall survarium::effect_zone::`vector deleting destructor'(
        survarium::effect_zone *this,
        char a2)
{
  survarium::effect_zone::~effect_zone(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


survarium::effect_zone *__thiscall survarium::effect_zone::`vector deleting destructor'(char *this, char a2)
{
  return survarium::effect_zone::`vector deleting destructor'((survarium::effect_zone *)(this - 264), a2);
}
