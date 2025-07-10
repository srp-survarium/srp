survarium::oxygen_tank *__thiscall survarium::oxygen_tank::`scalar deleting destructor'(
        survarium::oxygen_tank *this,
        char a2)
{
  survarium::oxygen_tank::~oxygen_tank(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
