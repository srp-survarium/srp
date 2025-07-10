// attributes: thunk
void __thiscall survarium::generic_anomaly::tick(
        survarium::generic_anomaly *this,
        unsigned int time_delta_ms,
        unsigned int current_time_ms)
{
  survarium::generic_anomaly_core::tick(this, time_delta_ms, current_time_ms);
}
