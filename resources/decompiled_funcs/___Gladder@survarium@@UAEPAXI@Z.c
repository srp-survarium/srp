survarium::ladder *__thiscall survarium::ladder::`scalar deleting destructor'(survarium::ladder *this, char a2)
{
  survarium::ladder::~ladder(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
