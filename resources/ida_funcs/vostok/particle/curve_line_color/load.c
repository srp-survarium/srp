void __thiscall vostok::particle::curve_line_color::load<vostok::configs::binary_config_value>(
        vostok::particle::curve_line_color *this,
        vostok::configs::binary_config_value config)
{
  const vostok::configs::binary_config_value *v2; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  const vostok::variant<32> **v4; // eax
  vostok::configs::binary_config_value *v5; // eax
  vostok::configs::binary_config_value *v6; // eax
  vostok::configs::binary_config_value *v7; // eax
  vostok::configs::binary_config_value *v8; // eax
  vostok::configs::binary_config_value *v9; // eax
  vostok::configs::binary_config_value v10; // [esp-18h] [ebp-140h]

  if ( vostok::configs::binary_config_value::value_exists(&config, "Input") )
  {
    v2 = vostok::configs::binary_config_value::operator[](&config, "Input");
    v4 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v3, (int)v2);
    this->m_evaluate_type = vostok::particle::string_to_evaluate_type((const char *)v4);
  }
  if ( vostok::configs::binary_config_value::value_exists(&config, "source") )
  {
    v5 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](&config, "source");
    if ( vostok::configs::binary_config_value::value_exists(v5, "data") )
    {
      v6 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](&config, "source");
      v7 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v6, "data");
      if ( vostok::configs::binary_config_value::value_exists(v7, "ramp") )
      {
        v8 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](&config, "source");
        v9 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v8, "data");
        v10 = *vostok::configs::binary_config_value::operator[](v9, "ramp");
        vostok::particle::curve_line_points<vostok::math::float4_pod,1>::load<vostok::configs::binary_config_value>(
          this,
          v10);
      }
    }
  }
}
