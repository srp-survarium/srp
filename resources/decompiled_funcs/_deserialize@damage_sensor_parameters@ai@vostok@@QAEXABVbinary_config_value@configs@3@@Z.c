void __thiscall vostok::ai::damage_sensor_parameters::deserialize(
        vostok::ai::damage_sensor_parameters *this,
        vostok::configs::binary_config_value *options)
{
  vostok::configs::binary_config_value *v2; // eax

  v2 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](options, "enabled");
  this->enabled = vostok::configs::binary_config_value::operator bool(v2);
}
