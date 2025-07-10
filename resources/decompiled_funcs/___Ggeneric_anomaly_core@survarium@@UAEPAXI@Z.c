survarium::generic_anomaly_core *__thiscall survarium::generic_anomaly_core::`scalar deleting destructor'(
        survarium::generic_anomaly_core *this,
        char a2)
{
  survarium::generic_anomaly_core::~generic_anomaly_core(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
