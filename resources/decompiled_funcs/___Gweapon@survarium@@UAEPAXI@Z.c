survarium::weapon *__thiscall survarium::weapon::`scalar deleting destructor'(survarium::weapon *this, char a2)
{
  survarium::weapon::~weapon(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
