void __thiscall vostok::ai::planning::specified_action::add_this_to_plan(
        vostok::ai::planning::specified_action *this,
        vostok::fixed_vector<vostok::ai::planning::plan_item,32> *plan,
        vostok::ai::planning::specified_problem *specific_problem)
{
  BOOL v3; // ecx
  bool has_passed_filters; // al
  survarium::game_camera *v5; // ecx
  survarium::game_camera *v6; // ecx
  const void **k; // [esp+Ch] [ebp-DCh]
  const void **j; // [esp+10h] [ebp-D8h]
  const vostok::ai::planning::generalized_action *m_prototype; // [esp+30h] [ebp-B8h]
  unsigned int *v11; // [esp+38h] [ebp-B0h]
  char v12; // [esp+5Ch] [ebp-8Ch]
  void *value; // [esp+60h] [ebp-88h] BYREF
  char v14; // [esp+67h] [ebp-81h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v15; // [esp+68h] [ebp-80h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+88h] [ebp-60h] BYREF
  const vostok::ai::planning::object_instance *object; // [esp+A8h] [ebp-40h]
  unsigned int i; // [esp+ACh] [ebp-3Ch]
  vostok::fixed_vector<void const *,4> objects; // [esp+B0h] [ebp-38h] BYREF
  const vostok::ai::planning::action_instance *action; // [esp+C8h] [ebp-20h]
  vostok::ai::planning::plan_item new_plan_item; // [esp+CCh] [ebp-1Ch] BYREF

  v12 = 0;
  if ( this->m_prototype )
  {
    action = vostok::ai::planning::pddl_problem::get_action_instance(
               (vostok::ai::planning::pddl_problem *)specific_problem->m_problem,
               this->m_prototype->m_type);
    if ( action )
    {
      vostok::buffer_vector<void const *>::buffer_vector<void const *>(
        &new_plan_item.parameters.vostok::buffer_vector<void const *>,
        (const void **)new_plan_item.parameters.m_buffer,
        4u,
        0);
      new_plan_item.action = action;
      vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>(&objects);
      for ( i = 0; ; ++i )
      {
        v5 = (survarium::game_camera *)(this->m_parameters_instances.m_end - this->m_parameters_instances.m_begin);
        if ( i >= (unsigned int)v5 )
          break;
        survarium::weapon_user_dead_state::finalize(v5);
        v11 = &this->m_parameters_instances.m_begin[i];
        m_prototype = this->m_prototype;
        survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
        object = vostok::ai::planning::specified_problem::get_object_by_type_and_index(
                   specific_problem,
                   m_prototype->m_parameter_types.m_begin[i],
                   *v11);
        v14 = 0;
        survarium::weapon_user_dead_state::finalize(v6);
        value = (void *)object->m_instance;
        vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
          &new_plan_item.parameters.vostok::buffer_vector<void const *>,
          (const void **)&value);
      }
      survarium::weapon_user_dead_state::finalize(v5);
      vostok::buffer_vector<vostok::ai::planning::plan_item>::construct(plan->m_end, &new_plan_item);
      ++plan->m_end;
      for ( j = objects.m_begin; j != objects.m_end; ++j )
        ;
      objects.m_end = objects.m_begin;
      for ( k = new_plan_item.parameters.m_begin; k != new_plan_item.parameters.m_end; ++k )
        ;
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "ai:", warning),
            v3 = has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v3);
        v12 = 2;
        vostok::logging::append(
          &v15,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\specified_action.cpp",
          0x8Du,
          "void __thiscall vostok::ai::planning::specified_action::add_this_to_plan(class vostok::fixed_vector<struct vos"
          "tok::ai::planning::plan_item,32> &,const class vostok::ai::planning::specified_problem &) const",
          "ai:",
          warning,
          "action instance wasn't found in problem");
      }
      if ( (v12 & 2) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)(v12 & 2),
          (int *)&v15);
    }
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
        0x86u,
        "void __thiscall vostok::ai::planning::specified_action::add_this_to_plan(class vostok::fixed_vector<struct vosto"
        "k::ai::planning::plan_item,32> &,const class vostok::ai::planning::specified_problem &) const",
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
