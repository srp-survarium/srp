void __userpurge vostok::ai::hearing_sensor_parameters::deserialize(
        vostok::ai::hearing_sensor_parameters *this@<ecx>,
        float a2@<xmm0>,
        vostok::configs::binary_config_value *options)
{
  vostok::configs::binary_config_value *v3; // eax
  const vostok::configs::binary_config_value *v4; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // ecx
  vostok::configs::binary_config_value *v6; // ecx
  vostok::configs::binary_config_value *v7; // ecx
  vostok::configs::binary_config_value *v8; // ecx
  vostok::configs::binary_config_value *v9; // ecx
  vostok::configs::binary_config_value *v10; // ecx
  vostok::configs::binary_config_value *v11; // ecx

  v3 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](options, "enabled");
  this->enabled = vostok::configs::binary_config_value::operator bool(v3);
  v4 = vostok::configs::binary_config_value::operator[](options, "max_sounds_count");
  this->max_sounds_count = (unsigned int)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                           v5,
                                           (int)v4);
  vostok::configs::binary_config_value::operator[](options, "max_sound_distance");
  vostok::configs::binary_config_value::operator float(v6);
  this->max_sound_distance = a2;
  vostok::configs::binary_config_value::operator[](options, "min_sound_threshold");
  vostok::configs::binary_config_value::operator float(v7);
  this->min_sound_threshold = a2;
  vostok::configs::binary_config_value::operator[](options, "always_recognized_distance");
  vostok::configs::binary_config_value::operator float(v8);
  this->always_recognized_distance = a2;
  vostok::configs::binary_config_value::operator[](options, "decreasing_time_quant");
  vostok::configs::binary_config_value::operator float(v9);
  this->decreasing_time_quant = a2;
  vostok::configs::binary_config_value::operator[](options, "decrease_factor");
  vostok::configs::binary_config_value::operator float(v10);
  this->decrease_factor = a2;
  vostok::configs::binary_config_value::operator[](options, "last_sound_time");
  vostok::configs::binary_config_value::operator float(v11);
  this->last_sound_time = a2;
}
