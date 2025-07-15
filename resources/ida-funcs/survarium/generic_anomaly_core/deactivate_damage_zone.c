// attributes: thunk
void __thiscall survarium::generic_anomaly_core::deactivate_damage_zone(
        survarium::generic_anomaly_core *this,
        survarium::damage_zone_core *damage_zone,
        bool forced)
{
  survarium::damage_zone_core::deactivate((survarium::damage_zone_core *)this, (bool)damage_zone);
}
