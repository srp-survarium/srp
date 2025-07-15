survarium::grenade *__thiscall survarium::grenade::`vector deleting destructor'(survarium::grenade *this, char a2)
{
  survarium::grenade::~grenade(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


survarium::grenade *__thiscall survarium::grenade::`vector deleting destructor'(char *this, char a2)
{
  return survarium::grenade::`vector deleting destructor'((survarium::grenade *)(this - 32), a2);
}
