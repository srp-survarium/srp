void __userpurge vostok::ai::vision_sensor_parameters::deserialize(
        vostok::ai::vision_sensor_parameters *this@<ecx>,
        float a2@<xmm0>,
        vostok::configs::binary_config_value *options)
{
  vostok::configs::binary_config_value *v3; // eax
  vostok::configs::binary_config_value *v4; // ecx
  vostok::configs::binary_config_value *v5; // ecx
  vostok::configs::binary_config_value *v6; // ecx
  vostok::configs::binary_config_value *v7; // ecx
  vostok::configs::binary_config_value *v8; // ecx
  vostok::configs::binary_config_value *v9; // ecx
  float v10; // xmm0_4
  vostok::configs::binary_config_value *v11; // ecx
  vostok::configs::binary_config_value *v12; // ecx
  vostok::configs::binary_config_value *v13; // ecx
  vostok::configs::binary_config_value *v14; // ecx
  vostok::configs::binary_config_value *v15; // ecx
  const vostok::configs::binary_config_value *v16; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v17; // ecx
  vostok::configs::binary_config_value *v18; // ecx

  v3 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](options, "enabled");
  this->enabled = vostok::configs::binary_config_value::operator bool(v3);
  vostok::configs::binary_config_value::operator[](options, "vertical_fov");
  vostok::configs::binary_config_value::operator float(v4);
  this->vertical_fov = a2;
  vostok::configs::binary_config_value::operator[](options, "min_indirect_view_factor");
  vostok::configs::binary_config_value::operator float(v5);
  this->min_indirect_view_factor = a2;
  vostok::configs::binary_config_value::operator[](options, "far_plane_distance");
  vostok::configs::binary_config_value::operator float(v6);
  this->far_plane_distance = a2;
  vostok::configs::binary_config_value::operator[](options, "near_plane_distance");
  vostok::configs::binary_config_value::operator float(v7);
  this->near_plane_distance = a2;
  vostok::configs::binary_config_value::operator[](options, "aspect_ratio_horizontal_dimension");
  vostok::configs::binary_config_value::operator float(v8);
  vostok::configs::binary_config_value::operator[](options, "aspect_ratio_vertical_dimension");
  vostok::configs::binary_config_value::operator float(v9);
  v10 = a2 / a2;
  this->aspect_ratio = v10;
  vostok::configs::binary_config_value::operator[](options, "time_quant");
  vostok::configs::binary_config_value::operator float(v11);
  this->time_quant = v10;
  vostok::configs::binary_config_value::operator[](options, "decrease_factor");
  vostok::configs::binary_config_value::operator float(v12);
  this->decrease_factor = v10;
  vostok::configs::binary_config_value::operator[](options, "velocity_factor");
  vostok::configs::binary_config_value::operator float(v13);
  this->velocity_factor = v10;
  vostok::configs::binary_config_value::operator[](options, "transparency_threshold");
  vostok::configs::binary_config_value::operator float(v14);
  this->transparency_threshold = v10;
  vostok::configs::binary_config_value::operator[](options, "luminosity_factor");
  vostok::configs::binary_config_value::operator float(v15);
  this->luminosity_factor = v10;
  v16 = vostok::configs::binary_config_value::operator[](options, "visibility_inertia");
  this->visibility_inertia = (unsigned int)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                             v17,
                                             (int)v16);
  vostok::configs::binary_config_value::operator[](options, "visibility_threshold");
  vostok::configs::binary_config_value::operator float(v18);
  this->visibility_threshold = v10;
  this->max_visibility = (double)this->visibility_inertia / this->time_quant * this->decrease_factor
                       + this->visibility_threshold;
}
