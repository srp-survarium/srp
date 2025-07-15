char __thiscall vostok::ai::planning::pddl_planner::build_plan(
        vostok::ai::planning::pddl_planner *this,
        vostok::ai::planning::search *search_service,
        vostok::ai::planning::specified_problem *actual_problem,
        const char *caption,
        bool verbose)
{
  survarium::game_camera *v6; // ecx
  int *v7; // eax
  survarium::game_camera *v8; // ecx
  BOOL v9; // ecx
  bool has_passed_filters; // al
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v11; // ecx
  int *v12; // eax
  survarium::game_camera *v13; // ecx
  bool v14; // [esp+4h] [ebp-D8h]
  int v16; // [esp+3Ch] [ebp-A0h]
  int v17; // [esp+54h] [ebp-88h]
  vostok::ai::std_allocator<vostok::ai::planning::specified_action> __a; // [esp+73h] [ebp-69h] BYREF
  int v19; // [esp+74h] [ebp-68h]
  bool v20; // [esp+7Bh] [ebp-61h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v21; // [esp+7Ch] [ebp-60h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+9Ch] [ebp-40h] BYREF
  char v23; // [esp+BFh] [ebp-1Dh]
  unsigned int j; // [esp+C0h] [ebp-1Ch]
  unsigned int i; // [esp+C4h] [ebp-18h]
  unsigned int plan_size; // [esp+C8h] [ebp-14h]
  bool was_actual; // [esp+CFh] [ebp-Dh]
  vostok::ai::vector<vostok::ai::planning::specified_action> specified_actions; // [esp+D0h] [ebp-Ch] BYREF

  v19 = 0;
  vostok::ai::planning::specified_problem::calculate_predicates_offsets(actual_problem);
  vostok::ai::planning::pddl_planner::reset(this);
  vostok::ai::planning::pddl_planner::set_current_world_state(this, actual_problem);
  stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>(
    &specified_actions._M_impl,
    &__a);
  vostok::ai::planning::pddl_planner::specify_actions(this, &specified_actions, actual_problem);
  if ( specified_actions._M_impl._M_finish - specified_actions._M_impl._M_start )
  {
    vostok::ai::planning::pddl_planner::add_actions(this, &specified_actions, actual_problem);
    vostok::ai::planning::pddl_planner::set_target_world_state(this, actual_problem);
    this->m_plan_tracker->m_verbose = verbose;
    this->m_planner.m_forward_search = vostok::ai::planning::pddl_planner::forward_search_required(&specified_actions);
    was_actual = vostok::ai::planning::propositional_planner::update(&this->m_planner, search_service, caption);
    v6 = (survarium::game_camera *)search_service;
    plan_size = search_service->m_plan._M_impl._M_finish - search_service->m_plan._M_impl._M_start;
    v14 = this->m_planner.m_failed || !plan_size;
    LOBYTE(v6) = v14;
    this->m_failed = v14;
    if ( !this->m_failed )
    {
      for ( i = 0; i < plan_size; ++i )
      {
        survarium::weapon_user_dead_state::finalize(v6);
        survarium::weapon_user_dead_state::finalize((survarium::game_camera *)search_service->m_plan._M_impl._M_start);
        v17 = *v7;
        survarium::weapon_user_dead_state::finalize(v8);
        vostok::ai::planning::specified_action::add_this_to_plan(
          &specified_actions._M_impl._M_start[v17],
          &this->m_current_plan,
          actual_problem);
        v6 = (survarium::game_camera *)(i + 1);
      }
    }
    if ( verbose )
    {
      vostok::ai::planning::specified_problem::dump_target_world_state(actual_problem);
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "ai:", info),
            v9 = has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v9);
        v19 |= 1u;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\pddl_planner.cpp",
          0x64u,
          "bool __thiscall vostok::ai::planning::pddl_planner::build_plan(class vostok::ai::planning::search &,class vost"
          "ok::ai::planning::specified_problem &,const char *,bool)",
          "ai:",
          info,
          "solution plan:");
      }
      v11 = (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)(v19 & 1);
      if ( (v19 & 1) != 0 )
      {
        v19 &= ~1u;
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v11,
          (int *)&log_callback);
      }
      if ( this->m_failed )
      {
        if ( !vostok::core::g_log_filter_tree
          || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "ai:", info) )
        {
          boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v11);
          v19 |= 2u;
          vostok::logging::append(
            &v21,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\pddl_planner.cpp",
            0x69u,
            "bool __thiscall vostok::ai::planning::pddl_planner::build_plan(class vostok::ai::planning::search &,class vo"
            "stok::ai::planning::specified_problem &,const char *,bool)",
            "ai:",
            info,
            "no plan can be built for such conditions");
        }
        if ( (v19 & 2) != 0 )
        {
          v19 &= ~2u;
          boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
            v11,
            (int *)&v21);
        }
      }
      else
      {
        for ( j = 0; j < plan_size; ++j )
        {
          survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v11);
          survarium::weapon_user_dead_state::finalize((survarium::game_camera *)search_service->m_plan._M_impl._M_start);
          v16 = *v12;
          survarium::weapon_user_dead_state::finalize(v13);
          vostok::ai::planning::specified_action::debug_output(&specified_actions._M_impl._M_start[v16], actual_problem);
          v11 = (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)(j + 1);
        }
      }
    }
    if ( was_actual )
    {
      vostok::ai::planning::plan_tracker::track(this->m_plan_tracker);
    }
    else if ( !this->m_failed )
    {
      vostok::ai::planning::plan_tracker::on_plan_changed(this->m_plan_tracker, &this->m_current_plan);
      vostok::ai::planning::plan_tracker::track(this->m_plan_tracker);
    }
    v20 = !this->m_failed;
    stlp_std::priv::_Impl_vector<vostok::ai::planning::specified_action,vostok::ai::std_allocator<vostok::ai::planning::specified_action>>::~_Impl_vector<vostok::ai::planning::specified_action,vostok::ai::std_allocator<vostok::ai::planning::specified_action>>(&specified_actions._M_impl);
    return v20;
  }
  else
  {
    this->m_failed = 1;
    v23 = 0;
    stlp_std::priv::_Impl_vector<vostok::ai::planning::specified_action,vostok::ai::std_allocator<vostok::ai::planning::specified_action>>::~_Impl_vector<vostok::ai::planning::specified_action,vostok::ai::std_allocator<vostok::ai::planning::specified_action>>(&specified_actions._M_impl);
    return v23;
  }
}
