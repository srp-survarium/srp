survarium::grenade_set_core *__thiscall survarium::grenade_set_core::`vector deleting destructor'(
        survarium::grenade_set_core *this,
        char a2)
{
  survarium::grenade_set_core::~grenade_set_core(this);
  if ( (a2 & 1) != 0 )
    operator delete((void *)this);
  return this;
}
