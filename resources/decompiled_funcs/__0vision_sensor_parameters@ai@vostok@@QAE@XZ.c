void __usercall vostok::ai::vision_sensor_parameters::vision_sensor_parameters(
        vostok::ai::vision_sensor_parameters *this@<ecx>,
        float a2@<xmm0>)
{
  vostok::memory::uninitialized_value<float>();
  this->vertical_fov = a2;
  vostok::memory::uninitialized_value<float>();
  this->min_indirect_view_factor = a2;
  vostok::memory::uninitialized_value<float>();
  this->far_plane_distance = a2;
  vostok::memory::uninitialized_value<float>();
  this->near_plane_distance = a2;
  vostok::memory::uninitialized_value<float>();
  this->aspect_ratio = a2;
  vostok::memory::uninitialized_value<float>();
  this->time_quant = a2;
  vostok::memory::uninitialized_value<float>();
  this->decrease_factor = a2;
  vostok::memory::uninitialized_value<float>();
  this->velocity_factor = a2;
  vostok::memory::uninitialized_value<float>();
  this->transparency_threshold = a2;
  vostok::memory::uninitialized_value<float>();
  this->luminosity_factor = a2;
  vostok::memory::uninitialized_value<float>();
  this->max_visibility = a2;
  vostok::memory::uninitialized_value<float>();
  this->visibility_threshold = a2;
  this->visibility_inertia = vostok::memory::uninitialized_value<unsigned int>();
  this->enabled = survarium::player_logic_base_state::is_ready_for_transition((btNullPairCache *)this) != 0 ? -51 : -3;
}
