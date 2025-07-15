void __thiscall vostok::ai::damage_sensor_parameters::damage_sensor_parameters(
        vostok::ai::damage_sensor_parameters *this)
{
  this->enabled = survarium::player_logic_base_state::is_ready_for_transition((btNullPairCache *)this) != 0 ? -51 : -3;
}
