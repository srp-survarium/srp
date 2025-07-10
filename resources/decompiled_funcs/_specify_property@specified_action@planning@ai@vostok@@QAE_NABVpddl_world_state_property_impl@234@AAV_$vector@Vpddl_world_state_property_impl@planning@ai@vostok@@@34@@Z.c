char __thiscall vostok::ai::planning::specified_action::specify_property(
        vostok::ai::planning::specified_action *this,
        survarium::game_camera *property_prototype,
        vostok::ai::vector<vostok::ai::planning::pddl_world_state_property_impl> *state)
{
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v5; // ecx
  vostok::buffer_vector<vostok::resources::request> *v7; // ecx
  const vostok::ai::planning::pddl_predicate *m_predicate; // [esp+20h] [ebp-70h]
  vostok::variant<32> *value; // [esp+24h] [ebp-6Ch] BYREF
  unsigned int index; // [esp+2Ch] [ebp-64h]
  char v12; // [esp+32h] [ebp-5Eh]
  char v13; // [esp+33h] [ebp-5Dh]
  void *buffer; // [esp+34h] [ebp-5Ch]
  const vostok::ai::planning::pddl_predicate *y_low; // [esp+38h] [ebp-58h]
  bool v16; // [esp+3Fh] [ebp-51h]
  int v17; // [esp+40h] [ebp-50h]
  char v18; // [esp+46h] [ebp-4Ah]
  char v19; // [esp+47h] [ebp-49h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+48h] [ebp-48h] BYREF
  unsigned int j; // [esp+68h] [ebp-28h]
  unsigned int i; // [esp+6Ch] [ebp-24h]
  vostok::ai::planning::pddl_world_state_property_impl specified_property; // [esp+70h] [ebp-20h] BYREF

  v17 = 0;
  v16 = LOBYTE(property_prototype->m_inverted_view_matrix.lines[1].elements[2]);
  y_low = (const vostok::ai::planning::pddl_predicate *)LODWORD(property_prototype->m_inverted_view_matrix.j.y);
  buffer = specified_property.m_indices.m_buffer;
  vostok::buffer_vector<unsigned int>::buffer_vector<unsigned int>(
    &specified_property.m_indices,
    (unsigned int *)specified_property.m_indices.m_buffer,
    4u,
    0);
  specified_property.m_predicate = y_low;
  specified_property.m_result = v16;
  for ( i = 0;
        i < (signed int)(LODWORD(property_prototype->m_inverted_view_matrix.i.x)
                       - (unsigned int)property_prototype->__vftable) >> 2;
        ++i )
  {
    v13 = 0;
    survarium::weapon_user_dead_state::finalize(property_prototype);
    v12 = 0;
    survarium::weapon_user_dead_state::finalize(v3);
    index = *((_DWORD *)&property_prototype->get_projection_matrix + i);
    value = (vostok::variant<32> *)*stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::operator[](
                                      &this->m_parameters_instances,
                                      index);
    vostok::buffer_vector<unsigned int>::push_back(
      (vostok::buffer_vector<vostok::variant<32> const *> *)&specified_property,
      (const vostok::variant<32> **)&value);
  }
  for ( j = 0; ; ++j )
  {
    v4 = (survarium::game_camera *)(state->_M_impl._M_finish - state->_M_impl._M_start);
    if ( j >= (unsigned int)v4 )
    {
      stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::push_back(
        &state->_M_impl,
        &specified_property);
      v18 = 1;
      vostok::buffer_vector<unsigned int>::~buffer_vector<unsigned int>(v7, &specified_property);
      return v18;
    }
    m_predicate = specified_property.m_predicate;
    survarium::weapon_user_dead_state::finalize(v4);
    if ( m_predicate == state->_M_impl._M_start[j].m_predicate )
    {
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)state->_M_impl._M_start);
      if ( vostok::ai::planning::specified_action::are_instances_indices_equal(
             (survarium::game_camera *)&specified_property,
             &state->_M_impl._M_start[j]) )
      {
        break;
      }
    }
  }
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "ai:", warning) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v5);
    v17 |= 1u;
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\specified_action.cpp",
      0x3Bu,
      "bool __thiscall vostok::ai::planning::specified_action::specify_property(const class vostok::ai::planning::pddl_wo"
      "rld_state_property_impl &,class vostok::ai::vector<class vostok::ai::planning::pddl_world_state_property_impl> &)",
      "ai:",
      warning,
      "attempt to add already set world state property, specification is skipping");
  }
  if ( (v17 & 1) != 0 )
  {
    v17 &= ~1u;
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v5,
      (int *)&log_callback);
  }
  v19 = 0;
  vostok::buffer_vector<unsigned int>::~buffer_vector<unsigned int>(
    (vostok::buffer_vector<vostok::resources::request> *)v5,
    &specified_property);
  return v19;
}
