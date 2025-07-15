// attributes: thunk
void __thiscall survarium::effect_zone_core::tick(
        survarium::effect_zone_core *this,
        unsigned int time_delta_ms,
        vostok::physics::loose_ptr_data *current_time_ms)
{
  survarium::collision_sensor::tick(this, time_delta_ms, current_time_ms);
}


void __thiscall survarium::effect_zone_core::tick(char *this, unsigned int a2, vostok::physics::loose_ptr_data *a3)
{
  survarium::effect_zone_core::tick((survarium::effect_zone_core *)(this - 32), a2, a3);
}
