survarium::grenade_core *__thiscall survarium::grenade_core::`vector deleting destructor'(
        survarium::grenade_core *this,
        char a2)
{
  survarium::grenade_core::~grenade_core(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


survarium::grenade_core *__thiscall survarium::grenade_core::`vector deleting destructor'(char *this, char a2)
{
  return survarium::grenade_core::`vector deleting destructor'((survarium::grenade_core *)(this - 32), a2);
}
