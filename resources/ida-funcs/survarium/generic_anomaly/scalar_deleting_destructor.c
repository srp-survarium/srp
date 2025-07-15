survarium::generic_anomaly *__thiscall survarium::generic_anomaly::`scalar deleting destructor'(
        survarium::generic_anomaly *this,
        char a2)
{
  survarium::generic_anomaly::~generic_anomaly(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
