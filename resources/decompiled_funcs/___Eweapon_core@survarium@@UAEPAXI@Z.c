survarium::weapon_core *__thiscall survarium::weapon_core::`vector deleting destructor'(
        survarium::weapon_core *this,
        char a2)
{
  survarium::weapon_core::~weapon_core(this);
  if ( (a2 & 1) != 0 )
    operator delete((void *)this);
  return this;
}
