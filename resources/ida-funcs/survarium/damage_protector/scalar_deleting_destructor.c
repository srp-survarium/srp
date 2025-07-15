survarium::anomaly_damage_protector *__thiscall survarium::damage_protector::`scalar deleting destructor'(
        survarium::anomaly_damage_protector *this,
        char a2)
{
  survarium::damage_protector::~damage_protector(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
