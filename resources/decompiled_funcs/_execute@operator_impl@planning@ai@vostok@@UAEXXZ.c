void __thiscall vostok::ai::planning::operator_impl::execute(vostok::ai::planning::operator_impl *this)
{
  BOOL m_first_execute; // ecx
  bool has_passed_filters; // al
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  const vostok::variant<32> **v5; // [esp+8h] [ebp-30h]
  char v6; // [esp+14h] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+18h] [ebp-20h] BYREF

  v6 = 0;
  m_first_execute = this->m_first_execute;
  if ( m_first_execute )
  {
    this->m_first_execute = 0;
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "ai:", info),
          m_first_execute = has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)m_first_execute);
      v6 = 1;
      v5 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v3, (int)&this->m_id);
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\operator.cpp",
        0x31u,
        "void __thiscall vostok::ai::planning::operator_impl::execute(void)",
        "ai:",
        info,
        "operator %s is executed",
        (const char *)v5);
    }
    if ( (v6 & 1) != 0 )
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)m_first_execute,
        (int *)&log_callback);
  }
}
