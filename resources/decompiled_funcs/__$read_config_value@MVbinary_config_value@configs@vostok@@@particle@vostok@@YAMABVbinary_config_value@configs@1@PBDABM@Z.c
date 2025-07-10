double __usercall vostok::particle::read_config_value<float,vostok::configs::binary_config_value>@<st0>(
        float a1@<xmm0>,
        vostok::configs::binary_config_value *config_value,
        const char *name,
        const float *default_value)
{
  vostok::configs::binary_config_value *v4; // ecx

  if ( !vostok::configs::binary_config_value::value_exists(config_value, name) )
    return *default_value;
  vostok::configs::binary_config_value::operator[](config_value, name);
  vostok::configs::binary_config_value::operator float(v4);
  return a1;
}
