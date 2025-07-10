survarium::damage_zone *__thiscall survarium::damage_zone::`scalar deleting destructor'(
        survarium::damage_zone *this,
        char a2)
{
  survarium::damage_zone::~damage_zone(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
