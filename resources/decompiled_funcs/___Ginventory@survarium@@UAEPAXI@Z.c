survarium::inventory *__thiscall survarium::inventory::`scalar deleting destructor'(
        survarium::inventory *this,
        char a2)
{
  survarium::inventory::~inventory(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
