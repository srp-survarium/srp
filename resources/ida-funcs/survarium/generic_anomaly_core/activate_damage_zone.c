void __thiscall survarium::generic_anomaly_core::activate_damage_zone(
        survarium::generic_anomaly_core *this,
        survarium::damage_zone_core *damage_zone,
        BOOL forced)
{
  survarium::damage_zone_core::activate(damage_zone, this->m_physics_world, (survarium::collision_sensor *)this, forced);
}
