void __thiscall vostok::particle::curve_line_ranged_base::load<vostok::configs::binary_config_value>(
        vostok::particle::curve_line_ranged_base *this,
        vostok::configs::binary_config_value config)
{
  vostok::configs::binary_config_value v2; // [esp-18h] [ebp-114h]
  vostok::configs::binary_config_value *data; // [esp+F8h] [ebp-4h]

  data = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](&config, "data");
  if ( vostok::configs::binary_config_value::value_exists(data, "curve0") )
  {
    v2 = *vostok::configs::binary_config_value::operator[](data, "curve0");
    vostok::particle::curve_line_points<float,0>::load<vostok::configs::binary_config_value>(&this->m_upper, v2);
  }
}
