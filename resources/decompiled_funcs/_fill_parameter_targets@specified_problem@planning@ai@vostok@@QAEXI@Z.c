void __thiscall vostok::ai::planning::specified_problem::fill_parameter_targets(
        vostok::ai::planning::specified_problem *this,
        unsigned int action_type)
{
  survarium::game_camera *v2; // ecx
  char *selector_name; // [esp+8h] [ebp-48h]
  char v5; // [esp+18h] [ebp-38h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+20h] [ebp-30h] BYREF
  vostok::ai::selectors::target_selector_base *selector; // [esp+44h] [ebp-Ch]
  unsigned int i; // [esp+48h] [ebp-8h]
  const vostok::ai::planning::action_instance *action; // [esp+4Ch] [ebp-4h]

  v5 = 0;
  if ( this->m_owner )
  {
    action = vostok::ai::planning::pddl_problem::get_action_instance(
               (vostok::ai::planning::pddl_problem *)this->m_problem,
               action_type);
    survarium::weapon_user_dead_state::finalize(v2);
    for ( i = 0; i < action->m_parameters.m_end - action->m_parameters.m_begin; ++i )
    {
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)action);
      selector_name = (char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)i,
                                (int)&action->m_parameters.m_begin[i]->m_selector_name);
      selector = vostok::ai::brain_unit::get_selector_by_name(this->m_owner, selector_name);
      if ( selector )
        selector->fill_targets_list(selector);
    }
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
        0x14Au,
        "void __thiscall vostok::ai::planning::specified_problem::fill_parameter_targets(const unsigned int)",
        "ai:",
        warning,
        "no brain unit set, selectors are unavailable");
    }
    if ( (v5 & 1) != 0 )
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)this,
        (int *)&log_callback);
  }
}
