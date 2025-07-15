void __thiscall vostok::ai::planning::goal_specificator::fill_problem(
        vostok::ai::planning::goal_specificator *this,
        vostok::ai::planning::specified_problem *specific_problem,
        const vostok::ai::planning::goal *current_goal,
        const vostok::fixed_vector<unsigned int,4> *targets_indices)
{
  unsigned int v4; // eax
  unsigned int v5; // eax
  survarium::game_camera *v6; // ecx
  survarium::game_camera *v7; // ecx
  survarium::game_camera *v8; // ecx
  survarium::game_camera *v9; // ecx
  survarium::game_camera *v10; // ecx
  vostok::buffer_vector<vostok::resources::request> *v11; // ecx
  stlp_std::pair<void const *,char const *> v12; // [esp-Ch] [ebp-140h] BYREF
  char *owner_caption; // [esp-4h] [ebp-138h] BYREF
  vostok::ai::planning::goal_specificator *thisa; // [esp+0h] [ebp-134h]
  const void **jj; // [esp+4h] [ebp-130h]
  vostok::variant<32> *v16; // [esp+8h] [ebp-12Ch] BYREF
  unsigned int type; // [esp+14h] [ebp-120h]
  char v18; // [esp+1Bh] [ebp-119h]
  const vostok::ai::planning::pddl_predicate *v19; // [esp+1Ch] [ebp-118h]
  void **instance; // [esp+20h] [ebp-114h]
  char v21; // [esp+27h] [ebp-10Dh]
  void *buffer; // [esp+28h] [ebp-10Ch]
  const vostok::ai::planning::pddl_predicate *m_predicate; // [esp+2Ch] [ebp-108h]
  bool m_result; // [esp+33h] [ebp-101h]
  unsigned int *v25; // [esp+40h] [ebp-F4h]
  char v26; // [esp+47h] [ebp-EDh]
  survarium::game_camera *v27; // [esp+48h] [ebp-ECh]
  char v28; // [esp+4Eh] [ebp-E6h]
  char v29; // [esp+4Fh] [ebp-E5h]
  unsigned int v30; // [esp+50h] [ebp-E4h]
  char v31; // [esp+56h] [ebp-DEh]
  char v32; // [esp+57h] [ebp-DDh]
  stlp_std::pair<void const *,char const *> *v33; // [esp+64h] [ebp-D0h]
  vostok::ai::vector<vostok::ai::planning::pddl_world_state_property_impl> *p_m_target_state; // [esp+70h] [ebp-C4h]
  vostok::fixed_vector<vostok::ai::planning::action_parameter *,4> *p_m_parameters; // [esp+74h] [ebp-C0h]
  unsigned int v36; // [esp+78h] [ebp-BCh]
  unsigned int m_type; // [esp+7Ch] [ebp-B8h]
  vostok::fixed_vector<unsigned int,4> *p_m_parameter_types; // [esp+80h] [ebp-B4h]
  unsigned int action_type; // [esp+84h] [ebp-B0h]
  vostok::ai::planning::generalized_action *m_first; // [esp+88h] [ebp-ACh]
  char v41; // [esp+8Fh] [ebp-A5h]
  stlp_std::pair<void const *,char const *> v42; // [esp+90h] [ebp-A4h] BYREF
  void *value; // [esp+98h] [ebp-9Ch] BYREF
  unsigned int index; // [esp+A8h] [ebp-8Ch]
  unsigned int ii; // [esp+ACh] [ebp-88h]
  vostok::ai::planning::action_parameter *v46; // [esp+B0h] [ebp-84h]
  vostok::ai::selectors::target_selector_base *v47; // [esp+B4h] [ebp-80h]
  unsigned int n; // [esp+B8h] [ebp-7Ch]
  const stlp_std::pair<void const *,char const *> *owner; // [esp+BCh] [ebp-78h]
  stlp_std::pair<void const *,char const *> result; // [esp+C0h] [ebp-74h] BYREF
  vostok::fixed_vector<void const *,4> objects; // [esp+C8h] [ebp-6Ch] BYREF
  vostok::ai::planning::pddl_world_state_property_impl new_target; // [esp+E0h] [ebp-54h] BYREF
  const vostok::ai::planning::pddl_world_state_property_impl *property; // [esp+100h] [ebp-34h]
  unsigned int i; // [esp+104h] [ebp-30h]
  char *caption; // [esp+108h] [ebp-2Ch]
  vostok::ai::planning::action_parameter *parameter; // [esp+10Ch] [ebp-28h]
  vostok::ai::selectors::target_selector_base *parameter_selector; // [esp+110h] [ebp-24h]
  unsigned int m; // [esp+114h] [ebp-20h]
  unsigned int j; // [esp+118h] [ebp-1Ch]
  vostok::ai::selectors::target_selector_base *selector; // [esp+11Ch] [ebp-18h]
  unsigned int k; // [esp+120h] [ebp-14h]
  const vostok::ai::planning::generalized_action *prototype; // [esp+124h] [ebp-10h]
  const vostok::ai::planning::generalized_action *it; // [esp+128h] [ebp-Ch]
  const vostok::ai::planning::pddl_problem *problem; // [esp+12Ch] [ebp-8h]
  const vostok::ai::planning::pddl_domain *domain; // [esp+130h] [ebp-4h]

  thisa = this;
  vostok::ai::planning::specified_problem::reset(specific_problem);
  domain = specific_problem->m_domain;
  problem = specific_problem->m_problem;
  m_first = domain->m_actions.m_first;
  for ( it = m_first; it; it = it->next )
  {
    prototype = it;
    action_type = it->m_type;
    if ( vostok::ai::planning::pddl_problem::get_action_instance(
           (vostok::ai::planning::pddl_problem *)problem,
           action_type) )
    {
      for ( k = 0; ; ++k )
      {
        p_m_parameter_types = &prototype->m_parameter_types;
        if ( k >= prototype->m_parameter_types.m_end - prototype->m_parameter_types.m_begin )
          break;
        m_type = prototype->m_type;
        vostok::ai::planning::specified_problem::fill_parameter_targets(specific_problem, m_type);
        v36 = prototype->m_type;
        selector = vostok::ai::planning::specified_problem::get_parameter_selector(specific_problem, v36, k);
        if ( selector )
        {
          for ( j = 0; ; ++j )
          {
            v4 = ((int (__thiscall *)(vostok::ai::selectors::target_selector_base *, vostok::ai::planning::goal_specificator *))selector->get_targets_count)(
                   selector,
                   thisa);
            if ( j >= v4 )
              break;
            jj = (const void **)((int (__thiscall *)(vostok::ai::selectors::target_selector_base *, unsigned int, vostok::ai::planning::goal_specificator *, const void **))selector->get_target_caption)(
                                  selector,
                                  j,
                                  thisa,
                                  jj);
            v12.second = (const char *)j;
            v12.first = &owner_caption;
            ((void (__thiscall *)(vostok::ai::selectors::target_selector_base *))selector->get_target)(selector);
            vostok::ai::planning::specified_problem::add_object_instance(specific_problem, v12, owner_caption);
          }
        }
      }
    }
  }
  for ( m = 0; ; ++m )
  {
    p_m_parameters = &current_goal->m_parameters;
    if ( m >= current_goal->m_parameters.m_end - current_goal->m_parameters.m_begin )
      break;
    parameter = vostok::ai::planning::goal::get_parameter(current_goal, m);
    parameter_selector = vostok::ai::planning::specified_problem::get_parameter_selector(specific_problem, parameter);
    if ( parameter_selector )
    {
      for ( caption = 0; ; ++caption )
      {
        v5 = parameter_selector->get_targets_count(parameter_selector);
        if ( (unsigned int)caption >= v5 )
          break;
        jj = (const void **)((int (__thiscall *)(vostok::ai::selectors::target_selector_base *, char *, vostok::ai::planning::goal_specificator *, const void **))parameter_selector->get_target_caption)(
                              parameter_selector,
                              caption,
                              thisa,
                              jj);
        v12.second = caption;
        v12.first = &owner_caption;
        ((void (__thiscall *)(vostok::ai::selectors::target_selector_base *))parameter_selector->get_target)(parameter_selector);
        vostok::ai::planning::specified_problem::add_object_instance(specific_problem, v12, owner_caption);
      }
    }
  }
  for ( i = 0; ; ++i )
  {
    p_m_target_state = &current_goal->m_target_state;
    if ( i >= current_goal->m_target_state._M_impl._M_finish - current_goal->m_target_state._M_impl._M_start )
      break;
    property = vostok::ai::planning::goal::get_target_state_property(current_goal, i);
    vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>(&objects);
    if ( vostok::ai::planning::goal::has_owner_parameter(current_goal) )
    {
      vostok::ai::planning::specified_problem::get_owner_as_object(specific_problem, &result);
      owner = &result;
      owner_caption = (char *)vostok::ai::planning::specified_problem::get_owner_caption(specific_problem);
      v33 = &v12;
      vostok::ai::planning::specified_problem::add_object_instance(specific_problem, *owner, owner_caption);
      vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
        &objects.vostok::buffer_vector<void const *>,
        &owner->first);
    }
    for ( n = 0; n < property->m_indices.m_end - property->m_indices.m_begin; ++n )
    {
      v32 = 0;
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)property);
      v31 = 0;
      survarium::weapon_user_dead_state::finalize(v6);
      v30 = property->m_indices.m_begin[n];
      v46 = vostok::ai::planning::goal::get_parameter(current_goal, v30);
      v47 = vostok::ai::planning::specified_problem::get_parameter_selector(specific_problem, v46);
      if ( v47 )
      {
        v29 = 0;
        survarium::weapon_user_dead_state::finalize(v7);
        v28 = 0;
        survarium::weapon_user_dead_state::finalize(v8);
        v27 = (survarium::game_camera *)property->m_indices.m_begin[n];
        v26 = 0;
        survarium::weapon_user_dead_state::finalize(v27);
        v25 = &targets_indices->m_begin[(_DWORD)v27];
        value = (void *)v47->get_target(v47, &v42, *v25)->first;
        vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
          &objects.vostok::buffer_vector<void const *>,
          (const void **)&value);
      }
    }
    m_result = property->m_result;
    m_predicate = property->m_predicate;
    buffer = new_target.m_indices.m_buffer;
    vostok::buffer_vector<unsigned int>::buffer_vector<unsigned int>(
      &new_target.m_indices,
      (unsigned int *)new_target.m_indices.m_buffer,
      4u,
      0);
    new_target.m_predicate = m_predicate;
    LOBYTE(v9) = m_result;
    new_target.m_result = m_result;
    for ( ii = 0; ii < objects.m_end - objects.m_begin; ++ii )
    {
      v21 = 0;
      survarium::weapon_user_dead_state::finalize(v9);
      instance = (void **)&objects.m_begin[ii];
      v19 = property->m_predicate;
      v18 = 0;
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)instance);
      type = v19->m_parameters.m_begin[ii];
      index = vostok::ai::planning::specified_problem::get_object_index(
                specific_problem,
                type,
                (const void *const *)instance);
      v41 = 0;
      survarium::weapon_user_dead_state::finalize(v10);
      v16 = (vostok::variant<32> *)index;
      vostok::buffer_vector<unsigned int>::push_back(
        (vostok::buffer_vector<vostok::variant<32> const *> *)&new_target,
        (const vostok::variant<32> **)&v16);
    }
    vostok::ai::planning::specified_problem::add_target_property(specific_problem, &new_target);
    vostok::buffer_vector<unsigned int>::~buffer_vector<unsigned int>(v11, &new_target);
    for ( jj = objects.m_begin; jj != objects.m_end; ++jj )
      ;
    objects.m_end = objects.m_begin;
  }
}
