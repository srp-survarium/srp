const vostok::variant<32> **__cdecl vostok::particle::read_config_value<unsigned int,vostok::configs::binary_config_value>(
        vostok::configs::binary_config_value *config_value,
        const char *name,
        const unsigned int *default_value)
{
  const vostok::configs::binary_config_value *v3; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v4; // ecx

  if ( !vostok::configs::binary_config_value::value_exists(config_value, name) )
    return (const vostok::variant<32> **)*default_value;
  v3 = vostok::configs::binary_config_value::operator[](config_value, name);
  return stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v4, (int)v3);
}
