void __thiscall vostok::ai::planning::generalized_action::add_precondition(
        vostok::ai::planning::generalized_action *this,
        const vostok::ai::planning::pddl_world_state_property_impl *precondition_to_be_added)
{
  vostok::fixed_vector<unsigned int,4> *p_m_parameters; // ecx
  bool has_passed_filters; // al
  const vostok::ai::planning::pddl_predicate *m_predicate; // [esp+2Ch] [ebp-2Ch]
  char v6; // [esp+34h] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+38h] [ebp-20h] BYREF

  v6 = 0;
  m_predicate = precondition_to_be_added->m_predicate;
  p_m_parameters = &m_predicate->m_parameters;
  if ( precondition_to_be_added->m_indices.m_end - precondition_to_be_added->m_indices.m_begin == m_predicate->m_parameters.m_end
                                                                                                - m_predicate->m_parameters.m_begin )
  {
    stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::push_back(
      &this->m_preconditions._M_impl,
      precondition_to_be_added);
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "ai:", error),
          (p_m_parameters = (vostok::fixed_vector<unsigned int,4> *)has_passed_filters) != 0) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)p_m_parameters);
      v6 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        "c:\\survarium\\sources\\vostok\\ai\\sources\\generalized_action_inline.h",
        0x1Cu,
        "void __thiscall vostok::ai::planning::generalized_action::add_precondition(const class vostok::ai::planning::pdd"
        "l_world_state_property_impl &)",
        "ai:",
        error,
        "placeholders count doesn't match with predicate parameters count");
    }
    if ( (v6 & 1) != 0 )
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)(v6 & 1),
        (int *)&log_callback);
  }
}
