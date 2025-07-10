vostok::ai::selectors::target_selector_base *__thiscall vostok::ai::planning::specified_problem::get_parameter_selector(
        vostok::ai::planning::specified_problem *this,
        const vostok::ai::planning::action_parameter *const parameter)
{
  char *selector_name; // [esp+8h] [ebp-38h]
  char v5; // [esp+14h] [ebp-2Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+18h] [ebp-28h] BYREF

  v5 = 0;
  if ( this->m_owner )
  {
    selector_name = (char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                              (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
                              (int)&parameter->m_selector_name);
    return vostok::ai::brain_unit::get_selector_by_name(this->m_owner, selector_name);
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "ai:", warning) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this);
      v5 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\specified_problem.cpp",
        0x13Eu,
        "class vostok::ai::selectors::target_selector_base *__thiscall vostok::ai::planning::specified_problem::get_param"
        "eter_selector(const class vostok::ai::planning::action_parameter *const ) const",
        "ai:",
        warning,
        "no brain unit set, selectors are unavailable");
    }
    if ( (v5 & 1) != 0 )
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)this,
        (int *)&log_callback);
    return 0;
  }
}
