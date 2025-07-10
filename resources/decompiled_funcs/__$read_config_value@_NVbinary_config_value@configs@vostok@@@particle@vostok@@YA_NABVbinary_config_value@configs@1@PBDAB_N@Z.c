bool __cdecl vostok::particle::read_config_value<bool,vostok::configs::binary_config_value>(
        vostok::configs::binary_config_value *config_value,
        const char *name,
        const bool *default_value)
{
  vostok::configs::binary_config_value *v3; // eax

  if ( !vostok::configs::binary_config_value::value_exists(config_value, name) )
    return *default_value;
  v3 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](config_value, name);
  return vostok::configs::binary_config_value::operator bool(v3);
}
