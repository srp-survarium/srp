void __thiscall vostok::ai::planning::pddl_planner::specify_actions(
        vostok::ai::planning::pddl_planner *this,
        const vostok::ai::planning::generalized_action *prototype,
        vostok::ai::vector<vostok::ai::planning::specified_action> *destination,
        vostok::ai::planning::specified_problem *actual_problem)
{
  unsigned int *v4; // eax
  const vostok::variant<32> **v5; // eax
  vostok::buffer_vector<vostok::resources::request> *v6; // ecx
  vostok::buffer_vector<vostok::resources::request> *v7; // ecx
  survarium::game_camera v8; // [esp+6Bh] [ebp-75h] BYREF
  bool offsets_incremented; // [esp+CFh] [ebp-11h]
  vostok::ai::vector<unsigned int> offsets; // [esp+D0h] [ebp-10h] BYREF
  unsigned int parameters_count; // [esp+DCh] [ebp-4h]

  if ( vostok::ai::planning::specified_action::can_be_specified(prototype, actual_problem) )
  {
    *(_DWORD *)((char *)&v8.m_inverted_view_matrix.i.elements[1] + 1) = prototype->m_type;
    *(_DWORD *)((char *)v8.m_inverted_view_matrix.i.elements + 1) = actual_problem->m_problem;
    if ( vostok::ai::planning::pddl_problem::get_action_instance(
           *(vostok::ai::planning::pddl_problem **)((char *)v8.m_inverted_view_matrix.i.elements + 1),
           *(const unsigned int *)((char *)&v8.m_inverted_view_matrix.i.elements[1] + 1)) )
    {
      *(survarium::game_camera_vtbl **)((char *)&v8.__vftable + 1) = (survarium::game_camera_vtbl *)&prototype->m_parameter_types;
      parameters_count = prototype->m_parameter_types.m_end - prototype->m_parameter_types.m_begin;
      *(float *)((char *)&v8.m_inverted_view_matrix.i.elements[2] + 1) = 0.0;
      survarium::weapon_user_dead_state::finalize(&v8);
      stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>(
        &offsets._M_impl,
        parameters_count,
        v4,
        (const vostok::ai::std_allocator<unsigned int> *)&v8);
      offsets_incremented = 1;
      while ( 1 )
      {
        if ( !offsets_incremented )
        {
          stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::~_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>(&offsets._M_impl);
          return;
        }
        vostok::buffer_vector<unsigned int>::buffer_vector<unsigned int>(
          (vostok::buffer_vector<unsigned int> *)((char *)&v8.m_inverted_view_matrix.lines[1].x + 1),
          (unsigned int *)((char *)&v8.m_inverted_view_matrix.j.elements[2] + 1),
          4u,
          0);
        for ( *(float *)((char *)&v8.m_inverted_view_matrix.i.elements[3] + 1) = 0.0;
              *(_DWORD *)((char *)&v8.m_inverted_view_matrix.i.elements[3] + 1) < parameters_count;
              ++*(_DWORD *)((char *)&v8.m_inverted_view_matrix.i.elements[3] + 1) )
        {
          survarium::weapon_user_dead_state::finalize(*(survarium::game_camera **)((char *)&v8.m_inverted_view_matrix.i.elements[3]
                                                                                 + 1));
          survarium::weapon_user_dead_state::finalize((survarium::game_camera *)offsets._M_impl._M_start);
          vostok::buffer_vector<unsigned int>::push_back(
            (vostok::buffer_vector<vostok::variant<32> const *> *)((char *)&v8.m_inverted_view_matrix.lines[1].x + 1),
            v5);
          if ( *(_DWORD *)((char *)&v8.m_inverted_view_matrix.i.elements[3] + 1) == parameters_count - 1 )
            offsets_incremented = vostok::ai::planning::increment_offsets(
                                    (survarium::game_camera *)&offsets,
                                    prototype,
                                    actual_problem);
        }
        if ( !parameters_count )
          break;
        if ( vostok::ai::planning::specified_problem::are_parameters_suitable(
               actual_problem,
               prototype->m_type,
               (survarium::game_camera *)((char *)&v8.m_inverted_view_matrix.lines[1].x + 1)) )
        {
LABEL_15:
          vostok::ai::planning::specified_action::specified_action((vostok::ai::planning::specified_action *)((char *)&v8.m_inverted_view_matrix.lines[2].elements[2] + 1));
          if ( vostok::ai::planning::specified_action::specify(
                 (vostok::ai::planning::specified_action *)((char *)&v8.m_inverted_view_matrix.lines[2].elements[2] + 1),
                 prototype,
                 (const vostok::fixed_vector<unsigned int,4> *)((char *)&v8.m_inverted_view_matrix.lines[1].x + 1)) )
          {
            stlp_std::priv::_Impl_vector<vostok::ai::planning::specified_action,vostok::ai::std_allocator<vostok::ai::planning::specified_action>>::push_back(
              &destination->_M_impl,
              (const vostok::ai::planning::specified_action *)((char *)&v8.m_inverted_view_matrix.lines[2].elements[2]
                                                             + 1));
          }
          vostok::ai::planning::specified_action::~specified_action((vostok::ai::planning::specified_action *)((char *)&v8.m_inverted_view_matrix.lines[2].elements[2] + 1));
          vostok::buffer_vector<unsigned int>::~buffer_vector<unsigned int>(
            v7,
            (float *)((char *)v8.m_inverted_view_matrix.j.elements + 1));
        }
        else
        {
          vostok::buffer_vector<unsigned int>::~buffer_vector<unsigned int>(
            v6,
            (float *)((char *)v8.m_inverted_view_matrix.j.elements + 1));
        }
      }
      offsets_incremented = 0;
      goto LABEL_15;
    }
  }
}
