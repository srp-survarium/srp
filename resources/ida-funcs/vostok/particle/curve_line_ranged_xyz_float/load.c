void __thiscall vostok::particle::curve_line_ranged_xyz_float::load<vostok::configs::binary_config_value>(
        vostok::particle::curve_line_ranged_xyz_float *this,
        vostok::configs::binary_config_value config)
{
  const vostok::configs::binary_config_value *v2; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  const vostok::variant<32> **v4; // eax
  vostok::configs::binary_config_value v5; // [esp-18h] [ebp-100h]
  vostok::configs::binary_config_value v6; // [esp-18h] [ebp-100h]
  vostok::configs::binary_config_value v7; // [esp-18h] [ebp-100h]

  if ( vostok::configs::binary_config_value::value_exists(&config, "Input") )
  {
    v2 = vostok::configs::binary_config_value::operator[](&config, "Input");
    v4 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v3, (int)v2);
    this->m_evaluate_type = vostok::particle::string_to_evaluate_type((const char *)v4);
  }
  if ( vostok::configs::binary_config_value::value_exists(&config, "source0") )
  {
    v5 = *vostok::configs::binary_config_value::operator[](&config, "source0");
    vostok::particle::curve_line_ranged_base::load<vostok::configs::binary_config_value>(&this->m_line_x, v5);
  }
  if ( vostok::configs::binary_config_value::value_exists(&config, "source1") )
  {
    v6 = *vostok::configs::binary_config_value::operator[](&config, "source1");
    vostok::particle::curve_line_ranged_base::load<vostok::configs::binary_config_value>(&this->m_line_y, v6);
  }
  if ( vostok::configs::binary_config_value::value_exists(&config, "source2") )
  {
    v7 = *vostok::configs::binary_config_value::operator[](&config, "source2");
    vostok::particle::curve_line_ranged_base::load<vostok::configs::binary_config_value>(&this->m_line_z, v7);
  }
}
