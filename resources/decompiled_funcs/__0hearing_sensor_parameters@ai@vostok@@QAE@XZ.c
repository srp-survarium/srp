void __usercall vostok::ai::hearing_sensor_parameters::hearing_sensor_parameters(
        vostok::ai::hearing_sensor_parameters *this@<ecx>,
        float a2@<xmm0>)
{
  vostok::memory::uninitialized_value<float>();
  this->max_sound_distance = a2;
  vostok::memory::uninitialized_value<float>();
  this->min_sound_threshold = a2;
  vostok::memory::uninitialized_value<float>();
  this->always_recognized_distance = a2;
  vostok::memory::uninitialized_value<float>();
  this->decreasing_time_quant = a2;
  vostok::memory::uninitialized_value<float>();
  this->decrease_factor = a2;
  vostok::memory::uninitialized_value<float>();
  this->last_sound_time = a2;
  this->max_sounds_count = vostok::memory::uninitialized_value<unsigned int>();
  this->enabled = survarium::player_logic_base_state::is_ready_for_transition((btNullPairCache *)this) != 0 ? -51 : -3;
}
