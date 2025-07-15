void __thiscall vostok::particle::curve_line_ranged_float::load<vostok::configs::binary_config_value>(
        vostok::particle::curve_line_ranged_float *this,
        vostok::configs::binary_config_value config)
{
  const vostok::configs::binary_config_value *v2; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  const vostok::variant<32> **v4; // eax
  vostok::configs::binary_config_value v5; // [esp-18h] [ebp-108h]

  if ( vostok::configs::binary_config_value::value_exists(&config, "Input") )
  {
    v2 = vostok::configs::binary_config_value::operator[](&config, "Input");
    v4 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v3, (int)v2);
    this->m_evaluate_type = vostok::particle::string_to_evaluate_type((const char *)v4);
  }
  if ( vostok::configs::binary_config_value::value_exists(&config, "source") )
  {
    v5 = *vostok::configs::binary_config_value::operator[](&config, "source");
    vostok::particle::curve_line_ranged_base::load<vostok::configs::binary_config_value>(&this->m_line, v5);
  }
}
