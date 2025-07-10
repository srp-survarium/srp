vostok::math::float3 *__cdecl vostok::particle::read_config_value<vostok::math::float3,vostok::configs::binary_config_value>(
        vostok::math::float3 *result,
        vostok::configs::binary_config_value *config_value,
        const char *name,
        const vostok::math::float3 *default_value)
{
  const vostok::configs::binary_config_value *v4; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // ecx
  const vostok::variant<32> **v6; // eax
  __int64 v8; // [esp+Ch] [ebp-8h]

  if ( vostok::configs::binary_config_value::value_exists(config_value, name) )
  {
    v4 = vostok::configs::binary_config_value::operator[](config_value, name);
    v6 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v5, (int)v4);
    v8 = *(_QWORD *)(v6 + 1);
    LODWORD(result->x) = *v6;
    *(_QWORD *)&result->elements[1] = v8;
  }
  else
  {
    *result = *default_value;
  }
  return result;
}
