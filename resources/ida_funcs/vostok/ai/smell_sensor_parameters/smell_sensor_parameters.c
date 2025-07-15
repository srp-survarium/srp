void __usercall vostok::ai::smell_sensor_parameters::smell_sensor_parameters(
        vostok::ai::smell_sensor_parameters *this@<ecx>,
        float a2@<xmm0>)
{
  vostok::memory::uninitialized_value<float>();
  this->max_smelling_distance = a2;
  vostok::memory::uninitialized_value<float>();
  this->min_intensity = a2;
  vostok::memory::uninitialized_value<float>();
  this->max_intensity = a2;
  vostok::memory::uninitialized_value<float>();
  this->always_recognized_distance = a2;
  vostok::memory::uninitialized_value<float>();
  this->decreasing_time_quant = a2;
  vostok::memory::uninitialized_value<float>();
  this->decrease_factor = a2;
  vostok::memory::uninitialized_value<float>();
  this->last_smell_time = a2;
  this->max_smells_count = vostok::memory::uninitialized_value<unsigned int>();
  this->enabled = survarium::player_logic_base_state::is_ready_for_transition((btNullPairCache *)this) != 0 ? -51 : -3;
}
