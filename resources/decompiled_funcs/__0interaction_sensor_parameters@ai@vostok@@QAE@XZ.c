void __thiscall vostok::ai::interaction_sensor_parameters::interaction_sensor_parameters(
        vostok::ai::interaction_sensor_parameters *this)
{
  this->enabled = survarium::player_logic_base_state::is_ready_for_transition((btNullPairCache *)this) != 0 ? -51 : -3;
}
