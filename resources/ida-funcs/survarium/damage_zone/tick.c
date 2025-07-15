// attributes: thunk
void __thiscall survarium::damage_zone::tick(
        survarium::damage_zone *this,
        unsigned int time_delta_ms,
        unsigned int current_time_ms)
{
  survarium::damage_zone_core::tick(this, time_delta_ms, current_time_ms);
}


void __thiscall survarium::damage_zone::tick(char *this, unsigned int a2, unsigned int a3)
{
  survarium::damage_zone::tick((survarium::damage_zone *)(this - 52), a2, a3);
}
