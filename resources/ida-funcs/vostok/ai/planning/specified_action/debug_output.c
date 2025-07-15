void __thiscall vostok::ai::planning::specified_action::debug_output(
        vostok::ai::planning::specified_action *this,
        vostok::ai::planning::specified_problem *problem)
{
  const vostok::variant<32> **v2; // eax
  survarium::game_camera *v3; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v4; // ecx
  char *v5; // eax
  unsigned int *m_begin; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v7; // ecx
  const vostok::variant<32> **v8; // eax
  const vostok::ai::planning::generalized_action *m_prototype; // [esp+30h] [ebp-288h]
  unsigned int *v11; // [esp+38h] [ebp-280h]
  char v12; // [esp+54h] [ebp-264h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v13; // [esp+58h] [ebp-260h] BYREF
  char v14; // [esp+7Fh] [ebp-239h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+80h] [ebp-238h] BYREF
  const vostok::ai::planning::object_instance *object; // [esp+A0h] [ebp-218h]
  unsigned int i; // [esp+A4h] [ebp-214h]
  vostok::fixed_string<512> output_text; // [esp+A8h] [ebp-210h] BYREF

  v12 = 0;
  if ( this->m_prototype )
  {
    v2 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
           (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this->m_prototype,
           (int)&this->m_prototype->m_caption);
    vostok::fixed_string<512>::fixed_string<512>(&output_text, (const char *)v2);
    vostok::buffer_string::append(&output_text, " (");
    for ( i = 0; i < this->m_parameters_instances.m_end - this->m_parameters_instances.m_begin; ++i )
    {
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_parameters_instances);
      v11 = &this->m_parameters_instances.m_begin[i];
      m_prototype = this->m_prototype;
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_prototype);
      object = vostok::ai::planning::specified_problem::get_object_by_type_and_index(
                 problem,
                 m_prototype->m_parameter_types.m_begin[i],
                 *v11);
      v14 = 0;
      survarium::weapon_user_dead_state::finalize(v3);
      v5 = (char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                     v4,
                     (int)&object->m_caption);
      vostok::buffer_string::append(&output_text, v5);
      if ( i == this->m_parameters_instances.m_end - this->m_parameters_instances.m_begin - 1 )
        vostok::buffer_string::append(&output_text, ")");
      else
        vostok::buffer_string::append(&output_text, (char *)&stru_95AF78.m_key_bindings[32]);
    }
    m_begin = this->m_parameters_instances.m_begin;
    if ( m_begin == this->m_parameters_instances.m_end )
      vostok::buffer_string::append(&output_text, ")");
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "ai:", info) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)m_begin);
      v12 = 2;
      v8 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v7, (int)&output_text);
      vostok::logging::append(
        &v13,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\specified_action.cpp",
        0x6Fu,
        "void __thiscall vostok::ai::planning::specified_action::debug_output(const class vostok::ai::planning::specified"
        "_problem &) const",
        "ai:",
        info,
        (const char *)v8);
    }
    if ( (v12 & 2) != 0 )
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)m_begin,
        (int *)&v13);
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "ai:", warning) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this);
      v12 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\specified_action.cpp",
        0x5Cu,
        "void __thiscall vostok::ai::planning::specified_action::debug_output(const class vostok::ai::planning::specified"
        "_problem &) const",
        "ai:",
        warning,
        "attempt to manipulate with unspecified action");
    }
    if ( (v12 & 1) != 0 )
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)this,
        (int *)&log_callback);
  }
}
