void __cdecl vostok::ai::behaviour::fill_action_parameter(
        vostok::configs::binary_config_value *options,
        vostok::ai::planning::action_parameter *parameter)
{
  vostok::configs::binary_config_value *v2; // eax
  const vostok::configs::binary_config_value *v3; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v4; // ecx
  const vostok::variant<32> **v5; // [esp+4h] [ebp-18h]
  bool v6; // [esp+Ah] [ebp-12h]

  if ( vostok::configs::binary_config_value::value_exists(options, "iterate_first_only") )
  {
    v2 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                   options,
                                                   "iterate_first_only");
    v6 = vostok::configs::binary_config_value::operator bool(v2);
  }
  else
  {
    v6 = 1;
  }
  parameter->m_iterate_only_first = v6;
  if ( vostok::configs::binary_config_value::value_exists(options, "selector") )
  {
    v3 = vostok::configs::binary_config_value::operator[](options, "selector");
    v5 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v4, (int)v3);
  }
  else
  {
    v5 = (const vostok::variant<32> **)&buf;
  }
  vostok::fixed_string<16>::operator=((vostok::fixed_string<16> *)v5, &parameter->m_selector_name);
}
