int __thiscall survarium::_dynamic_initializer_for__s_dispersion_buckshot_sigma_cc__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_dispersion_buckshot_sigma_cc,
    "dispersion_buckshot_sigma",
    1,
    command_type_engine_internal,
    execution_filter_general);
  s_dispersion_buckshot_sigma_cc.m_min = epsilon_3_4;
  s_dispersion_buckshot_sigma_cc.m_value = &s_dispersion_buckshot_sigma_value;
  s_dispersion_buckshot_sigma_cc.m_max = FLOAT_10_0;
  s_dispersion_buckshot_sigma_cc.m_need_args = 1;
  s_dispersion_buckshot_sigma_cc.__vftable = (vostok::console_commands::cc_float_vtbl *)&vostok::console_commands::cc_float::`vftable';
  return atexit(survarium::_dynamic_atexit_destructor_for__s_dispersion_buckshot_sigma_cc__);
}
